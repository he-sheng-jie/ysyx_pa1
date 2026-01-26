
#include <cctype>    // for isspace, isdigit
#include <climits>   // for INT_MAX, INT_MIN, LLONG_MAX
#include <cstdint>   // for uint32_t, uint8_t
#include <cstring>   // for strcmp, strlen
#include <cstdlib>   // not strictly needed, but safe
#include "all.h"
#include "sdb.h"
#include "difftest.h"
#include "reg.h"
void test_for_watchpoint_and_diff(void){
#if DIFF_TEST
    difftest_step();
#endif

#if WATCHPOINT_TEST
    if(watchpoint_change_test()){
            printf("触发监视点\n");
            watchpoint_display();
            break;
        }
#endif  

}
void cpu_exec(uint32_t n){

  for(int i = 0; i < n && is_break && diff_check; i++){
    //进行一次上升沿的模拟
    top->inst = mem_read(top->pc);
    top->clk = 0; top->eval();
    top->clk = 1; top->eval();
    test_for_watchpoint_and_diff();
  }
}

int string_to_int(const char *str, int *result) {
    if (str == nullptr || result == nullptr) {
        return -1;
    }

    while (std::isspace(static_cast<unsigned char>(*str))) {
        ++str;
    }

    int sign = 1;
    if (*str == '+') {
        ++str;
    } else if (*str == '-') {
        sign = -1;
        ++str;
    }

    if (*str == '\0') {
        return -1;
    }

    long long value = 0;
    while (*str != '\0') {
        if (!std::isdigit(static_cast<unsigned char>(*str))) {
            return -1;
        }

        int digit = *str - '0';

        if (value > (LLONG_MAX - digit) / 10) {
            return -2;
        }

        value = value * 10 + digit;
        ++str;
    }

    value *= sign;

    if (value > INT_MAX || value < INT_MIN) {
        return -2;
    }

    *result = static_cast<int>(value);
    return 0;
}

// Parse hexadecimal string (with or without 0x prefix)
bool parse_hex_arg(char *args, uint32_t *result) {
    if (args == nullptr || result == nullptr) {
        return false;
    }

    char *p = args;
    while (std::isspace(static_cast<unsigned char>(*p))) {
        ++p;
    }

    if (*p == '\0') {
        return false;
    }

    if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
        p += 2;
    }

    if (*p == '\0') {
        return false;
    }

    uint32_t value = 0;
    bool has_valid_digit = false;

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
            break; // stop at first non-hex char (e.g., space, '+')
        }

        if (value > (0xFFFFFFFFU >> 4)) {
            return false; // overflow in 32-bit
        }

        value = (value << 4) | digit;
        has_valid_digit = true;
        ++p;
    }

    if (!has_valid_digit) {
        return false;
    }

    *result = value;
    return true;
}



static int cmd_c(char *args) {
    cpu_exec(-1);
    return 0;
}

static int cmd_q(char *args) {
    return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args) {
    int n = 0;
    if (string_to_int(args, &n) == 0) {
        cpu_exec(n);
    }
    return 0;
}

static int cmd_info(char *args) {
    if (std::strcmp(args, "r") == 0) {
        reg_display();
    }
    if (std::strcmp(args, "w") == 0) {
        watchpoint_display();
    }
    return 0;
}

static int cmd_p(char *args) {
    bool success = false;
    uint32_t result = expr(args, &success);
    if (success) {
        printf("%u   0x%x\n", result, result);
    } else {
        printf("error\n");
    }
    return 0;
}

static int cmd_w(char *args) {
    watchpoint_add(args);
    return 0;
}

static int cmd_d(char *args) {
    int no = 0;
    if (string_to_int(args, &no) == 0) {
        watchpoint_delete(no);
    }
    return 0;
}

static int cmd_x(char *tmp) {
    if (tmp == nullptr) return 0;

    // Make a copy because strtok modifies the string
    char *str = strdup(tmp);
    if (str == nullptr) return 0;

    char *cmd = std::strtok(str, " ");
    char *args = (cmd != nullptr) ? cmd + std::strlen(cmd) + 1 : nullptr;

    int n = 0;
    uint32_t paddr = 0;
    bool valid = false;

    if (cmd && args &&
        string_to_int(cmd, &n) == 0 &&
        parse_hex_arg(args, &paddr)) {
        for (int i = 0; i < n; ++i) {
            printf("addr:0x%08x data:0x%08x\n",
                   paddr + 4 * i,
                   mem_read(paddr + 4 * i));
        }
        valid = true;
    }

    free(str);
    return 0;
}


static struct {
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    { "help", "Display information about all supported commands", cmd_help },
    { "c", "Continue the execution of the program", cmd_c },
    { "q", "Exit NEMU", cmd_q },
    { "si", "-[N] Execute N instructions in single step", cmd_si },
    { "info", "-r/-w Print various debugging information", cmd_info },
    { "x", "/NFU ADDR Examine memory", cmd_x },
    { "p", "进行一个表达式的求解，支持多形式", cmd_p },
    { "w", "设置一个表达式的监测点", cmd_w },
    { "d", "删除一个表达式的监测点", cmd_d },
};

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

static int cmd_help(char *args) {
    char *arg = std::strtok(nullptr, " ");
    if (arg == nullptr) {
        for (size_t i = 0; i < NR_CMD; ++i) {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    } else {
        for (size_t i = 0; i < NR_CMD; ++i) {
            if (std::strcmp(arg, cmd_table[i].name) == 0) {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

void sdb_loop(void) {
    char input[1024];
    while (true) {
        printf("(npc) ");
        if (!fgets(input, sizeof(input), stdin)) {
            // 遇到 EOF（如 Ctrl+D）或错误，退出调试器
            printf("\n");
            return;
        }

        // 去除末尾换行符
        size_t len = std::strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // 跳过空行
        if (input[0] == '\0') {
            continue;
        }

        // 复制输入用于 strtok（因为 strtok 会修改字符串）
        // 注意：我们直接在 input 上操作，因为已读入缓冲区
        char *str = input;
        char *str_end = str + std::strlen(str);

        char *cmd = std::strtok(str, " ");
        if (cmd == nullptr) {
            continue;
        }

        char *args = cmd + std::strlen(cmd) + 1;
        if (args >= str_end) {
            args = nullptr;
        }

        size_t i;
        for (i = 0; i < NR_CMD; ++i) {
            if (std::strcmp(cmd, cmd_table[i].name) == 0) {
                if (cmd_table[i].handler(args) < 0) {
                    // 命令要求退出（如 'q'）
                    return;
                }
                break;
            }
        }

        if (i == NR_CMD) {
            printf("Unknown command '%s'\n", cmd);
        }
    }
}



void sdb_init(void){
    init_regex();
    init_wp_pool();
#if DIFF_TEST
  init_difftest("/home/he/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so", MEM_SIZE, 0);
#endif
}