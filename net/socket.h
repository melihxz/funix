// net/socket.h

#ifndef SOCKET_H
#define SOCKET_H

#include <stdint.h>

// Soket türleri ve durumları için sabitler
#define SOCK_STREAM 1  // TCP
#define SOCK_DGRAM  2  // UDP

#define SOCKET_STATE_CLOSED     0
#define SOCKET_STATE_LISTENING  1
#define SOCKET_STATE_ESTABLISHED 2

// Soket yapısı
struct socket {
    int type;            // SOCK_STREAM veya SOCK_DGRAM
    int state;           // Soket durumu
    uint32_t local_ip;   // Yerel IP adresi
    uint16_t local_port; // Yerel port numarası
    uint32_t remote_ip;  // Uzak IP adresi
    uint16_t remote_port;// Uzak port numarası
    void *protocol_data; // Protokol verileri (TCP, UDP, vs.)
};

// Soket yönetimi işlevleri
struct socket *socket_create(int type);
void socket_close(struct socket *sock);
int socket_bind(struct socket *sock, uint32_t ip, uint16_t port);
int socket_listen(struct socket *sock, int backlog);
struct socket *socket_accept(struct socket *sock);
int socket_connect(struct socket *sock, uint32_t ip, uint16_t port);
int socket_send(struct socket *sock, const void *buf, uint32_t len);
int socket_recv(struct socket *sock, void *buf, uint32_t len);

#endif // SOCKET_H
