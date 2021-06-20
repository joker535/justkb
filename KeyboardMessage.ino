/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "kbtools.h"
#include "encoder.h"

Encoder ecc(13,14);
Kbtools kb;

void setup() {
  // make the pushButton pin an input:
  // initialize control over the keyboard:
  kb.begin();
  ecc.encoderInit();
}

void loop() {
  int8_t newv = ecc.encoderUpdate();
  if(newv > 0){
    kb.record();
    kb.addKeyPress(KC_A);
    kb.addKeyPress(KC_B);
    kb.report();
    kb.record();
    kb.report();
  }else if(newv < 0){
    
  }
}
