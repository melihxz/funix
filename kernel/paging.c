// funix/kernel/paging.c

#include "paging.h"
#include "types.h"

// Sayfa tablosu ve dizini
#define PAGE_DIRECTORY_ENTRY_COUNT 1024
#define PAGE_TABLE_ENTRY_COUNT 1024

typedef struct {
    uint32_t entries[PAGE_TABLE_ENTRY_COUNT];
} page_table_t;

typedef struct {
    uint32_t entries[PAGE_DIRECTORY_ENTRY_COUNT];
} page_directory_t;

static page_directory_t *kernel_page_directory;
static page_table_t *kernel_page_table;

void init_paging() {
    // Sayfa tablosunu ve dizinini ayır
    kernel_page_directory = (page_directory_t *)0x100000; // Örnek adres
    kernel_page_table = (page_table_t *)0x101000;        // Örnek adres

    // Sayfa dizinini sıfırla
    for (int i = 0; i < PAGE_DIRECTORY_ENTRY_COUNT; i++) {
        kernel_page_directory->entries[i] = 0;
    }

    // Sayfa tablosunu sıfırla
    for (int i = 0; i < PAGE_TABLE_ENTRY_COUNT; i++) {
        kernel_page_table->entries[i] = 0;
    }

    // İlk sayfa tablosu, dizin ile ilişkilendir
    kernel_page_directory->entries[0] = (uint32_t)kernel_page_table | 0x07; // 0x07: Present, Read/Write, User
}
