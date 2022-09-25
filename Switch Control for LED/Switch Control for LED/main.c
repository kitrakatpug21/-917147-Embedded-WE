/*
 * Switch Control for LED.c
 *
 * Created: 14-08-2022 11:05:23 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b00000001; // led at PC0
	DDRA = 0b00000000; // Whole PORTA is an Input PORT
	while (1) 
    {
		if (PINA & 0b10000000) // PA7
		{
			// LED will turn ON
			PORTC = 0b00000001; // MAKE PC0 as HIGH
		}
		else
		{
			// LED will turn OFF
			PORTC = 0b00000000; // MAKE PC0 as LOW
		}
    }
}

