// libc/string.h

#ifndef STRING_H
#define STRING_H

#include <stddef.h>

// String kopyalama
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// String birleştirme
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

// String uzunluğu
size_t strlen(const char *s);

// String karşılaştırma
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

// String arama
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);

// String ayırma
char *strtok(char *str, const char *delim);

#endif // STRING_H
