/*
 * Keypad Interface.c
 *
 * Created: 11-09-2022 10:37:05 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00001111; // PA0 to PA3 are Output, PA4 to PA7 are Input
	DDRC = 0b00001111; // LED AT PC0 to PC3
	while (1) 
    {
		// LOGIC FOR FIRST ROW OF KEYPAD
		PORTA |= 0b00000001; // Assign +5V to PA0 
		PORTA &= ~(0b00001110); // Assign 0V to PA1, PA2 and PA3 
		//(1,2,3 can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-1 is pressed
			PORTC = 0b00000001;
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-2 is pressed
			PORTC = 0b00000010;
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-3 is pressed
			PORTC = 0b00000011;
		}
		_delay_ms(100);

		// LOGIC FOR SECOND ROW OF KEYPAD
		PORTA |= 0b00000010; // Assign +5V to PA1
		PORTA &= ~(0b00001101); // Assign 0V to PA0, PA2 and PA3
		//(4,5,6 can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-4 is pressed
			PORTC = 0b00000100;
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-5 is pressed
			PORTC = 0b00000101;
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-6 is pressed
			PORTC = 0b00000110;
		}
		_delay_ms(100);
		
		// LOGIC FOR THIRD ROW OF KEYPAD
		PORTA |= 0b00000100; // Assign +5V to PA2
		PORTA &= ~(0b00001011); // Assign 0V to PA0, PA1 and PA3
		//(7,8,9 can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-7 is pressed
			PORTC = 0b00000111;
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-8 is pressed
			PORTC = 0b00001000;
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-9 is pressed
			PORTC = 0b00001001;
		}
		_delay_ms(100);
		
		// LOGIC FOR FOURTH ROW OF KEYPAD
		PORTA |= 0b00001000; // Assign +5V to PA3
		PORTA &= ~(0b00000111); // Assign 0V to PA0, PA1 and PA2
		//(*,0,# can be input in this case)
		if (PINA & 0b00100000)
		{
			// if +5V logic is found at PA5, button-* is pressed
			PORTC = 0b000001100;
		}
		else if (PINA & 0b01000000)
		{
			// if +5V logic is found at PA6, button-0 is pressed
			PORTC = 0b00000000;
		}
		else if (PINA & 0b10000000)
		{
			// if +5V logic is found at PA7, button-# is pressed
			PORTC = 0b00001111;
		}
		_delay_ms(100);
    }
}

