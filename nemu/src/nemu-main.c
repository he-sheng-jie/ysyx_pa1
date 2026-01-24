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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// 表达式求值函数
extern word_t expr(char *e, bool *success);
void run_expr_tests(void) {


    // open the expr file
    FILE *test_fp = fopen("/home/he/ysyx-workbench/nemu/tools/gen-expr/input", "r");
    if (test_fp == NULL) {
        printf("Error: Cannot open test file\n");
        return;
    }
    printf("File opened successfully.\n");
    

    // 打开输出文件
    FILE *demo_fp = fopen("/home/he/ysyx-workbench/nemu/tools/gen-expr/demo.txt", "w");
    FILE *result_fp = fopen("/home/he/ysyx-workbench/nemu/tools/gen-expr/result.txt", "w");
    
    if (demo_fp == NULL || result_fp == NULL) {
        printf("Error: Cannot create output files\n");
        fclose(test_fp);
        if (demo_fp) fclose(demo_fp);
        if (result_fp) fclose(result_fp);
        return;
    }


    
    char line[65536];  // 缓冲区，处理长表达式
    int line_count = 0; 
    
    // 循环读取最多9999行
    while (line_count < 9999 && fgets(line, sizeof(line), test_fp) != NULL) {
        line_count++;
        
        // 移除换行符
        line[strcspn(line, "\n")] = '\0';
        
        // 跳过空行
        if (strlen(line) == 0) {
            continue;
        }
        
        printf("\n=== Processing line %d ===\n", line_count);
        printf("Original line: %s\n", line);
        
        // 找到第一个数字的结束位置（第一个空格或制表符）
        char *number_end = line;
        while (*number_end != '\0' && *number_end != ' ' && *number_end != '\t') {
            number_end++;
        }
        
        if (*number_end == '\0') {
            printf("Error: No space found after number in line %d\n", line_count);
            continue;
        }
        
        // 临时保存数字结束位置
        char temp_char = *number_end;  // 保存空格字符
        *number_end = '\0';  // 临时截断，便于转换数字
        
        // 转换数字部分
        char *endptr;
        uint32_t parsed_result = strtol(line, &endptr, 0);
        if (endptr == line) {
            printf("Error: Invalid number format in line %d\n", line_count);
            // 恢复原始字符
            *number_end = temp_char;
            continue;
        }
        
        // 恢复原始字符
        *number_end = temp_char;
        
        // 表达式部分从number_end开始
        char *expression = number_end;
        
        // 跳过多余的空格/制表符
        while (*expression == ' ' || *expression == '\t') {
            expression++;
        }
        
        printf("Parsed result: %lu\n", (unsigned long)parsed_result);
        printf("Parsed expression: %s\n", expression);
        
        // 将 parsed_result 写入 demo 文件
        fprintf(demo_fp, "%lu\n", (unsigned long)parsed_result);
        
        // 测试expr函数
        bool success = false;
        char expr_copy[65536];
        strncpy(expr_copy, expression, sizeof(expr_copy) - 1);
        expr_copy[sizeof(expr_copy) - 1] = '\0';
        
        word_t my_expr_result = expr(expr_copy, &success);
        
        if (!success) {
            printf("Error: expr() failed for expression: %s\n", expression);
            // 在result文件中写入错误标记
            fprintf(result_fp, "ERROR\n");
        } else {
            printf("my_expr_result: %lu\n", (unsigned long)my_expr_result);
            // 将 my_expr_result 写入 result 文件
            fprintf(result_fp, "%lu\n", (unsigned long)my_expr_result);
        }
        
        // 每处理100行输出一次进度
        if (line_count % 100 == 0) {
            printf("Processed %d lines...\n", line_count);
        }
    }
    
    printf("\n=== Processing completed ===\n");
    printf("Total lines processed: %d\n", line_count);
    
    // 关闭所有文件
    fclose(test_fp);
    fclose(demo_fp);
    fclose(result_fp);
    
    printf("Results written to:\n");
    printf("  - /home/he/ysyx-workbench/nemu/tools/gen-expr/demo.txt\n");
    printf("  - /home/he/ysyx-workbench/nemu/tools/gen-expr/result.txt\n");
}

int main(int argc, char *argv[]) {

  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
  
    // int run_tests = 1;
    
    // // 如果启用了测试模式，运行测试然后退出
    // if (run_tests) {
    //     run_expr_tests();
    //     return 0;  // 测试模式直接退出，不启动NEMU
    // }
  
  engine_start();
  return is_exit_status_bad();
}
