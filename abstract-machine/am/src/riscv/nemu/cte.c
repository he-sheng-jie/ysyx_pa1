#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  printf("\n=== EXCEPTION CONTEXT DUMP ===\n");
  printf("mepc   = 0x%x\n", c->mepc);
  printf("mcause = 0x%x (", c->mcause);
  if (c->mcause == 7) printf("ecall/Environment Call)\n");
  else if (c->mcause == 3) printf("breakpoint/ebreak)\n");
  else printf("unknown)\n");
  printf("mstatus= 0x%x\n", c->mstatus);
  
  printf("\nRegisters:\n");
  for (int i = 0; i < NR_REGS; i++) {
    if (i % 4 == 0) printf("  ");
    printf("x%d=0x%x ", i, c->gpr[i]);
    if (i % 4 == 3) printf("\n");
  }
  printf("================================\n\n");
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 0x1:ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
