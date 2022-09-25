/*
 * Motor Interfacing.c
 *
 * Created: 21-08-2022 10:36:25 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRC = 0b11000011;
	while (1)
	{
		PORTC = 0b00000001;// motor 1 is clockwise, motor 2 is off
		_delay_ms(3000);
		PORTC = 0b01000000;// motor 2 is clockwise, motor 1 is off
		_delay_ms(3000);
		PORTC = 0b01000001;// both motor is clockwise
		_delay_ms(3000);
		PORTC = 0b00000000;// both motor turned off
		_delay_ms(3000);
		PORTC = 0b00000010;// motor 1 is anti-clockwise, motor 2 is off
		_delay_ms(3000);
		PORTC = 0b10000000;// motor 2 is anti-clockwise, motor 1 is off
		_delay_ms(3000);
		PORTC = 0b10000010;// both motor is anti-clockwise
		_delay_ms(3000);
		PORTC = 0b00000000;// both motor turned off
		_delay_ms(3000);
	}
}

/*
// For Unidirectional Motors
int main(void)
{
    DDRC = 0b01000001;
    while (1) 
    {
	    PORTC = 0b00000001;// motor 1 is turned on
		_delay_ms(3000);
	    PORTC = 0b01000000;// motor 2 is turned on
	    _delay_ms(3000);
	    PORTC = 0b01000001;// both motor turned on
	    _delay_ms(3000);
	    PORTC = 0b00000000;// both motor turned off
		_delay_ms(3000);
    }
}
*/
