# v3.0
A compact MIDI-controlled loop switcher designed to fit beneath a guitar pedalboard. It enables efficient switching of up to four mono effects pedals, using an ESP32 development board for processing. The device features BLE MIDI connectivity, relay-based signal switching, and LED indicators for clear visual feedback.

![Loop Switcher Diagram](https://lukewakeford.co.uk/wp-content/uploads/2025/01/LoopSwitcherDiagram.png)
![Circuit Board Unpopulated](https://i.imgur.com/rXYmMo1.jpeg)
![Circuit Board Populated](https://i.imgur.com/NJytogt.jpeg)

# Features
- **Hardware MIDI I/O:** MIDI input and output supported via 3.5mm TRS connectors, ensuring compatibility with modern MIDI standards.
- **Effects Loop Integration:** Supports up to 4 mono effects pedals, with signal routing through 3.5mm TRS connections for a streamlined setup.
- **ESP32 SuperMini:** Provides processing power and enables BLE-MIDI passthrough for seamless wireless MIDI communication.
- **MINI560 Pro PSU:** High-efficiency step-down buck converter accepts 5V to 20V input and outputs a stable 5V, ensuring reliable power delivery to the system.

# 3.5 vs 6.5mm TRS
This project uses compact 3.5mm stereo TRS connectors to handle mono signals for each effects pedal. This design choice reduces the overall size of the project, making it more suitable for tight spaces, such as beneath a pedalboard. While this departs from the traditional 6.5mm standard, compatibility is ensured through the use of 3.5mm stereo to 6.5mm mono splitter cables. 

# Dependencies
- **BLE-MIDI Transport:** Utilizes the Arduino BLE-MIDI Library for Bluetooth MIDI communication.
- **MIDI Library:** Built upon the FortySevenEffects Arduino MIDI Library for robust MIDI processing and handling.
