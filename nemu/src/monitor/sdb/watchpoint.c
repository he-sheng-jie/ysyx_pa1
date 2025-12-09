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

#include "sdb.h"

#define NR_WP 32
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char expr[2048];
  word_t value;
} WP;


static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  if(free_ == NULL){
    assert(0);
    return NULL;
  }
  
  WP* new = free_;
  free_ = free_->next;
  new->next = head;
  head = new;
  return new;
}

WP* get_head(){
  
  return head;
}
void free_wp(WP *wp){

  WP *prev = NULL;
  WP *curr = head;
  
  while (curr != NULL && curr->NO != wp->NO) {
    prev = curr;
    curr = curr->next;
  }
  
  if (curr == NULL) {
    assert(0);
    return;
  }
  
  // 从head链表中移除
  if (prev == NULL) {
    head = curr->next;  // 删除的是头节点
  } else {
    prev->next = curr->next;
  }
  
  // 放回free_链表头部
  curr->next = free_;
  free_ = curr;
  
}


void watchpoint_add(char *args) {
  if (args == NULL || args[0] == '\0') {
    printf("用法：w EXPRESSION\n");
    return;
  }
  
  WP *wp = new_wp();
  if (wp == NULL) return;
  
  strncpy(wp->expr, args, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0';
  
  bool success = false;
  wp->value = expr(wp->expr, &success);
  
  if (!success) {
    printf("错误：表达式 '%s' 无效\n", wp->expr);
    free_wp(wp);
    return;
  }
  
  printf("监视点 #%d 已设置：%s = %u (0x%08x)\n", 
         wp->NO + 1, wp->expr, wp->value, wp->value);
}

void isa_watchpoint_display(void) {
  if (head == NULL) {
    return;
  }
  
  printf("当前监视点列表：\n");
  printf("#\t表达式\t\t值\n");
  printf("-\t--------\t--\n");
  
  WP *current = head;
  while (current != NULL) {
    printf("%d\t%s\t\t%u\n", 
           current->NO + 1, 
           current->expr, 
           current->value);
    current = current->next;
  }
}

void watchpoint_delete(int no) {
  if (no < 1 || no > NR_WP) {
    printf("错误：编号 %d 无效（有效范围：1-%d）\n", no, NR_WP);
    return;
  }
  
  WP *current = head;
  
  // 在链表中查找（NO从0开始，用户输入从1开始）
  while (current != NULL && current->NO != no - 1) {
    current = current->next;
  }
  
  if (current == NULL) {
    printf("错误：未找到监视点 #%d\n", no);
    return;
  }
  
  printf("删除监视点 #%d：%s = %u\n", no, current->expr, current->value);
  free_wp(current);
}

void watchpoint_updata(void){
  if (head == NULL) {
    return;
  }

  WP *current = head;
  while (current != NULL) {
    bool success = false;
    current->value=expr(current->expr,&success);
    if(success)
      current = current->next;
    else
      assert(0);
  }
}

int watchpoint_change_test(void) {
  if (head == NULL) {
    return 0;
  }
  
  WP *current = head;
  while (current != NULL) {
    bool success = false;
    word_t tmp = expr(current->expr,&success);
    if(tmp!=current->value||(!success)){
      watchpoint_updata();
      return 1;
    }
    current = current->next;
  }
  return 0;
}

