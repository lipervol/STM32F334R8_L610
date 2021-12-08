#ifndef ESP8266
#define ESP8266
#include "L610_init.h"

void ESP_AT(void);
void ESP_RESTORE(void);
void ESP_WIFI(void);
void ESP_DHCP(void);
void ESP_IPSET(void);
void ESP_UDP(void);
void ESP_START(void);
void RECV_Scan(void);

#endif
