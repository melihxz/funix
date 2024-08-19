// funix/kernel/memory.c

#include "memory.h"
#include "types.h"

#define HEAP_START 0x200000
#define HEAP_SIZE  0x100000

static uint8_t *heap_start = (uint8_t *)HEAP_START;
static uint8_t *heap_end = (uint8_t *)(HEAP_START + HEAP_SIZE);

void init_memory() {
    // Heap alanını sıfırla
    for (uint8_t *ptr = heap_start; ptr < heap_end; ptr++) {
        *ptr = 0;
    }

    // Diğer bellek yönetimi yapılandırmaları
}

void *malloc(size_t size) {
    // Basit heap tahsisi
    static uint8_t *heap_ptr = heap_start;

    if (heap_ptr + size > heap_end) {
        // Bellek doldu
        return NULL;
    }

    void *ptr = heap_ptr;
    heap_ptr += size;
    return ptr;
}

void free(void *ptr) {
    // Basit heap serbest bırakma (gerçek bir implemantasyon eklenmeli)
}
