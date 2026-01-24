// #include <cpu/ftrace.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <elf.h>

// #define MAX_SYMBOLS    1024
// #define MAX_CALL_DEPTH 64

// // 符号表项：包含地址、大小和名称
// typedef struct {
//   uint32_t addr;
//   uint32_t size;   // 函数大小（若可用）
//   char *name;
// } symbol_t;

// static symbol_t symbols[MAX_SYMBOLS];
// static int symbol_count = 0;
// static bool ftrace_initialized = false;  // 避免重复初始化

// // 调用栈
// static const char *call_stack[MAX_CALL_DEPTH];
// static int call_depth = 0;

// bool ftrace_enabled = false;

// // ========== 符号查找 ==========
// static const char* lookup_symbol(uint32_t addr) {
//   for (int i = 0; i < symbol_count; i++) {
//     if (symbols[i].addr == addr) {
//       return symbols[i].name;
//     }
//   }
//   return NULL;
// }

// // ========== 辅助：安全 strdup 封装 ==========
// static char* safe_strdup(const char *str) {
//   if (!str) return NULL;
//   char *copy = malloc(strlen(str) + 1);
//   if (copy) strcpy(copy, str);
//   return copy;
// }

// // ========== ELF 解析子函数 ==========
// static bool load_elf_sections(FILE *fp, Elf32_Ehdr *ehdr,
//                               Elf32_Shdr **shdrs_out, char **shstrtab_out) {
//   // 读取节区头表
//   fseek(fp, ehdr->e_shoff, SEEK_SET);
//   Elf32_Shdr *shdrs = malloc(ehdr->e_shnum * sizeof(Elf32_Shdr));
//   if (!shdrs || fread(shdrs, sizeof(Elf32_Shdr), ehdr->e_shnum, fp) != ehdr->e_shnum) {
//     free(shdrs);
//     return false;
//   }

//   // 读取节区名称字符串表
//   fseek(fp, shdrs[ehdr->e_shstrndx].sh_offset, SEEK_SET);
//   size_t shstrtab_size = shdrs[ehdr->e_shstrndx].sh_size;
//   char *shstrtab = malloc(shstrtab_size);
//   if (!shstrtab || fread(shstrtab, 1, shstrtab_size, fp) != shstrtab_size) {
//     free(shdrs); free(shstrtab);
//     return false;
//   }

//   *shdrs_out = shdrs;
//   *shstrtab_out = shstrtab;
//   return true;
// }

// static bool load_symbol_and_string_tables(FILE *fp, Elf32_Shdr *shdrs, int symtab_idx, int strtab_idx,
//                                           Elf32_Sym **syms_out, char **strtab_out) {
//   // 加载 .strtab
//   fseek(fp, shdrs[strtab_idx].sh_offset, SEEK_SET);
//   size_t strtab_size = shdrs[strtab_idx].sh_size;
//   char *strtab = malloc(strtab_size);
//   if (!strtab || fread(strtab, 1, strtab_size, fp) != strtab_size) {
//     free(strtab);
//     return false;
//   }

//   // 加载 .symtab
//   fseek(fp, shdrs[symtab_idx].sh_offset, SEEK_SET);
//   size_t symtab_size = shdrs[symtab_idx].sh_size;
//   Elf32_Sym *syms = malloc(symtab_size);
//   if (!syms || fread(syms, 1, symtab_size, fp) != symtab_size) {
//     free(strtab); free(syms);
//     return false;
//   }

//   *syms_out = syms;
//   *strtab_out = strtab;
//   return true;
// }

// // ========== 初始化 ftrace ==========
// void ftrace_init(const char *elf_path) {
//   if (ftrace_initialized) {
//     fprintf(stderr, "ftrace: already initialized\n");
//     return;
//   }

//   FILE *fp = fopen(elf_path, "rb");
//   if (!fp) {
//     fprintf(stderr, "ftrace: cannot open ELF file %s\n", elf_path);
//     return;
//   }

//   Elf32_Ehdr ehdr;
//   if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1) goto error;

//   if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
//     fprintf(stderr, "ftrace: not a valid ELF file\n");
//     goto error;
//   }

//   if (ehdr.e_type != ET_EXEC) {
//     fprintf(stderr, "ftrace: only executable ELF supported\n");
//     goto error;
//   }

//   Elf32_Shdr *shdrs = NULL;
//   char *shstrtab = NULL;
//   if (!load_elf_sections(fp, &ehdr, &shdrs, &shstrtab)) {
//     goto error;
//   }

//   // 查找 .symtab 和 .strtab
//   int symtab_idx = -1, strtab_idx = -1;
//   for (int i = 0; i < ehdr.e_shnum; i++) {
//     if (shdrs[i].sh_type == SHT_SYMTAB) symtab_idx = i;
//     if (shdrs[i].sh_type == SHT_STRTAB) strtab_idx = i;
//   }

//   if (symtab_idx == -1 || strtab_idx == -1) {
//     fprintf(stderr, "ftrace: .symtab or .strtab not found\n");
//     free(shdrs); free(shstrtab);
//     goto error;
//   }

//   Elf32_Sym *syms = NULL;
//   char *strtab = NULL;
//   if (!load_symbol_and_string_tables(fp, shdrs, symtab_idx, strtab_idx, &syms, &strtab)) {
//     free(shdrs); free(shstrtab);
//     goto error;
//   }

//   // 提取函数符号
//   symbol_count = 0;
//   int sym_count = shdrs[symtab_idx].sh_size / sizeof(Elf32_Sym);
//   for (int i = 0; i < sym_count && symbol_count < MAX_SYMBOLS; i++) {
//     if (ELF32_ST_TYPE(syms[i].st_info) == STT_FUNC && syms[i].st_value != 0) {
//       symbols[symbol_count].addr = syms[i].st_value;
//       symbols[symbol_count].size = syms[i].st_size;  // 可能为 0
//       symbols[symbol_count].name = safe_strdup(strtab + syms[i].st_name);
//       if (!symbols[symbol_count].name) {
//         // 内存不足，跳过
//         continue;
//       }
//       symbol_count++;
//     }
//   }

//   free(syms); free(strtab); free(shdrs); free(shstrtab);
//   fclose(fp);

//   ftrace_initialized = true;
//   ftrace_enabled = true;
//   printf("ftrace: loaded %d symbols from %s\n", symbol_count, elf_path);
//   return;

// error:
//   fclose(fp);
//   ftrace_enabled = false;
//   ftrace_initialized = false;
// }

// // ========== 新增：打印所有符号信息 ==========
// void ftrace_dump_symbols(void) {
//   if (!ftrace_initialized) {
//     printf("ftrace: not initialized yet.\n");
//     return;
//   }

//   printf("=== ftrace symbol table (%d symbols) ===\n", symbol_count);
//   for (int i = 0; i < symbol_count; i++) {
//     uint32_t start = symbols[i].addr;
//     uint32_t end = start + symbols[i].size;
//     if (symbols[i].size > 0) {
//       printf("0x%08x - 0x%08x (%5u bytes): %s\n", start, end, symbols[i].size, symbols[i].name);
//     } else {
//       printf("0x%08x                 (unknown size): %s\n", start, symbols[i].name);
//     }
//   }
//   printf("========================================\n");
// }

// // ========== 原有调用/返回处理（保持不变）==========
// void ftrace_on_call(uint32_t call_pc, uint32_t target_pc) {
//   if (!ftrace_enabled || call_depth >= MAX_CALL_DEPTH) return;

//   const char *func_name = lookup_symbol(target_pc);
//   if (!func_name) func_name = "unknown";

//   call_stack[call_depth++] = func_name;

//   for (int i = 0; i < call_depth - 1; i++) printf("  ");
//   printf("0x%08x: call [%s@0x%08x]\n", call_pc, func_name, target_pc);
// }

// void ftrace_on_ret(uint32_t ret_pc) {
//   if (!ftrace_enabled || call_depth <= 0) return;

//   const char *func_name = call_stack[--call_depth];

//   for (int i = 0; i < call_depth; i++) printf("  ");
//   printf("0x%08x: ret  [%s]\n", ret_pc, func_name);
// }

// void handle_ftrace(uint32_t pc, uint32_t opcode, uint32_t dnpc) {
//   if (!ftrace_enabled) return;

//   if (opcode == 0x00008067) {
//     ftrace_on_ret(pc);
//     return;
//   }

//   uint32_t opcode_type = opcode & 0x7f;
//   if (opcode_type == 0x6f) {
//     ftrace_on_call(pc, dnpc);
//   }
//   else if (opcode_type == 0x67) {
//     uint32_t funct3 = (opcode >> 12) & 0x7;
//     if (funct3 != 0) return;

//     uint32_t rd = (opcode >> 7) & 0x1f;
//     uint32_t rs1 = (opcode >> 15) & 0x1f;
//     uint32_t imm = ((opcode >> 20) & 0x7ff);

//     if (rd == 1 && rs1 != 0) {
//       ftrace_on_call(pc, dnpc);
//     }
//     else if (rd == 0 && rs1 == 1 && imm == 0) {
//       ftrace_on_ret(pc);
//     }
//   }
// }