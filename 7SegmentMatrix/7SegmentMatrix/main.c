/*
 * 7SegmentMatrix.c
 *
 * Created: 14-08-2022 10:31:50 AM
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
	while (1)
	{
		for (int thou = 0; thou <= 2; thou = thou + 1)
		{
			for (int hund = 0; hund <= 9; hund = hund + 1)
			{
				for (int tens = 0; tens <= 5; tens = tens + 1)
				{
					for (int ones = 0; ones <= 9; ones = ones + 1)
					{
						if (thou == 2 && hund == 3 && tens == 5 && ones == 9)
						{
							thou = 0;
							hund = 0;
							tens = 0;
							ones = 0;
						}
						for (int rp = 0; rp < 10; rp = rp+ 1)// for a real time clock, (rp < 600)
						{
							PORTD = 0b00001110;
							PORTC = segment[thou];
							_delay_ms(15);
							PORTD = 0b00001101;
							PORTC = segment[hund];
							_delay_ms(15);
							PORTD = 0b000001011;
							PORTC = segment[tens];
							_delay_ms(15);
							PORTD = 0b000000111;
							PORTC = segment[ones];
							_delay_ms(15);
						}
					}
				}
			}
		}
	}
}