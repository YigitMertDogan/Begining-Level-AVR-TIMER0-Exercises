						///////////////////////////// TIMER 0 EXERCISES  //////////////////////////////

// Analyse your code from PB0 Pin with  osiloscope or logic analyzer after you finished writing the code!
// It will help you to understand this topic!
// For more Information, you can get contact with me
// https://worldclasslab.wordpress.com/

#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>               // Library for Delay Commands

#ifndef F_CPU
#define F_CPU			16000000UL
#endif

int main(void)
{
	DDRB |= (1<<PB0);                 // Set The PB0 Pin as Output
	TCCR0B |= (1<<CS00);			  // Set The Prescaler as CLK/1024
	TCCR0B |= (1<<CS02);				
	TIMSK0 |= (1<<TOIE0);			  // Enabled The Timer-Counter0 Overflow Interrupt Register
	
	sei();							  // Enabled The Global Interrupt

    while (1) 
    {
		
    }
}

ISR (TIMER0_OVF_vect)
{
	PORTB ^= (1<<PB0);				  // Toggle The PB0 Pin as ON and OFF
}





