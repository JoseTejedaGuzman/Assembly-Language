/*
 * GccApplication5.c
 *
 * Created: 10/11/2022 2:52:22 PM
 * Author : jose_
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int clear;

int main(void){
    
	DDRB = 0xFF;
	
	TCCR1A = 0b11000110;
	TCCR1B = 0b00001001;
	
	ADCSRA = 0b10000111;
	ADMUX = 0b01000000;
	TCNT1 = 0;
	OCR1A = 0;
	OCR1B = 0;
	OCR2A = 0;
	
	sei();
	
    while (1) {
		
		ADCSRA |= (1<<ADSC);
		while(ADCSRA & (1<<ADSC));
		OCR1A = ADC;
		OCR1B = ADC;
		OCR2A = ADC;
		clear = ADCH;
		
		//for (int i = 0; i <= 0x03ff; i ++){
				//OCR1A = OCR1A-1;
			//_delay_ms(50); }
			
		//OCR1A=0x3ff;	

	}
}

ISR(TIMER1_COMPA_vect)
{
	if(PORTB == 0xff){
		OCR1A = ADC * 64;
		OCR1B = ADC * 64;
		OCR2A = ADC * 64;
	}
	else
	 {
		 OCR1A = 100;
		 OCR1B = 200;
		 OCR2A = 200;
}
}


