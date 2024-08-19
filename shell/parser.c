// shell/parser.c

#include "parser.h"
#include "commands.h"
#include "screen.h"
#include <string.h>

// Komutları çözümleme ve çalıştırma
int parse_and_execute(char *input) {
    char *argv[10];
    int argc = 0;
    
    // Girdiyi böl ve argümanları ayıkla
    argv[argc] = strtok(input, " ");
    while (argv[argc] != NULL) {
        argc++;
        argv[argc] = strtok(NULL, " ");
    }
    
    // Komutları tanımla ve çalıştır
    if (strcmp(argv[0], "help") == 0) {
        return cmd_help(argc, argv);
    } else if (strcmp(argv[0], "exit") == 0) {
        return cmd_exit(argc, argv);
    } else {
        kprintf("Unknown command: %s\n", argv[0]);
        return -1;
    }
}
