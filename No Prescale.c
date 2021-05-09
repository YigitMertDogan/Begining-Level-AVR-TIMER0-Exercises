						///////////////////////////// TIMER 0 EXERCISES  //////////////////////////////

// Analyse your code from PB4 Pin with  osiloscope or logic analyzer after you finished writing the code!
// It will help you to understand this topic!
// For more Information, you can get contact with me
// https://worldclasslab.wordpress.com/


#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef F_CPU		
#define F_CPU		16000000UL
#endif
#include <util/delay.h>               // Library for Delay Commands

int main(void)
{
	DDRB |= (1<<PB4);				  // Set The PB4 Pin as Output		
	TIMSK0 |= (1<<TOIE0);		      // Enabled The Timer-Counter0 Overflow Interrupt Register
	TCCR0B |= (1<<CS00);              // Set the Timer0 as No Prescale On The Clock to Get Fastest
	
	sei();                            // Enabled The Global Interrupts
    while (1)  
    {

    }
}

ISR (TIMER0_OVF_vect)				  //	Selected Timer0 Overflow With This ISR Function
{
	PORTB ^= (1<<PB4);                // Toggle The PB4 Pin, When The Everytime Overflow Occurs.
}


