#ifndef __L610_H
#define __L610_H
#include "usart.h"
#include "string.h"
#include "L610_TCP.h"
#include "stm32f3xx_it.h"
#include "stdio.h"
#include "stdlib.h"
#include "L610_Ali.h"

void L610_Init(void);
void L610_Poweron(void);
void L610_Poweroff(void);
void AT_Check(void);
void CSQ_Check(void);
void ATI_Check(void);
void L610_Start(void);
void CPIN_Check(void);
void GPRS_Check(void);
void EPS_Check(void);
void Hex_Set(void);
void CFUN_Set(void);

#endif
