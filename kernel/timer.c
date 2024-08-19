// funix/kernel/timer.c

#include "timer.h"
#include "ctype.h"

#define PIT_CHANNEL0 0x40
#define PIT_COMMAND  0x43
#define PIT_FREQ     1193180

void init_timer() {
    // Zamanlayıcı ayarlarını yap
    uint32_t divisor = PIT_FREQ / 1000; // 1 ms kesme

    // Komut register'ını ayarla
    outb(PIT_COMMAND, 0x36);

    // Kanal 0'a divisor'ı yaz
    outb(PIT_CHANNEL0, divisor & 0xFF);
    outb(PIT_CHANNEL0, (divisor >> 8) & 0xFF);

    // Kesme işlemini ayarla (örneğin, IRQ0)
    // Burada gerekli yapılandırma işlemleri yapılır
}
