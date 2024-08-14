// memory.h
#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

// Bellek yönetim işlevleri
void init_memory(void);
void* alloc(uint32_t size);
void free(void* ptr);
void* memset(void* ptr, int value, uint32_t num);

#endif // MEMORY_H
