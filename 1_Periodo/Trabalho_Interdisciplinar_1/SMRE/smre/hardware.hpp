#ifndef HARDWARE_HPP
#define HARDWARE_HPP

#include "config.hpp"
#include "connection.hpp"
#include "hooks.hpp"
#include "data.hpp"

// Versao minima: sem OLED, LED, buzzer nem botao. O unico periferico
// e o potenciometro de E_r; todo o feedback sai pelo Serial.
class Hardware {
    private:
        DataRepository data;
        Connection conn;
        Hooks hooks;

        bool lastPushOk;

    public:
        Hardware();

        void begin();

        int readReceivedEnergy();

        void computeAll();

        void showSerial();

        void collector();
        void manipulator();
        void printer();

        bool push();
        bool pull();

        void keepConnection();
        int getTimer();
};

#endif
