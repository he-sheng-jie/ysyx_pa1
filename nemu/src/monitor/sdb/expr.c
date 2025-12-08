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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, 
  TK_EQ,
  /* TODO: Add more token types */
  TK_UEQ,
  TK_NUM,
  TK_AND,
  TK_OR,
  TK_HEX,
  TK_REG,
  TK_DEREF
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},          // plus
  {"==", TK_EQ},        // 相等
  {"!=", TK_UEQ},        // 不等
  {"\\-?[0-9]+", TK_NUM},          // 十进制数字
  {"\\-", '-'},          // 减
  {"\\*", '*'},          // 乘或者解引用？
  {"\\/", '/'},          // 除
  {"\\(", '('},          // 左括号
  {"\\)", ')'},          // 右括号
  {"(0x|0X)[0-9a-fA-F]+",TK_HEX},     //十六进制数字

  {"\\$[a-zA-Z0-9]+",TK_REG},                //寄存器读取运算      
  {"\\&\\&", TK_AND},             //与运算
  {"\\|\\|", TK_OR},              //或运算  
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[2048] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
//以下内容为辅助所写
//下面这个函数是用于将字符串转换成int型数进行返回的
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

word_t str_to_int(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0; // 空字符串返回0
    }
    
    // 处理符号
    bool is_negative = false;
    if (*str == '-') {
        is_negative = true;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    // 检查是否是十六进制
    bool is_hex = false;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        is_hex = true;
        str += 2; // 跳过 "0x" 或 "0X"
    }
    
    word_t result = 0;
    
    if (is_hex) {
        // 处理十六进制
        while (*str != '\0') {
            char c = *str;
            int digit;
            
            if (c >= '0' && c <= '9') {
                digit = c - '0';
            } else if (c >= 'a' && c <= 'f') {
                digit = c - 'a' + 10;
            } else if (c >= 'A' && c <= 'F') {
                digit = c - 'A' + 10;
            } else {
                // 遇到非十六进制字符，停止转换
                break;
            }
            
            result = result * 16 + digit;
            str++;
        }
    } else {
        // 处理十进制
        while (*str != '\0' && isdigit((unsigned char)*str)) {
            int digit = *str - '0';
            
            result = result * 10 + digit;
            str++;
        }
    }
    
     return is_negative ? -result : result;
}

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        switch (rules[i].token_type) {
           case TK_NOTYPE: 
        break;  // 跳过空格
        
    case TK_HEX:  
    case TK_NUM:
      if(nr_token == 0||(tokens[nr_token-1].type != TK_NUM && tokens[nr_token-1].type != ')' ) )
        {
        tokens[nr_token].type = TK_NUM;
        // 直接将数值存储到str当中，包括了0x
        char num_buf[32];
        strncpy(num_buf, substr_start, substr_len);
        num_buf[substr_len] = '\0';
        strcpy(tokens[nr_token].str, num_buf); 
        nr_token++;
        break; 
        } else {
        tokens[nr_token].type = substr_start[0];  // 直接存储'+', '-'等字符
        nr_token++;
        tokens[nr_token].type = TK_NUM;
        char num_buf[32];
        strncpy(num_buf, substr_start+1, substr_len-1);
        num_buf[substr_len-1] = '\0';
        strcpy(tokens[nr_token].str, num_buf); 
        nr_token++;
        break; 
        }
    case TK_REG:
        tokens[nr_token].type = TK_REG;
        // 直接将这个寄存器的名称存储到str中
        char reg_buf[32];
        strncpy(reg_buf, substr_start, substr_len);
        reg_buf[substr_len] = '\0';
        strcpy(tokens[nr_token].str, reg_buf); 
        nr_token++;
        break;   

    case TK_EQ:
        tokens[nr_token].type = TK_EQ;
        nr_token++;
        break;
        
    case TK_UEQ:
        tokens[nr_token].type = TK_UEQ;
        nr_token++;
        break;
    case TK_AND:
        tokens[nr_token].type = TK_AND;
        nr_token++;
        break;
    case TK_OR:
        tokens[nr_token].type = TK_OR;
        nr_token++;
        break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
        // 单字符token直接存储字符本身作为类型
        tokens[nr_token].type = substr_start[0];  // 直接存储'+', '-'等字符
        nr_token++;
        break;
    
    default:
        tokens[nr_token].type = rules[i].token_type;
        nr_token++;
        break;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

// 辅助函数：判断是否为运算符
static bool is_op(int type) {
  return type == '+' || type == '-' || type == '*' || type == '/' || 
         type == TK_EQ || type == TK_UEQ||type == TK_AND || type == TK_OR;
}

// 辅助函数：获取运算符优先级
static int op_precedence(int type) {
  switch (type) {
    case '*':
    case '/':
      return 5;  // 最高优先级
    case '+':
    case '-':
      return 4;
    case TK_EQ:   // ==
    case TK_UEQ:  // !=
      return 3;
    case TK_AND:  // &&
      return 2;
    case TK_OR:   // ||
      return 1;   // 最低优先级
    default:
      return 0;  // 不是运算符
  }
}
// 辅助函数：检查括号是否匹配
static bool check_paren(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }
  
  int level = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') {
      level++;
    } else if (tokens[i].type == ')') {
      level--;
      if (level == 0 && i < q) {
        return false;  // 在找到匹配的右括号之前遇到了0
      }
    }
  }
  
  return level == 0;
}

// 辅助函数：找到主运算符位置
static int find_main_op(int p, int q) {
  int level = 0;
  int main_pos = -1;
  int min_prec = 100;  // 初始化为高优先级
  
  for (int i = p; i <= q; i++) {
    int type = tokens[i].type;
    
    if (type == '(') {
      level++;
    } else if (type == ')') {
      level--;
    } else if (level == 0 && is_op(type)) {
      // 在括号外找到运算符
      int prec = op_precedence(type);
      
      // 更新主运算符（优先级最低的运算符）
      // 对于相同优先级，取右边的（左结合性）
      if (prec < min_prec) {
        min_prec = prec;
        main_pos = i;
      } else if (prec == min_prec && main_pos != -1) {
        // 相同优先级，取右边的（左结合）
        if (i > main_pos) {
          main_pos = i;
        }
      }
    }
  }
  
  return main_pos;
}
word_t   eval(int p, int q) {
  if (p > q) {
    /* Bad expression */
    return -1;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
     if (tokens[p].type == TK_NUM) {
      // 我们需要从 token.str 中获取值
      return str_to_int(tokens[p].str);
    } else if (tokens[p].type == TK_REG){
      bool get_reg = false;
      int32_t n = isa_reg_str2val(&tokens[p].str[1], &get_reg);
      if(get_reg)
        return n;
      else
        return -1;
    } else {
      // 错误：不是数字,也不是寄存器
      return -1;
    }
  }
  else if (check_paren(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else {
    int op_pos = find_main_op(p, q);
    
    if (op_pos == -1) {
      // 没有找到运算符，可能是表达式错误
      return -1;
    }
    
 // 递归求值左右子表达式
    int32_t val1 = eval(p, op_pos - 1);
    int32_t val2 = eval(op_pos + 1, q);
    
    // 根据运算符类型计算结果
    switch (tokens[op_pos].type) {
      case '+':
        return val1 + val2;
      case '-':
        return val1 - val2;
      case '*':
        return val1 * val2;
      case '/':
        if (val2 == 0) {
          return -1;  // 除零错误
        }
        return val1 / val2;
      case TK_EQ:
        return (val1 == val2);
      case TK_UEQ:
        return (val1 != val2);
      case TK_AND:
        return (val1 && val2);
      case TK_OR:
        return (val1 || val2);
      default: assert(0);
    }
  }
}
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  

  int p = 0;
  int q = nr_token - 1;
  /* TODO: Insert codes to evaluate the expression. */
  word_t n = eval(p,q);
  if(n!=-1){
    *success = true;
    return n;
    }
  else
    return 0;
}

