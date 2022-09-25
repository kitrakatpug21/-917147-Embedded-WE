/*
 * Analog to Digital Conversion.c
 *
 * Created: 03-09-2022 10:29:32 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00000000;
	ADMUX = 0b01000101;
	ADCSRA = 0b10000110;
	DDRC = 0b11111111;
	DDRD = 0b00000011;
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
		// now we will wait for the flag to be Set to 1
		while ((ADCSRA & 0b00010000) == 0)
		{
			// wait here till conversion is complete
		}
		PORTC = ADCL;
		PORTD = ADCH;
		_delay_ms(10);
    }
}

