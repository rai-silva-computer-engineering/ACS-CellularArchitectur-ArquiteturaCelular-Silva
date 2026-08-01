#include <Arduino.h>

const int MOTOR_ESQ_A = 25;
const int MOTOR_ESQ_B = 26;

const int MOTOR_DIR_A = 27;
const int MOTOR_DIR_B = 14;


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


MotorController motor;


void setup() {

    Serial.begin(115200);

    motor.iniciar();

}


void loop() {

    Serial.println("Frente");
    motor.frente();
    delay(3000);


    Serial.println("Direita");
    motor.direita();
    delay(1500);


    Serial.println("Frente");
    motor.frente();
    delay(3000);


    Serial.println("Esquerda");
    motor.esquerda();
    delay(1500);


    Serial.println("Trás");
    motor.tras();
    delay(3000);


    Serial.println("Parado");
    motor.parar();
    delay(3000);

}
