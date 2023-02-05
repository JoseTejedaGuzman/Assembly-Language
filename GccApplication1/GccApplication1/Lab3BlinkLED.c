/*
 * GccApplication1.c
 *
 * Created: 9/19/2022 3:00:06 PM
 * Author : jose_
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void){
	
	DDRD = 0b01110000;
	
	EICRA = (1<<ISC01)|(0<<ISC00);
	EIMSK = (1<<INT0);
	sei();
	while (1) {
		
			PORTD = 0b00010000;
			_delay_ms (500);
			PORTD = 0b00100000;
			_delay_ms(500);
			PORTD = 0b01000000;
			_delay_ms (500);
			
	}
	

}

ISR(INT0_vect)
{
	PORTD = 0b00000000;
	_delay_ms(1000);

}




