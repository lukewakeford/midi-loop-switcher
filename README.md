# v3.0

MIDI loop switcher, designed to fit underneath a guitar pedal board and enable switching of up to 4 mono effects pedals.

# Features
- Hardware MIDI in and out via 3.5mm TRS
- I/O for up to 4 mono effects pedals via 3.5mm TRS
- ESP32 SuperMini (enables BLE-MIDI through)
- MINI560 Pro PSU (5V-20V in to 5V out step-down buck converter)

# Of Note
Uses 3.5mm stereo TRS to carry mono signals to and from each effects pedal, which breaks from the 6.5mm standard slightly and requires 3.5mm stereo to 6.5mm mono splitter cables (I've also designed a small circuit board to perform this function, TBA.).

# Depends on
BLE-MIDI transport https://github.com/lathoub/Arduino-BLE-MIDI
FortySevenEffects MIDI Library https://github.com/FortySevenEffects/arduino_MIDI_library