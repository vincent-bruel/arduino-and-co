## Subject: Control a dust collector (Jet DC110A-M 230V 1.5HP) via magnetic sensors on blast gates and/or with 4 way line selector
Note that the relay controled by the Arduino Nano does not control directly the dust collector: it controls a power Contactor that controls the dust collector power.
You can use regular ethernet cables (with or without rj45 connectors) to plug sensors and switches to the PCB hosting the Arduino and the relay.

The magnetic detection is made with hall sensors (cheap A3144).

WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

## Logical Architecture
This schema shows the logical architecture.
The dust collector has two crosses on it since only the blower part is used: the vortex, the bags, and the mobile cart on wheels are not used.
The motor board for the "Mobile hole board" movement is not yet developped, but it will be based on a Arduino Nano also and a powerfull DC motor driver (Wiper motor certainly):
1. "Mobile hole board" movement will be bound to the blast gate detector (via Serial Comm) to select the main dust collection line when activated: currently I have to manually move the "mobile hole board" in front of the main line hole.
2. Nowadays a simple switch is used to turn the dust collector after manually having moved the "mobile hole board" for the non-main-line dust producers
3. This simple switch will be replaced by an analog potentiometer (or a rotary encoder) to select which line to align with the "mobile hole board".

![Logical Architecture](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/DustCollectorCommander-architecture.jpg)

## Some use cases
1. Use the Bandsaw: 
	A. Operator will turn the 4 way selector to the Bandsaw position
	B. The Arduino motor controler (AMC-board) will Turn the dust collector off (if it was on), 
	B. AMC-board will Send, via Serial Comm, an order to the Motor Board to move the "mobile hole board" in the Bandsaw line position
	C. AMC-board will Wait a few seconds for the Motor board to acomplish its task
	D. AMC-board will Turn the dust collector ON.
	E. Operator will use the Bandsaw
	F. Operator will turn the 4 way selector to the OFF position
	G. AMC-board will Turn the dust collector OFF.

2. Use the Miter saw
	A. Whe assume that the 4 way selector is in the OFF position
	B. Operator will push the blast gate of the Miter saw (open position)
	C. AMC-board will Turn the dust collector ON
	D. Operator will use the miter saw
	E. Operator will push the blast gate of the Miter saw (closed position)
	F. AMC-board will Turn the dust collector OFF.

## Electrical diagram for the Arduino Dust controler
In this diagram, only one Hall Sensor and only one manual switch are drawn to stay clear.
But you can add as many as there are Numerical/Analogical PIN on the Arduino you choose.
All black wires are connected together (and here to the Arduino GND pin) in this type of protoboard.
All red wires are connected together (and here to the Arduino 5V pin) in this type of protoboard.

![Diagram](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/DustCollectorCommander_bb.jpg)
  
## Electrical diagram for the board switch
<This diagram will be drawn very soon>

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

## Pinout mapping for the 230V box controlling the dust collector
See photo and plans.
