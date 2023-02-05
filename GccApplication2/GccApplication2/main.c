/*
 * GccApplication2.c
 *
 * Created: 9/20/2022 3:15:26 PM
 * Author : jose_
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void){
	
	
	DDRD = 0xFF;
	PORTD = 0xFF;
	TCCR1B = (1 << CS02) | (0 << CS01) | (0 << CS00);
	TIMSK1 = 0b00000001;
	
	sei();
	while (1){};

	

}

ISR(TIMER1_OVF_vect)
{
	PORTD ^= 0xFF;

}


