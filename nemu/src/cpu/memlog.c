#include <cpu/memlog.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <isa.h>

// 默认 dump 最近 20 条记录
int memlog_dump_count = 20;

typedef struct {
  bool is_write;
  paddr_t addr;
  int len;
  word_t data;
} memlog_entry_t;

static memlog_entry_t buf[MEMLOG_SIZE];
static int head = 0;
static bool full = false;
static FILE *log_fp = NULL;
static bool file_initialized = false;
static char log_path[256] = {0}; // 存储外部传入的路径

// 外部可调用的初始化函数
void init_log_file(const char *path) {
  if (file_initialized) {
    // 如果已初始化，先关闭旧文件（可选）
    if (log_fp) fclose(log_fp);
    log_fp = NULL;
  }

  if (!path) {
    fprintf(stderr, "Error: memlog path is NULL\n");
    exit(1);
  }

  strncpy(log_path, path, sizeof(log_path) - 1);
  log_path[sizeof(log_path) - 1] = '\0';

  // 打开文件（清空模式）
  log_fp = fopen(log_path, "w");
  if (!log_fp) {
    fprintf(stderr, "Error: Cannot open memlog file '%s' for writing!\n", log_path);
    exit(1);
  }

  file_initialized = true;
}

void memlog_record(bool is_write, paddr_t addr, int len, word_t data) {
  // 1. 更新环形缓冲区（用于 dump）
  buf[head].is_write = is_write;
  buf[head].addr = addr;
  buf[head].len = len;
  buf[head].data = data;
  head = (head + 1) & (MEMLOG_SIZE - 1);
  if (head == 0) full = true;

  // 2. 写入文件（确保已初始化）
  if (!file_initialized) {
    // 安全兜底：未初始化时不记录（或可 panic）
    return;
  }

  const char *op = is_write ? "WRITE" : "READ ";
  
  if (len == 1) {
    fprintf(log_fp, "%s 0x%08x <- 0x%02x\n", op, addr, (uint8_t)data);
  } else if (len == 2) {
    fprintf(log_fp, "%s 0x%08x <- 0x%04x\n", op, addr, (uint16_t)data);
  } else if (len == 4) {
    fprintf(log_fp, "%s 0x%08x <- 0x%08x\n", op, addr, data);
  } else {
    fprintf(log_fp, "%s 0x%08x (%d bytes) <- 0x%016lx\n", op, addr, len, (unsigned long)data);
  }

  fflush(log_fp); // 确保立即写入磁盘
}

void memlog_dump_to_stdout(void) {
  int total = full ? MEMLOG_SIZE : head;
  int count = (memlog_dump_count < total) ? memlog_dump_count : total;
  int start = (head - count + MEMLOG_SIZE) & (MEMLOG_SIZE - 1);

  printf("\n=== Memory Access Log (last %d records) ===\n", count);
  for (int i = 0; i < count; i++) {
    int idx = (start + i) & (MEMLOG_SIZE - 1);
    const char *op = buf[idx].is_write ? "WRITE" : "READ ";

    if (buf[idx].len == 1) {
      printf("[%3d] %s 0x%08x <- 0x%02x\n", 
             i, op, buf[idx].addr, (uint8_t)buf[idx].data);
    } else if (buf[idx].len == 2) {
      printf("[%3d] %s 0x%08x <- 0x%04x\n", 
             i, op, buf[idx].addr, (uint16_t)buf[idx].data);
    } else if (buf[idx].len == 4) {
      printf("[%3d] %s 0x%08x <- 0x%08x\n", 
             i, op, buf[idx].addr, buf[idx].data);
    } else {
      printf("[%3d] %s 0x%08x (%d bytes) <- 0x%016lx\n", 
             i, op, buf[idx].addr, buf[idx].len, (unsigned long)buf[idx].data);
    }
  }
  printf("=========================================\n\n");
}