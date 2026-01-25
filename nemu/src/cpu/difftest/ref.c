/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  uint8_t *buf8 = (uint8_t *)buf;
  if (direction == DIFFTEST_TO_DUT) {
    for (size_t i = 0; i < n; i++) {
      buf8[i] = paddr_read(addr + i, 1);
    }
  } else {
    for (size_t i = 0; i < n; i++) {
      paddr_write(addr + i, 1, buf8[i]);
    }
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_DUT) {
    uint32_t *ref_regs = (uint32_t *)dut;
    for (int i = 0; i < 32; i++) {
      ref_regs[i] = cpu.gpr[i];  // x0 ~ x31
    }
    ref_regs[32] = cpu.pc;       // pc
  } else {
    uint32_t *ref_regs = (uint32_t *)dut;
    for (int i = 0; i < 32; i++) {
      cpu.gpr[i] = ref_regs[i];  // x0 ~ x31
    }
    cpu.pc = ref_regs[32];       // pc

  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
