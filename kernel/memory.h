// funix/kernel/memory.h

#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

void init_memory();
void *malloc(size_t size);
void free(void *ptr);

#endif
