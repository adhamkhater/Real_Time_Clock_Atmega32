/*
 * timer.h
 *
 * Created: 8/25/2023 11:42:06 AM
 *  Author: Khater
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "generic_macros_header.h"
/* no prescaler, normal mode , IRQ enable */
void timer0_normal_init(void);

void timer0_ctc_init(uint8_t);

void timer0_frq_gen_init(uint8_t count);





#endif /* TIMER_H_ */