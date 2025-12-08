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
static int has_division = 0; // 是否有除法运算符


static inline int choose(int n) {
    return rand() % n;
}

// 即插即用函数：检查表达式是否有除0风险
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
            
            // 跳过空格
            while (j < len && expr[j] == ' ') j++;
            
            if (j >= len) {
                return true; // 除号在末尾
            }
            
            // 检查右边是否是简单的0
            if (expr[j] == '0') {
                // 检查是否是十六进制的一部分
                if (j + 1 < len && (expr[j+1] == 'x' || expr[j+1] == 'X')) {
                    // 可能是0x...，需要进一步检查
                } else {
                    // 检查0后面是否只有空格或运算符
                    int k = j + 1;
                    while (k < len && expr[k] == ' ') k++;
                    if (k == len || 
                        expr[k] == '+' || expr[k] == '-' || expr[k] == '*' || 
                        expr[k] == '/' || expr[k] == ')' || expr[k] == '\0') {
                        return true; // 除以0
                    }
                }
            }
            
            // 对于复杂情况，我们简单生成一个新表达式来测试
            // 创建一个测试表达式：1 / (右表达式)，如果结果为0则右表达式为0
            int right_start = j;
            int right_len = len - right_start;
            if (right_len > 100) right_len = 100; // 限制长度
            
            char right_expr[128];
            strncpy(right_expr, expr + right_start, right_len);
            right_expr[right_len] = '\0';
            
            // 去除首尾空格
            while (right_len > 0 && isspace(right_expr[0])) {
                memmove(right_expr, right_expr + 1, right_len);
                right_len--;
            }
            while (right_len > 0 && isspace(right_expr[right_len-1])) {
                right_expr[--right_len] = '\0';
            }
            
            // 如果右表达式为空或只是空格
            if (right_len == 0) {
                return true;
            }
            
            // 创建测试表达式
            char test_expr[256];
            snprintf(test_expr, sizeof(test_expr), "1/(%s)", right_expr);
            
            // 使用现有框架测试
            char test_code[512];
            snprintf(test_code, sizeof(test_code), code_format, test_expr);
            
            FILE *fp = fopen("/tmp/.div_test.c", "w");
            if (!fp) return true; // 保守返回true
            
            fputs(test_code, fp);
            fclose(fp);
            
            // 编译测试
            int ret = system("gcc /tmp/.div_test.c -o /tmp/.div_test 2>/dev/null");
            if (ret != 0) {
                //system("rm -f /tmp/.div_test.c");
                return true; // 编译失败，保守返回true
            }
            
            // 运行测试
            fp = popen("/tmp/.div_test", "r");
            if (!fp) {
                //system("rm -f /tmp/.div_test.c /tmp/.div_test");
                return true;
            }
            
            unsigned result = 0;
            if (fscanf(fp, "%u", &result) != 1) {
                result = 0; // 读取失败，假设为0
            }
            pclose(fp);
            
            // 清理
            //system("rm -f /tmp/.div_test.c /tmp/.div_test");
            
            // 如果1/(右表达式)为0，说明右表达式为0（除0错误）
            // 实际上，如果右表达式为0，在C语言中会是运行时错误，程序会崩溃
            // 但这里我们捕获了编译和运行，如果运行成功且结果为0，说明右表达式为无穷大？不合理
            // 实际上，如果右表达式为0，程序会崩溃，我们不会得到结果
            
            // 更简单的逻辑：如果测试程序能运行成功，且结果不是无穷大，就认为没问题
            // 如果除0，程序会崩溃或被除0信号终止，不会正常输出结果
            // 所以如果fscanf成功读取，说明没有除0
            // 但为了安全，如果结果为0，我们也认为有问题
            if (result == 0) {
                return true; // 1/非0应该至少是1，如果为0说明有问题
            }
        }
    }
    
    return false;
}

void gen(char a){
   if (pos < sizeof(buf)-1) {
            buf[pos]=a;
        }
   pos++;
}

void gen_num(){
   int num = choose(256);  // 0-255
    
    // 转换为字符串
    char num_str[16];
    sprintf(num_str, "%d", num);
    
    for (char *p = num_str; *p != '\0' && pos < sizeof(buf) - 1; p++) {
        buf[pos++] = *p;
    }
}

void gen_rand_space(){
  for(int i=choose(10);i>0;i--)
    gen(' ');
}
void gen_rand_op(){
  switch(choose(4)){
  case 0:gen('*'); break;
  case 1:gen('+'); break;
  case 2:gen('/'); break;
  default:gen('-'); break;
  }

}
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

void reset_gen() {
    pos = 0;
    depth = 0;
    has_division = 0;
   
    memset(buf, 0, sizeof(buf));
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    int attempts = 0;
    bool has_division_by_zero;
    
    do {
        reset_gen();
        gen_rand_expr(40);
        
        if (pos < sizeof(buf)) {
            buf[pos] = '\0';  
        }
        
        // 使用即插即用函数检查
        has_division_by_zero = check_division_by_zero_simple(buf);
        attempts++;
        
    } while (has_division_by_zero && attempts < 10);
    
    // 如果多次尝试都失败，生成简单表达式
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
    //system("rm -f /tmp/.code.c /tmp/.expr");
  }
  return 0;
}
