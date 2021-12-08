#include "L610_init.h"
extern char Recv_Buffer[LN];

//��ʼ��L610�������
void L610_Init(void){
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	LL_GPIO_SetPinMode(GPIOA,LL_GPIO_PIN_0,LL_GPIO_MODE_OUTPUT);
	LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_0);
} 

//����L610
void L610_Poweron(void){
	LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_0);
	LL_mDelay(2000);
	LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_0);
}

//�ر�L610
void L610_Poweroff(void){
	LL_mDelay(3200);
	LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_0);
	LL_mDelay(3200);
	LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_0);
}

//����AT
void AT_Check(void){
	char *strx;
	Send_Buffer("AT\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,"OK");
	while(strx==NULL)
	{
		Clear_Buffer();
		Send_Buffer("AT\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,"OK");
	}
	Clear_Buffer();
}

//AT+CSQ? ����ź�ǿ��
void CSQ_Check(void){
	Send_Buffer("AT+CSQ?\r\n");
	Clear_Buffer();
	LL_mDelay(1000);
}

//L610�������
void L610_Start(void){
	Clear_Buffer();
	AT_Check();
	LL_mDelay(200);
	CFUN_Set();
	LL_mDelay(200);
	CSQ_Check();
	LL_mDelay(200);
	CSQ_Check();
	LL_mDelay(200);
	CSQ_Check();
	LL_mDelay(200);
	ATI_Check();
	LL_mDelay(200);
	CPIN_Check();
	LL_mDelay(200);
	GPRS_Check();
	LL_mDelay(200);
	EPS_Check();
	LL_mDelay(200);;
	Hex_Set();
	LL_mDelay(200);
	IP_Allo();
	LL_mDelay(200);
	CSQ_Check();
	LL_mDelay(200);
}

//ATI ���ģ��̼��汾��
void ATI_Check(void){
	Send_Buffer("ATI\r\n");
	LL_mDelay(500);
}

//AT+CFUN=1 ���ù���ģʽ
void CFUN_Set(void){
	Send_Buffer("AT+CFUN=1\r\n");
	LL_mDelay(500);
}

//AT+CPIN? ���SIM��״̬
void CPIN_Check(void){
	char *strx;
	Send_Buffer("AT+CPIN?\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,"+CPIN: READY");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+CPIN?\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,"+CPIN: READY");
	}
	Clear_Buffer();
}

//AT+CGREG? ���GPRS�Ƿ���ã���������Ƿ�����
void GPRS_Check(void){
	char *strx,*extstrx;
	Send_Buffer("AT+CGREG?\r\n");
	strx=strstr(Recv_Buffer,"+CGREG: 0,1");
	extstrx=strstr(Recv_Buffer,"+CGREG: 0,5");
	while(strx==NULL&&extstrx==NULL)
	{
		Clear_Buffer();
		Send_Buffer("AT+CGREG?\r\n");
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,"+CGREG: 0,1");
		extstrx=strstr(Recv_Buffer,"+CGREG: 0,5");
	}
	Clear_Buffer();
}

//AT+CEREG? �������ģ���Ƿ�����
void EPS_Check(void){
	char *strx,*extstrx;
	Send_Buffer("AT+CEREG?\r\n");
	strx=strstr(Recv_Buffer,"+CEREG: 0,1");
	extstrx=strstr(Recv_Buffer,"+CEREG: 0,5");
	while(strx==NULL&&extstrx==NULL)
	{
		Clear_Buffer();
		Send_Buffer("AT+CEREG?\r\n");
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,"+CEREG: 0,1");
		extstrx=strstr(Recv_Buffer,"+CEREG: 0,5");
	}
	Clear_Buffer();
}

//AT+GTSET="IPRFMT",0 ����L610�����ϱ��ĸ�ʽ
void Hex_Set(void){
	char *strx;
	Send_Buffer("AT+GTSET=\"IPRFMT\",0\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,"OK");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+GTSET=\"IPRFMT\",0\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,"OK");
	}
	Clear_Buffer();
}
