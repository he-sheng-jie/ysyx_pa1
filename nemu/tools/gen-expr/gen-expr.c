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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

// 全局状态
static int pos = 0;          // 缓冲区当前位置
static int depth = 0;        // 递归深度


static inline int choose(int n) {
    return rand() % n;
}

// 提取除号 '/' 之后的右操作数表达式（仅提取第一个完整项）
// 输入：expr 指向除号 '/' 之后的第一个字符（即 expr = &original[i+1]）
// 输出：将右操作数复制到 out_buf，返回实际长度；若无效返回 0
static int extract_divisor_expr(const char *expr, char *out_buf, size_t out_size) {
    if (expr == NULL || out_buf == NULL || out_size == 0) return 0;

    int i = 0;
    int j = 0; // out_buf 写入位置
    int paren_level = 0;

    // 跳过前导空格
    while (expr[i] == ' ') i++;


    // 开始提取表达式项：数字、括号表达式、十六进制等
    while (expr[i] != '\0') {
        char c = expr[i];

        // 若在顶层（paren_level == 0），遇到低优先级运算符则终止
        if (paren_level == 0) {
            if (c == '+' || c == '-' || c == '*' || c == '/' || 
                c == ')' || c == '\0' ) {
                break;
            }
        }

        // 处理括号
        if (c == '(') {
            paren_level++;
        } else if (c == ')') {
            if (paren_level <= 0) break; // unmatched )
            paren_level--;
        }

        

        // 写入字符（确保不溢出）
        if (j < (int)out_size - 1) {
            out_buf[j++] = c;
        }
        i++;
    }

    // 终止字符串
    if (j < (int)out_size) {
        out_buf[j] = '\0';
    } else if (out_size > 0) {
        out_buf[out_size - 1] = '\0';
    }


    return j; // 返回有效长度（不含 '\0'）
}

bool check_division_by_zero_simple(const char *expr) {
    if (expr == NULL || *expr == '\0') {
        return false;
    }
    
    int len = strlen(expr);
    
    // 从尾部开始遍历
    for (int i = len - 1; i >= 0; i--) {
        if (expr[i] == '/') {
            // 找到除号，检查右边是否是0
            int j = i + 1;

            char right_expr[1024];

            // 我们生成一个新表达式来测试
            // 创建一个测试表达式：1 / (右表达式)，如果结果为0则右表达式为0
            int right_start = j;
            int right_len = extract_divisor_expr(expr + right_start, right_expr, sizeof(right_expr));
            
            // 若提取失败或为空
            if (right_len == 0) {
                return true; // 后无内容 → 除零风险
            }
            
            // 使用现有框架测试
            char test_code[1024 + 128];
            snprintf(test_code, sizeof(test_code), code_format, right_expr);
            
            FILE *fp = fopen("/tmp/.div_test.c", "w");
            if (!fp) return true; // 返回true
            
            fputs(test_code, fp);
            fclose(fp);
            
            // 编译测试
            int ret = system("gcc /tmp/.div_test.c -o /tmp/.div_test 2>/dev/null");
            if (ret != 0) {
                return true; // 编译失败，返回true
            }
            
            // 运行测试
            fp = popen("/tmp/.div_test", "r");
            if (!fp) {
                system("rm -f /tmp/.div_test.c /tmp/.div_test");
                return true;
            }
            
            unsigned result = 0;
            if (fscanf(fp, "%u", &result) != 1) {
                result = 0; // 读取失败，假设为0
            }
            pclose(fp);
            

            if (result == 0) {
                return true; // 1/非0应该至少是1，如果为0说明有问题
            }
        }
    }
    
    return false;
}

// 在buf中添加字符
void gen(char a){
   if (pos < sizeof(buf)-1) {
            buf[pos]=a;
        }
   pos++;
}

// 将0-255的一个随机数转换成字符串,输入buf
void gen_num(){
   int num = choose(256);  // 0-255
    
    // 转换为字符串
    char num_str[16];
    sprintf(num_str, "%d", num);
    
    for (char *p = num_str; *p != '\0' && pos < sizeof(buf) - 1; p++) {
        buf[pos++] = *p;
    }
}

// 随机生成0-9个空格填入buf
void gen_rand_space(){
  for(int i=choose(10);i>0;i--)
    gen(' ');
}

// 随机生成运算符
void gen_rand_op(){
  switch(choose(4)){
  case 0:gen('*'); break;
  case 1:gen('+'); break;
  case 2:gen('/'); break;
  default:gen('-'); break;
  }

}

//  用于生成表达式
//  利用递归深度以及数组大小控制避免buf溢出情况 
void gen_rand_expr(int max_depth) {
  if (depth >= max_depth || pos > sizeof(buf) - 100) {
        gen_num();
        depth--;
        return;
    }
    
    depth++;
  switch (choose(3)) {
    case 0: gen_num(); gen_rand_space();break;
    case 1: gen('('); gen_rand_space();gen_rand_expr(20); gen_rand_space();gen(')');gen_rand_space(); break;
    default: gen_rand_expr(20); gen_rand_space();gen_rand_op(); gen_rand_space();gen_rand_expr(20);gen_rand_space(); break;
  }
}

// 全局变量清零
void reset_gen() {
    pos = 0;
    depth = 0;
   
    memset(buf, 0, sizeof(buf));
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;

  // 获得需要生成的表达式的数量
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }

  
  int i;
  for (i = 0; i < loop; i ++) {
    int attempts = 0;
    bool has_division_by_zero;
    
    do {
        // 进行表达式的生成
        reset_gen();
        gen_rand_expr(40);
        
        if (pos < sizeof(buf)) {
            buf[pos] = '\0';  
        }
        
        // 监测是否存在除0的情况
        has_division_by_zero = check_division_by_zero_simple(buf);
        attempts++;
        // 避免多次除0导致死循环
    } while (has_division_by_zero && attempts < 10);
    

    if (has_division_by_zero) {
        reset_gen();
        gen_num();
        buf[pos] = '\0';
    }

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
