#ifndef SDB_H
#define SDB_H

#include <stdint.h>
#include <stdbool.h>

void sdb_init(void);
void sdb_loop(void);
void init_regex(void);
uint32_t reg_str2val(const char *name, bool *success);
uint32_t expr(char *e, bool *success);

void init_wp_pool();
void watchpoint_add(char *args);
void watchpoint_delete(int no);
void watchpoint_display(void);
int watchpoint_change_test(void);
void watchpoint_updata(void);

#endif
