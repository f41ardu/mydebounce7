/*

 */

// You may find this helpful http://de.wikibooks.org/wiki/C%2B%2B-Programmierung:_Klassen

#ifndef PinClass3_H
#define PinClass3_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"  // for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

class PinClass3
{
  public:                             // öffentlich
    // PinClass3();                   // der Default-Konstruktor
    PinClass3(uint8_t a);             // Konstruktor mit Parameter
    PinClass3(uint8_t a, unsigned int OnTime, unsigned int OffTime); 
    //   PinClass3(const LED& a);     // Copy-Konstruktor wird nicht benötigt
    ~PinClass3();                     // Class Destruktor
                                      // Funktionen
    void init(uint8_t pin);           // einen PIN initialisieren
    void on();                        // einen PIN einschalten
    void off();                       // einen PIN ausschalten
    void blink(int intervall);        // PIN ein und auschalten (intervall)
    void fade(int value);             // eine Spannung (0 .. 5Volt/255) am PIN ausgeben
    void timechange(int OnTime, int OffTime);
    void toggle();                    // PIN Zustand umschalten (ON/OFF, OFF/ON)
    void flash();                     // PIN ein und auschalten (OnTime, OffTime)

  private:                            // privat
    bool _status;
    uint8_t _pin;
    unsigned int _previousMillis, _currentMillis, _intervalMillis, _OnTime, _OffTime;
};

#endif // PinClass3


