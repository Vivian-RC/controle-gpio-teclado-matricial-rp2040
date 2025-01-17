#ifndef COMPONENTES_H
#define COMPONENTES_H

#include <stdint.h> // Certifique-se de que esta linha está presente

// Definindo os pinos do teclado
extern const uint32_t LINHAS[4];
extern const uint32_t COLUNAS[4];
extern const uint32_t LED_R;
extern const uint32_t LED_G;
extern const uint32_t LED_B;
extern const uint32_t BUZZER;

// Função para inicializar todos os componentes (LEDs, buzzer, teclado, LCD, etc.)
void inicializar_componentes(void);

#endif  // COMPONENTES_H
