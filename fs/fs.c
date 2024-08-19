// fs/fs.c

#include "fs.h"
#include "vfs.h"
#include "file.h"
#include "inode.h"
#include "screen.h"

// Dosya sistemi montajı
int fs_mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags) {
    kprintf("Mounting filesystem: %s on %s with type %s\n", source, target, filesystemtype);
    // VFS çağrısı
    return vfs_mount(source, target, filesystemtype, mountflags);
}

// Dosya sistemi montajını kaldırma
int fs_umount(const char *target) {
    kprintf("Unmounting filesystem from: %s\n", target);
    // VFS çağrısı
    return vfs_umount(target);
}

// Dosya sistemi formatlama
int fs_format(const char *device, const char *filesystemtype) {
    kprintf("Formatting device: %s with filesystem type: %s\n", device, filesystemtype);
    // Dosya sistemi formatlama işlemi
    return vfs_format(device, filesystemtype);
}

// Dosya sistemi bilgilerini elde etme
int fs_statfs(const char *path, struct statfs *buf) {
    kprintf("Getting filesystem stats for: %s\n", path);
    // Statfs çağrısı
    return vfs_statfs(path, buf);
}
