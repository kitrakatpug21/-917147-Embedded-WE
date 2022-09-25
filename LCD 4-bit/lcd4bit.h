
#include <avr/io.h>

#define LCD_DDR DDRD
#define LCD_PORT PORTD

void lcd_command(uint8_t cmd)
{
	// this is the first half (upper nibble) of the actual data
	//1. Set RS Pin to 0 for config mode
	LCD_PORT = 0b00000000;
	//2. Load the Data on PORT-D
	LCD_PORT = LCD_PORT | (cmd & 0b11110000);
	//3. Generate the Clock Signal 0-1-0
	LCD_PORT = LCD_PORT | 0b00000010;
	_delay_ms(10);
	LCD_PORT = LCD_PORT & ~(0b00000010);
	_delay_ms(10);
	// this is the second half (lower nibble) of the actual data
	//1. Set RS Pin to 0 for config mode
	LCD_PORT = 0b00000000;
	//2. Load the Data on PORT-D
	LCD_PORT = LCD_PORT | ((cmd<<4) & 0b11110000);
	//3. Generate the Clock Signal 0-1-0
	LCD_PORT = LCD_PORT | 0b00000010;
	_delay_ms(10);
	LCD_PORT = LCD_PORT & ~(0b00000010);
	_delay_ms(10);
}

void lcd_character(char ch)
{
	// this is the first half (upper nibble) of the actual data
	//1. Set RS Pin to 1 for data mode
	LCD_PORT = 0b00000001;
	//2. Load the Data on PORT-D
	LCD_PORT = LCD_PORT | (ch & 0b11110000);
	//3. Generate the Clock Signal 0-1-0
	LCD_PORT = LCD_PORT | 0b00000010;
	_delay_ms(10);
	LCD_PORT = LCD_PORT & ~(0b00000010);
	_delay_ms(10);
	// this is the second half (lower nibble) of the actual data
	//1. Set RS Pin to 1 for data mode
	LCD_PORT = 0b00000001;
	//2. Load the Data on PORT-D
	LCD_PORT = LCD_PORT | ((ch<<4) & 0b11110000);
	//3. Generate the Clock Signal 0-1-0
	LCD_PORT = LCD_PORT | 0b00000010;
	_delay_ms(10);
	LCD_PORT = LCD_PORT & ~(0b00000010);
	_delay_ms(10);
}
void lcd_inititalize()
{
	LCD_DDR = 0xFF;
	// 1. LCD Power Up Require 300ms
	_delay_ms(300);
	//2. to setup LCD (8-bit) 16 char 2 row mode, command = 0x38
	//2. to setup LCD (8-bit) 16 char 1 row mode, command = 0x30
	//2. to setup LCD (4-bit) 16 char 2 row mode, command = 0x28
	//2. to setup LCD (4-bit) 16 char 1 row mode, command = 0x20
	//lcd_command(0x38);
	lcd_command(0x33);lcd_command(0x32);
	lcd_command(0x28);
	//3. to setup the lcd cursors as BLINK, command = 0x0F
	//3. to setup the lcd cursors as SOLID, command = 0x0E
	//3. to setup the lcd cursors disabled, command = 0x0C
	lcd_command(0x0C);
	//4. to clear the lcd display, command = 0x01
	lcd_command(0x01);
	_delay_ms(10);
	//5. to setup lcd print in Left-Right Direction, command = 0x06
	//5. to setup lcd print in Right-Left Direction, command = 0x04
	lcd_command(0x06);
}

void print(char *xyz)
{
	while (*xyz != '\0')
	{
		lcd_character(*xyz);
		xyz++;
	}
}