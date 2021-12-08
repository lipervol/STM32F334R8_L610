#include "ESP8266.h"

extern char Recv_Buffer2[LN];
	
//AT
void ESP_AT(void){	
	char *strx;
	Clear_Buffer2();
	Send_Buffer2("AT\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer2,"OK");
	while(strx==NULL){
		Clear_Buffer2();
		Send_Buffer2("AT\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer2,"OK");
	}
	Clear_Buffer2();
}

//AT+RESTORE
void ESP_RESTORE(void){
	char *strx;
	Clear_Buffer2();
	Send_Buffer2("AT+RESTORE\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer2,"OK");
	while(strx==NULL){
		Clear_Buffer2();
		Send_Buffer2("AT+RESTORE\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer2,"OK");
	}
	Clear_Buffer2();
}

//AT+CWSAP="JUBIAN","A2044.33",11,3
void ESP_WIFI(void){
	char *strx;
	Clear_Buffer2();
	Send_Buffer2("AT+CWSAP=\"JUBIAN\",\"A2044.33\",11,3\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer2,"OK");
	while(strx==NULL){
		Clear_Buffer2();
		Send_Buffer2("AT+CWSAP=\"JUBIAN\",\"A2044.33\",11,3\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer2,"OK");
	}
	Clear_Buffer2();
}

//AT+CWDHCP=0,1
void ESP_DHCP(void){
	char *strx;
	Clear_Buffer2();
	Send_Buffer2("AT+CWDHCP=0,1\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer2,"OK");
	while(strx==NULL){
		Clear_Buffer2();
		Send_Buffer2("AT+CWDHCP=0,1\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer2,"OK");
	}
	Clear_Buffer2();
}

//AT+CIPAP="192.168.4.33"
void ESP_IPSET(void){
	char *strx;
	Clear_Buffer2();
	Send_Buffer2("AT+CIPAP=\"192.168.4.33\"\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer2,"OK");
	while(strx==NULL){
		Clear_Buffer2();
		Send_Buffer2("AT+CIPAP=\"192.168.4.33\"\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer2,"OK");
	}
	Clear_Buffer2();
}

//AT+CIPSTART="UDP","192.168.4.33",5000,5000
void ESP_UDP(void){
	char *strx;
	Clear_Buffer2();
	Send_Buffer2("AT+CIPSTART=\"UDP\",\"192.168.4.33\",5000,5000\r\n");
	LL_mDelay(500);
	strx=strstr(Recv_Buffer2,"OK");
	while(strx==NULL){
		Clear_Buffer2();
		Send_Buffer2("AT+CIPSTART=\"UDP\",\"192.168.4.33\",5000,5000\r\n"); 
		LL_mDelay(500);
		strx=strstr(Recv_Buffer2,"OK");
	}
	Clear_Buffer2();
}

void ESP_START(void){
	ESP_AT();
	ESP_RESTORE();
	ESP_WIFI();
	ESP_DHCP();
	ESP_IPSET();
	ESP_UDP();
}

void RECV_Scan(void){
	char *strx1,*strx2,*strx3,*strd,name[100],data[100];
	float f;
	int n;
	strx1=strstr(Recv_Buffer2,"+IPD");
	while(strx1!=NULL){
		strd=strstr(strx1,"#");
		strx1=strstr(strx1,":");
		strx2=strstr(strx1+1,":");
		strx3=strstr(strx2+1,":");
		if(Recv_Buffer2[strx1-Recv_Buffer2+1]=='f'){
			for(int i=1;i<strx3-strx2;i++){
				name[i-1]=strx2[i];
			}
			for(int i=1;i<strd-strx3;i++){
				data[i-1]=strx3[i];
			}
			f=atof(data);
			Ali_Postfloat(name,f);
			memset(name,0,sizeof(name));
			memset(data,0,sizeof(data));
		}
		if(Recv_Buffer2[strx1-Recv_Buffer2+1]=='c'){
			for(int i=1;i<strx3-strx2;i++){
				name[i-1]=strx2[i];
			}
			for(int i=1;i<strd-strx3;i++){
				data[i-1]=strx3[i];
			}
			Ali_Postchar(name,data);
			memset(name,0,sizeof(name));
			memset(data,0,sizeof(data));
		}
		if(Recv_Buffer2[strx1-Recv_Buffer2+1]=='i'){
			for(int i=1;i<strx3-strx2;i++){
				name[i-1]=strx2[i];
			}
			for(int i=1;i<strd-strx3;i++){
				data[i-1]=strx3[i];
			}
			n=atoi(data);
			Ali_Postint(name,n);
			memset(name,0,sizeof(name));
			memset(data,0,sizeof(data));
		}
		strx1=strstr(strd,"+IPD");
	}
	Clear_Buffer2();
}
