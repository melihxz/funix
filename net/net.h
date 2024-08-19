// net/net.h

#ifndef NET_H
#define NET_H

#include <stdint.h>
#include "socket.h"
#include "tcp.h"
#include "udp.h"
#include "ip.h"

// Ağ yönetimi için temel fonksiyonlar
void net_init();
void net_shutdown();
void net_poll();

#endif // NET_H
