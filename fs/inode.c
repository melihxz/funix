// fs/inode.c

#include "inode.h"
#include "vfs.h"

// Inode alma
struct inode *inode_get(uint32_t inode_number) {
    kprintf("Getting inode: %d\n", inode_number);
    // Inode tablosundan inode'ı bul ve döndür
    return NULL; // Gerçek uygulamada inode adresi döndürülmelidir
}

// Inode serbest bırakma
void inode_release(struct inode *inode) {
    kprintf("Releasing inode: %d\n", inode->i_number);
    // Inode'i serbest bırak
}

// Inode'dan okuma
int inode_read(struct inode *inode, void *buf, uint32_t offset, uint32_t size) {
    kprintf("Reading from inode: %d\n", inode->i_number);
    // Inode'dan veri okuma işlemi
    return size; // Okunan byte sayısını döndür
}

// Inode'a yazma
int inode_write(struct inode *inode, const void *buf, uint32_t offset, uint32_t size) {
    kprintf("Writing to inode: %d\n", inode->i_number);
    // Inode'a veri yazma işlemi
    return size; // Yazılan byte sayısını döndür
}
