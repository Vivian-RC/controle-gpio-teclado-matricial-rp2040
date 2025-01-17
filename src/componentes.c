#include "componentes.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"  // Include necessário para i2c
#include "lcd.h"

// Definindo os pinos do teclado
const uint32_t LINHAS[4] = {6, 7, 8, 9};       // GPIOs das linhas do teclado
const uint32_t COLUNAS[4] = {10, 11, 12, 13};  // GPIOs das colunas do teclado
const uint32_t LED_R = 14; // LED vermelho
const uint32_t LED_G = 15; // LED verde
const uint32_t LED_B = 16; // LED azul
const uint32_t BUZZER = 17; // Buzzer

// Inicializa todos os componentes (teclado, LEDs, buzzer e LCD)
void inicializar_componentes() {
    // Configura GPIOs das linhas como saída
    for (int linha = 0; linha < 4; linha++) {
        gpio_init(LINHAS[linha]);
        gpio_set_dir(LINHAS[linha], GPIO_OUT);
        gpio_put(LINHAS[linha], 1);
    }

    // Configura GPIOs das colunas como entrada
    for (int coluna = 0; coluna < 4; coluna++) {
        gpio_init(COLUNAS[coluna]);
        gpio_set_dir(COLUNAS[coluna], GPIO_IN);
        gpio_pull_up(COLUNAS[coluna]);
    }

    // Configura os LEDs e o buzzer
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 0);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 0);

    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_put(LED_B, 0);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);

    // Inicializar o LCD
    i2c_init(i2c_default, 100000);
    gpio_set_function(4, GPIO_FUNC_I2C);  // SDA no GPIO 4
    gpio_set_function(5, GPIO_FUNC_I2C);  // SCL no GPIO 5
    gpio_pull_up(4);  // Habilitar pull-up no SDA
    gpio_pull_up(5);  // Habilitar pull-up no SCL
    lcd_init();
}
