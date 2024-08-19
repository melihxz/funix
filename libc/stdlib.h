// libc/stdlib.h

#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>

// Bellek yönetimi işlevleri
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t size);

// Genel yardımcı işlevler
int atoi(const char *str);
long atol(const char *str);
char *itoa(int value, char *str, int base);

// Program sonlandırma
void exit(int status);

#endif // STDLIB_H
