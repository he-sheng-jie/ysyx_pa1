#include "all.h"
#include "reg.h"
#include "difftest.h"
#include <dlfcn.h>      // dlopen, dlsym
#include <cassert>      // assert
#include <cstdio>       // printf
#include <cstdint>
#include <cstring>

bool diff_check = true;

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = nullptr;
void (*ref_difftest_regcpy)(void *dut, bool direction) = nullptr;
void (*ref_difftest_exec)(uint64_t n) = nullptr;
void (*ref_difftest_raise_intr)(uint64_t NO) = nullptr;




extern const char *regs[]; 

void print_reg_diff(const CPU_state *ref) {
    printf("\n=== Register Diff (DUT vs REF) ===\n");
    printf("%-4s | %-12s | %-12s | %s\n", "Reg", "DUT", "REF", "Match?");
    printf("----------------------------------------\n");

    bool all_match = true;

    // 打印通用寄存器 x0-x31
    for (int i = 0; i < 32; i++) {
        uint32_t dut_val = (i == 0) ? 0 : top->debug_rf[i]; // x0 恒为 0
        uint32_t ref_val = ref->gpr[i];
        bool match = (dut_val == ref_val);

        if (!match) all_match = false;

        const char *status = match ? "OK" : "\033[1;31mMISMATCH\033[0m"; // 红色高亮
        printf("%-4s | 0x%08x   | 0x%08x   | %s\n",
               regs[i], dut_val, ref_val, status);
    }

    // 打印 PC
    uint32_t dut_pc = top->pc;
    uint32_t ref_pc = ref->pc;
    bool pc_match = (dut_pc == ref_pc);
    if (!pc_match) all_match = false;

    const char *pc_status = pc_match ? "OK" : "\033[1;31mMISMATCH\033[0m";
    printf("%-4s | 0x%08x   | 0x%08x   | %s\n", "pc", dut_pc, ref_pc, pc_status);

    printf("----------------------------------------\n");
    if (all_match) {
        printf("\033[1;32m>>> All registers match!\033[0m\n");
    } else {
        printf("\033[1;31m>>> Mismatch detected! Check highlighted lines.\033[0m\n");
    }

    // 👇 新增：用黄色输出 pc_before（上一条指令的地址）
    printf("\033[1;33mpc_before = 0x%08x\033[0m\n", top->pc_before);
    printf("\n");
}

bool difftest_checkregs(CPU_state *ref_r) {
  int i;
  for(i = 0;i < 32; i++){
    if(ref_r->gpr[i] != top->debug_rf[i]){ 
        return false;
      }
  }
  if(ref_r->pc != top->pc)
    {
      return false;
    }
  return true;
}

void init_difftest(char *ref_so_file, long img_size, int port) {
    assert(ref_so_file != nullptr);

    void *handle = dlopen(ref_so_file, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        assert(false);
    }

    // 使用 reinterpret_cast 安全转换（C++ 要求）
    ref_difftest_memcpy = reinterpret_cast<decltype(ref_difftest_memcpy)>(
        dlsym(handle, "difftest_memcpy")
    );
    assert(ref_difftest_memcpy && "Failed to load difftest_memcpy");

    ref_difftest_regcpy = reinterpret_cast<decltype(ref_difftest_regcpy)>(
        dlsym(handle, "difftest_regcpy")
    );
    assert(ref_difftest_regcpy && "Failed to load difftest_regcpy");

    ref_difftest_exec = reinterpret_cast<decltype(ref_difftest_exec)>(
        dlsym(handle, "difftest_exec")
    );
    assert(ref_difftest_exec && "Failed to load difftest_exec");

    ref_difftest_raise_intr = reinterpret_cast<decltype(ref_difftest_raise_intr)>(
        dlsym(handle, "difftest_raise_intr")
    );
    assert(ref_difftest_raise_intr && "Failed to load difftest_raise_intr");

    auto ref_difftest_init = reinterpret_cast<void (*)(int)>(
        dlsym(handle, "difftest_init")
    );
    assert(ref_difftest_init && "Failed to load difftest_init");

    // 初始化并同步初始状态
    ref_difftest_init(port);
    ref_difftest_memcpy(RESET_VECTOR, ROM, MEM_SIZE, DIFFTEST_TO_REF);
    ref_difftest_regcpy(top->debug_rf, DIFFTEST_TO_REF);
}


static void checkregs(CPU_state *ref) {
  if (!difftest_checkregs(ref)) {
    diff_check = false;
    printf("\n[DIFFTEST FAILED]\n");
    print_reg_diff(ref);
  }
}

void print_cpu_state(const CPU_state *s, const char *label = "CPU") {
    printf("=== %s State ===\n", label);
    printf("PC = 0x%08x (%u)\n", s->pc, s->pc);

    const char *reg_names[] = {
        "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
        "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
        "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
        "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
    };

    for (int i = 0; i < 32; i++) {
        // x0 (zero) 应始终为 0，但这里仍打印实际值用于调试
        printf("%-4s = 0x%08x (%10u)", reg_names[i], s->gpr[i], s->gpr[i]);
        if (i % 2 == 1) {
            printf("\n"); // 每行两个寄存器
        } else {
            printf("  ");
        }
    }
    if (32 % 2 != 0) printf("\n"); // 确保换行
}

void difftest_step(void) {
  CPU_state ref_r;

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r);
}


