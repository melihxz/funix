// fs/inode.h

#ifndef INODE_H
#define INODE_H

#include <stdint.h>

// Inode yapısı tanımı
struct inode {
    uint32_t i_number;     // Inode numarası
    uint32_t i_size;       // Dosya boyutu
    uint32_t i_blocks;     // Bloğun başlangıç adresi
    uint16_t i_mode;       // Erişim hakları
    uint16_t i_uid;        // Sahip kullanıcı ID
    uint16_t i_gid;        // Sahip grup ID
    uint16_t i_nlink;      // Link sayısı
};

// Inode işlemleri için prototipler
struct inode *inode_get(uint32_t inode_number);
void inode_release(struct inode *inode);
int inode_read(struct inode *inode, void *buf, uint32_t offset, uint32_t size);
int inode_write(struct inode *inode, const void *buf, uint32_t offset, uint32_t size);

#endif // INODE_H
