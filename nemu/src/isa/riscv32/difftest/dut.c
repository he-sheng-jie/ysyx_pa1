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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

#include <stdio.h>
void compare_regs(CPU_state *ref) {
  const char *reg_names[32] = {
    "zero", "ra",   "sp",   "gp",   "tp",   "t0",   "t1",   "t2",
    "s0",   "s1",   "a0",   "a1",   "a2",   "a3",   "a4",   "a5",
    "a6",   "a7",   "s2",   "s3",   "s4",   "s5",   "s6",   "s7",
    "s8",   "s9",   "s10",  "s11",  "t3",   "t4",   "t5",   "t6"
  };
  
  printf("=== REGISTER COMPARISON ===\n");
  
  // 检查 PC
  if (cpu.pc != ref->pc) {
    printf("PC: NEMU=0x%08x, REF=0x%08x ❌\n", cpu.pc, ref->pc);
  } else {
    printf("PC: 0x%08x ✅\n", cpu.pc);
  }
  
  // 检查通用寄存器
  for (int i = 0; i < 32; i++) {
    if (cpu.gpr[i] != ref->gpr[i]) {
      printf("%s: NEMU=0x%08x, REF=0x%08x ❌\n", 
             reg_names[i], cpu.gpr[i], ref->gpr[i]);
    }
  }
  
  printf("===========================\n");
}

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int i;
  for(i = 0;i < 32; i++){
    if(ref_r->gpr[i] != cpu.gpr[i]){ 
        compare_regs(ref_r);
        return false;
      }
  }
  if(ref_r->pc != cpu.pc)
    {
      compare_regs(ref_r);
      return false;
    }
  return true;
}

void isa_difftest_attach() {
}
