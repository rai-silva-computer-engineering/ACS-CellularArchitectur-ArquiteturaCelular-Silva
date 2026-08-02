#include <Arduino.h>

const int MOTOR_ESQ_A = 25;
const int MOTOR_ESQ_B = 26;

const int MOTOR_DIR_A = 27;
const int MOTOR_DIR_B = 14;

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;

class MotorController {

public:

    void iniciar() {
        pinMode(MOTOR_ESQ_A, OUTPUT);
        pinMode(MOTOR_ESQ_B, OUTPUT);

        pinMode(MOTOR_DIR_A, OUTPUT);
        pinMode(MOTOR_DIR_B, OUTPUT);

        parar();
    }

    void frente() {
        digitalWrite(MOTOR_ESQ_A, HIGH);
        digitalWrite(MOTOR_ESQ_B, LOW);

        digitalWrite(MOTOR_DIR_A, HIGH);
        digitalWrite(MOTOR_DIR_B, LOW);
    }

    void tras() {
        digitalWrite(MOTOR_ESQ_A, LOW);
        digitalWrite(MOTOR_ESQ_B, HIGH);

        digitalWrite(MOTOR_DIR_A, LOW);
        digitalWrite(MOTOR_DIR_B, HIGH);
    }

    void esquerda() {
        digitalWrite(MOTOR_ESQ_A, LOW);
        digitalWrite(MOTOR_ESQ_B, HIGH);

        digitalWrite(MOTOR_DIR_A, HIGH);
        digitalWrite(MOTOR_DIR_B, LOW);
    }

    void direita() {
        digitalWrite(MOTOR_ESQ_A, HIGH);
        digitalWrite(MOTOR_ESQ_B, LOW);

        digitalWrite(MOTOR_DIR_A, LOW);
        digitalWrite(MOTOR_DIR_B, HIGH);
    }

    void parar() {
        digitalWrite(MOTOR_ESQ_A, LOW);
        digitalWrite(MOTOR_ESQ_B, LOW);

        digitalWrite(MOTOR_DIR_A, LOW);
        digitalWrite(MOTOR_DIR_B, LOW);
    }
};

class Ultrassonico {

public:

    void iniciar() {
        pinMode(TRIG_PIN, OUTPUT);
        pinMode(ECHO_PIN, INPUT);

        digitalWrite(TRIG_PIN, LOW);
    }

    float distancia() {
        digitalWrite(TRIG_PIN, LOW);
        delayMicroseconds(2);

        digitalWrite(TRIG_PIN, HIGH);
        delayMicroseconds(10);

        digitalWrite(TRIG_PIN, LOW);

        long tempo = pulseIn(ECHO_PIN, HIGH);

        return tempo * 0.0343 / 2.0;
    }
};

MotorController motor;
Ultrassonico sensor;

void setup() {
    Serial.begin(115200);

    motor.iniciar();
    sensor.iniciar();
}

void loop() {
    float distancia = sensor.distancia();

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    if (distancia > 20) {
        motor.frente();
    } else {
        Serial.println("Obstaculo detectado");

        motor.parar();
        delay(500);

        motor.tras();
        delay(800);

        motor.parar();
        delay(300);

        motor.direita();
        delay(700);

        motor.parar();
        delay(300);
    }

    delay(100);
}
