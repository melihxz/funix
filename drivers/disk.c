// funix/drivers/disk.c

#include "disk.h"
#include "io.h"

// IDE disk portları
#define DISK_PORT_BASE 0x1F0
#define DISK_COMMAND_PORT (DISK_PORT_BASE + 7)
#define DISK_DATA_PORT (DISK_PORT_BASE + 0)
#define DISK_SECTOR_COUNT_PORT (DISK_PORT_BASE + 2)
#define DISK_SECTOR_NUMBER_PORT (DISK_PORT_BASE + 3)
#define DISK_CYLINDER_LOW_PORT (DISK_PORT_BASE + 4)
#define DISK_CYLINDER_HIGH_PORT (DISK_PORT_BASE + 5)
#define DISK_DRIVE_SELECT_PORT (DISK_PORT_BASE + 6)

// Komut kodları
#define DISK_CMD_READ_SECTOR 0x20
#define DISK_CMD_WRITE_SECTOR 0x30
#define DISK_CMD_IDENTIFY 0xEC

// Diskin hazır olup olmadığını kontrol et
static void wait_for_disk() {
    while ((inb(DISK_COMMAND_PORT) & 0x80)) {
        // Diskin veri hazır olmasını bekle
    }
}

// Disk sürücüsünü başlat
void init_disk() {
    // Disk seçim işlemi
    outb(DISK_DRIVE_SELECT_PORT, 0xA0); // Master disk için

    // Kimlik komutunu göndererek diskin yanıtını al
    outb(DISK_COMMAND_PORT, DISK_CMD_IDENTIFY);
    
    // Diskin yanıtını bekle
    wait_for_disk();

    // Yanıtı oku
    uint16_t buffer[256];
    insw(DISK_DATA_PORT, buffer, 256);

    // Kimlik yanıtını işleme
    // Örneğin, disk modelini ve diğer bilgileri alabilirsiniz
    char model[41];
    for (int i = 0; i < 20; ++i) {
        model[i * 2] = buffer[0x20 + i] & 0xFF;
        model[i * 2 + 1] = (buffer[0x20 + i] >> 8) & 0xFF;
    }
    model[40] = '\0'; // Null terminator

    // Disk modelini ekrana yazdır
    kprintf("Disk Model: %s\n", model);

    // Diskin diğer bilgilerini kontrol et
    // Bu aşamada, disk özelliklerini kontrol edebilir veya yapılandırabilirsiniz.
}

// Bir sektörden veri okuma işlemi yapar
void read_disk_sector(uint32_t sector, void *buffer) {
    outb(DISK_DRIVE_SELECT_PORT, 0xA0); // Master disk için
    outb(DISK_SECTOR_COUNT_PORT, 1);   // Sadece bir sektör oku
    outb(DISK_SECTOR_NUMBER_PORT, sector & 0xFF); // Sektör numarasının düşük byte'ı
    outb(DISK_CYLINDER_LOW_PORT, (sector >> 8) & 0xFF); // Silindirin düşük byte'ı
    outb(DISK_CYLINDER_HIGH_PORT, (sector >> 16) & 0xFF); // Silindirin yüksek byte'ı
    outb(DISK_COMMAND_PORT, DISK_CMD_READ_SECTOR); // Okuma komutunu gönder

    wait_for_disk(); // Diskin veriyi hazırlamasını bekle

    insl(DISK_DATA_PORT, buffer, 256); // 256 kelime oku (512 byte)
}

// Bir sektöre veri yazma işlemi yapar
void write_disk_sector(uint32_t sector, const void *buffer) {
    outb(DISK_DRIVE_SELECT_PORT, 0xA0); // Master disk için
    outb(DISK_SECTOR_COUNT_PORT, 1);   // Sadece bir sektör yaz
    outb(DISK_SECTOR_NUMBER_PORT, sector & 0xFF); // Sektör numarasının düşük byte'ı
    outb(DISK_CYLINDER_LOW_PORT, (sector >> 8) & 0xFF); // Silindirin düşük byte'ı
    outb(DISK_CYLINDER_HIGH_PORT, (sector >> 16) & 0xFF); // Silindirin yüksek byte'ı
    outb(DISK_COMMAND_PORT, DISK_CMD_WRITE_SECTOR); // Yazma komutunu gönder

    wait_for_disk(); // Diskin veriyi hazırlamasını bekle

    outsl(DISK_DATA_PORT, buffer, 256); // 256 kelime yaz (512 byte)
}

// Diskin hata durumlarını kontrol et
int check_disk_errors() {
    uint8_t status = inb(DISK_COMMAND_PORT);
    if (status & 0x01) { // Hata bitini kontrol et
        return -1; // Hata durumunda -1 döndür
    }
    return 0; // Hata yoksa 0 döndür
}

// Diskin hazır olup olmadığını ve hatalarını kontrol et
int check_disk_status() {
    uint8_t status = inb(DISK_COMMAND_PORT);

    // Diskin hazır olup olmadığını kontrol et
    if (!(status & 0x08)) {
        return -1; // Disk hazır değil
    }

    // Hata durumlarını kontrol et
    if (status & 0x01) {
        return -2; // Hata var
    }

    return 0; // Disk düzgün çalışıyor
}
