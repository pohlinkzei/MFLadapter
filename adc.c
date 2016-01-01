/*
 * adc.c
 *
 * Created: 21.10.2012 10:28:06
 *  Author: Udo
 */ 

#include <avr/io.h>
#include "adc.h"
#include "io.h"

// Der ADC braucht pro Messung 77 ADC-clocks (125 kHz) = 0,62 msec;

void adc_Init (void)
{
	ADMUX = 0x00;							// VCC (5V) als Referenz
	ADCSRA = 0x00;							// abgeschaltet
	ADCSRA |= ( (1<<ADPS1) | (1<<ADPS0) );	// Vorteiler auf 8 (125 kHz)
}

uint16_t adc_Mess (uint8_t kanal)
{
	uint8_t 	i;
	uint16_t	result;
	
	adc_Init();
	ADMUX	|= kanal;		// Kanal wählen
	ADCSRA	|= (1<<ADEN);	// ADC Einschalten
	
	// Dummy-Wandlung vornehmen und verwerfen
	ADCSRA |= (1<<ADSC);	// Wandlung beginnen
	// Auf Aschluss der Wandlung warten (ADSC = 0)
	loop_until_bit_is_clear (ADCSRA, ADSC);
	
	// ADC_NUMBER Messungen durchführen und Mittelwert bilden
	result = 0;
	for (i = 0; i < ADC_NUMBER; i++)
	{
		ADCSRA |= (1<<ADSC);		// Wandlung beginnen
		loop_until_bit_is_clear (ADCSRA, ADSC);	// Auf Abschluss warten
		result += ADCL;			// aufaddieren
		result += (ADCH<<8);
	}
	adc_Init();				// ADC ausschalten
	result /= ADC_NUMBER;	// Mittelwert bilden
	return result;
}
