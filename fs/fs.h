// fs/fs.h

#ifndef FS_H
#define FS_H

#include <stdint.h>
#include "file.h"
#include "inode.h"
#include "vfs.h"

// Temel dosya sistemi işlevlerinin tanımları
int fs_mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags);
int fs_umount(const char *target);
int fs_format(const char *device, const char *filesystemtype);
int fs_statfs(const char *path, struct statfs *buf);

#endif // FS_H
