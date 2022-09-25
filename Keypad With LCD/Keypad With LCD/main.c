/*
 * Keypad With LCD.c
 *
 * Created: 11-09-2022 11:11:26 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd4bit.h"

int main(void)
{
    DDRA = 0b00001111; // PA0 to PA3 are Output, PA4 to PA7 are Input
	DDRD = 0b11111111; // LCD AT PORT-D (4bitMode)
	lcd_inititalize();
	while (1) 
    {
		// LOGIC FOR FIRST ROW OF KEYPAD
		PORTA |= 0b00000001; // Assign +5V to PA0 
		PORTA &= ~(0b00001110); // Assign 0V to PA1, PA2 and PA3 
		//(1,2,3 can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-1 is pressed
			// debouncing Logic
			while((PINA & 0b00100000))
			{
				// wait until button is released
			}
			print(0x80,"1");
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-2 is pressed
			// debouncing Logic
			while((PINA & 0b01000000))
			{
				// wait until button is released
			}
			print(0x80,"2");
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-3 is pressed
			// debouncing Logic
			while((PINA & 0b10000000))
			{
				// wait until button is released
			}
			print(0x80,"3");
		}
		_delay_ms(100);

		// LOGIC FOR SECOND ROW OF KEYPAD
		PORTA |= 0b00000010; // Assign +5V to PA1
		PORTA &= ~(0b00001101); // Assign 0V to PA0, PA2 and PA3
		//(4,5,6 can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-4 is pressed
			// debouncing Logic
			while((PINA & 0b00100000))
			{
				// wait until button is released
			}
			print(0x80,"4");
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-2 is pressed
			// debouncing Logic
			while((PINA & 0b01000000))
			{
				// wait until button is released
			}
			print(0x80,"5");
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-3 is pressed
			// debouncing Logic
			while((PINA & 0b10000000))
			{
				// wait until button is released
			}
			print(0x80,"6");
		}
		_delay_ms(100);
		
		// LOGIC FOR THIRD ROW OF KEYPAD
		PORTA |= 0b00000100; // Assign +5V to PA2
		PORTA &= ~(0b00001011); // Assign 0V to PA0, PA1 and PA3
		//(7,8,9 can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-7 is pressed
			// debouncing Logic
			while((PINA & 0b00100000))
			{
				// wait until button is released
			}
			print(0x80,"7");
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-2 is pressed
			// debouncing Logic
			while((PINA & 0b01000000))
			{
				// wait until button is released
			}
			print(0x80,"8");
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-3 is pressed
			// debouncing Logic
			while((PINA & 0b10000000))
			{
				// wait until button is released
			}
			print(0x80,"9");
		}
		_delay_ms(100);
		
		// LOGIC FOR FOURTH ROW OF KEYPAD
		PORTA |= 0b00001000; // Assign +5V to PA3
		PORTA &= ~(0b00000111); // Assign 0V to PA0, PA1 and PA2
		//(*,0,# can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-* is pressed
			// debouncing Logic
			while((PINA & 0b00100000))
			{
				// wait until button is released
			}
			print(0x80,"*");
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-2 is pressed
			// debouncing Logic
			while((PINA & 0b01000000))
			{
				// wait until button is released
			}
			print(0x80,"0");
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-3 is pressed
			// debouncing Logic
			while((PINA & 0b10000000))
			{
				// wait until button is released
			}
			print(0x80,"#");
		}
		_delay_ms(100);
    }
}

