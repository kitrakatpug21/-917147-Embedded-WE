/*
 * 7Segment Display.c
 *
 * Created: 07-08-2022 10:13:07 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRC = 0b01111111;// PC6 to PC0 as OUTPUT
	DDRD = 0b01111111;// PD6 to PD0 as OUTPUT
	while (1) 
    {
		PORTD = 0b00111111; //0 at Port D
		PORTC = 0b00111111; //0
		_delay_ms(1000);// generate precise 1 second delay
		PORTC = 0b00000110; //1
		_delay_ms(1000);
		PORTC = 0b01011011; //2
		_delay_ms(1000);
		PORTC = 0b01001111; //3
		_delay_ms(1000);
		PORTC = 0b01100110; //4
		_delay_ms(1000);
		PORTC = 0b01101101; //5
		_delay_ms(1000);
		PORTC = 0b01111101; //6
		_delay_ms(1000);
		PORTC = 0b00000111; //7
		_delay_ms(1000);
		PORTC = 0b01111111; //8
		_delay_ms(1000);
		PORTC = 0b01101111; //9
		_delay_ms(1000);
		
		PORTD = 0b00000110; //1 at Port D
		PORTC = 0b00111111; //0
		_delay_ms(1000);// generate precise 1 second delay
		PORTC = 0b00000110; //1
		_delay_ms(1000);
		PORTC = 0b01011011; //2
		_delay_ms(1000);
		PORTC = 0b01001111; //3
		_delay_ms(1000);
		PORTC = 0b01100110; //4
		_delay_ms(1000);
		PORTC = 0b01101101; //5
		_delay_ms(1000);
		PORTC = 0b01111101; //6
		_delay_ms(1000);
		PORTC = 0b00000111; //7
		_delay_ms(1000);
		PORTC = 0b01111111; //8
		_delay_ms(1000);
		PORTC = 0b01101111; //9
		_delay_ms(1000);
    }
}

