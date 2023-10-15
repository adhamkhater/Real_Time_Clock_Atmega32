/*
 * timer.c
 *
 * Created: 8/25/2023 11:41:55 AM
 *  Author: Khater
 */ 
#include "timer.h"

void timer0_normal_init(void){
	TCCR0 = 0b001; // no prescale
	TIMSK = 1; // enable ovf irq
	SETBIT(SREG, 7); // enable global irq
}

void timer0_ctc_init(uint8_t count){
	TCCR0 = 0b101; // 1024 - prescale
	SETBIT(TCCR0,WGM01); // ctc mode
	OCR0 = count;
	TIMSK = 0b10; // enable ctc irq
	SETBIT(SREG, 7); // enable global irq	
}

void timer0_frq_gen_init(uint8_t count){
	TCCR0 = 0b01; // no-prescaler
	SETBIT(TCCR0,COM00); // toggle pb3
	SETBIT(TCCR0,WGM01); // ctc mode
	SETBIT(DDRB, 3);
	OCR0 = count;
	//TIMSK = 0b10; // enable ctc irq
	//SETBIT(SREG, 7); // enable global irq
}