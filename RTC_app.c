/*
 * RTC_app.c
 *
 * Created: 9/24/2023 1:14:24 AM
 * Author : khater
 */ 

#include "7seg.h"
#include "LCD.h"
#include "keypad.h"
#include "timer.h"
volatile uint8_t minutes= 0;
volatile uint8_t seconds = 0;
volatile uint8_t hours = 0;
volatile uint8_t flag = 0; // flag to enter the interrupt for time adjust
void set_cloc_param(uint8_t * param, uint8_t max);
int main(void)
{
    SevenSeg_init();
	LCD_init();
	keypad_init();
	/*
		C.C = 1024/16 usec => 1024/16 usec * OCR = 10000 usec => OCR =	156.2
	*/
	timer0_ctc_init(78); // 5msec to make the 7seg stop blinking we decreased the msec of the timer interrupt therefore better quality
	
	CLRBIT(DDRB, PB1); // PB1 is output
	CLRBIT(DDRB, PB2); // PB2 is output
	CLRBIT(DDRB, PB3); // PB3 is output
	SETBIT(PORTB, 1);
	SETBIT(PORTB, 2);
	SETBIT(PORTB, 3);
	
	SETBIT(MCUCR, ISC11); // falling edge triggers int
	SETBIT(GICR, INT2); // enable INT2 interrupt
	SETBIT(SREG, 7);
	

    while (1){
		// 
		switch(flag){
			case 1: set_cloc_param(& seconds, 59); break;
			case 2: set_cloc_param(& minutes, 59); break;
			case 3: set_cloc_param(& hours, 23); break;
		}
		/////////////////////////
		if(seconds == 60){
			minutes ++;
			seconds = 0;
				
		}
		//////////////////////////
		if(minutes == 60){
			hours ++;
			minutes = 0;
		}
		//////////////////////////
		if(hours > 23){
			hours = 0;
			minutes = 0;
			seconds = 0;
		}
		//////////////////////////
		
		LCD_write_command(1); // 0x80 -> makes you start from the begining but (1) clears everything therefore LCD blinks
		LCD_write_num(hours);
		LCD_write_char(':');
		LCD_write_num(minutes);
		LCD_write_char(':');
		LCD_write_num(seconds);
		_delay_ms(300);
		
		
	}

	
		
}


ISR(INT2_vect){
	flag++;
	if(flag == 4){
		flag =0;
	}	
		
}




ISR(TIMER0_COMP_vect){
	static uint16_t counter = 0;
	if(flag != 0){
		counter = 0;
	}
	counter ++;
	
	static seven_seg_counter = 0; // switch case for the hours min or seconds 7seg
	////////////////////////////
	seven_seg_counter ++;
	/////////////////////
	switch (seven_seg_counter){
		case 1:SevenSeg_write(seconds / 10, 1);break;
		case 2:SevenSeg_write(seconds % 10, 2);break;
		case 3:SevenSeg_write(minutes / 10, 3);break;
		case 4:SevenSeg_write(minutes % 10, 4);break;
		case 5:SevenSeg_write(hours / 10, 5);break;
		case 6:SevenSeg_write(hours % 10, 6); seven_seg_counter =0; break;
	}
	if(counter == 199){
		seconds ++;
		counter = 0;

	}
	

}

void set_cloc_param(uint8_t * param, uint8_t max){
	if(READBIT(PINB, PB1) == 0){
		(* param) ++ ;
		if((*param) > max){
			*param =0;
		}
		while(READBIT(PINB, PB1) == 0){}
			
	}
	else if(READBIT(PINB, PB3) == 0){
		(* param) -- ;
		if((*param) == 255){
			*param = max;
		}
		while(READBIT(PINB, PB3) == 0){}
	}
	
	
}