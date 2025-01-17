#ifndef TECLADO_H
#define TECLADO_H

#include <stdint.h> // Biblioteca para tipos como uint32_t

// Matriz de teclas do teclado
extern const char matriz_teclas[4][4];

// Lê a tecla pressionada e retorna o caractere correspondente
char ler_teclado(void);

// Sequência de teclas pressionadas (declaradas externamente no arquivo .c)
extern char sequencia[32];  // Capacidade para até 32 teclas
extern int indice;          // Índice para adicionar teclas na sequência

#endif // TECLADO_H
