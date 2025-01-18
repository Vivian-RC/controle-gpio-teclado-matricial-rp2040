#include "unity.h"
#include "teclado.h"
#include "componentes.h"

// Mock das funções gpio_get e gpio_put
void gpio_put(uint32_t gpio, int value) {
    // Função vazia para mock
}

int gpio_get(uint32_t gpio) {
    // Retorna 0 como padrão para simular tecla pressionada
    return 0;
}

void setUp(void) {
    // Configurações que ocorrem antes de cada teste
}

void tearDown(void) {
    // Limpeza que ocorre após cada teste
}

void test_ler_teclado_tecla_1(void) {
    gpio_put(LINHAS[0], 0);
    gpio_get(COLUNAS[0]);
    gpio_put(LINHAS[0], 1);

    char tecla = ler_teclado();
    TEST_ASSERT_EQUAL_CHAR('1', tecla);
}

void test_ler_teclado_tecla_A(void) {
    gpio_put(LINHAS[0], 0);
    gpio_get(COLUNAS[3]);
    gpio_put(LINHAS[0], 1);

    char tecla = ler_teclado();
    TEST_ASSERT_EQUAL_CHAR('A', tecla);
}

// Adicione mais testes conforme necessário

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ler_teclado_tecla_1);
    RUN_TEST(test_ler_teclado_tecla_A);
    // Adicione mais testes aqui

    return UNITY_END();
}
