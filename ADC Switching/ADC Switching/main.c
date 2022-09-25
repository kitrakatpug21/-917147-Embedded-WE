/*
 * ADC Switching.c
 *
 * Created: 03-09-2022 11:20:19 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00000000;
	ADMUX = 0b01000011;
	ADCSRA = 0b10000110;
	DDRC = 0b11111111;
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
		// now we will wait for the flag to be Set to 1
		while ((ADCSRA & 0b00010000) == 0)
		{
			// wait here till conversion is complete
		}
		if (ADC >=0 && ADC <= 10)
		{
			PORTC = 0b00000000;
		}
		else if (ADC >=11 && ADC <= 59)
		{
			PORTC = 0b00001100;
		}
		else if (ADC >=60 && ADC <= 99)
		{
			PORTC = 0b00001110;
		}
		else if (ADC >=100 && ADC <= 199)
		{
			PORTC = 0b00000001;
		}
		else if (ADC >=200 && ADC <= 299)
		{
			PORTC = 0b00000010;
		}
		else if (ADC >=300 && ADC <= 399)
		{
			PORTC = 0b00000011;
		}
		else if (ADC >=400 && ADC <= 499)
		{
			PORTC = 0b00000100;
		}
		else if (ADC >=500 && ADC <= 599)
		{
			PORTC = 0b00000101;
		}
		else if (ADC >=600 && ADC <= 699)
		{
			PORTC = 0b00000110;
		}
		else if (ADC >=700 && ADC <= 799)
		{
			PORTC = 0b00000111;
		}
		else if (ADC >=800 && ADC <= 899)
		{
			PORTC = 0b00001000;
		}
		else if (ADC >=900 && ADC <= 999)
		{
			PORTC = 0b00001001;
		}
		else if (ADC >=1000)
		{
			PORTC = 0b00001111;
		}
    }
}

