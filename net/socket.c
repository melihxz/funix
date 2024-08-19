// net/socket.c

#include "socket.h"
#include "screen.h"
#include "tcp.h"
#include "udp.h"

// Soket oluşturma
struct socket *socket_create(int type) {
    kprintf("Creating socket of type: %d\n", type);
    struct socket *sock = (struct socket *)kalloc(sizeof(struct socket));
    if (!sock) return NULL;
    sock->type = type;
    sock->state = SOCKET_STATE_CLOSED;
    return sock;
}

// Soket kapatma
void socket_close(struct socket *sock) {
    kprintf("Closing socket\n");
    if (sock->protocol_data) {
        if (sock->type == SOCK_STREAM) {
            tcp_close(sock);
        } else if (sock->type == SOCK_DGRAM) {
            udp_close(sock);
        }
    }
    kfree(sock);
}

// Soket bind işlemi
int socket_bind(struct socket *sock, uint32_t ip, uint16_t port) {
    kprintf("Binding socket to IP: %d, Port: %d\n", ip, port);
    sock->local_ip = ip;
    sock->local_port = port;
    return 0;
}

// Soket listen işlemi (TCP)
int socket_listen(struct socket *sock, int backlog) {
    if (sock->type != SOCK_STREAM) return -1;
    kprintf("Socket is now listening with backlog: %d\n", backlog);
    sock->state = SOCKET_STATE_LISTENING;
    return tcp_listen(sock, backlog);
}

// Soket accept işlemi (TCP)
struct socket *socket_accept(struct socket *sock) {
    if (sock->state != SOCKET_STATE_LISTENING) return NULL;
    kprintf("Accepting connection on socket\n");
    return tcp_accept(sock);
}

// Soket connect işlemi (TCP)
int socket_connect(struct socket *sock, uint32_t ip, uint16_t port) {
    if (sock->type != SOCK_STREAM) return -1;
    kprintf("Connecting to IP: %d, Port: %d\n", ip, port);
    return tcp_connect(sock, ip, port);
}

// Soket üzerinden veri gönderme (TCP/UDP)
int socket_send(struct socket *sock, const void *buf, uint32_t len) {
    if (sock->type == SOCK_STREAM) {
        return tcp_send(sock, buf, len);
    } else if (sock->type == SOCK_DGRAM) {
        return udp_send(sock, buf, len);
    }
    return -1;
}

// Soket üzerinden veri alma (TCP/UDP)
int socket_recv(struct socket *sock, void *buf, uint32_t len) {
    if (sock->type == SOCK_STREAM) {
        return tcp_recv(sock, buf, len);
    } else if (sock->type == SOCK_DGRAM) {
        return udp_recv(sock, buf, len);
    }
    return -1;
}
