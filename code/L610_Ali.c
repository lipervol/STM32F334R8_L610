#include "L610_Ali.h"

extern char Recv_Buffer[LN];

//开始连接
void Ali_Link(void){
	L610_Start();
	LL_mDelay(200);
	IP_Allo();
	LL_mDelay(200);
	Ali_Auth();
	LL_mDelay(200);
	Ali_Conn();
}

//认证
void Ali_Auth(void){
	char *strx;
	Clear_Buffer();
	Send_Buffer("AT+CLOUDAUTH=\"a1sg139tgpK\",\"L610\",\"764f79d8c4cef6ab1b603dab40ad622a\",\"iot-auth.aliyun.com\"\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,"+CLOUDAUTH: OK");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+CLOUDAUTH=\"a1sg139tgpK\",\"L610\",\"764f79d8c4cef6ab1b603dab40ad622a\",\"iot-auth.aliyun.com\"\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,"+CLOUDAUTH: OK");
	}
	Clear_Buffer();
}

//设置连接时间
void Ali_Conn(void){
	Send_Buffer("AT+CLOUDCONN=80,0,4\r\n");
	LL_mDelay(2000);
	Clear_Buffer();
}

//断开连接
void Ali_Disconn(void){
	char *strx;
	Clear_Buffer();
	Send_Buffer("AT+CLOUDDISCONN\r\n");
	LL_mDelay(1000);
	strx=strstr(Recv_Buffer,"OK");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+CLOUDDISCONN\r\n"); 
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"OK");
	}
	Clear_Buffer();
}

//订阅消息
void Ali_Subget(void){
	char *strx;
	Clear_Buffer();
	Send_Buffer("AT+CLOUDSUB=\"/a1sg139tgpK/L610/user/get\",0\r\n");
	LL_mDelay(1000);
	strx=strstr(Recv_Buffer,"+CLOUDSUB: OK");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+CLOUDSUB=\"/a1sg139tgpK/L610/user/get\",0\r\n"); 
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+CLOUDSUB: OK");
	}
	Clear_Buffer();
}

//取消订阅
void Ali_Dissubget(void){
	char *strx;
	Clear_Buffer();
	Send_Buffer("AT+CLOUDUNSUB=\"/a1sg139tgpK/L610/user/get\"\r\n");
	LL_mDelay(1000);
	strx=strstr(Recv_Buffer,"OK");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer("AT+CLOUDUNSUB=\"/a1sg139tgpK/L610/user/get\"\r\n"); 
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"OK");
	}
	Clear_Buffer();
}

//发布消息
void Ali_Pub(char p[]){
	char buffer[100];
	sprintf(buffer,"AT+CLOUDPUB=\"/a1sg139tgpK/L610/user/update\",1,\"%s\"\r\n",p);
	char *strx;
	Clear_Buffer();
	Send_Buffer(buffer);
	LL_mDelay(1000);
	strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
	while(strx==NULL){
		Clear_Buffer();
		Send_Buffer(buffer); 
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
	}
	Clear_Buffer();
}

//属性上报（浮点型）
void Ali_Postfloat(char p[],float value){
	char buffer[100],commend[100];
	int len=0;
	sprintf(buffer,"{'params': {'%s': %.2f}, 'method': 'thing.event.property.post'}\r\n",p,value);
	for(;len<100;len++){
		if(buffer[len]==0x00) break;
	}
	sprintf(commend,"AT+CLOUDPUB=\"/sys/a1sg139tgpK/L610/thing/event/property/post\",1,%d\r\n",len);
	char *strx;
	Clear_Buffer();
	Send_Buffer(commend);
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,">");
	while(strx==NULL){
		Clear_Buffer();
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,">");
	}
	Send_Buffer(buffer);
	Clear_Buffer();
	strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
	while(strx==NULL){
		Clear_Buffer();
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
}
}

//属性上报（字符型）
void Ali_Postchar(char p[],char value[]){
	char buffer[100],commend[100];
	int len=0;
	sprintf(buffer,"{'params': {'%s': '%s'}, 'method': 'thing.event.property.post'}\r\n",p,value);
	for(;len<100;len++){
		if(buffer[len]==0x00) break;
	}
	sprintf(commend,"AT+CLOUDPUB=\"/sys/a1sg139tgpK/L610/thing/event/property/post\",1,%d\r\n",len);
	char *strx;
	Clear_Buffer();
	Send_Buffer(commend);
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,">");
	while(strx==NULL){
		Clear_Buffer();
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,">");
	}
	Send_Buffer(buffer);
	Clear_Buffer();
	strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
	while(strx==NULL){
		Clear_Buffer();
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
}
}

//属性上报（整型）
void Ali_Postint(char p[],int value){
	char buffer[100],commend[100];
	int len=0;
	sprintf(buffer,"{'params': {'%s': %d}, 'method': 'thing.event.property.post'}\r\n",p,value);
	for(;len<100;len++){
		if(buffer[len]==0x00) break;
	}
	sprintf(commend,"AT+CLOUDPUB=\"/sys/a1sg139tgpK/L610/thing/event/property/post\",1,%d\r\n",len);
	char *strx;
	Clear_Buffer();
	Send_Buffer(commend);
	LL_mDelay(500);
	strx=strstr(Recv_Buffer,">");
	while(strx==NULL){
		Clear_Buffer();
		LL_mDelay(500);
		strx=strstr(Recv_Buffer,">");
	}
	Send_Buffer(buffer);
	Clear_Buffer();
	strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
	while(strx==NULL){
		Clear_Buffer();
		LL_mDelay(1000);
		strx=strstr(Recv_Buffer,"+CLOUDPUB: OK");
}
}
