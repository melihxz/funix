// net/udp.h

#ifndef UDP_H
#define UDP_H

#include <stdint.h>
#include "socket.h"

// UDP işlemleri için işlevler
void udp_init();
void udp_shutdown();
void udp_poll();
int udp_send(struct socket *sock, const void *buf, uint32_t len);
int udp_recv(struct socket *sock, void *buf, uint32_t len);
void udp_close(struct socket *sock);

#endif // UDP_H
