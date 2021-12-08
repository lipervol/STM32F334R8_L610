#include "usart.h"
#include "L610_init.h"
#include "L610_TCP.h"
#include "L610_Ali.h"
#include "ESP8266.h"

void Systemclock_Init(void){
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
	if(LL_RCC_HSI_IsReady()==0){
		LL_RCC_HSI_Enable();
		while(LL_RCC_HSI_IsReady()==0);
	}
	LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI_DIV_2,LL_RCC_PLL_MUL_16);
	LL_RCC_PLL_Enable();
	while(LL_RCC_PLL_IsReady()==0);
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
	while(LL_RCC_GetSysClkSource()!=LL_RCC_SYS_CLKSOURCE_STATUS_PLL);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
	LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	
	LL_Init1msTick(64000000);
	LL_SetSystemCoreClock(64000000);
		
}

extern char Recv_Buffer[LN];
extern char Recv_Buffer2[LN];

int main(void){
	L610_Init();
	Systemclock_Init();
	Usart1_Init();
	Usart2_Init();
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
	ESP_START();
	L610_Poweron();
	LL_mDelay(500);
	Ali_Link();
	LL_mDelay(500);
	int n=0;
	while(1){
		if(n==120) {
			Ali_Auth();
			n=0;
		}
		RECV_Scan();
		LL_mDelay(500);
		LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5);
		n++;
	}
}

