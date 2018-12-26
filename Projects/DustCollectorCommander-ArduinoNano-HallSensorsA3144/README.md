## Subject: Control a dust collector (Jet DC110A-M 230V 1.5HP) via sensors on blast gates and/or with manual switches
Note that the relai controled by the Arduino Nano does not control directly the dust collector: it controls a power Contacter that controls the dust collector power.
You can use regular ethernet cables (with or without rj45 connectors) to plug sensors and switches to the PCB hosting the Arduino and the relay.

## Schema
![Schema](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/DustCollectorCommander_bb.jpg)
  
## You will need Arduino IDE to program arduino nano via USB.

## Pinout mapping for hall effect sensor A3144
A3144   | Other device
------- | ----------------------
VCC     | VCC power line 5V
GND     | GND power line
SIGNAL  | Arduino D3, or D4, or D5, or whatever pin you choose
VCC     | 10kohms resistor R1
SIGNAL  | 10kohms resistor R1

## Pinout mapping for switch button (configured as INPUT_PULLUP in arduino sketch, so with 20k resistor hidden)
BUTTON  | Other device
------- | ----------------------
PIN1    | 10nF C1 ceramik (103J)
PIN2    | 10nF C1 ceramik (103J)
PIN1    | VCC power line 5V
PIN2    | Arduino D6 pin 

## Pinout mapping for Arduino
ARDUINO  | Other device
-------- | ----------------------
D3,D4,D5 | to A3144 hall effect SIGNAL pin
D6, ...  | to manual switch PIN2
VIN      | to HILINK (220V-5V converter) V+ pin
GND      | to HILINK (220V-5V converter) V- pin

## Pinout mapping for the HILINK (220V-5V converter)
HILINK    | Other device
----------| ----------------------
230V pin1 | to 230V plug PHASE
230V pin2 | to 230V plug NEUTRAL
V+        | VIN Arduino
V-        | GND Arduino

## Pinout mapping for the 230V relay 10A
1. Connecting high voltage side
When looking at the relay, with the 3 pins of the high voltage side in front of you, the 2 pins to connect are
the 2 left pins.
2. Connecting low voltage side

RELAI     | Other device
----------| ----------------------
5V in     | VCC power line 5V
GND       | GND power line
DIN       | Arduino D2

## Pinout mapping for the 230V box controlling the dust collector
See photo and plans.
