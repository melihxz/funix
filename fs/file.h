// fs/file.h

#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include "inode.h"

// Dosya işlemleri için fonksiyon prototipleri
int file_open(const char *path, int flags);
int file_close(int fd);
int file_read(int fd, void *buf, uint32_t count);
int file_write(int fd, const void *buf, uint32_t count);
int file_seek(int fd, int offset, int whence);

#endif // FILE_H
