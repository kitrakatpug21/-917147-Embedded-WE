/*
 * Timer_Introduction.c
 *
 * Created: 18-09-2022 10:43:49 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

int main(void)
{
    DDRB = 0b00001000;
	// TCCR0 = 0b00011001;
	// Timer-0: CTC Mode; Toggle Output; No Prescale
	TCCR0 = 0b00011010;
	// Timer-0: CTC Mode; Toggle Output; Prescale by 8
	OCR0 = 255;
	// Set the compare Value to TOP/MAX (255)
    while (1) 
    {
		TCNT0 = 0;
		while ((TIFR & 0b00000001)==0)
		{};// wait here till flag is set
		TIFR = 0b00000001;	
		
    }
}

