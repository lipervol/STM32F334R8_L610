#ifndef __L610_TCP
#define __L610_TCP
#include "usart.h"
#include "string.h"
#include "L610_init.h"
#include "stm32f3xx_it.h"

void IP_Allo(void);
void Check_Socket(void);
void Creat_TCP(void);
void TCP_SendData(char *bufferdata,int n);
void End_TCP(void);
void IP_release(void);

#endif
