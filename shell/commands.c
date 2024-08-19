// shell/commands.c

#include "commands.h"
#include "screen.h"

// "help" komutu: Mevcut komutların listesini gösterir
int cmd_help(int argc, char **argv) {
    kprintf("Available commands:\n");
    kprintf("help - Display this help message\n");
    kprintf("exit - Exit the shell\n");
    // Diğer komutlar burada listelenebilir
    return 0;
}

// "exit" komutu: Kabuktan çıkışı sağlar
int cmd_exit(int argc, char **argv) {
    kprintf("Exiting shell...\n");
    return 0;  // Çıkış kodu
}
