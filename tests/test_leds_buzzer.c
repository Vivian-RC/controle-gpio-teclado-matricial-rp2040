#include "unity.h"
#include "componentes.h"
#include "leds_buzzer.h"

// Mock da função gpio_put
void gpio_put(uint32_t gpio, int value) {
    // Função vazia para mock
}

// Função de setup do Unity
void setUp(void) {
    // Configurações que ocorrem antes de cada teste
}

// Função de teardown do Unity
void tearDown(void) {
    // Limpeza que ocorre após cada teste
}

void test_controlar_componentes_led_r(void) {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);
    gpio_put(LED_R, 1);

    controlar_componentes('A');
}

void test_controlar_componentes_led_g(void) {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);
    gpio_put(LED_G, 1);

    controlar_componentes('B');
}

void test_controlar_componentes_led_b(void) {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);
    gpio_put(LED_B, 1);

    controlar_componentes('C');
}

void test_controlar_componentes_buzzer(void) {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(BUZZER, 0);
    gpio_put(BUZZER, 1);
    gpio_put(BUZZER, 0); // Assumindo que o BUZZER é desligado após a espera

    controlar_componentes('#');
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_controlar_componentes_led_r);
    RUN_TEST(test_controlar_componentes_led_g);
    RUN_TEST(test_controlar_componentes_led_b);
    RUN_TEST(test_controlar_componentes_buzzer);

    return UNITY_END();
}
