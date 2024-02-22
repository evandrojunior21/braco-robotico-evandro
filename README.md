# Controle de Servos e Motor de Passo com Arduino

Este projeto Arduino permite controlar vários servos motores e um motor de passo usando potenciômetros. Os componentes principais incluem servos motorizados, um motor de passo NEMA17 e o driver PCA9685 para os servos para movimentar um braço robótico. 
Projeto para impressão 3D: https://www.thingiverse.com/limpsquid/designs


## Hardware Necessário

6 x Servo Motor – MG966R Series	(metálico)
Servo Driver, PCA9685	
Battery Pack (5V, 2200 mAh)	
Arduino Uno	(Usei um mega para conectar todos os 6 potênciometros)
Arduino HC-05	
Protoboard 2x
NEMA 17 Servo Motor	
A4988 Stepper Motor Driver	
LiPo 11.1V, 2200mAh, 3s
Potênciometros 10k 6x
Fios de conexão

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

