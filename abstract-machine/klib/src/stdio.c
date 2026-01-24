#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

typedef struct {
  char *buf;          // 输出缓冲区（若 to_console == false）
  int count;          // 已输出字符数
  bool to_console;    // true: 输出到 putch; false: 输出到 buf
} output_ctx_t;

static void out_char(output_ctx_t *ctx, char c) {
  if (ctx->to_console) {
    putch(c);
  } else {
    if (ctx->buf) {
      ctx->buf[ctx->count] = c;
    }
    ctx->count++;
  }
}

// 将无符号整数按指定进制输出到 ctx
static void print_uint(output_ctx_t *ctx, unsigned int val, int base, bool uppercase) {
  char tmp[32];
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

    if (*f == '%') {
      out_char(ctx, '%');
      f++;
      continue;
    }

    // 处理格式符
    if (*f == 'd' || *f == 'i') {
      int val = va_arg(ap, int);
      if (val < 0) {
        out_char(ctx, '-');
        // 安全计算绝对值：利用无符号算术
        unsigned int uval = (unsigned int)(-(unsigned int)val); // 注意：这里依赖无符号回绕
        // 更严谨的方式（避免对 int 取负）：
        // unsigned int uval = (val == INT_MIN) ? (unsigned int)INT_MIN : (unsigned int)(-val);
        // 但我们用通用技巧：
        if (val != 0) {
          uval = 0U - (unsigned int)val; // 定义良好的无符号减法
        } else {
          uval = 0;
        }
        print_uint(ctx, uval, 10, false);
      } else {
        print_uint(ctx, (unsigned int)val, 10, false);
      }
    }
    else if (*f == 'u') {
      unsigned int val = va_arg(ap, unsigned int);
      print_uint(ctx, val, 10, false);
    }
    else if (*f == 'x') {
      unsigned int val = va_arg(ap, unsigned int);
      print_uint(ctx, val, 16, false);
    }
    else if (*f == 'X') {
      unsigned int val = va_arg(ap, unsigned int);
      print_uint(ctx, val, 16, true);
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

  return ctx->count;
}

// ==================== Public API ====================

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  output_ctx_t ctx = { .buf = NULL, .count = 0, .to_console = true };
  int ret = vprintf_internal(&ctx, fmt, ap);
  va_end(ap);
  return ret;
}

int sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  output_ctx_t ctx = { .buf = str, .count = 0, .to_console = false };
  int ret = vprintf_internal(&ctx, format, ap);
  // 添加终止符
  if (str) str[ctx.count] = '\0';
  va_end(ap);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  output_ctx_t ctx = { .buf = out, .count = 0, .to_console = false };
  int ret = vprintf_internal(&ctx, fmt, ap);
  if (out) out[ctx.count] = '\0';
  return ret;
}

// 暂未实现带长度限制的版本
int snprintf(char *out, size_t n, const char *fmt, ...) {
  // TODO: 实现时需在 out_char 中检查 count < n-1
  panic("snprintf not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("vsnprintf not implemented");
}

#endif