/*
  Devlopment Branch
*/
// http://de.wikibooks.org/wiki/C%2B%2B-Programmierung:_Klassen

#include "bounce.h"

/*
  bounce::bounce(): // Constructor
  _pin(0), _status(0)
  {
  //leerer Constructor;
  }
*/
bounce::bounce(uint8_t a): // Constructor mit Initialisierung
  _pin(a)
{
  init(_pin);
}

bounce::bounce(unsigned int intervall, uint8_t a): // Constructor mit Initialisierung
  _pin(a), _intervalMillis(intervall)
{
  init(_pin);
  _previousMillis = millis();
}

 

bounce::~bounce() // Destructor
{
}

void bounce::init(uint8_t pin) // LED intialsieren
{
  _pin = pin;                   // speichert den LED Pin in der privaten Variable _led
  pinMode(_pin, INPUT);
}

bool bounce::read()
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

