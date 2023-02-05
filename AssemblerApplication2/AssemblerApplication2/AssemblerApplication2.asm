.include "m328def.inc" 
.org 0x0000
           RJMP begin; jump to begin 
.ORG 0X0002 
			RJMP Interrupt;
.org 0x0034 
 begin:    CLI
           LDI    R16,low(RAMEND)
		   OUT    SPL,R16
           LDI    R16,high(RAMEND)
		   OUT    SPH, R16   
		                
			LDI R16, (0<<ISC01)|(1<<ISC00)
			STS EICRA, R16

			LDI R16, (1<<INT0)
			OUT EIMSK, R16

		   LDI    R16,0xFF 
           OUT    DDRB, R16 

		   LDI		R16, 0x00
		   OUT		DDRD, R16

		   sei
		     
main:
           LDI    R16,0xFF 
           OUT    PORTB, R16

           RCALL  Delay

		   LDI	  R16, 0x00
           OUT    PORTB, R16

           RCALL  Delay
		   RJMP   main

Interrupt: 

		   LDI    R20, 0x0000
		   OUT    PORTD, R20

		   RCALL Delay

		   RETI


Delay:     LDI    R17, 0x9E
		   LDI    R18, 0x9E
		   LDI    R19, 0x9E

loop:      DEC    R17 
           BRNE   loop 
		   
loop2:	   LDI R17, 0x9E
		   DEC R18
		   BRNE loop

loop3:		  LDI R18, 0x9E
		  DEC R19
		  BRNE   loop
		               
          RET  

