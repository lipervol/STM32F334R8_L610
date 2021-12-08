#include "L610_TCP.h"

extern char Recv_Buffer[LN];

//AT+mipcall= 请求运营商分配IP
void IP_Allo(void){
	char *strx;
	Send_Buffer("AT+mipcall=1,\"ctnet\"\r\n");
	LL_mDelay(3000);
	Send_Buffer("AT+mipcall?\r\n");
	LL_mDelay(3000);
	strx=strstr(Recv_Buffer,"+MIPCALL: 1");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+mipcall=0\r\n");
		LL_mDelay(2000);
		Send_Buffer("AT+mipcall=1,\"ctnet\"\r\n");
		LL_mDelay(3000);
		Send_Buffer("AT+mipcall?\r\n");
		LL_mDelay(3000);
		strx=strstr(Recv_Buffer,"+MIPCALL: 1");
	}
	LL_mDelay(1000);
	Clear_Buffer();
}

//AT+MIPOPEN? 查询可用的socket ID 
void Check_Socket(void)
{
	char *strx;
	Clear_Buffer();
	Send_Buffer("AT+MIPOPEN?\r\n"); 
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,"+MIPOPEN:");
	while(strx==NULL)
	{
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+MIPOPEN:");
	}
	Clear_Buffer();
}

//AT+MIPOPEN=socket,localport,"IP",port,0 通过socket创建TCP连接
void Creat_TCP(void)
{
	char *strx;
	Clear_Buffer();
	Send_Buffer("AT+MIPOPEN=1,,\"47.92.117.163\",30000,0\r\n");
	LL_mDelay(3000);
	strx=strstr(Recv_Buffer,"+MIPOPEN: 1,1");
	while(strx==NULL)
	{
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+MIPOPEN: 1,1");
	}
	Clear_Buffer();
}

//AT+MIPSEND=socketID,Length 发送数据
void TCP_SendData(char *bufferdata,int n)
{
	char temp[LN];
	Clear_Buffer();
	LL_mDelay(2000);
	sprintf(temp,"AT+MIPSEND=1,%d\r\n",n);
	Send_Buffer(temp);
	Send_Buffer(bufferdata);
	LL_mDelay(2000);
	Clear_Buffer();
}

//AT+MIPCLOSE=1 关闭TCP连接
void End_TCP(void){
	char *strx;
	Clear_Buffer();
	LL_mDelay(2000);
	Send_Buffer("AT+MIPCLOSE=1\r\n");
	strx=strstr(Recv_Buffer,"+MIPCLOSE: 1,0");
	while(strx==NULL)
	{
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+MIPCLOSE: 1,0");
	}
	Clear_Buffer();
}

//AT+MIPCALL=0 释放IP地址
void IP_release(void){
	char *strx;
	Clear_Buffer();
	LL_mDelay(2000);
	Send_Buffer("AT+MIPCALL=0\r\n");
	strx=strstr(Recv_Buffer,"+MIPCALL: 0");
	while(strx==NULL)
	{
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+MIPCALL: 0");
	}
	Clear_Buffer();
}


