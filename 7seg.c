/*
 * _7seg.c
 *
 * Created: 8/19/2023 12:38:34 PM
 *  Author: safifi
 */ 

#include "7seg.h"
#include "7seg_cfg.h"



void SevenSeg_init(void){
	SEVEN_SEG_PORT_INIT();
}
/*
0 ==> 


*/
// common cathode
uint8_t ss_data [] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};
void SevenSeg_write(uint8_t data, uint8_t ss_num){
	SS_EN1(1);SS_EN2(1);SS_EN3(1);SS_EN4(1);SS_EN5(1);SS_EN6(1);
	// since i have more than 2 seven seg therefore if you will enable 1 and the rest should be switched off
	switch(ss_num){
		case 1:  SS_EN1(0); break;
		case 2:  SS_EN2(0); break;
		////////////////0/////////
		case 3:  SS_EN3(0); break;
		case 4:  SS_EN4(0); break;
		////////////////0////////
		case 5:  SS_EN5(0); break;
		case 6:  SS_EN6(0); break;
	}
	SS_PORT = ss_data[data];
}
