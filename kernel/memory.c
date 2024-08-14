// memory.c
#include "memory.h"

// Basit bir bellek yönetimi için başlangıç adresi ve boyut
#define MEMORY_SIZE 0x100000 // 1 MB
static uint8_t memory[MEMORY_SIZE];
static uint32_t memory_index = 0;

// Bellek başlangıç işlevi
void init_memory(void) {
    // Belleği sıfırla
    memset(memory, 0, MEMORY_SIZE);
    memory_index = 0;
}

// Bellek tahsis işlevi
void* alloc(uint32_t size) {
    if (memory_index + size > MEMORY_SIZE) {
        // Bellek yetersiz
        return NULL;
    }

    void* ptr = &memory[memory_index];
    memory_index += size;
    return ptr;
}

// Bellek serbest bırakma işlevi (bu basit sürümde işlevselliği yok)
void free(void* ptr) {
    // Basit sürümde bellek serbest bırakma işlevi yok
}

// Bellek sıfırlama işlevi
void* memset(void* ptr, int value, uint32_t num) {
    uint8_t* p = (uint8_t*)ptr;
    for (uint32_t i = 0; i < num; ++i) {
        p[i] = (uint8_t)value;
    }
    return ptr;
}
