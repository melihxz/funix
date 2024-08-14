// shell.c
#include "shell.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void shell_loop() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("shell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            continue;
        }

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        process_command(input);
    }
}

void process_command(const char *cmd) {
    if (strcmp(cmd, "hello") == 0) {
        print_hello();
    } else {
        printf("Unknown command: %s\n", cmd);
    }
}
