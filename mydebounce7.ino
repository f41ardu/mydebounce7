/* 
  
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
