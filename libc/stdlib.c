// libc/stdlib.c

#include "stdlib.h"
#include "errno.h"

// Basit malloc uygulaması (Heap yönetimi varsayılır)
void *malloc(size_t size) {
    void *ptr = allocate_memory(size); // Hypothetical memory allocator
    if (!ptr) {
        errno = ENOMEM;
    }
    return ptr;
}

void free(void *ptr) {
    deallocate_memory(ptr); // Hypothetical memory deallocator
}

void *calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    void *ptr = malloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

void *realloc(void *ptr, size_t size) {
    void *new_ptr = malloc(size);
    if (new_ptr && ptr) {
        memcpy(new_ptr, ptr, size);  // Hypothetical memory copy function
        free(ptr);
    }
    return new_ptr;
}

// String to integer dönüşümleri
int atoi(const char *str) {
    int num = 0;
    while (*str) {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

long atol(const char *str) {
    long num = 0;
    while (*str) {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

char *itoa(int value, char *str, int base) {
    char *ptr = str;
    int temp;
    do {
        temp = value % base;
        value /= base;
        *ptr++ = (temp < 10) ? temp + '0' : temp + 'A' - 10;
    } while (value);
    *ptr = '\0';
    return str;
}

// Program sonlandırma
void exit(int status) {
    _exit(status);  // Hypothetical low-level exit function
}
