/*
 * adc.h
 *
 * Created: 21.10.2012 10:24:23
 *  Author: Udo
 */ 

#ifndef ADC_H_
#define ADC_H_

#define ADC_MUX_SPG2		(0)								// ADC0 = PA0
#define ADC_MUX_TEMP		(1<<MUX0)						// ADC1 = PA1
#define ADC_MUX_POTI_TEMP	(1<<MUX1)						// ADC2 = PA2
#define ADC_MUX_SPG1		(1<<MUX2 | 1<<MUX1)				// ADC6 = PA6
#define ADC_MUX_POTI_SPG	(1<<MUX2 | 1<<MUX1 | 1<<MUX0)	// ADC7 = PA7
#define ADC_NUMBER			4	// Anzahl der Messungen pro Durchgang


void adc_Init (void);
uint16_t adc_Mess (uint8_t kanal);

#endif /* ADC_H_ */