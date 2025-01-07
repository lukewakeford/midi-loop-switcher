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

# BOM
| **Name**           | **Designator**          | **Quantity** |
|--------------------|-------------------------|--------------|
| 2.54-1*2P Header   | MINI560                 | 4            |
| MINI560 Pro 5V     | MINI560                 | 1            |
| 2.54-1*8P Header   | ESP32-C3 SuperMini      | 2            |
| ESP32-C3 SuperMini | ESP32-C3 SuperMini      | 1            |
| DIP-8 Socket       | U5                      | 1            |        
| Optoisolator 6N137 | U5                      | 1            |
| 220Ω Resistor      | R5,R7,R8,R9,R10,R11,R12 | 7            |
| 1kΩ Resistor       | R1,R2,R3,R4,R6          | 5            |
| 1N4004 Diode       | D1,D2,D3,D4,D5          | 5            |
| PN2222AL Transistor| U1,U2,U3,U4             | 4            |
| 3mm LED            | LED1,LED2,LED3,LED4     | 4            |
| 3.5mm TRS          | MIDIIN,MIDOUT,PEDAL1-4  | 6            |
| 6.5mm TRS          | INPUT,OUTPUT            | 2            |
| Omron G5V-2-H1     | K1,K2,K3,K4             | 4            |
| DC Jack            | N/A                     | 1            |

# Assembly

#### Step 1: Resistors
- **Install R1, R2, R3, R4, R6:**
  - Place each resistor into its corresponding position on the PCB.
  - Solder the leads and trim excess wire.
- **Install R5, R7, R8, R9, R10, R11, R12:**
  - Repeat the same process as above.

#### Step 2: Diodes
- **Install D1, D2, D3, D4, D5:**
  - Align the cathode (marked end) with the PCB’s silkscreen.
  - Solder and trim the leads.

#### Step 3: Transistors
- **Install U1, U2, U3, U4:**
  - Ensure proper orientation and alignment.
  - Solder the pins in place.

#### Step 4: LEDs
- **Install LED1, LED2, LED3, LED4:**
  - Align the flat side of the LED with the PCB marking.
  - Solder and trim leads.

#### Step 5: Connectors and Jacks
- **Install MIDIIN, MIDOUT, PEDAL1, PEDAL2, PEDAL3, PEDAL4:**
  - Place the connectors in their respective positions.
  - Solder all pins securely.
- **Install INPUT, OUTPUT:**
  - Install and solder one connector at a time to ensure proper alignment.

#### Step 6: Relays
- **Install K1, K2, K3, K4:**
  - Place the relays into their designated slots.
  - Solder them securely.

#### Step 7: DC Jack
- **Install the DC Jack:**
  - Insert the jack into its position.
  - Solder all contact points.

#### Step 8: Integrated Circuits and Headers
- **Solder the headers and sockets:**
  - 4x 2pin headers for the MINI560 Pro
  - 2x 8pin headers for the ESP32-C3
  - 8 pin socket for the Optoisolator (U5)
- **Insert MINI560 Pro:**
  - Ensure the correct orientation of the PSU with voltage IN on the left and OUT on the right. There is an arrow on the bottom of the module to help with this.
  - Place the module onto the previously soldered headers.
- **Insert ESP32-C3 SuperMini:**
  - Align the module pins with the corresponding footprint on the PCB.
  - Place the module onto the previously soldered headers.
- **Insert the Optoisolator (U5):**
  - Place the IC into the previously soldered socket, ensuring correct orientation.


![Circuit Board Populated](https://i.imgur.com/NJytogt.jpeg)

# 3.5 vs 6.5mm TRS
This project uses compact 3.5mm stereo TRS connectors to handle mono signals for each effects pedal. This design choice reduces the overall size of the project, making it more suitable for tight spaces, such as beneath a pedalboard. While this departs from the traditional 6.5mm standard, compatibility is ensured through the use of 3.5mm stereo to 6.5mm mono splitter cables. 

# Dependencies
- **BLE-MIDI Transport:** Utilizes the Arduino BLE-MIDI Library for Bluetooth MIDI communication.
- **MIDI Library:** Built upon the FortySevenEffects Arduino MIDI Library for robust MIDI processing and handling.
