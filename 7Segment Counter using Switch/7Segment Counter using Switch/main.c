/*
 * 7Segment Counter using Switch.c
 *
 * Created: 14-08-2022 11:18:55 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

uint8_t segment[10] = {
	0b00111111, //Display 0 at Index 0
	0b00000110, //Display 1 at Index 1
	0b01011011, //Display 2 at Index 2
	0b01001111, //Display 3 at Index 3
	0b01100110, //Display 4 at Index 4
	0b01101101, //Display 5 at Index 5
	0b01111101, //Display 6 at Index 6
	0b00000111, //Display 7 at Index 7
	0b01111111, //Display 8 at Index 8
	0b01101111, //Display 9 at Index 9
};

int main(void)
{
    DDRC = 0b01111111;// PC6 to PC0 as OUTPUT
    DDRD = 0b00001111; // COM Pin for Seg 1 and 2 and 3 and 4
    DDRA = 0b00000000; // Whole PORTA is an Input PORT
	int thou = 0, hund = 0, tens = 0, ones = 0;
	while (1) 
    {
		if (PINA & 0b10000000) // PA7 as Increment Counter
		{
			while(PINA & 0b10000000); // PA7 as Increment Counter
			if (tens == 5 && ones == 9)
			{
				tens = 0; ones = 0;
			}
			else if (tens < 5 && ones == 9)
			{
				tens = tens + 1;
				ones = 0;
			}
			else
			{
				ones = ones + 1;
			}
		}
		if (PINA & 0b00000001) // PA0 as Decrement Counter
		{
			if (tens == 0 && ones == 0)
			{
				tens = 5; ones = 9;
			}
			else if (tens > 0 && ones == 0)
			{
				tens = tens - 1;
				ones = 9;
			}
			else
			{
				ones = ones - 1;
			}
		}
		for (int rp = 0; rp < 10; rp = rp+ 1)// for a real time clock, (rp < 600)
		{
// 			PORTD = 0b00001110;
// 			PORTC = segment[thou];
// 			_delay_ms(15);
// 			PORTD = 0b00001101;
// 			PORTC = segment[hund];
// 			_delay_ms(15);
			PORTD = 0b000001011;
			PORTC = segment[tens];
			_delay_ms(15);
			PORTD = 0b000000111;
			PORTC = segment[ones];
			_delay_ms(15);
		}
    }
}

