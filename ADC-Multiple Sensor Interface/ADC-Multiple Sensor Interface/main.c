/*
 * ADC-Multiple Sensor Interface.c
 *
 * Created: 04-09-2022 11:08:31 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void ADC_Init(uint8_t channel)
{
	DDRA = 0b00000000;
	ADMUX = 0b01000000 | channel;
	ADCSRA = 0b10000110;
}

uint16_t ADC_GetResult()
{
	ADCSRA = ADCSRA | 0b01000000; // Set the Start bit to 1
	// now we will wait for the flag to be Set to 1
	while ((ADCSRA & 0b00010000) == 0)
	{/* wait here till conversion is complete */}
	return ADC;
}

int main(void)
{
	DDRC = 0b11111111;
	DDRD = 0b00000011;
	uint16_t result = 0;
	while (1)
	{
		ADC_Init(1);
		result = ADC_GetResult();
		PORTC = result;
		PORTD = (result>>8);
		_delay_ms(100);
		
		/*ADC_Init(4);
		result = ADC_GetResult();
		PORTC = result;
		PORTD = (result>>8);
		_delay_ms(1000);
		
		ADC_Init(6);
		result = ADC_GetResult();
		PORTC = result;
		PORTD = (result>>8);
		_delay_ms(1000);*/
	}
}

//#include <stdlib.h>
//#include <stdio.h>
// char array[16];
// sprintf(array,"2 x 3 = %d",2*3)
//array = "2 x 3 = 6\0"

/*
char array[16];
sprintf(array, "ADC: %d", ADC_GetResult())
lcd_config(0x80);
lcd_print(array);
*/