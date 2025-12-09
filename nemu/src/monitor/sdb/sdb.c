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
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();



//我写的用于将字符串参数转换成整数的函数
int string_to_int(const char *str, int *result) {
    // 参数检查
    if (str == NULL || result == NULL) {
        return -1; // 参数错误
    }
    
    // 跳过前导空白字符
    while (isspace((unsigned char)*str)) {
        str++;
    }
    
    // 处理可选的正负号
    int sign = 1;
    if (*str == '+') {
        str++;
    } else if (*str == '-') {
        sign = -1;
        str++;
    }
    
    // 检查是否为空字符串或只有符号
    if (*str == '\0') {
        return -1; // 无效输入
    }
    
    // 转换数字
    long long value = 0; // 使用long long来检测溢出
    int digit_count = 0;
    
    while (*str != '\0') {
        // 检查是否为数字字符
        if (!isdigit((unsigned char)*str)) {
            return -1; // 非数字字符
        }
        
        // 转换为数字
        int digit = *str - '0';
        
        // 检查溢出
        if (value > (LLONG_MAX - digit) / 10) {
            return -2; // 溢出错误
        }
        
        value = value * 10 + digit;
        digit_count++;
        str++;
    }
    
    // 应用符号
    value *= sign;
    
    // 检查是否在int范围内
    if (value > INT_MAX || value < INT_MIN) {
        return -2; // 溢出错误
    }
    
    // 返回结果
    *result = (int)value;
    return 0; // 成功
}

bool parse_hex_arg(char *args, uint32_t *result) {
    if (args == NULL || result == NULL) {
        return false;
    }
    
    char *p = args;
    
    // 跳过空白字符
    while (isspace((unsigned char)*p)) {
        p++;
    }
    
    // 检查字符串是否为空
    if (*p == '\0') {
        return false;
    }
    
    // 检查是否以 "0x" 或 "0X" 开头
    if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
        p += 2;
    }
    
    // 检查跳过前缀后是否还有字符
    if (*p == '\0') {
        return false;
    }
    
    uint32_t value = 0;
    bool has_valid_digit = false;
    
    // 逐个字符解析
    while (*p != '\0') {
        char ch = *p;
        uint8_t digit;
        
        if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
        } else if (ch >= 'a' && ch <= 'f') {
            digit = ch - 'a' + 10;
        } else if (ch >= 'A' && ch <= 'F') {
            digit = ch - 'A' + 10;
        } else {
            // 遇到非十六进制字符，停止解析
            // 可能是表达式的一部分，如 "0x80000000 + 4"
            break;
        }
        
        // 检查溢出（32位）
        if (value > (0xFFFFFFFFU >> 4)) {
            return false;
        }
        
        value = (value << 4) | digit;
        has_valid_digit = true;
        p++;
    }
    
    if (!has_valid_digit) {
        return false;
    }
    
    *result = value;
    return true;
}




/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }
   
  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args){
  int n=0;
  if(!string_to_int(args,&n))
    cpu_exec(n);
  return 0;
}

static int cmd_info(char *args){
  if(strcmp(args, "r") == 0) {
     isa_reg_display();
  }
  if(strcmp(args, "w") == 0) {
     isa_watchpoint_display();
  }
 
  return 0;
}

static int cmd_p(char *args){
  bool success = false;
  int result = expr(args,&success);
  if(success)
    printf("%d\n",result);
  else
    printf("error\n");
  return 0;
}

static int cmd_w(char *args){
  watchpoint_add(args);
  return 0;
}

static int cmd_d(char *args){
  int no = 0;
  if(!string_to_int(args,&no))
    watchpoint_delete(no);
  return 0;
}
static int cmd_x(char *tmp){
    char *str = tmp;
    char *str_end = str + strlen(str);
    
    /* 把第一个数抽取出来*/
    char *cmd = strtok(str, " ");
    
    /* 解析第二个表达式
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }
    
    int n;
    uint32_t paddr;
    if(!string_to_int(cmd,&n) && cmd && args && parse_hex_arg(args,&paddr)){
      for(int i=0;i<n;i++)
        {
        printf("addr:0x%08x data:0x%08x\n",paddr+4*i,paddr_read(paddr+4*i,4));
        
        }
    
    }
    
 
  return 0;
}
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },

  /* TODO: Add more commands */
  { "si","-[N] Execute N instructions in single step",cmd_si },
  {"info","-r/-w Print various debugging information",cmd_info},
  { "x", "/NFU ADDR Examine memory", cmd_x },
  { "p", "进行一个表达式的求解，支持多形式", cmd_p },
  { "w", "设置一个表达式的监测点", cmd_w },
  { "d", "删除一个表达式的监测点", cmd_d },
  
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif



    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
