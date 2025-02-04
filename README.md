# Atividade 2 - Temporizador de um Disparo (One Shot)

Este projeto foi desenvolvido para aprimorar o conhecimento sobre temporização utilizando a função add_alarm_in_ms() do Pico SDK. A simulação foi realizada no **Wokwi** e testada na placa **BitDogLab**.

## Componentes Utilizados

1. **Microcontrolador:** Raspberry Pi Pico W
2. **LEDs:** 3 LEDs (Azul, Vermelho e Verde)
3. **Resistores:** 3 resistores de 330 Ω
4. **Botão:** 1 Pushbutton
4. **Ferramentas:** Wokwi (Simulador) e BitDogLab

## Funcionalidade

Ao pressionar o botão (pushbutton), os três LEDs serão ligados simultaneamente. Em seguida, de acordo com o temporizador configurado, haverá uma sequência de desligamento:

1. Todos os LEDs acendem ao pressionar o botão.

2. Após 950 milissegundo, um LED é desligado.

3. Após mais 950 milissegundo, o segundo LED é desligado.

Após mais 950 milissegundo, o último LED é desligado.

O botão só pode ser acionado novamente após o último LED ser desligado, foi usado o intervalo de 950 milissegundos em vez de 1s para que tornasse visivel o desligamento do LED.

A transição entre os LEDs é controlada pelo temporizador utilizando funções de call-back, seguindo o modelo da função turn_off_callback(), abordada em aula.


#### Usando o Simulador Wokwi

- Clone este repositório: git clone https://github.com/rober1o/AS_U4C5O1234E--ATIVIDADE_02.git;
- Usando a extensão Raspberry Pi Pico importar o projeto;
- Compilar o código e clicar no arquivo diagram.json.

#### Usando a BitDogLab

- Clone este repositório: git clone https://github.com/rober1o/AS_U4C5O1234E--ATIVIDADE_02.git;
- Usando a extensão Raspberry Pi Pico importar o projeto;
- Compilar o projeto;
- Plugar a BitDogLab usando um cabo USB e gravar o código.



## Demonstração

<!-- TODO: adicionar link do vídeo -->
Vídeo demonstrando as funcionalidades da solução implementada na BitDogLab: [Demonstração](https://youtu.be/tIvuOfA9YlU)
