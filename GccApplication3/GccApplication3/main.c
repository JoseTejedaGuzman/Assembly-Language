/*
 * GccApplication3.c
 *
 * Created: 9/26/2022 2:56:31 PM
 * Author : jose_
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void){
	
	
	DDRB = 0xFF;
	
	TCNT1 = 0;
	OCR1A = 0x3ff;
	
	TCCR1A = 0b11000011;
	TCCR1B = 0b00001001;
	//TIMSK1 = (1<<OCIE1A);//0b00000100;
	//TIMSK1|= (1<<OCIE1A);
	
	sei();
    while (1) {
		for (int i = 0; i <= 0x03ff; i ++){
			OCR1A = OCR1A-i;
			_delay_ms(50);
			}
            OCR1A=0x3ff;
	}

}

