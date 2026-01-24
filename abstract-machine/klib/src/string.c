#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>
#include <stddef.h> 

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  if (s == NULL) return 0; 

  const char *p = s;
  while (*p != '\0') {
    p++;
  }
  return (size_t)(p - s);
}

char *strcpy(char *dst, const char *src) { 
  char *tmp = dst;
  while(*src != '\0'){
    *tmp = *src;
    tmp++;
    src++;
  }
  *tmp = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *tmp = dst;
  size_t i = 0;
  while(i < n){
    if(*src != '\0'){
      *tmp = *src;
      src++;
    } else {
      *tmp = '\0';
    }
    tmp++;
    i++;
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *tmp = dst;
  while(*tmp != '\0'){
    tmp++;
  }
  while(*src != '\0'){
    *tmp = *src;
    tmp++;
    src++;
  }
  *tmp = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  while(*s1 == *s2){
    if (*s1 == '\0') return 0;
    s1++;
    s2++;
  } 
  return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i = 0;
  for(i = 0;i < n;i++){
    if(*s1 != *s2 || *s1 == '\0')
      return (*(unsigned char *)s1 - *(unsigned char *)s2);
    s1++;
    s2++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  char *tmp = s;
  size_t i = 0;
  while(i < n){
    *tmp = (unsigned char) c;
    tmp++;
    i++;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  if (n == 0) return dst;

  size_t i = 0;
  unsigned char *begin1 = (unsigned char *)dst;
  unsigned char *begin2 = (unsigned char *)src;
  unsigned char *end1 = begin1 + n - 1;
  unsigned char *end2 = begin2 + n - 1;
  if(begin1 <= begin2){
    while(i < n){
      *begin1 = *begin2;
      begin1++;
      begin2++;
      i++;
    }
  } else {
    while(i < n){
      *end1 = *end2;
      end1--;
      end2--;
      i++;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  if (n == 0) return out;

  size_t i = 0;
  unsigned char *begin1 = (unsigned char *)out;
  unsigned char *begin2 = (unsigned char *)in;

  while(i < n){
    *begin1 = *begin2;
    begin1++;
    begin2++;
    i++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  size_t i = 0;
  unsigned char *tmp1 = (unsigned char *)s1;
  unsigned char *tmp2 = (unsigned char *)s2;

  while(i < n){
    if(*tmp1 != *tmp2)
        return *tmp1 - *tmp2;
    tmp1++;
    tmp2++;
    i++;
  }
  return 0;
}

#endif
