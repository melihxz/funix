// fs/file.c

#include "file.h"
#include "vfs.h"

// Dosya açma
int file_open(const char *path, int flags) {
    kprintf("Opening file: %s\n", path);
    // Dosya açma işlemleri, inode tablosundan dosyanın bulunması
    return 0; // Dosya betimleyici döndür
}

// Dosya kapatma
int file_close(int fd) {
    kprintf("Closing file descriptor: %d\n", fd);
    // Dosya betimleyici serbest bırakma
    return 0; // Başarılı
}

// Dosya okuma
int file_read(int fd, void *buf, uint32_t count) {
    kprintf("Reading %d bytes from file descriptor: %d\n", count, fd);
    // Okuma işlemi
    return count; // Okunan byte sayısını döndür
}

// Dosya yazma
int file_write(int fd, const void *buf, uint32_t count) {
    kprintf("Writing %d bytes to file descriptor: %d\n", count, fd);
    // Yazma işlemi
    return count; // Yazılan byte sayısını döndür
}

// Dosya arama (seek)
int file_seek(int fd, int offset, int whence) {
    kprintf("Seeking in file descriptor: %d to offset %d\n", fd, offset);
    // Seek işlemi
    return 0; // Yeni pozisyon döndür
}
