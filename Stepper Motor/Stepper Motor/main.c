/*
 * Stepper Motor.c
 *
 * Created: 28-08-2022 11:16:25 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11000011;// stepper motor
	int count = 0;
	while (1) 
    {
		if (PINA & 0b00000001)
		{
			while (PINA & 0b00000001);
			if (count == 7)
				count = 0;
			else 
				count = count + 1;
		}
		if (PINA & 0b10000000)
		{
			while (PINA & 0b10000000);
			if (count == 0)
				count = 7;
			else
				count = count - 1;
		}
		if (count == 0)
			PORTC = 0b10000001;//0 (0) Deg
		else if (count == 1)
			PORTC = 0b10000000;//315 (-45) Deg
		else if (count == 2)
			PORTC = 0b11000000;//270 (-90) Deg
		else if (count == 3)
			PORTC = 0b01000000;//225 (-135) Deg
		else if (count == 4)
			PORTC = 0b01000010;//180 (-180) Deg
		else if (count == 5)
			PORTC = 0b00000010;//135 (-225) Deg
		else if (count == 6)
			PORTC = 0b00000011;//90 (-270) Deg
		else if (count == 7)
			PORTC = 0b00000001;//45 (-315) Deg
    }
}

/*
// rotate clockwise (4-step)
PORTC = 0b00000001;//45 Deg
_delay_ms(1000);
PORTC = 0b00000010;//135 Deg
_delay_ms(1000);
PORTC = 0b01000000;//225 Deg
_delay_ms(1000);
PORTC = 0b10000000;//315 Deg
_delay_ms(1000);
*/
/*
// rotate anti-clockwise (4-step)
PORTC = 0b10000000;//315 (-45) Deg
_delay_ms(1000);
PORTC = 0b01000000;//225 (-135) Deg
_delay_ms(1000);
PORTC = 0b00000010;//135 (-225) Deg
_delay_ms(1000);
PORTC = 0b00000001;//45 (-315) Deg
_delay_ms(1000);

*/