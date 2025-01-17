#include "lcd.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Função para enviar um byte ao LCD
void i2c_write_byte(uint8_t val) {
    i2c_write_blocking(i2c_default, LCD_ADDR, &val, 1, false);
}

// Função para alternar o pino de enable no LCD
void lcd_toggle_enable(uint8_t val) {
    sleep_us(600);
    i2c_write_byte(val | LCD_ENABLE_BIT);
    sleep_us(600);
    i2c_write_byte(val & ~LCD_ENABLE_BIT);
    sleep_us(600);
}

// Função para enviar um byte (comando ou caractere) ao LCD
void lcd_send_byte(uint8_t val, int mode) {
    uint8_t high = mode | (val & 0xF0) | LCD_BACKLIGHT;
    uint8_t low = mode | ((val << 4) & 0xF0) | LCD_BACKLIGHT;

    i2c_write_byte(high);
    lcd_toggle_enable(high);
    i2c_write_byte(low);
    lcd_toggle_enable(low);
}

// Função para inicializar o LCD
void lcd_init() {
    lcd_send_byte(0x03, 0);  // Enviar os 3 primeiros bytes para inicializar
    lcd_send_byte(0x03, 0);
    lcd_send_byte(0x03, 0);
    lcd_send_byte(0x02, 0);

    lcd_send_byte(LCD_FUNCTIONSET | 0x08, 0);  // Configurar o LCD para 2 linhas
    lcd_send_byte(LCD_DISPLAYCONTROL | 0x04, 0);  // Ligar o display
    lcd_send_byte(LCD_CLEARDISPLAY, 0);  // Limpar o display
}

// Função para mover o cursor para a posição desejada
void lcd_set_cursor(int row, int col) {
    int pos = (row == 0) ? 0x80 + col : 0xC0 + col;
    lcd_send_byte(pos, 0);
}

// Função para exibir uma string no LCD
void lcd_string(const char* str) {
    while (*str) {
        lcd_send_byte(*str++, 1);
    }
}