# v3.0
A compact MIDI-controlled loop switcher designed to fit beneath a guitar pedalboard. It enables efficient switching / bypassing of up to four mono effects pedals, using an ESP32 development board for processing. The device features BLE MIDI connectivity, relay-based signal switching, and LED indicators for clear visual feedback.

# Switching Logic
- By default, each pedal is bypassed using a loop between pins 11 and 6.
- When engaged, the conntected pedal is looped in using pins 9 and 8.
- Pins 13 and 4 carry the signal **IN** from the input jack or previous pedal and **OUT** to the next pedal or output jack

![Loop Switcher Relay Schema](https://github.com/user-attachments/assets/c99659fc-116c-4d3b-bc2b-e44422bc4c06)

# Features
- **Hardware MIDI I/O:** MIDI input and output supported via 3.5mm TRS connectors, ensuring compatibility with modern MIDI standards. Checkout my other project [slimdin.uk](https://slimdin.uk) for the smallest 5pin din to trs midi adapter you've seen in a while.
- **Effects Loop Integration:** Supports up to 4 mono effects pedals, with signal routing through 3.5mm TRS connections for a streamlined setup.
- **ESP32 SuperMini:** Provides processing power and enables BLE-MIDI passthrough for seamless wireless MIDI communication.
- **MINI560 Pro PSU:** High-efficiency step-down buck converter accepts 5V to 20V input and outputs a stable 5V, ensuring reliable power delivery to the system.
  
![LoopSwitcherDiagram](https://github.com/user-attachments/assets/ce536639-fe6f-47b1-a9bc-3814a44265fb)

# Build Pictures
![Circuit Board Populated](https://i.imgur.com/NJytogt.jpeg)

# 3.5 vs 6.5mm TRS
This project uses compact 3.5mm stereo TRS connectors to handle mono signals for each effects pedal. This design choice reduces the overall size of the project, making it more suitable for tight spaces, such as beneath a pedalboard. While this departs from the traditional 6.5mm standard, compatibility is ensured through the use of 3.5mm stereo to 6.5mm mono splitter cables. 

# Dependencies
- **BLE-MIDI Transport:** Utilizes the Arduino BLE-MIDI Library for Bluetooth MIDI communication.
- **MIDI Library:** Built upon the FortySevenEffects Arduino MIDI Library for robust MIDI processing and handling.
