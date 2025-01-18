#include "unity.h"
#include "componentes.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "lcd.h"

void setUp() {
    // Configuração inicial dos testes, se necessário
}

void tearDown() {
    // Limpeza após cada teste, se necessário
}

void test_inicializar_componentes() {
    // Chama a função que estamos testando
    inicializar_componentes();

    // Verifica se as linhas do teclado foram configuradas corretamente
    for (int linha = 0; linha < 4; linha++) {
        TEST_ASSERT_EQUAL(GPIO_OUT, gpio_get_dir(LINHAS[linha]));
        TEST_ASSERT_EQUAL(1, gpio_get(LINHAS[linha]));
    }

    // Verifica se as colunas do teclado foram configuradas corretamente
    for (int coluna = 0; coluna < 4; coluna++) {
        TEST_ASSERT_EQUAL(GPIO_IN, gpio_get_dir(COLUNAS[coluna]));
        TEST_ASSERT_EQUAL(1, gpio_is_pulled_up(COLUNAS[coluna]));  // Verifica se o pull-up está habilitado
    }

    // Verifica se os LEDs foram configurados corretamente
    TEST_ASSERT_EQUAL(GPIO_OUT, gpio_get_dir(LED_R));
    TEST_ASSERT_EQUAL(0, gpio_get(LED_R));

    TEST_ASSERT_EQUAL(GPIO_OUT, gpio_get_dir(LED_G));
    TEST_ASSERT_EQUAL(0, gpio_get(LED_G));

    TEST_ASSERT_EQUAL(GPIO_OUT, gpio_get_dir(LED_B));
    TEST_ASSERT_EQUAL(0, gpio_get(LED_B));

    // Verifica se o buzzer foi configurado corretamente
    TEST_ASSERT_EQUAL(GPIO_OUT, gpio_get_dir(BUZZER));
    TEST_ASSERT_EQUAL(0, gpio_get(BUZZER));

    // Verifica se o I2C foi inicializado corretamente
    // Você pode adicionar verificações específicas para o I2C aqui, se necessário
    // Por exemplo, verificar se os pinos SDA e SCL estão configurados para I2C
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_inicializar_componentes);
    return UNITY_END();
}
