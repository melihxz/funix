// fs.c
#include "fs.h"
#include <string.h>

// Sabit dosya sistemi
static filesystem_t fs;

// Basit dosya sistemi başlatma
void init_filesystem(void) {
    // Dosya sistemini sıfırla
    memset(&fs, 0, sizeof(fs));

    // Örnek dosyalar ekle
    strcpy(fs.files[0].name, "example.txt");
    fs.files[0].size = 13;
    fs.files[0].start_block = 0;

    // Dosya sayısını güncelle
    fs.file_count = 1;
}

// Dosya okuma işlevi
int32_t read_file(const char *filename, void *buffer, uint32_t size) {
    for (uint32_t i = 0; i < fs.file_count; ++i) {
        if (strcmp(fs.files[i].name, filename) == 0) {
            // Dosya bulundu, içeriği kopyala
            if (size < fs.files[i].size) {
                return -1; // Yetersiz bellek
            }
            // Örnek veri
            const char *example_data = "Hello, World!";
            memcpy(buffer, example_data, fs.files[i].size);
            return fs.files[i].size;
        }
    }
    return -1; // Dosya bulunamadı
}

// Dosya yazma işlevi
int32_t write_file(const char *filename, const void *data, uint32_t size) {
    for (uint32_t i = 0; i < fs.file_count; ++i) {
        if (strcmp(fs.files[i].name, filename) == 0) {
            // Dosya bulundu, içeriği yaz
            // Örnek veri yazma işlemi
            if (size > sizeof("Hello, World!") - 1) {
                return -1; // Aşırı veri
            }
            // Dosya verisini güncelle
            // Burada gerçek bir veri yazma işlemi yapılırdı
            return size;
        }
    }
    return -1; // Dosya bulunamadı
}
