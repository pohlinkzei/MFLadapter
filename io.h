/*
 * io.h
 *
 * Created: 21.10.2012 10:10:17
 *  Author: Udo
 */ 

#ifndef IO_H_
#define IO_H_

// Port A
// 0	Output	Vol-		
// 1	Output	Next	
// 2	Output	NC
// 3	Input	DIP1		int. PU
// 4	Input	DIP3		int. PU
// 5	Output	Prev
// 6	Input	DIP4		int. PU
// 7	Input	DIP2		int. PU

#define set_DDRA()			DDRA  = 0b00100111
#define set_PORTA()			PORTA = 0b11011000
#define setPref_ein()		(PORTA |= (1<<PORTA5))
#define setPref_aus()		(PORTA &=~(1<<PORTA5))
#define setNext_ein()		(PORTA |= (1<<PORTA1))
#define setNext_aus()		(PORTA &=~(1<<PORTA1))
#define setVol_minus_ein()		(PORTA |= (1<<PORTA0))
#define setVol_minu_aus()		(PORTA &=~(1<<PORTA0))



#define DIP1_Lesen()		bit_is_set (PINA,PINA3)
#define DIP2_Lesen()		bit_is_set (PINA,PINA7)
#define DIP3_Lesen()		bit_is_set (PINA,PINA4)
#define DIP4_Lesen()		bit_is_set (PINA,PINA6)



// Port B
// 0	Output	MFL_Bus
// 1	Output	Vol+
// 2	Input	MFL_Bus_in	INT0
// 3	Input	Reset
#define set_DDRB()			DDRB  = 0b0011
#define set_PORTB()			PORTB = 0b0000

#define setVolPlus_ein()	(PORTB |= (1<<PORTB1))
#define setVolPlus_aus()	(PORTB &=~(1<<PORTB1))

#define setBus_ein()		(PORTB |= (1<<PORTB0))
#define setBus_aus()		(PORTB &=~(1<<PORTB0))

void io_Init (void);

#endif /* IO_H_ */