/*
 * mflAdapter.c
 *
 * Created: 30.05.2015 11:20:38
 *  Author: Hubert
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "io.h"
#include "irsnd.h"
#include "irmp.h"

static void
timer1_init (void)
{
#if defined (__AVR_ATtiny45__) || defined (__AVR_ATtiny85__)                // ATtiny45 / ATtiny85:

#if F_CPU >= 16000000L
    OCR1C   =  (F_CPU / F_INTERRUPTS / 8) - 1;                              // compare value: 1/15000 of CPU frequency, presc = 8
    TCCR1   = (1 << CTC1) | (1 << CS12);                                    // switch CTC Mode on, set prescaler to 8
#else
    OCR1C   =  (F_CPU / F_INTERRUPTS / 4) - 1;                              // compare value: 1/15000 of CPU frequency, presc = 4
    TCCR1   = (1 << CTC1) | (1 << CS11) | (1 << CS10);                      // switch CTC Mode on, set prescaler to 4
#endif

#else                                                                       // ATmegaXX:
    OCR1A   =  (F_CPU / F_INTERRUPTS) - 1;                                  // compare value: 1/15000 of CPU frequency
    TCCR1B  = (1 << WGM12) | (1 << CS10);                                   // switch CTC Mode on, set prescaler to 1
#endif

#ifdef TIMSK1
    TIMSK1  = 1 << OCIE1A;                                                  // OCIE1A: Interrupt by timer compare
#else
    TIMSK   = 1 << OCIE1A;                                                  // OCIE1A: Interrupt by timer compare
#endif
}


int
main (void)
{
  IRMP_DATA irmp_data;
 
  irmp_init();                // initialize irmp
  irsnd_init();               // initialize irsnd
  timer1_init();               // initialize timer
  sei ();                     // enable interrupts
 
  for (;;)
  {
    if (irmp_get_data (&irmp_data))
    {
      irmp_data.flags = 0;    // reset flags!
      irsnd_send_data (&irmp_data, 0);
    }
  }
}


#ifdef TIM1_COMPA_vect                                                      // ATtiny84
#define COMPA_VECT  TIM1_COMPA_vect
#else
#define COMPA_VECT  TIMER1_COMPA_vect                                       // ATmega
#endif

ISR(COMPA_VECT)                                                             // Timer1 output compare A interrupt service routine, called every 1/15000 sec
{
  if (! irsnd_ISR())          // call irsnd ISR
  {                           // if not busy...
      irmp_ISR();             // call irmp ISR
  }
  // call other timer interrupt routines...
}