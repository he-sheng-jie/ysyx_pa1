#ifndef ALL_H
#define ALL_H

#include <cstdint>
#include "verilated.h"
#include "Vtop.h"  
#include "sdb.h"

#define MEM_SIZE (128 * 1024 * 1024)

extern VerilatedContext* contextp;
extern Vtop* top;
extern bool is_break;
extern uint8_t ROM[MEM_SIZE];
extern uint8_t RAM[MEM_SIZE];


uint32_t mem_read(uint32_t pc);
#endif 