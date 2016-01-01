/*
 * io.c
 *
 * Created: 21.10.2012 10:29:04
 *  Author: Udo
 */ 

#include <avr/io.h>
#include "io.h"

void io_Init (void)
{
	set_PORTA();
	set_DDRA();
	set_PORTB();
	set_DDRB();
}