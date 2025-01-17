#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "lcd.h"
#include "componentes.h"
#include "teclado.h"
#include "leds_buzzer.h"

int main() {
    stdio_init_all();
    inicializar_componentes();

    while (true) {
        char tecla = ler_teclado();
        if (tecla != '\0') {
            if (tecla == '#') {
                // Limpa a linha onde a sequência está
                limpar_linha(0);
                limpar_linha(1);

                // Reseta o índice para permitir uma nova digitação
                indice = 0;
                sequencia[0] = '\0';
            } else {
                if (indice < 31) {  // Limita a sequência a 32 caracteres
                    sequencia[indice++] = tecla;
                    sequencia[indice] = '\0';  // Termina a string
                }
            }
            printf("Tecla pressionada: %c\n", tecla);
            atualizar_lcd(sequencia, indice);
            controlar_componentes(tecla);
        }
        sleep_ms(50); // Adicional para evitar sobrecarga do loop
    }
    return 0;
}
