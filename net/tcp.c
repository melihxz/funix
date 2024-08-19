// net/tcp.c

#include "tcp.h"
#include "screen.h"

// TCP başlatma
void tcp_init() {
    kprintf("Initializing TCP subsystem...\n");
}

// TCP kapatma
void tcp_shutdown() {
    kprintf("Shutting down TCP subsystem...\n");
}

// TCP olaylarını işleme
void tcp_poll() {
    // TCP bağlantı yönetimi ve zaman aşımı kontrolü
}

// TCP bağlantıyı dinleme
int tcp_listen(struct socket *sock, int backlog) {
    kprintf("TCP: Listening on socket with backlog %d\n", backlog);
    // TCP dinleme işlemi
    return 0;
}

// TCP bağlantıyı kabul etme
struct socket *tcp_accept(struct socket *sock) {
    kprintf("TCP: Accepting connection\n");
    // Yeni bir socket yapısı oluşturulmalı ve döndürülmeli
    return NULL;
}

// TCP bağlantı kurma
int tcp_connect(struct socket *sock, uint32_t ip, uint16_t port) {
    kprintf("TCP: Connecting to IP %d, Port %d\n", ip, port);
    // TCP bağlantı kurulumu
    return 0;
}

// TCP üzerinden veri gönderme
int tcp_send(struct socket *sock, const void *buf, uint32_t len) {
    kprintf("TCP: Sending %d bytes\n", len);
    // TCP veri gönderme işlemi
    return len;
}

// TCP üzerinden veri alma
int tcp_recv(struct socket *sock, void *buf, uint32_t len) {
    kprintf("TCP: Receiving %d bytes\n", len);
    // TCP veri alma işlemi
    return len;
}

// TCP soketi kapatma
void tcp_close(struct socket *sock) {
    kprintf("TCP: Closing socket\n");
    // TCP soketi kapatma işlemi
}
