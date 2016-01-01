/*
 * interrupt.c
 *
 * Created: 30.05.2015 13:58:46
 *  Author: Hubert
 */ 
#include <avr/io.h>
#include "io.h"

void interrupt_init(){
	MCUCR |= (1<<ISC00);
	GIMSK |= (1<<INT0);
}
/*
extern volatile uint16_t us100;
extern volatile uint32_t mfl_data;
*/

/*
ISR(INT0_vect){
	// lesen des MFL busses
	// 10ms high
	// 5ms low
	// 4byte data
	// 2ms high, 1ms low = high
	// 1ms high, 1ms low = low
	uint16_t tim = us100;
	us100 = 0;
	if(tim > 90 && tim < 110){// enable puls
		;
	}else if(tim > 45 && tim < 55){ //enable puls
		mfl_data = 0x00000000;
	}else if(tim > 18 && tim < 22){ //high
		mfl_data & 0x80000000;
		mfl_data >> 1;
		
	}else if(tim > 9 && tim < 11){	//low
		if(PORTB & (1<<PORTB2)){
			mfl_data >> 1;
		}else{
			;
		}
	}
}
*/