#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600
uint8_t numberOfServos = 6; // Agora são 6 servos

int potStepPin = A0;   // Pino analógico conectado ao potenciômetro para o motor de passo NEMA17
int potServoPin1 = A1; // Pino analógico conectado ao potenciômetro para os primeiros dois servos
int potServoPin2 = A2; // Pino analógico conectado ao potenciômetro para o terceiro servo
int potServoPin3 = A3; // Pino analógico conectado ao potenciômetro para o quarto servo
int potServoPin4 = A4; // Pino analógico conectado ao potenciômetro para o quinto servo
int potServoPin5 = A5; // Pino analógico conectado ao potenciômetro para o sexto servo

// NEMA 17
const int dirPin = 4;
const int stepPin = 5;
const int stepsPerRevolution = 100;
int stepDelay = 9500;

void setup()
{
    Serial.begin(9600);
    myServo.begin();
    myServo.setPWMFreq(60);
    delay(10);

    // Inicializa os servos nas posições iniciais
    myServo.setPWM(0, 0, map(120, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(1, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(2, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(3, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(4, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(5, 0, map(0, 0, 180, SERVOMIN, SERVOMAX));
    delay(1000);

    // NEMA 17
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    // Inicia o motor de passo parado
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, LOW);
}

void loop()
{
    // Controle dos primeiros dois servos (sincronizados)
    int potServoValue1 = analogRead(potServoPin1);
    int syncedServoPosition = map(potServoValue1, 0, 1023, -90, 90);
    myServo.setPWM(0, 0, map(120 + syncedServoPosition, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(1, 0, map(-syncedServoPosition, 0, 180, SERVOMIN, SERVOMAX));

    // Controle dos outros três servos
    int potServoValue2 = analogRead(potServoPin2);
    int potServoValue3 = analogRead(potServoPin3);
    int potServoValue4 = analogRead(potServoPin4);
    int potServoValue5 = analogRead(potServoPin5);

    // Mapeia os valores dos potenciômetros para o intervalo de -90 a 90
    int servo2Position = map(potServoValue2, 0, 1023, -90, 90);
    int servo3Position = map(potServoValue3, 0, 1023, -90, 90);
    int servo4Position = map(potServoValue4, 0, 1023, -90, 90);
    int servo5Position = map(potServoValue5, 0, 1023, -90, 90);

    // Define a posição dos outros três servos com base nos valores dos potenciômetros
    myServo.setPWM(2, 0, map(-servo2Position, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(3, 0, map(-servo3Position, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(4, 0, map(servo4Position, 0, 180, SERVOMIN, SERVOMAX));
    myServo.setPWM(5, 0, map(servo5Position, 0, 180, SERVOMIN, SERVOMAX));

    // Controle do motor de passo
    int potStepValue = analogRead(potStepPin);

    // Determina a direção do motor de passo com base no valor do potenciômetro
    if (potStepValue < 400)
    {
        digitalWrite(dirPin, LOW); // Gira para a esquerda
    }
    else if (potStepValue > 600)
    {
        digitalWrite(dirPin, HIGH); // Gira para a direita
    }

    // Verifica se o valor do potenciômetro está fora de uma margem ao redor do centro
    if (potStepValue < 400 || potStepValue > 600)
    {
        // Calcula a quantidade de passos a serem movidos
        int stepsToMove = map(potStepValue, 0, 1023, 0, stepsPerRevolution);

        // Move o motor de passo
        for (int x = 0; x < stepsToMove; x++)
        {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(stepDelay);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(stepDelay);
        }
    }
    else
    {
        digitalWrite(stepPin, LOW); // Para o motor de passo
    }

    // Monitoramento serial das posições dos servos e do valor do potenciômetro
    Serial.print("Servo 0: ");
    Serial.print(myServo.getPWM(0));
    Serial.print("\t Servo 1: ");
    Serial.print(myServo.getPWM(1));
    Serial.print("\t Servo 2: ");
    Serial.print(myServo.getPWM(2));
    Serial.print("\t Servo 3: ");
    Serial.print(myServo.getPWM(3));
    Serial.print("\t Servo 4: ");
    Serial.print(myServo.getPWM(4));
    Serial.print("\t Servo 5: ");
    Serial.print(myServo.getPWM(5));
    Serial.print("\t Potenciômetro Motor de Passo: ");
    Serial.println(potStepValue);

    delay(10); // Pequeno atraso para estabilidade
}