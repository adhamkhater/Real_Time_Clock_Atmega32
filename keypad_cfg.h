/*
 * keypad_cfg.h
 *
 * Created: 8/19/2023 10:57:32 AM
 *  Author: Khater
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/* PC0-PC3  output connected to A,B,C,D */

#define KEYPAD_PORT_INIT()  DDRB = 0b00001111; \
						  PORTB =0b11111111;

#define KEYPAD_A(x) if(x == 0) CLRBIT(PORTB, PB0); else SETBIT(PORTB, PB0);
#define KEYPAD_B(x) if(x == 0) CLRBIT(PORTB, PB1); else SETBIT(PORTB, PB1);
#define KEYPAD_C(x) if(x == 0) CLRBIT(PORTB, PB2); else SETBIT(PORTB, PB2);
#define KEYPAD_D(x) if(x == 0) CLRBIT(PORTB, PB3); else SETBIT(PORTB, PB3);

#define KEYPAD_1  READBIT(PINB,PB4)
#define KEYPAD_2  READBIT(PINB,PB5)
#define KEYPAD_3  READBIT(PINB,PB6)
#define KEYPAD_4  READBIT(PINB,PB7) 

#endif /* KEYPAD_CFG_H_ */