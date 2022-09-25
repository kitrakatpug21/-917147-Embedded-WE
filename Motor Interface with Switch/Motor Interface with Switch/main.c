/*
 * Motor Interface with Switch.c
 *
 * Created: 21-08-2022 10:51:39 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11000011;// motor
	DDRA = 0b00000000;// switch
	while (1) 
    {
		if (PINA & (0b00000001))
		{
			// CLOCK WISE BOTH MOTOR
			PORTC = 0b01000001;
		}
		else if (PINA & (0b00000010))
		{
			// Anti-CLOCK WISE BOTH MOTOR
			PORTC = 0b10000010;
		}
		else if (PINA & (0b00000100))
		{
			// MOTOR-1 CLOCKWISE MOTOR-2 ANTI-CLOCKWISE
			PORTC = 0b10000001;
		}
		else if (PINA & (0b00001000))
		{
			// MOTOR-1 ANTI-CLOCKWISE MOTOR-2 CLOCKWISE
			PORTC = 0b01000010;
		}
		else
		{
			PORTC = 0b00000000;
		}
    }
}

