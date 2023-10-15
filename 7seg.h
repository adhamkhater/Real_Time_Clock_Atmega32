/*
 * _7seg.h
 *
 * Created: 8/19/2023 12:38:43 PM
 *  Author: safifi
 */ 


#ifndef SEG_H_
#define SEG_H_

#include "generic_macros_header.h"

void SevenSeg_init(void);
void SevenSeg_write(uint8_t data, uint8_t ss_num);


#endif /* 7SEG_H_ */