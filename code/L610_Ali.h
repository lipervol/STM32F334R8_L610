#ifndef __L610_Ali_
#define __L610_Ali_

#include "L610_init.h"

void Ali_Link(void);
void Ali_Auth(void);
void Ali_Conn(void);
void Ali_Disconn(void);
void Ali_Subget(void);
void Ali_Dissubget(void);
void Ali_Pub(char p[]);
void Ali_Postchar(char p[],char value[]);
void Ali_Postfloat(char p[],float value);
void Ali_Postint(char p[],int value);

#endif
