#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_BLUE_PIN 11
#define LED_RED_PIN 12
#define LED_GREEN_PIN 13
#define BUTTON_A 5


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
}

int main() {
    iniciar_pinos();  // Inicializa os pinos

    while (true) {
        // Código principal não faz nada, já que a lógica de LEDs está sendo controlada pelos alarmes

    }

    return 0;
}
