#ifndef ALL_H
#define ALL_H

#include <cstdint>
#include "verilated.h"
#include "Vtop.h"  

#define WATCHPOINT_TEST  0
#define I_TRACE 0
#define M_TRACE 0
#define F_TRACE 0
#define DIFF_TEST 1

#define MEM_SIZE (128 * 1024 * 1024)

struct CPU_state {
    std::uint32_t gpr[32];  // 32 个通用寄存器 (x0-x31)
    std::uint32_t pc;       // 程序计数器
};

extern VerilatedContext* contextp;
extern Vtop* top;
extern bool is_break;
extern uint32_t inst_now;
extern uint8_t ROM[MEM_SIZE];
extern uint8_t RAM[MEM_SIZE];
extern bool diff_check;

uint32_t mem_read(uint32_t pc);
#endif 