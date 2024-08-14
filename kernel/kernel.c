// kernel.c
#include "kernel.h"
#include "memory.h"
#include "process.h"
#include "syscall.h"
#include "fs.h"

// Ekran belleğine erişim
static char *video_memory = (char *)VIDEO_MEMORY_ADDRESS;
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

// Ekrana karakter yazdırma işlevi
void print_char(char c, int x, int y) {
    if (x >= VGA_WIDTH || y >= VGA_HEIGHT) return;
    video_memory[(y * VGA_WIDTH + x) * 2] = c; // Karakter
    video_memory[(y * VGA_WIDTH + x) * 2 + 1] = WHITE; // Renk
}

// Ekrana string yazdırma işlevi
void print_string(const char *str, int x, int y) {
    while (*str) {
        print_char(*str++, x++, y);
    }
}

// Kernel başlangıç işlevi
void kmain(void) {
    // Bellek, işlem, sistem çağrıları ve dosya sistemini başlat
    init_memory();
    init_processes();
    init_syscalls();
    init_filesystem();

    // Ekrana mesaj yazdır
    print_string("Hello, Kernel World!", 0, 0);

    // Dosya sistemi ile etkileşim (örnek)
    char buffer[128];
    read_file("example.txt", buffer, sizeof(buffer));
    print_string(buffer, 0, 1);

    const char *new_data = "New file content!";
    write_file("example.txt", new_data, strlen(new_data));
}
