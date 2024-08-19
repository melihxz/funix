// funix/kernel/init.c

#include "init.h"
#include "paging.h"
#include "process.h"
#include "timer.h"
#include "memory.h"
#include "screen.h"

void init_system() {
    // Bellek yönetimini başlat
    init_memory();

    // Sayfa tablosunu başlat
    init_paging();

    // Süreç yönetimini başlat
    init_processes();

    // Zamanlayıcıyı başlat
    init_timer();

    // Ekranı başlat
    init_screen();
}
