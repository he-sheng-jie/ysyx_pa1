#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdint>
#include <cassert>
#include <regex.h>
#include "sdb.h"
#include "all.h"

// Token 类型定义
enum {
  TK_NOTYPE = 256,
  TK_EQ,
  TK_UEQ,
  TK_NUM,
  TK_AND,
  TK_OR,
  TK_HEX,
  TK_REG,
  TK_GE,
  TK_LE,
  TK_GT,
  TK_LT,
  TK_BITAND,
  TK_BITOR,
  TK_BITXOR,
  TK_BITNOT,
  TK_SHL,
  TK_SHR,
  TK_DEREF
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},
  {"\\+", '+'},
  {"==", TK_EQ},
  {"!=", TK_UEQ},
  {"(0x|0X)[0-9a-fA-F]+", TK_HEX},
  {"\\-?[0-9]+", TK_NUM},
  {"\\-", '-'},
  {"\\*", '*'},
  {"\\/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"\\$[a-zA-Z0-9]+", TK_REG},
  {"\\&\\&", TK_AND},
  {"\\|\\|", TK_OR},
  {"<<", TK_SHL},
  {">>", TK_SHR},
  {">=", TK_GE},
  {"<=", TK_LE},
  {">", TK_GT},
  {"<", TK_LT},
  {"\\&", TK_BITAND},
  {"\\|", TK_BITOR},
  {"\\^", TK_BITXOR},
  {"\\~", TK_BITNOT},
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]))

static regex_t re[NR_REGEX];

// 前向声明
static bool make_token(char *e);
static int op_precedence(int type);
static bool check_paren(int p, int q);
static int find_main_op(int p, int q);
static bool is_unary_op(int pos);
static uint32_t str_to_int(const char *str);
static uint32_t eval(int p, int q, bool *success);

// 全局 tokens（使用 static 避免链接冲突）
static struct token {
  int type;
  char str[32];
} tokens[2048];

static int nr_token = 0;

// 初始化正则表达式
void init_regex() {
  char error_msg[128];
  for (size_t i = 0; i < NR_REGEX; i++) {
    int ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, sizeof(error_msg));
      fprintf(stderr, "regex compilation failed: %s\n%s\n", error_msg, rules[i].regex);
      assert(false);
    }
  }
}

// 字符串转整数（支持十进制/十六进制）
static uint32_t str_to_int(const char *str) {
  if (!str || *str == '\0') return 0;

  bool is_negative = false;
  if (*str == '-') {
    is_negative = true;
    ++str;
  } else if (*str == '+') {
    ++str;
  }

  bool is_hex = false;
  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
    is_hex = true;
    str += 2;
  }

  uint32_t result = 0;
  if (is_hex) {
    while (*str) {
      char c = *str;
      int digit;
      if (c >= '0' && c <= '9') digit = c - '0';
      else if (c >= 'a' && c <= 'f') digit = c - 'a' + 10;
      else if (c >= 'A' && c <= 'F') digit = c - 'A' + 10;
      else break;
      result = result * 16 + digit;
      ++str;
    }
  } else {
    while (*str && std::isdigit(static_cast<unsigned char>(*str))) {
      result = result * 10 + (*str - '0');
      ++str;
    }
  }

  return is_negative ? -result : result;
}

// 词法分析
static bool make_token(char *e) {
  int position = 0;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    bool matched = false;
    for (size_t i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;
        position += substr_len;

        switch (rules[i].token_type) {
          case TK_NOTYPE:
            break;

          case TK_HEX:
          case TK_NUM: {
            if (nr_token == 0 || 
                (tokens[nr_token - 1].type != TK_NUM && tokens[nr_token - 1].type != ')')) {
              tokens[nr_token].type = TK_NUM;
              std::strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';
              nr_token++;
            } else {
              // 处理负号等一元操作（如 -123）
              tokens[nr_token].type = substr_start[0];
              nr_token++;
              tokens[nr_token].type = TK_NUM;
              std::strncpy(tokens[nr_token].str, substr_start + 1, substr_len - 1);
              tokens[nr_token].str[substr_len - 1] = '\0';
              nr_token++;
            }
            break;
          }

          case TK_REG: {
            tokens[nr_token].type = TK_REG;
            std::strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          }

          case '+':
          case '-':
          case '*':
          case '/':
          case '(':
          case ')':
          case TK_EQ:
          case TK_UEQ:
          case TK_AND:
          case TK_OR:
          case TK_GE:
          case TK_LE:
          case TK_GT:
          case TK_LT:
          case TK_BITAND:
          case TK_BITOR:
          case TK_BITXOR:
          case TK_BITNOT:
          case TK_SHL:
          case TK_SHR: {
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          }

          default:
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
        }
        matched = true;
        break;
      }
    }

    if (!matched) {
      fprintf(stderr, "no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  return true;
}

// 运算符优先级
static int op_precedence(int type) {
  switch (type) {
    case '*': case '/': return 10;
    case '+': case '-': return 9;
    case TK_SHL: case TK_SHR: return 8;
    case TK_GT: case TK_LT: case TK_GE: case TK_LE: return 7;
    case TK_EQ: case TK_UEQ: return 6;
    case TK_BITAND: return 5;
    case TK_BITXOR: return 4;
    case TK_BITOR: return 3;
    case TK_AND: return 2;
    case TK_OR: return 1;
    default: return 0;
  }
}

// 括号匹配检查
static bool check_paren(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')') return false;
  int level = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') level++;
    else if (tokens[i].type == ')') {
      level--;
      if (level == 0 && i < q) return false;
    }
  }
  return level == 0;
}

// 查找主运算符（最低优先级、左结合）
static int find_main_op(int p, int q) {
  int level = 0;
  int main_pos = -1;
  int min_prec = 1000;

  for (int i = p; i <= q; i++) {
    int type = tokens[i].type;
    if (type == '(') level++;
    else if (type == ')') level--;
    else if (level == 0 && op_precedence(type) > 0) {
      int prec = op_precedence(type);
      if (prec < min_prec) {
        min_prec = prec;
        main_pos = i;
      } else if (prec == min_prec && i > main_pos) {
        main_pos = i; // 左结合：取右边的同优先级运算符
      }
    }
  }
  return main_pos;
}

// 是否为一元运算符
static bool is_unary_op(int pos) {
  return (tokens[pos].type == TK_BITNOT || tokens[pos].type == TK_DEREF);
}

// 表达式求值
static uint32_t eval(int p, int q, bool *success) {
  if (success) *success = true; 

  if (p > q) {
    if (success) *success = false;
    return 0;
  }
  else if (p == q) {
    if (tokens[p].type == TK_NUM) {
      return str_to_int(tokens[p].str);
    } else if (tokens[p].type == TK_REG) {
      bool get_reg = false;
      // 注意：寄存器名以 '$' 开头，跳过 '$'
      uint32_t val = reg_str2val(&tokens[p].str[1], &get_reg);
      if (get_reg) {
        if (success) *success = true;
        return val;
      } else {
        if (success) *success = false;
        return 0;
      }
    } else {
      if (success) *success = false;
      return 0;
    }
  }
  else if (check_paren(p, q)) {
    return eval(p + 1, q - 1, success);
  }
  else{
    int op_pos = find_main_op(p, q);
    if (op_pos != -1) {
        uint32_t val1 = eval(p, op_pos - 1, success);
        uint32_t val2 = eval(op_pos + 1, q, success);

        switch (tokens[op_pos].type) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/':
            if (val2 == 0) {
            if (success) *success = false;
            return 0;
            }
            return val1 / val2;
        case TK_EQ: return (val1 == val2) ? 1 : 0;
        case TK_UEQ: return (val1 != val2) ? 1 : 0;
        case TK_AND: return (val1 && val2) ? 1 : 0;
        case TK_OR: return (val1 || val2) ? 1 : 0;
        case TK_GT: return (val1 > val2) ? 1 : 0;
        case TK_LT: return (val1 < val2) ? 1 : 0;
        case TK_GE: return (val1 >= val2) ? 1 : 0;
        case TK_LE: return (val1 <= val2) ? 1 : 0;
        case TK_BITAND: return val1 & val2;
        case TK_BITOR: return val1 | val2;
        case TK_BITXOR: return val1 ^ val2;
        case TK_SHL: return val1 << val2;
        case TK_SHR: return val1 >> val2;
        default: assert(false); return 0;
        }
    } else if (is_unary_op(p)) {
        bool sub_ok = true;
        uint32_t val = eval(p + 1, q, &sub_ok);
        if (!sub_ok) {
        if (success) *success = false;
        return 0;
        }
        switch (tokens[p].type) {
        case TK_BITNOT: return ~val;
        case TK_DEREF: {
            return mem_read(val);
        }
        default: assert(false); return 0;
        }
    } else {
        if (success) *success = false;
        return 0;
    }
  }

}

// 主表达式接口
uint32_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  // 将前导 '*' 识别为解引用
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*') {
      if (i == 0 ||
          tokens[i-1].type == '(' ||
          tokens[i-1].type == '+' || tokens[i-1].type == '-' ||
          tokens[i-1].type == '*' || tokens[i-1].type == '/' ||
          tokens[i-1].type == TK_EQ || tokens[i-1].type == TK_UEQ ||
          tokens[i-1].type == TK_AND || tokens[i-1].type == TK_OR ||
          tokens[i-1].type == TK_GT || tokens[i-1].type == TK_LT ||
          tokens[i-1].type == TK_GE || tokens[i-1].type == TK_LE ||
          tokens[i-1].type == TK_BITAND || tokens[i-1].type == TK_BITOR ||
          tokens[i-1].type == TK_BITXOR ||
          tokens[i-1].type == TK_SHL || tokens[i-1].type == TK_SHR ||
          tokens[i-1].type == TK_BITNOT || tokens[i-1].type == TK_DEREF) {
        tokens[i].type = TK_DEREF;
      }
    }
  }

  return eval(0, nr_token - 1, success);
}