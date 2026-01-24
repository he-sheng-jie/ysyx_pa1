#ifndef __MEMLOG_H__
#define __MEMLOG_H__

#include <stdbool.h>
#include <stdint.h>
#include <isa.h>

#define MEMLOG_SIZE 256  // 必须是 2^n
extern int memlog_dump_count;

// 外部初始化接口
void init_log_file(const char *path);

// 记录和 dump 接口
void memlog_record(bool is_write, paddr_t addr, int len, word_t data);
void memlog_dump_to_stdout(void);

#endif