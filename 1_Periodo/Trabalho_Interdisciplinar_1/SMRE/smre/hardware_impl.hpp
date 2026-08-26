#ifndef HARDWARE_IMPL_HPP
#define HARDWARE_IMPL_HPP

#include "config.hpp"
#include "hardware.hpp"

Hardware::Hardware() {
    lastPushOk = false;
}

void Hardware::begin() {
    Serial.begin(115200);
    // Espera o USB CDC do S3 enumerar para nao perder o banner de boot.
    delay(1000);

    pinMode(PIN_POT_RECEIVED, INPUT);

    Serial.println();
    Serial.println("== SixSeven boot (versao minima) ==");
    Serial.print("WiFi \"");
    Serial.print(WIFI_SSID);
    Serial.print("\"... ");
    bool wifiOk = conn.start();
    Serial.println(wifiOk ? "conectado" : "FALHOU (vai tentando em background)");
    if (wifiOk) {
        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
    }
    Serial.print("backend: http://");
    Serial.print(SERVER_HOST);
    Serial.print(":");
    Serial.println(SERVER_PORT);
    Serial.println("lendo E_r no GPIO 1 — E_b vem do backend");
}

int Hardware::readReceivedEnergy() {
    int value = analogRead(PIN_POT_RECEIVED);
    data.setReceivedEnergy(value);
    hooks.setReceivedEnergy(value);
    return value;
}

void Hardware::computeAll() {
    data.computeMeanReceived(data.getReceivedEnergy());
    data.computeVariation();
    data.computeMeanVariation();
}

void Hardware::showSerial() {
    data.printSerial();
    // sem LED/buzzer, a estabilidade so aparece aqui
    Serial.print("estado: ");
    Serial.println(data.isStable() ? "estavel" : "INSTAVEL");
    Serial.print("ultimo envio: ");
    Serial.println(lastPushOk ? "ok" : "--");
    conn.printStatus();
}

void Hardware::collector() {
    readReceivedEnergy();
}

void Hardware::manipulator() {
    computeAll();
}

void Hardware::printer() {
    showSerial();
}

bool Hardware::push() {
    lastPushOk = hooks.push(data.toJson(), conn);
    return lastPushOk;
}

bool Hardware::pull() {
    bool ok = hooks.pull(conn);
    if (ok) data.applyHooks(hooks);
    return ok;
}

void Hardware::keepConnection() {
    conn.keepAlive();
}

int Hardware::getTimer() {
    return data.getTimer();
}

#endif
