/*
 * timer.c
 *
 * Created: 21.10.2012 10:42:04
 *  Author: Udo
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include "io.h"
#include "timer.h"
uint16_t us100;



void timer0_Init(void)
{
	// Zeitgeber 25ms für Zeitsteuerung und einige Entprellungen
	// 100 us, Teiler 64 , 156 bei 1 MHz
	
	TCCR0A = 0x00;
	TCCR0B = 0x00;
	us100 = 0;
	OCR0A = 156;
	TIMSK0  = (1<<OCIE0A);
	TCCR0B = (1<<CS00) | (1<<CS00); //teiler 64
}	
ISR(TIM0_COMPA_vect){
	us100++;
}	
	
void timer1_Init(void)
{
	// Zeitgeber 10ms für Tasteentprellung
	// 10 ms, Teiler 8, 0xFB1E bei 1 MHz
	TCCR1A = 0x00;
	TCCR1B = 0x00;	
	TCCR1C = 0x00;
	TCNT1  = TIMER1_WERT;
	TIMSK1  = (1<<TOIE1);
	TCCR1B = (1<<CS11);
}
ISR(TIM1_OVF_vect)
{
/*	static uint8_t	ct0;
	static uint8_t	ct1;
	static uint8_t	rpt;
	uint8_t 		i;
	
	
	TCNT1 = TIMER1_WERT;	// Zurücksetzen
	
	// Entprellen
	// Tasten entprellen
	i = key_state ^ (~KEY_PIN);						// key changed ?
	ct0 = ~( ct0 & i );                             // reset or count ct0
	ct1 = ct0 ^ (ct1 & i);                          // reset or count ct1
	i &= ct0 & ct1;                                 // count until roll over ?
	key_state ^= i;                                 // then toggle debounced state
	key_press |= key_state & i;                     // 0->1: key press detect
	
	if ((key_state & REPEAT_MASK) == 0)				// check repeat function
	{
		rpt = REPEAT_START;							// start delay
	}	
	if (--rpt == 0)
	{
		rpt = REPEAT_NEXT;                          // repeat delay
		key_rpt |= key_state & REPEAT_MASK;
	}	*/	
}


// 	if (SH_ENTPRELL_EIN == Sh.Entprellstatus)
// 	{
// 		if (Sh.Entprellzeit > 0)
// 		{
// 			Sh.Entprellzeit --;
// 		}
// 	}

    
    

    
    

