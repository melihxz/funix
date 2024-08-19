// funix/kernel/paging.h

#ifndef PAGING_H
#define PAGING_H

#include "types.h"

void init_paging();

// Sayfa tablosu ve dizini için veri yapıları
typedef struct {
    uint32_t entries[1024];
} page_table_t;

typedef struct {
    uint32_t entries[1024];
} page_directory_t;

#endif
