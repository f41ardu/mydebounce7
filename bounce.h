/*
   Devlopment Branch
*/
// http://de.wikibooks.org/wiki/C%2B%2B-Programmierung:_Klassen

#ifndef bounce_H
#define bounce_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"  // for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

class bounce
{
  public:                             // öffentlich
    // PinClass3();                   // der Default-Konstruktor
    bounce(uint8_t a);             // Konstruktor mit Parameter
    bounce(unsigned int interval_millis,  uint8_t a); // Button Debounce
    ~bounce();                     // Class Destruktor
                                      // Funktionen
    void init(uint8_t pin);           // einen PIN initialisieren
    bool read();                      // PIN (Button) lesen

  private:                            // privat
    bool _status;
    uint8_t _pin;
    unsigned int _previousMillis, _currentMillis, _intervalMillis;
};

#endif // PinClass3
