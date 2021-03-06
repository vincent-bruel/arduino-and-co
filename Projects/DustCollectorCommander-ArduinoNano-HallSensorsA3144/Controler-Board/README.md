
## Electrical diagram for the Arduino Dust controler
In this diagram, only one Hall Sensor and only one manual switch are drawn to stay clear.
But you can add as many as there are Numerical/Analogical PIN on the Arduino you choose.
All black wires are connected together (and here to the Arduino GND pin) in this type of protoboard.
All red wires are connected together (and here to the Arduino 5V pin) in this type of protoboard.

![Diagram](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Controler-Board/controler-board.jpg)
  

WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

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
D2       | to RELAY DIN (command)
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
the 2 left pins (for a Songle classical blue relay).


RELAI     | Other device
----------| ----------------------
LEFT      | Output 230V phase
MIDDLE    | Input 230V phase
RIGHT     | Unused

2. Connecting low voltage side

RELAI     | Other device
----------| ----------------------
5V in     | VCC power line 5V
GND       | GND power line
DIN       | Arduino D2