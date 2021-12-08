#include "stm32f3xx_it.h"

void NMI_Handler(void)
{
}


void HardFault_Handler(void)
{
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
}

void USER_BUTTON_IRQHANDLER(void)
{

}

char Recv_Buffer[LN];
int Rec_i=0;

void USART1_IRQHandler(void)
{
	uint8_t temp;
	if(LL_USART_IsActiveFlag_RXNE(USART1)==1){
		temp= LL_USART_ReceiveData8(USART1);
		Recv_Buffer[Rec_i++]=temp;
		}
}

void Clear_Buffer(void){
		memset(Recv_Buffer,0,sizeof(Recv_Buffer));
		Rec_i=0;		
}

char Recv_Buffer2[LN];
int Rec_i2=0;

void USART2_IRQHandler(void)
{
	uint8_t temp;
	if(LL_USART_IsActiveFlag_RXNE(USART2)==1){
		temp= LL_USART_ReceiveData8(USART2);
		Recv_Buffer2[Rec_i2++]=temp;
		}
}

void Clear_Buffer2(void){
		memset(Recv_Buffer2,0,sizeof(Recv_Buffer2));
		Rec_i2=0;		
}
