#include <cctype>    // for isspace, isdigit
#include <climits>   // for INT_MAX, INT_MIN, LLONG_MAX
#include <cstdint>   // for uint32_t, uint8_t
#include <cstring>   // for strcmp, strlen
#include <cstdlib>   // not strictly needed, but safe
#include "all.h"
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void reg_display(void){
    for(int i = 0;i <31;i++)
        printf("%s:data:%u  0x%x\n",regs[i],top->debug_rf[i],top->debug_rf[i]);
}

static bool reg_name_equal(const char *input, const char *expected) {
    while (*input && *expected) {
        char c1 = (*input >= 'A' && *input <= 'Z') ? *input + 32 : *input;
        char c2 = (*expected >= 'A' && *expected <= 'Z') ? *expected + 32 : *expected;
        if (c1 != c2) return false;
        input++;
        expected++;
    }
    return *input == '\0' && *expected == '\0';
}


uint32_t reg_str2val(const char *name, bool *success) {
    if (!name || !success) {
        if (success) *success = false;
        return 0;
    }

    if (name[0] == 'x' || name[0] == 'X') {
        char *end;
        long idx = strtol(name + 1, &end, 10);
        if (*end == '\0' && idx >= 0 && idx < 32) {
            *success = true;
            if (idx == 0) return 0;
            return top->debug_rf[idx];
        }
    }

    for (int i = 0; i < 32; i++) {
        if (reg_name_equal(name, regs[i])) {
            *success = true;
            if (i == 0) return 0;
            return top->debug_rf[i];
        }
    }
    if (reg_name_equal(name, "pc")) {
        *success = true;
        return top->pc;
    }
    *success = false;
    return 0;
}