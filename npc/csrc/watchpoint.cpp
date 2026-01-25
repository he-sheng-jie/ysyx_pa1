#include "sdb.h"
#include <cstring>   // for strncpy
#include <cstdio>    // for printf
#include <cassert>   // for assert

#define NR_WP 32


typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[2048];  // 存储用户输入的表达式字符串
  uint32_t value;     // 缓存当前表达式的求值结果
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = nullptr;
static WP *free_ = nullptr;

// 前向声明
WP* new_wp();
void free_wp(WP *wp);
extern uint32_t expr(char *e, bool *success);  // 假设在 expr.cpp 中定义

void init_wp_pool() {
  for (int i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1) ? nullptr : &wp_pool[i + 1];
  }
  head = nullptr;
  free_ = wp_pool;
}

WP* new_wp() {
  if (free_ == nullptr) {
    assert(false);
    return nullptr;
  }

  WP* new_wp = free_;
  free_ = free_->next;
  new_wp->next = head;
  head = new_wp;
  return new_wp;
}

WP* get_head() {
  return head;
}

void free_wp(WP *wp) {
  if (wp == nullptr) return;

  WP *prev = nullptr;
  WP *curr = head;
  while (curr != nullptr && curr->NO != wp->NO) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == nullptr) {
    assert(false);
    return;
  }

  // 从使用链表中移除
  if (prev == nullptr) {
    head = curr->next;
  } else {
    prev->next = curr->next;
  }

  // 放回空闲链表
  curr->next = free_;
  free_ = curr;
}

void watchpoint_add(char *args) {
  if (args == nullptr || args[0] == '\0') {
    std::printf("用法：w EXPRESSION\n");
    return;
  }

  WP *wp = new_wp();
  if (wp == nullptr) return;

  std::strncpy(wp->expr, args, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0';

  bool success = false;
  wp->value = expr(wp->expr, &success);

  if (!success) {
    std::printf("错误：表达式 '%s' 无效\n", wp->expr);
    free_wp(wp);
    return;
  }

  std::printf("监视点 #%d 已设置：%s = %u (0x%08x)\n",
              wp->NO + 1, wp->expr, static_cast<unsigned>(wp->value), wp->value);
}

void watchpoint_display(void) {
  if (head == nullptr) {
    std::printf("无监视点。\n");
    return;
  }

  std::printf("当前监视点列表：\n");
  std::printf("#\t表达式\t\t值\n");
  std::printf("-\t--------\t--\n");

  WP *current = head;
  while (current != nullptr) {
    std::printf("%u\t%s\t\t%u\n",
                current->NO + 1,
                current->expr,
                static_cast<unsigned>(current->value));
    current = current->next;
  }
}

void watchpoint_delete(int no) {
  if (no < 1 || no > NR_WP) {
    std::printf("错误：编号 %d 无效（有效范围：1-%d）\n", no, NR_WP);
    return;
  }

  WP *current = head;
  while (current != nullptr && current->NO != no - 1) {
    current = current->next;
  }

  if (current == nullptr) {
    std::printf("错误：未找到监视点 #%d\n", no);
    return;
  }

  std::printf("删除监视点 #%u：%s = %u\n", no, current->expr, static_cast<unsigned>(current->value));
  free_wp(current);
}

void watchpoint_updata(void) {
  WP *current = head;
  while (current != nullptr) {
    bool success = false;
    current->value = expr(current->expr, &success);
    if (!success) {
      std::printf("警告：监视点 #%d 表达式求值失败: %s\n", current->NO + 1, current->expr);
      // 可选择继续或断言，这里选择继续
    }
    current = current->next;
  }
}

int watchpoint_change_test(void) {
  WP *current = head;
  while (current != nullptr) {
    bool success = false;
    uint32_t tmp = expr(current->expr, &success);
    if (!success || tmp != current->value) {
      watchpoint_updata();  // 更新所有值
      return 1;
    }
    current = current->next;
  }
  return 0;
}