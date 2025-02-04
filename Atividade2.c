#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_BLUE_PIN 11
#define LED_RED_PIN 12
#define LED_GREEN_PIN 13
#define BUTTON_A 5

// Funções de callback
int64_t apaga_azul_callback(alarm_id_t id, void *user_data);
int64_t apaga_vermelho_callback(alarm_id_t id, void *user_data);
int64_t apaga_verde_callback(alarm_id_t id, void *user_data);
int64_t desbloquear_botao_callback(alarm_id_t id, void *user_data);

// Função para acender todos os LEDs
void acender_todos() {
    gpio_put(LED_BLUE_PIN, true);  // Acende o LED azul
    gpio_put(LED_RED_PIN, true);   // Acende o LED vermelho
    gpio_put(LED_GREEN_PIN, true); // Acende o LED verde
}

// Callback para desligar o LED azul após 1 segundo
int64_t apaga_azul_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE_PIN, false);  // Desliga o LED azul
    // Cria um alarme para desligar o LED vermelho após 950 milissegundos
    add_alarm_in_ms(950, apaga_vermelho_callback, NULL, false);
    return 0;
}

// Callback para desligar o LED vermelho após 1 segundo
int64_t apaga_vermelho_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_RED_PIN, false);  // Desliga o LED vermelho
    // Cria um alarme para desligar o LED verde após 950 milissegundos
    add_alarm_in_ms(950, apaga_verde_callback, NULL, false);
    return 0;
}

// Callback para desligar o LED verde após 1 segundo
int64_t apaga_verde_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_GREEN_PIN, false);  // Desliga o LED verde
    return 0;
}

// Função de interrupção para o botão
void gpio_irq_handler(uint gpio, uint32_t events) {
    // Verifica se o botão foi pressionado e se o botão não está bloqueado
    if (gpio_get(BUTTON_A) == 0) {

        if (gpio_get(BUTTON_A) == 0) {  // Confirma que o botão foi pressionado
            acender_todos();  // Acende todos os LEDs
            gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, false, gpio_irq_handler);  //Desabilita a interrupção
            // Chama o primeiro alarme para desligar o LED azul 950 milissegundos
            add_alarm_in_ms(950, apaga_azul_callback, NULL, false);
            // Chama o callback para desbloquear o botão após 3 segundos
            add_alarm_in_ms(3000, desbloquear_botao_callback, NULL, false);
        }
    }
}

// Callback para desbloquear o botão após 3 segundos
int64_t desbloquear_botao_callback(alarm_id_t id, void *user_data) {
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, gpio_irq_handler);
    return 0;
}

// Função para inicializar os pinos
void iniciar_pinos() {
    gpio_init(LED_BLUE_PIN);
    gpio_init(LED_RED_PIN);
    gpio_init(LED_GREEN_PIN);
    gpio_init(BUTTON_A);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);  // Ativa o pull-up interno no botão
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, gpio_irq_handler);  // Configura interrupção
}

int main() {
    iniciar_pinos();  // Inicializa os pinos

    while (true) {
        // Código principal não faz nada, já que a lógica de LEDs está sendo controlada pelos alarmes

    }

    return 0;
}
