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


// This code turns a led on/off through a debounced switch

#include "pinclass3.h"
#include "bounce.h"

#define SWITCH 2
#define pinGreen 5
#define pinYellow 7
#define pinRed 6

// This variables will change:
volatile bool buttonState = LOW;         // current state of the button
volatile bool lastButtonState = LOW;     // previous state of the button
volatile uint8_t counter = 0;             // button click counter

// Instantiate a Button with a 5 millisecond debounce time
bounce Button(5, SWITCH);

// Instantiate 3 LED objects with on and off time in milliseconds
PinClass3 ledGreen(pinGreen,500,500), 
          ledYellow(pinYellow,250,250), 
          ledRed(pinRed,500,50);

void setup() {
// noop
}

// forever
void loop() {
  buttonState = Button.read();
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    // increase counter only if button pressed
    if (buttonState == 1) counter++;
  }
  if (counter == 0) {
    ledGreen.blink(250);
    ledYellow.off();
    ledRed.off();
  }
  if (counter == 1)  {
    ledGreen.blink(1000);
    ledYellow.flash();
    ledRed.blink(125);
  }
  if (counter == 2)  {
    ledGreen.off();
    ledYellow.off();
    ledRed.flash();
  }
  if (counter == 3)  {
    ledGreen.off();
    ledYellow.off();
    ledRed.off();
  }
  // reset counter
  if (counter > 3) counter = 0;
}
