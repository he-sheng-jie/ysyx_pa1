#include <cpu/iringbuf.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static char buf[IRINGBUF_SIZE][256];  // 每条指令日志最大256字节
static int head = 0;
static bool full = false;

void iringbuf_record(const char *logbuf) {
  if (logbuf) {
    strncpy(buf[head], logbuf, sizeof(buf[head]) - 1);
    buf[head][sizeof(buf[head]) - 1] = '\0';
  } else {
    buf[head][0] = '\0';
  }

  head = (head + 1) % IRINGBUF_SIZE;
  if (head == 0) full = true;
}

void iringbuf_dump() {
  printf("\n=== Recent Instructions (iringbuf) ===\n");
  int start = full ? head : 0;
  int count = full ? IRINGBUF_SIZE : head;

  for (int i = 0; i < count; i++) {
    int idx = (start + i) % IRINGBUF_SIZE;
    const char *arrow = (i == count - 1) ? "  --> " : "       ";
    printf("%s%s\n", arrow, buf[idx]);
  }
  printf("======================================\n\n");
}