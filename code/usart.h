#ifndef __USART_H
#define __USART_H

#define LN 1000
#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_system.h"
#include "stm32f3xx_ll_utils.h"
#include "stm32f3xx_ll_cortex.h"
#include "stm32f3xx_ll_gpio.h"
#include "stm32f3xx_ll_exti.h"
#include "stm32f3xx_ll_usart.h"
#include "stm32f3xx_ll_pwr.h"

void Usart1_Init(void);
void Usart2_Init(void);
void Send_Buffer(char* buffer);
void Send_Buffer2(char* buffer);

#endif
