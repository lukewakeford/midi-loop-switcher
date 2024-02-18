/*
  midi-loop-switcher
  Lightweight sketch for switching signal relays based on midi cc changes
  Requires the excellent arduino_midi_library from Forty Seven Effects https://github.com/FortySevenEffects/arduino_midi_library
*/

#include <MIDI.h>

const int midiChannel = 2;

const int relayOnePin = 12;
const int relayTwoPin = 14;
const int relayThreePin = 4;
const int relayFourPin = 5;

MIDI_CREATE_DEFAULT_INSTANCE();

// engages/disengaged relays based on a midi control change
void handleControlChange(
  byte channel, 
  byte number, 
  byte value
){
  // generate the state based on the midi value
  // 0-64 = LOW - 64-127 = HIGH
  uint8_t STATE = ( value > 64 ) ? HIGH : LOW;
  // set the relay state based on cc numbers 1-4
  switch (number) {
  case 1:
    digitalWrite(relayOnePin, STATE); 
    break;
  case 2:
    digitalWrite(relayTwoPin, STATE); 
    break;
  case 3:
    digitalWrite(relayThreePin, STATE); 
    break;
  case 4:
    digitalWrite(relayFourPin, STATE); 
    break;
  }
}

void setup(){
  // configure digital pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relayOnePin, OUTPUT);
  pinMode(relayTwoPin, OUTPUT);
  pinMode(relayThreePin, OUTPUT);
  pinMode(relayFourPin, OUTPUT);

  // setup the midi library
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.begin(midiChannel);
}

void loop(){
  // read midi for the callback
  MIDI.read();
}