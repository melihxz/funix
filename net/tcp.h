// net/tcp.h

#ifndef TCP_H
#define TCP_H

#include <stdint.h>
#include "socket.h"

// TCP işlemleri için işlevler
void tcp_init();
void tcp_shutdown();
void tcp_poll();
int tcp_listen(struct socket *sock, int backlog);
struct socket *tcp_accept(struct socket *sock);
int tcp_connect(struct socket *sock, uint32_t ip, uint16_t port);
int tcp_send(struct socket *sock, const void *buf, uint32_t len);
int tcp_recv(struct socket *sock, void *buf, uint32_t len);
void tcp_close(struct socket *sock);

#endif // TCP_H
