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

#include "bounce.h"


  bounce::bounce(): // Constructor
  _pin(0), _status(0), _previousMillis(0), _currentMillis(0), _intervalMillis(0) 
  {
  //leerer Constructor;
  }

bounce::bounce(uint8_t a): // Constructor mit Initialisierung
  _pin(a),  _status(0), _previousMillis(0), _currentMillis(0), _intervalMillis(0)
{
  init(_pin);
}

bounce::bounce(unsigned int intervall, uint8_t a): // Constructor mit Initialisierung
  _pin(a), _status(0), _previousMillis(0), _currentMillis(0), _intervalMillis(intervall)
{
  init(_pin);
  _previousMillis = millis();
}

bounce::~bounce() // Destructor
{
}

void bounce::init(uint8_t pin) // LED intialsieren
{
  _pin = pin;                   // speichert pin in der privaten Variable _pin
  pinMode(_pin, INPUT);
}

volatile bool bounce::read()
{
  bool newState = digitalRead(_pin);
  if (_status != newState ) {
    if (millis() - _previousMillis >= _intervalMillis) {
      _previousMillis = millis();
      _status = newState;
    }
  }
  return _status;
}

