# Controle de Servos e Motor de Passo com Arduino

Este projeto Arduino permite controlar vários servos motores e um motor de passo usando potenciômetros. Os componentes principais incluem servos motorizados, um motor de passo NEMA17 e o driver PCA9685 para os servos para movimentar um braço robótico. 
Projeto para impressão 3D: https://www.thingiverse.com/limpsquid/designs


## Hardware Necessário

- Arduino Uno ou Mega (foi usando um mega pela quantidade portas analógicas caso use o Uno utilize um módulo hub de portas)
- PCA9685 Servo Driver (https://www.eletrogate.com/modulo-pwm-pca9685-i2c-16-canais-para-servo?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant&utm_source=google&utm_medium=cpc&utm_campaign=[MC4]_[G]_[PMax]_Categorias&utm_content=&utm_term=&gad_source=1&gclid=CjwKCAiA29auBhBxEiwAnKcSqoP_PlXb0uz7SRL7BcZ8FP4b5UA1UIzqzjuvcCacWAGWC0OnEYw3fBoCjigQAvD_BwE)
- Servos motores (6 motores)
- Motor de passo NEMA17
- Potenciômetros (quantidade conforme necessário)
- Módulo de driver de motor de passo (https://www.baudaeletronica.com.br/produto/driver-de-motor-de-passo-a4988.html)
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

