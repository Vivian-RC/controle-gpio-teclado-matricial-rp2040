#ifndef LCD_H
#define LCD_H

#include <stdint.h>

// Definindo o endereço e pinos do LCD
#define LCD_ADDR 0x27
#define LCD_ENABLE_BIT 0x04
#define LCD_BACKLIGHT 0x08

// Funções do LCD
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_FUNCTIONSET 0x20
#define LCD_SETDDRAMADDR 0x80

void i2c_write_byte(uint8_t val);
void lcd_toggle_enable(uint8_t val);
void lcd_send_byte(uint8_t val, int mode);
void lcd_init();
void lcd_set_cursor(int row, int col);
void lcd_string(const char* str);

#endif