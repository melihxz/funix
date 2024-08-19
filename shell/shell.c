// shell/shell.c

#include "shell.h"
#include "commands.h"
#include "parser.h"
#include "screen.h"

// Kabuk başlatma işlemi
void shell_init() {
    kprintf("Shell initializing...\n");
    // Gerekli başlangıç işlemleri
}

// Kabuk çalışma döngüsü
void shell_run() {
    kprintf("Shell running...\n");
    
    char input[256];
    
    while (1) {
        kprintf("funix> ");  // Prompt göstergesi
        kgets(input, sizeof(input));  // Kullanıcı girdisini al
        
        if (parse_and_execute(input) == 0) {  // Komutu çalıştır
            break;  // Çıkış komutu
        }
    }
}

// Kabuk kapatma işlemi
void shell_shutdown() {
    kprintf("Shell shutting down...\n");
    // Kapanış işlemleri
}
