/*
  Copyright © 2017 Th. Rautenstrauch. All Rights Reserved.

  Redistribution and use in source and binary forms, with or without modification, are permitted provided that
  the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and
   the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
   and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. The name of the author may not be used to endorse or promote products derived from this software without 
   specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY Th. Rautenstrauch "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
   BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
   DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
   OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
   OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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


