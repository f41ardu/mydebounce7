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

#include "pinclass3.h"

/*
  PinClass3::PinClass3(): // Constructor
  _pin(0), _status(0)
  {
  //leerer Constructor;
  }
*/
PinClass3::PinClass3(uint8_t a): // Constructor mit Initialisierung
  _pin(a)
{
  init(_pin);
}

PinClass3::PinClass3(uint8_t pin, unsigned int OnTime, unsigned int OffTime): // Contructor
  _pin(pin), _OnTime(OnTime), _OffTime(OffTime)
{
  init(_pin);
  _previousMillis = millis();
  off();
}

PinClass3::~PinClass3() // Destructor
{
}

void PinClass3::init(uint8_t pin) // LED intialsieren
{
  _pin = pin;                   // speichert den LED Pin in der privaten Variable _led
  pinMode(_pin, OUTPUT);
}
void PinClass3::on() // LED ein
{
  _status = true;
  digitalWrite(_pin, HIGH); //set the pin HIGH and thus turn LED on
}

void PinClass3::off() // LED aus
{
  _status = false;
  digitalWrite(_pin, LOW); //set the pin HIGH and thus turn LED off
}

void PinClass3::blink(int intervall) // LED intervall ms blinken lassen
{
  // check to see if it's time to change the state of the LED
  if ((_currentMillis - _previousMillis >= intervall / 2))
  {
    toggle();  // Turn it off
    _previousMillis = _currentMillis;  // Remember the time
  }
  else if ((_currentMillis - _previousMillis >= intervall / 2))
  {
    toggle();  // turn it on
    _previousMillis = _currentMillis;   // Remember the time
  }
  _currentMillis = millis();
}

void PinClass3::fade(int value) // LED Helligkeit setzen
{
  analogWrite(_pin, value);
}

void PinClass3::toggle()
{
  _status ? off() : on();
}

void PinClass3::timechange(int OnTime, int OffTime) //
{
  _OnTime = OnTime;
  _OffTime = OffTime;
}

void PinClass3::flash() {
  // check to see if it's time to change the state of the LED
  if ((_currentMillis - _previousMillis >= _OnTime))
  {
    toggle();  // Turn it off
    _previousMillis = _currentMillis;  // Remember the time
  }
  else if ((_currentMillis - _previousMillis >= _OffTime))
  {
    toggle();  // turn it on
    _previousMillis = _currentMillis;   // Remember the time
  }
  _currentMillis = millis();
}


