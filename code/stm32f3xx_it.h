#ifndef __STM32F3xx_IT_H
#define __STM32F3xx_IT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_system.h"
#include "stm32f3xx_ll_utils.h"
#include "stm32f3xx_ll_cortex.h"
#include "stm32f3xx_ll_gpio.h"
#include "stm32f3xx_ll_exti.h"
#include "stm32f3xx_ll_usart.h"
#include "stm32f3xx_ll_pwr.h"
#include "usart.h"
#include "string.h"


void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void USER_BUTTON_IRQHANDLER(void);
void USART1_IRQHandler(void);
void Clear_Buffer(void);
void USART2_IRQHandler(void);
void Clear_Buffer2(void);

#ifdef __cplusplus
}
#endif

#endif 

