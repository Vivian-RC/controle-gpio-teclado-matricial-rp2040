#include "leds_buzzer.h"
#include "componentes.h"
#include "pico/stdlib.h"

// Função para controlar LEDs e buzzer com base na tecla
void controlar_componentes(char tecla) {
    // Desliga todos os componentes inicialmente
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);

    // Liga o componente correspondente à tecla pressionada
    switch (tecla) {
        case 'A': gpio_put(LED_R, 1); break; // LED vermelho
        case 'B': gpio_put(LED_G, 1); break; // LED verde
        case 'C': gpio_put(LED_B, 1); break; // LED azul
        case '#': 
            gpio_put(BUZZER, 1); 
            sleep_ms(200); // Duração de 200ms
            gpio_put(BUZZER, 0);
            break; // Buzzer com duração fixa
        default: break; // Nenhuma ação para outras teclas
    }
}