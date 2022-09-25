/*
 * 7Segment using Array.c
 *
 * Created: 07-08-2022 10:46:19 AM
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
	DDRD = 0b01111111;// PD6 to PD0 as OUTPUT
	DDRB = 0b01111111;// PB6 to PB0 as OUTPUT
	while (1)
	{
		for (int hundreds = 0; hundreds <= 9; hundreds = hundreds + 1)
		{
			for (int tens = 0; tens <= 9; tens = tens + 1)
			{
				for (int ones = 0; ones <= 9; ones = ones + 1)
				{
					PORTC = segment[ones];
					PORTD = segment[tens];
					PORTB = segment[hundreds];
					_delay_ms(300);
				}
			}
		}
	}
}
/*
PORTA = 0b00000001; // PORTA = 1;
for (int i = 0; i < 8 ; i = i + 1)
{
	PORTA = 1 << i;
}
*/
