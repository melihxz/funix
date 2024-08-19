// funix/drivers/disk.h

#ifndef DISK_H
#define DISK_H

#include <stdint.h>

// Disk sürücüsü ile ilgili fonksiyon prototipleri

// Disk sürücüsünü başlat
void init_disk();

// Bir sektörden veri okuma işlemi yapar
void read_disk_sector(uint32_t sector, void *buffer);

// Bir sektöre veri yazma işlemi yapar
void write_disk_sector(uint32_t sector, const void *buffer);

// Diskin hata durumlarını kontrol eder
int check_disk_errors();

// Diskin durumunu kontrol eder
int check_disk_status();

#endif // DISK_H
