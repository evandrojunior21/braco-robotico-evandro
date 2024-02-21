# Controle de Servos e Motor de Passo com Arduino

Este projeto Arduino permite controlar vários servos motores e um motor de passo usando potenciômetros. Os componentes principais incluem servos motorizados, um motor de passo NEMA17 e o driver PCA9685 para os servos.

## Hardware Necessário

- Arduino Uno ou Mega
- PCA9685 Servo Driver
- Servos motores (quantidade conforme necessário)
- Motor de passo NEMA17
- Potenciômetros (quantidade conforme necessário)
- Módulo de driver de motor de passo (se necessário)
- Fios de conexão

## Instalação e Configuração

1. Conecte os servos, o motor de passo e os potenciômetros aos pinos definidos no código.
2. Carregue o código no Arduino usando a IDE do Arduino.
3. Alimente o sistema e ajuste os potenciômetros para controlar os movimentos dos servos e do motor de passo.

## Configurações do Código

- O código utiliza a biblioteca `Adafruit_PWMServoDriver` para controlar os servos através do PCA9685.
- O motor de passo é controlado através dos pinos `step` e `dir` no Arduino.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir problemas ou enviar solicitações de pull.

## Licença

Este projeto está licenciado sob a Licença MIT - consulte o arquivo [LICENSE](LICENSE) para obter detalhes.

