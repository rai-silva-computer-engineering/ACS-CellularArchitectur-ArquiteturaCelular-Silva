#include <Arduino.h>

// ============================
// Classe principal do robô
// ============================

class RobotBrain {
public:
    void iniciar() {
        Serial.begin(115200);

        Serial.println("--------------------");
        Serial.println("Mordomo IA");
        Serial.println("Sistema iniciado");
        Serial.println("--------------------");
    }

    void atualizar() {
        verificarSensores();
        controlarMotores();
        controlarBateria();
        comunicarIA();
    }

private:
    void verificarSensores() {
        Serial.println("Lendo sensores...");
    }

    void controlarMotores() {
        Serial.println("Motores OK");
    }

    void controlarBateria() {
        Serial.println("Bateria OK");
    }

    void comunicarIA() {
        Serial.println("Esperando comandos...");
    }
};

RobotBrain robo;

void setup() {
    robo.iniciar();
}

void loop() {
    robo.atualizar();
    delay(1000);
}
