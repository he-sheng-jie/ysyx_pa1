#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 最大输出缓冲区大小（用于临时存储数字）
#define MAX_NUM_BUF 32

typedef struct {
  char *buf;          // 输出缓冲区（若 to_console == false）
  size_t count;       // 已输出字符数
  size_t max_size;    // 最大输出大小（0 表示无限制）
  bool to_console;    // true: 输出到 putch; false: 输出到 buf
} output_ctx_t;

static void out_char(output_ctx_t *ctx, char c) {
  // 检查是否达到最大大小限制
  if (ctx->max_size > 0 && ctx->count >= ctx->max_size - 1) {
    return; // 达到上限，不再输出
  }
  
  if (ctx->to_console) {
    putch(c);
  } else {
    if (ctx->buf) {
      ctx->buf[ctx->count] = c;
    }
  }
  ctx->count++;
}

// 将无符号整数按指定进制输出到 ctx
static void print_uint(output_ctx_t *ctx, uint64_t val, int base, bool uppercase) {
  char tmp[MAX_NUM_BUF];
  int i = 0;

  if (val == 0) {
    tmp[i++] = '0';
  } else {
    while (val) {
      int digit = val % base;
      tmp[i++] = (digit < 10) ? ('0' + digit) : (uppercase ? 'A' : 'a') + (digit - 10);
      val /= base;
    }
  }

  // 反向输出
  while (i > 0) {
    out_char(ctx, tmp[--i]);
  }
}

// 内部格式化函数（支持 va_list）
static int vprintf_internal(output_ctx_t *ctx, const char *fmt, va_list ap) {
  const char *f = fmt;

  while (*f) {
    if (*f != '%') {
      out_char(ctx, *f++);
      continue;
    }

    f++; // skip '%'

    if (*f == '\0') break; // 防止格式串以 % 结尾

    // 处理 %% 
    if (*f == '%') {
      out_char(ctx, '%');
      f++;
      continue;
    }

    // 解析长度修饰符
    bool is_long = false;
    bool is_longlong = false;
    
    if (*f == 'l') {
      is_long = true;
      f++;
      if (*f == 'l') {
        is_longlong = true;
        is_long = false; // ll 优先于 l
        f++;
      }
    }

    // 处理格式符
    if (*f == 'd' || *f == 'i') {
      int64_t val;
      if (is_longlong) {
        val = va_arg(ap, long long);
      } else if (is_long) {
        val = va_arg(ap, long);
      } else {
        val = va_arg(ap, int);
      }
      
      if (val < 0) {
        out_char(ctx, '-');
        // 安全处理 INT64_MIN
        uint64_t uval = (uint64_t)(-val); // 对于 INT64_MIN，-val 在 unsigned 中是定义良好的
        print_uint(ctx, uval, 10, false);
      } else {
        print_uint(ctx, (uint64_t)val, 10, false);
      }
    }
    else if (*f == 'u') {
      uint64_t val;
      if (is_longlong) {
        val = va_arg(ap, unsigned long long);
      } else if (is_long) {
        val = va_arg(ap, unsigned long);
      } else {
        val = va_arg(ap, unsigned int);
      }
      print_uint(ctx, val, 10, false);
    }
    else if (*f == 'x' || *f == 'X') {
      uint64_t val;
      if (is_longlong) {
        val = va_arg(ap, unsigned long long);
      } else if (is_long) {
        val = va_arg(ap, unsigned long);
      } else {
        val = va_arg(ap, unsigned int);
      }
      bool uppercase = (*f == 'X');
      print_uint(ctx, val, 16, uppercase);
    }
    else if (*f == 'p') {
      // 指针总是以 16 进制输出，带 0x 前缀
      uintptr_t val = va_arg(ap, uintptr_t);
      out_char(ctx, '0');
      out_char(ctx, 'x');
      print_uint(ctx, val, 16, false);
    }
    else if (*f == 'c') {
      int val = va_arg(ap, int);
      out_char(ctx, (char)val);
    }
    else if (*f == 's') {
      const char *s = va_arg(ap, const char*);
      if (s == NULL) s = "(null)";
      while (*s) {
        out_char(ctx, *s++);
      }
    }
    else {
      // 未知格式符：输出 % 和该字符
      out_char(ctx, '%');
      out_char(ctx, *f);
    }
    f++;
  }

  return (int)ctx->count;
}

// ==================== Public API ====================

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  output_ctx_t ctx = { .buf = NULL, .count = 0, .max_size = 0, .to_console = true };
  int ret = vprintf_internal(&ctx, fmt, ap);
  va_end(ap);
  return ret;
}

int sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  output_ctx_t ctx = { .buf = str, .count = 0, .max_size = 0, .to_console = false };
  int ret = vprintf_internal(&ctx, format, ap);
  // 添加终止符
  if (str) str[ctx.count] = '\0';
  va_end(ap);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  output_ctx_t ctx = { .buf = out, .count = 0, .max_size = 0, .to_console = false };
  int ret = vprintf_internal(&ctx, fmt, ap);
  if (out) out[ctx.count] = '\0';
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  if (n == 0) return 0;
  
  va_list ap;
  va_start(ap, fmt);
  output_ctx_t ctx = { .buf = out, .count = 0, .max_size = n, .to_console = false };
  int ret = vprintf_internal(&ctx, fmt, ap);
  // 添加终止符（确保不越界）
  if (out) {
    size_t term_pos = (ctx.count < n) ? ctx.count : n - 1;
    out[term_pos] = '\0';
  }
  va_end(ap);
  return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  if (n == 0) return 0;
  
  output_ctx_t ctx = { .buf = out, .count = 0, .max_size = n, .to_console = false };
  int ret = vprintf_internal(&ctx, fmt, ap);
  // 添加终止符（确保不越界）
  if (out) {
    size_t term_pos = (ctx.count < n) ? ctx.count : n - 1;
    out[term_pos] = '\0';
  }
  return ret;
}

#endif