#include "config.hpp"
#include "connection.hpp"
#include "hooks.hpp"
#include "data.hpp"
#include "hardware.hpp"
#include "hardware_impl.hpp"

// Versao minima do SMRE: so a placa + 1 potenciometro (E_r).
// Sem botao, o hardware opera sempre que estiver alimentado.

Hardware hardware;

unsigned long lastRead = 0;
unsigned long lastSend = 0;

void setup() {
    hardware.begin();
}

void loop() {
    unsigned long now = millis();

    hardware.keepConnection();

    if (now - lastRead >= READ_INTERVAL) {
        lastRead = now;
        hardware.collector();
        hardware.manipulator();
    }

    if (now - lastSend >= (unsigned long)hardware.getTimer()) {
        lastSend = now;
        hardware.pull();
        hardware.push();
        hardware.printer();
    }
}
