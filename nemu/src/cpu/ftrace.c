#include <cpu/ftrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <elf.h>

#define MAX_SYMBOLS    1024
#define MAX_CALL_DEPTH 64

// 符号表项
typedef struct {
  uint32_t addr;
  uint32_t size;
  char *name;
} symbol_t;

static symbol_t symbols[MAX_SYMBOLS];
static int symbol_count = 0;
static bool ftrace_initialized = false;

// 调用栈
static const char *call_stack[MAX_CALL_DEPTH];
static int call_depth = 0;

bool ftrace_enabled = false;

// ========== 符号查找 ==========
static const char* lookup_symbol(uint32_t addr) {
  for (int i = 0; i < symbol_count; i++) {
    if (symbols[i].addr == addr) {
      return symbols[i].name;
    }
  }
  return NULL;
}

// ========== 安全 strdup ==========
static char* safe_strdup(const char *str) {
  if (!str) return NULL;
  size_t len = strlen(str);
  char *copy = malloc(len + 1);
  if (copy) memcpy(copy, str, len + 1);
  return copy;
}

// ========== 按地址排序 ==========
static int compare_symbols(const void *a, const void *b) {
  uint32_t addr_a = ((const symbol_t *)a)->addr;
  uint32_t addr_b = ((const symbol_t *)b)->addr;
  if (addr_a < addr_b) return -1;
  if (addr_a > addr_b) return 1;
  return 0;
}

// ========== 纯 C 解析 ELF 符号表 ==========
void ftrace_init(const char *elf_path) {
  if (ftrace_initialized) {
    fprintf(stderr, "ftrace: already initialized\n");
    return;
  }

  FILE *fp = fopen(elf_path, "rb");
  if (!fp) {
    fprintf(stderr, "ftrace: cannot open ELF file %s\n", elf_path);
    return;
  }

  // 读取 ELF 头
  Elf32_Ehdr ehdr;
  if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1) {
    fprintf(stderr, "ftrace: failed to read ELF header\n");
    fclose(fp);
    return;
  }

  // 验证 ELF
  if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
    fprintf(stderr, "ftrace: not a valid ELF file\n");
    fclose(fp);
    return;
  }

  if (ehdr.e_ident[EI_CLASS] != ELFCLASS32) {
    fprintf(stderr, "ftrace: only 32-bit ELF supported\n");
    fclose(fp);
    return;
  }

  if (ehdr.e_type != ET_EXEC && ehdr.e_type != ET_DYN) {
    fprintf(stderr, "ftrace: not an executable or shared object\n");
    fclose(fp);
    return;
  }

  // 读取节区头表
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  Elf32_Shdr *shdrs = malloc(ehdr.e_shnum * sizeof(Elf32_Shdr));
  if (!shdrs || fread(shdrs, sizeof(Elf32_Shdr), ehdr.e_shnum, fp) != ehdr.e_shnum) {
    fprintf(stderr, "ftrace: failed to read section headers\n");
    free(shdrs);
    fclose(fp);
    return;
  }

  // 读取节区名称字符串表 (.shstrtab)
  uint32_t shstrndx = ehdr.e_shstrndx;
  if (shstrndx >= ehdr.e_shnum) {
    fprintf(stderr, "ftrace: invalid shstrndx\n");
    free(shdrs);
    fclose(fp);
    return;
  }

  fseek(fp, shdrs[shstrndx].sh_offset, SEEK_SET);
  size_t shstrtab_size = shdrs[shstrndx].sh_size;
  char *shstrtab = malloc(shstrtab_size);
  if (!shstrtab || fread(shstrtab, 1, shstrtab_size, fp) != shstrtab_size) {
    fprintf(stderr, "ftrace: failed to read .shstrtab\n");
    free(shdrs); free(shstrtab);
    fclose(fp);
    return;
  }

  // 查找 .symtab 和 .strtab
  int symtab_idx = -1, strtab_idx = -1;
  for (int i = 0; i < ehdr.e_shnum; i++) {
    if (shdrs[i].sh_type == SHT_SYMTAB) {
      symtab_idx = i;
      strtab_idx = shdrs[i].sh_link; // .symtab 的 sh_link 指向 .strtab
    }
  }

  if (symtab_idx == -1) {
    fprintf(stderr, "ftrace: .symtab not found\n");
    free(shdrs); free(shstrtab);
    fclose(fp);
    return;
  }

  if (strtab_idx >= ehdr.e_shnum) {
    fprintf(stderr, "ftrace: invalid .strtab index\n");
    free(shdrs); free(shstrtab);
    fclose(fp);
    return;
  }

  // 读取 .strtab（符号名称字符串表）
  fseek(fp, shdrs[strtab_idx].sh_offset, SEEK_SET);
  size_t strtab_size = shdrs[strtab_idx].sh_size;
  char *strtab = malloc(strtab_size);
  if (!strtab || fread(strtab, 1, strtab_size, fp) != strtab_size) {
    fprintf(stderr, "ftrace: failed to read .strtab\n");
    free(shdrs); free(shstrtab); free(strtab);
    fclose(fp);
    return;
  }

  // 读取 .symtab（符号表）
  fseek(fp, shdrs[symtab_idx].sh_offset, SEEK_SET);
  size_t symtab_size = shdrs[symtab_idx].sh_size;
  Elf32_Sym *syms = malloc(symtab_size);
  if (!syms || fread(syms, 1, symtab_size, fp) != symtab_size) {
    fprintf(stderr, "ftrace: failed to read .symtab\n");
    free(shdrs); free(shstrtab); free(strtab); free(syms);
    fclose(fp);
    return;
  }

  // 提取函数符号
  symbol_count = 0;
  int sym_count = symtab_size / sizeof(Elf32_Sym);
  for (int i = 0; i < sym_count && symbol_count < MAX_SYMBOLS; i++) {
    Elf32_Sym *sym = &syms[i];

    // 必须是函数类型
    if (ELF32_ST_TYPE(sym->st_info) != STT_FUNC) continue;

    // 地址不能为 0
    if (sym->st_value == 0) continue;

    // 名称偏移必须有效
    if (sym->st_name == 0 || sym->st_name >= strtab_size) continue;

    const char *name = strtab + sym->st_name;
    if (name[0] == '\0') continue;

    // 跳过本地符号（如 .Lxxx）
    if (name[0] == '.') continue;

    symbols[symbol_count].addr = sym->st_value;
    symbols[symbol_count].size = sym->st_size;
    symbols[symbol_count].name = safe_strdup(name);
    if (symbols[symbol_count].name) {
      symbol_count++;
    }
  }

  // 清理
  free(syms); free(strtab); free(shdrs); free(shstrtab);
  fclose(fp);

  // 排序
  qsort(symbols, symbol_count, sizeof(symbol_t), compare_symbols);

  ftrace_initialized = true;
  ftrace_enabled = true;
  printf("ftrace: loaded %d symbols from %s\n", symbol_count, elf_path);
}

// ========== 打印符号表 ==========
void ftrace_dump_symbols(void) {
  if (!ftrace_initialized) {
    printf("ftrace: not initialized yet.\n");
    return;
  }

  printf("=== ftrace symbol table (%d symbols) ===\n", symbol_count);
  for (int i = 0; i < symbol_count; i++) {
    uint32_t start = symbols[i].addr;
    uint32_t end = start + symbols[i].size;
    if (symbols[i].size > 0) {
      printf("0x%08x - 0x%08x (%5u bytes): %s\n", start, end, symbols[i].size, symbols[i].name);
    } else {
      printf("0x%08x                 (unknown size): %s\n", start, symbols[i].name);
    }
  }
  printf("========================================\n");
}

// ========== 调用/返回跟踪（保持不变）==========
void ftrace_on_call(uint32_t call_pc, uint32_t target_pc) {
  if (!ftrace_enabled || call_depth >= MAX_CALL_DEPTH) return;
  const char *func_name = lookup_symbol(target_pc);
  if (!func_name) func_name = "unknown";
  call_stack[call_depth++] = func_name;
  for (int i = 0; i < call_depth - 1; i++) printf("  ");
  printf("0x%08x: call [%s@0x%08x]\n", call_pc, func_name, target_pc);
}

void ftrace_on_ret(uint32_t ret_pc) {
  if (!ftrace_enabled || call_depth <= 0) return;
  const char *func_name = call_stack[--call_depth];
  for (int i = 0; i < call_depth; i++) printf("  ");
  printf("0x%08x: ret  [%s]\n", ret_pc, func_name);
}

void handle_ftrace(uint32_t pc, uint32_t opcode, uint32_t dnpc) {
  if (!ftrace_enabled) return;
  if (opcode == 0x00008067) {
    ftrace_on_ret(pc);
    return;
  }
  uint32_t opcode_type = opcode & 0x7f;
  if (opcode_type == 0x6f) {
    ftrace_on_call(pc, dnpc);
  } else if (opcode_type == 0x67) {
    uint32_t funct3 = (opcode >> 12) & 0x7;
    if (funct3 != 0) return;
    uint32_t rd = (opcode >> 7) & 0x1f;
    uint32_t rs1 = (opcode >> 15) & 0x1f;
    uint32_t imm = ((opcode >> 20) & 0x7ff);
    if (rd == 1 && rs1 != 0) {
      ftrace_on_call(pc, dnpc);
    } else if (rd == 0 && rs1 == 1 && imm == 0) {
      ftrace_on_ret(pc);
    }
  }
}