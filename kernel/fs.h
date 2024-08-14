// fs.h
#ifndef FS_H
#define FS_H

#include <stdint.h>

// Basit bir dosya yapısı
typedef struct {
    char name[32];
    uint32_t size;
    uint32_t start_block;
} file_t;

// Basit bir dosya sistemi yapısı
typedef struct {
    file_t files[64];
    uint32_t file_count;
} filesystem_t;

// Dosya sistemi fonksiyon prototipleri
void init_filesystem(void);
int32_t read_file(const char *filename, void *buffer, uint32_t size);
int32_t write_file(const char *filename, const void *data, uint32_t size);

#endif // FS_H
