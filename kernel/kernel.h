// kernel.h
#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

// Ekran renkleri
#define WHITE 0x07

// Ekran belleği başlangıç adresi
#define VIDEO_MEMORY_ADDRESS 0xb8000

// Ekran yazdırma işlevleri
void kmain(void);
void print_char(char c, int x, int y);
void print_string(const char *str, int x, int y);

// Bellek yönetimi işlevleri
void init_memory(void);

// İşlem yönetimi işlevleri
void init_processes(void);

// Sistem çağrıları işlevleri
void init_syscalls(void);

// Dosya sistemi işlevleri
void init_filesystem(void);
void read_file(const char *filename);
void write_file(const char *filename, const char *data);

#endif // KERNEL_H
