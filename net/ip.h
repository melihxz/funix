// net/ip.h

#ifndef IP_H
#define IP_H

#include <stdint.h>

// IP başlatma ve kapatma
void ip_init();
void ip_shutdown();

// IP adresleme ve yönlendirme
uint32_t ip_address_to_int(const char *ip);
char *ip_int_to_address(uint32_t ip);

// IP paketi gönderme/alma
int ip_send_packet(uint32_t dest_ip, const void *buf, uint32_t len);
int ip_receive_packet(void *buf, uint32_t len);

#endif // IP_H
