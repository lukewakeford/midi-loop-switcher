/*
  Requires the excellent arduino_midi_library from Forty Seven Effects https://github.com/FortySevenEffects/arduino_midi_library
  Lightweight sketch for switching signal relays based on midi cc changes
  Switches relays 1-4 using midi control change messages:
  - Channel: 2 by default
  - Number: 1-4 (Relays 1-4)
  - Value: 0-64 = OFF - 64-127 = ON
  Built for ESP32 SuperMini
  Forwards BLE midi on to hardward midi out
*/

#include <HardwareSerial.h>
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32_NimBLE.h>

#define midiInputChannel 2 // For controlling relays

// ESP32 SuperMini Pin Setup
#define relayOnePin 0
#define relayTwoPin 1
#define relayThreePin 2
#define relayFourPin 3
#define ledOnePin 9
#define ledTwoPin 7
#define ledThreePin 6
#define ledFourPin 5
#define RX 20
#define TX 21

// Create Hardware and BLE Midi instances
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, HARDWAREMIDI);
BLEMIDI_CREATE_INSTANCE("BLE MIDI", BLUETOOTHMIDI);

void setup(){
  // Define Midi Serial ports
  Serial1.begin(31250, SERIAL_8N1, RX, TX);

  // Configure digital pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledOnePin, OUTPUT);
  pinMode(ledTwoPin, OUTPUT);
  pinMode(ledThreePin, OUTPUT);
  pinMode(ledFourPin, OUTPUT);
  pinMode(relayOnePin, OUTPUT);
  pinMode(relayTwoPin, OUTPUT);
  pinMode(relayThreePin, OUTPUT);
  pinMode(relayFourPin, OUTPUT);

  // Setup callbacks and start listening for incoming Midi
  BLUETOOTHMIDI.setHandleControlChange(handleControlChange);
  BLUETOOTHMIDI.begin(MIDI_CHANNEL_OMNI);
  HARDWAREMIDI.setHandleControlChange(handleControlChange);
  HARDWAREMIDI.begin(midiInputChannel);
  // Disable hardware midi thru to avoid clashing issues
  HARDWAREMIDI.turnThruOff();
}

void loop(){
  // Read hardware Midi for the callback
  HARDWAREMIDI.read();

  // Forward bluetooth Midi to hardware Midi
  if (BLUETOOTHMIDI.read()){
    HARDWAREMIDI.send(
      BLUETOOTHMIDI.getType(),
      BLUETOOTHMIDI.getData1(),
      BLUETOOTHMIDI.getData2(),
      BLUETOOTHMIDI.getChannel()
    );
  }
}

// Engages/disengaged relays & LEDs based on a midi control change
void handleControlChange(
  byte channel, 
  byte number, 
  byte value
){
  // Generate the state based on the midi value
  // 0-64 = LOW - 64-127 = HIGH
  uint8_t STATE = ( value > 64 ) ? HIGH : LOW;
  // Set the relay and LED state based on cc numbers 1-4
  switch (number) {
  case 1:
    digitalWrite(relayOnePin, STATE); 
    digitalWrite(ledOnePin, STATE);
    break;
  case 2:
    digitalWrite(relayTwoPin, STATE);
    digitalWrite(ledTwoPin, STATE);
    break;
  case 3:
    digitalWrite(relayThreePin, STATE);
    digitalWrite(ledThreePin, STATE);
    break;
  case 4:
    digitalWrite(relayFourPin, STATE);
    digitalWrite(ledFourPin, STATE);
    break;
  }
}