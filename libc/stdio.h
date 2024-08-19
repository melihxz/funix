// libc/stdio.h

#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>
#include <stddef.h>

// Standart giriş/çıkış işlemleri
int printf(const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);
int vsnprintf(char *str, size_t size, const char *format, va_list ap);

#endif // STDIO_H
