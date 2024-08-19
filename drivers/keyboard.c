// funix/drivers/keyboard.c

#include "keyboard.h"
#include "io.h"

#define KEYBOARD_PORT 0x60

void init_keyboard() {
    // Klavye yapılandırması yapılabilir
    // Örneğin, IRQ1 yapılandırması
}

char read_key() {
    return inb(KEYBOARD_PORT);
}
