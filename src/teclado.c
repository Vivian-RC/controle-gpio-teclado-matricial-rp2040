#include "teclado.h"
#include "componentes.h"
#include "pico/stdlib.h"

// Matriz de teclas do teclado matricial
const char matriz_teclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Variável para armazenar a sequência de teclas pressionadas
char sequencia[32];  // Capacidade para até 32 teclas
int indice = 0;      // Índice para adicionar teclas na sequência

// Função para ler o teclado matricial
char ler_teclado() {
    for (int linha = 0; linha < 4; linha++) {
        gpio_put(LINHAS[linha], 0); // Ativa a linha atual
        for (int coluna = 0; coluna < 4; coluna++) {
            if (!gpio_get(COLUNAS[coluna])) { // Detecta tecla pressionada
                sleep_ms(100); // Debounce
                gpio_put(LINHAS[linha], 1); // Desativa a linha
                return matriz_teclas[linha][coluna];
            }
        }
        gpio_put(LINHAS[linha], 1); // Desativa a linha atual
    }
    return '\0'; // Nenhuma tecla pressionada
}