// process.c
#include "process.h"
#include "memory.h"

// Maksimum işlem sayısı
#define MAX_PROCESSES 10

// İşlem tablosu
static process_t process_table[MAX_PROCESSES];
static uint32_t process_count = 0;

// İşlem oluşturma işlevi
void create_process(void (*entry_point)()) {
    if (process_count >= MAX_PROCESSES) return;

    process_t *p = &process_table[process_count++];
    p->pid = process_count;
    p->state = PROCESS_READY;
    p->stack_size = 4096; // 4 KB
    p->stack = (uint32_t*)alloc(p->stack_size);

    // Basit bir işlem yığını başlatma (return address ve entry point ayarla)
    uint32_t *stack_top = p->stack + (p->stack_size / sizeof(uint32_t)) - 1;
    *stack_top-- = (uint32_t)entry_point;
    p->stack[0] = (uint32_t)stack_top;
}

// İşlem sonlandırma işlevi
void terminate_process(uint32_t pid) {
    for (uint32_t i = 0; i < process_count; ++i) {
        if (process_table[i].pid == pid) {
            free(process_table[i].stack);
            process_table[i].state = PROCESS_TERMINATED;
            return;
        }
    }
}

// İşlem zamanlayıcı işlevi (basit)
void schedule(void) {
    for (uint32_t i = 0; i < process_count; ++i) {
        if (process_table[i].state == PROCESS_READY) {
            process_table[i].state = PROCESS_RUNNING;
            // Basit zamanlayıcı (burada sadece bir işlem çalıştırılır)
            // Gerçek zamanlayıcı burada çalıştırılacak
            return;
        }
    }
}
