// process.h
#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

// İşlem durumları
typedef enum {
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_BLOCKED,
    PROCESS_TERMINATED
} process_state_t;

// İşlem yapısı
typedef struct {
    uint32_t pid;
    process_state_t state;
    uint32_t *stack;
    uint32_t stack_size;
} process_t;

// İşlem yönetim işlevleri
void init_processes(void);
void create_process(void (*entry_point)());
void terminate_process(uint32_t pid);
void schedule(void);

#endif // PROCESS_H
