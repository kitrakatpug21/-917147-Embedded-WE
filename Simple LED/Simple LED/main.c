/*
 * Simple LED.c
 *
 * Created: 31-07-2022 10:42:48 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
// Microcontroller Library for general IO

#define F_CPU 8000000UL
//1MHZ - 16MHZ only 1MHz to 8MHz internal generate, beyond 8MHz we need external crystal ossc 

int main(void)
{
	// Data Direction Setup
	/*
	DDRA : if bit is 1 then set particular pin as output
	DDRA : if bit is 0 then set particular pin as input/reset
	*/
	DDRA = 3;
	// 00000011;
    while (1) 
    {
		PORTA = 1;// 125ns
		for (long temp = 0; temp <= 200000; temp = temp + 1)
		{ 
			// 125ns 
		}
		PORTA = 2;// 125ns
		for (long temp = 0; temp <= 200000; temp = temp + 1)
		{
			// 125ns
		}
		// 00000010; => only PA0 is 5V, PA1 is 0V
    }
}

/*
TURN ALL LEDS ON PORT A ON (ONE-BY-ONE)
ONLY PA0 ON REST ALL OFF
ONLY PA1 ON REST ALL OFF
ONLY PA2 ON REST ALL OFF
ONLY PA3 ON REST ALL OFF
ONLY PA4 ON REST ALL OFF
ONLY PA5 ON REST ALL OFF
ONLY PA6 ON REST ALL OFF
ONLY PA7 ON REST ALL OFF
*/