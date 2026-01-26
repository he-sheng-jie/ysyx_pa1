#ifndef DIFFTEST_H
#define DIFFTEST_H

#include <cstdint>
#include <cstddef>
#include "all.h"
constexpr bool DIFFTEST_TO_REF = true;   // DUT → REF
constexpr bool DIFFTEST_TO_DUT = false;  // REF → DUT

constexpr uint32_t RESET_VECTOR = 0x80000000;

extern bool diff_check;  

extern void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction);
extern void (*ref_difftest_regcpy)(void *dut, bool direction);
extern void (*ref_difftest_exec)(uint64_t n);
extern void (*ref_difftest_raise_intr)(uint64_t NO);

void init_difftest(char *ref_so_file, long img_size, int port);
void difftest_step(void);
bool difftest_checkregs(CPU_state *ref_r);

#endif 