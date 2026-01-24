#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <stdint.h>
#include <stdbool.h>

void ftrace_init(const char *elf_path);
void ftrace_dump_symbols(void);
void handle_ftrace(uint32_t pc, uint32_t opcode, uint32_t dnpc);

#endif