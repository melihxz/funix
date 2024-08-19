// funix/kernel/process.c

#include "process.h"
#include "memory.h"
#include "types.h"

// Süreç yapısı
typedef struct {
    uint32_t *stack_pointer;
    uint32_t program_counter;
    // Diğer süreç bilgileri
} process_t;

static process_t *current_process;

void init_processes() {
    // İlk süreç ve diğer süreçler için yapılandırmaları yap
    current_process = (process_t *)0x200000; // Örnek adres

    // Bellek tahsisi ve ilk süreç başlatma
    current_process->stack_pointer = (uint32_t *)0x200000;
    current_process->program_counter = (uint32_t)0x100000; // Örnek kod adresi
}

void switch_context(process_t *new_process) {
    // Eski süreç bağlamını sakla
    asm volatile("mov %%esp, %0" : "=r"(current_process->stack_pointer));

    // Yeni süreç bağlamını yükle
    current_process = new_process;
    asm volatile("mov %0, %%esp" : : "r"(current_process->stack_pointer));
}
