// include/stdio.h

#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>

#define EOF (-1)

// Temel giriş-çıkış işlevleri
int printf(const char *format, ...);
int sprintf(char *str, const char *format, ...);
int vsprintf(char *str, const char *format, va_list ap);
int putchar(int c);
int getchar(void);

#endif // STDIO_H
