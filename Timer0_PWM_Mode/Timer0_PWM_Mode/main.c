/*
 * Timer0_PWM_Mode.c
 *
 * Created: 25-09-2022 10:59:19 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRB = 0b00001000; // PB3 as Output for OC0 pin
    TCCR0 = 0b01101010;
	// Force: No, WGM: (Fast)PWM, Output: Set on Match, Prescale: by 64
	TCNT0 = 0;
	
	while (1) 
    {
		if (PINA & 0b00000001)
			OCR0 = 90; 
		else
			OCR0 = 200;
		/*for (int duty= 0; duty <= 255; duty = duty + 1)
		{
			OCR0 = duty;
			_delay_ms(100);
		}*/
    }
}

