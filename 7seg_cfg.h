/*
 * _7seg_cfg.h
 *
 * Created: 8/19/2023 12:38:54 PM
 *  Author: khater
 */ 


#ifndef SEG_CFG_H_
#define SEG_CFG_H_

#include "generic_macros_header.h"

#define SEVEN_SEG_PORT_INIT() DDRC = 0xff; SETBIT(DDRD,0); SETBIT(DDRD,1);SETBIT(DDRD,2); SETBIT(DDRD,3);SETBIT(DDRD,4); SETBIT(DDRD,5);SETBIT(DDRD,6);
#define SS_PORT PORTC

#define SS_EN1(x) if(x == 0) CLRBIT(PORTD, PD0); else SETBIT(PORTD, PD0); // first 7SEG
#define SS_EN2(x) if(x == 0) CLRBIT(PORTD, PD1); else SETBIT(PORTD, PD1);
////////////////////////////////////////////////////////////////////////
#define SS_EN3(x) if(x == 0) CLRBIT(PORTD, PD2); else SETBIT(PORTD, PD2); // second 7SEG
#define SS_EN4(x) if(x == 0) CLRBIT(PORTD, PD3); else SETBIT(PORTD, PD3);
///////////////////////////////////////////////////////////////////////
#define SS_EN5(x) if(x == 0) CLRBIT(PORTD, PD4); else SETBIT(PORTD, PD4); // 3rd 7SEG
#define SS_EN6(x) if(x == 0) CLRBIT(PORTD, PD5); else SETBIT(PORTD, PD5);
///////////////////////////////////////////////////////////////////////
#endif /* 7SEG_CFG_H_ */