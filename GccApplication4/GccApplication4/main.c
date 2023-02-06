/*
 * GccApplication4.c
 *
 * Created: 10/10/2022 3:37:41 PM
 * Author : jose_
 */ 

#include <avr/io.h>

int clear;

int main(void){
	
	DDRD = 0xFF;
	ADCSRA = 0b10000111;
	ADMUX = 0b01000000;
    
    while (1) 
    {
			ADCSRA |= (1<<ADSC);
			while(ADCSRA & (1<<ADSC));
			PORTD = ADCL;
			clear = ADCH;
    }
}

