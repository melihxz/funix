// funix/kernel/main.c

#include "init.h"
#include "screen.h"
#include "stdlib.h"

void kernel_main() {
    // Ekranı başlat
    init_screen();

    // Sistemi başlat
    init_system();

    // Bilgilendirme mesajı
    printf("Funix OS Booted Successfully\n");

    // Sonsuz döngü, sistem çalışırken bekle
    while (1) {
        // Burada sistem işlemlerini gerçekleştirin
        // Örneğin, süreçleri ve zamanlayıcıları kontrol et
    }
}
