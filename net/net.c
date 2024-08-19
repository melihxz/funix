// net/net.c

#include "net.h"
#include "screen.h"

// Ağ alt sistemini başlatma
void net_init() {
    kprintf("Initializing network subsystem...\n");
    // IP, TCP, UDP ve diğer ağ bileşenlerini başlat
    ip_init();
    tcp_init();
    udp_init();
}

// Ağ alt sistemini kapatma
void net_shutdown() {
    kprintf("Shutting down network subsystem...\n");
    // Ağ bileşenlerini düzgün bir şekilde kapat
    tcp_shutdown();
    udp_shutdown();
}

// Ağ olaylarını işleme
void net_poll() {
    // Ağ olaylarını işlemek için düzenli olarak çağrılacak
    tcp_poll();
    udp_poll();
}
