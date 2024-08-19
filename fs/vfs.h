// fs/vfs.h

#ifndef VFS_H
#define VFS_H

#include <stdint.h>
#include "inode.h"

// Virtual File System (VFS) için fonksiyon tanımları
int vfs_mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags);
int vfs_umount(const char *target);
int vfs_format(const char *device, const char *filesystemtype);
int vfs_statfs(const char *path, struct statfs *buf);

#endif // VFS_H
