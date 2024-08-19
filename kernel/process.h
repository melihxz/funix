// funix/kernel/process.h

#ifndef PROCESS_H
#define PROCESS_H

#include "ctype.h"

// Süreç yapısı
typedef struct {
    uint32_t *stack_pointer;
    uint32_t program_counter;
    // Diğer süreç bilgileri
} process_t;

void init_processes();
void switch_context(process_t *new_process);

#endif
