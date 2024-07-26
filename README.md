# v1.0

Midi loop switcher, designed to fit undneath a guitar pedal board and enabled switching of up to 4 mono effects pedals.

Makes use of 3.5mm stereo jacks to carry mono signals to and from each effects pedal, this requires 3.5mm stereo to 6.5mm mono splitter cables to split the signal (I've also designed a small circuit board to perform this function tba.)

Built around the ESP8266 with a light weight sketch for switching signal relays.

Uses Forty Seven Effects https://github.com/FortySevenEffects/arduino_midi_library to listen for Midi CC changes on channel 2, numbers 1-4, value 0-64 = OFF / 64-127 = ON