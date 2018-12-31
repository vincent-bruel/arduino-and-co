## Subject: Control a dust collector (Jet DC110A-M 230V 1.5HP) via magnetic sensors on blast gates and/or with 4 way line selector
Note that the relay controled by the Arduino Nano does not control directly the dust collector: it controls a power Contactor that controls the dust collector power.
You can use regular ethernet cables (with or without rj45 connectors) to plug sensors and switches to the PCB hosting the Arduino and the relay.

The magnetic detection is made with hall sensors (cheap A3144).

WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

## Logical Architecture
This schema shows the logical architecture.
It shows:
1. The Mobile-Hole-Linear-Plate : a simple wood board with four 125mm hole in it. One of this 4 holes is aligned (nowadays: manually) via a DC motor with rack and pinion.
2. The Motor-Board: Arduino Nano and DC motor driver
3. The Controler-Board: Arduino Nano and relay. Input: magnetic sensors on each blast gate. Output: live to the Switch-Board.
4. The Switch-Board: 230V box with a 20A contactor triggered by the relay which is inside the Controler-Board.
5. The 4 way selector: a simple potentiometer (or multi switch), with 4 positions to make the Controler-Board ask to the Motor-Board to select the desired Hole line.
6. The Blast gates with magnetic sensor: DIY wood blast gate, with a A3144 sensor, a 10Kohm resistor and a magnet
7. The flexible pipes: thin metallic flexible pipes 125mm diameter
8. The non flexible pipes: standard 100mm PVC pipes (grey ones).
9. The DC 12V motor: a car wiper motor
10. The green lines: they are made of RJ45 cables with three cables used for 5V, GND, and return SIGNAL.
11. The red lines: they are made of 3x1.5mm flexible cable for 230V, with only 2 cables used on the Controler-Board to Switch-board path.
12. The violet lines: they are made of RJ45 cables with three cables used for: RX, TX, GND.

The dust collector has two crosses on it since only the blower part is used: the vortex, the bags, and the mobile cart on wheels are not used.
The motor board for the "Mobile hole board" movement is not yet developped, but it will be based on a Arduino Nano also and a powerfull DC motor driver (Wiper motor certainly):
1. "Mobile hole board" movement will be bound to the blast gate detector (via Serial Comm) to select the main dust collection line when activated: currently I have to manually move the "mobile hole board" in front of the main line hole.
2. Nowadays a simple switch is used to turn the dust collector after manually having moved the "mobile hole board" for the non-main-line dust producers
3. This simple switch will be replaced by an analog potentiometer (or a rotary encoder) to select which line to align with the "mobile hole board".

![Logical Architecture](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/DustCollectorCommander-architecture.jpg)

## Some use cases
1. Use the Bandsaw: 
	1. Operator will turn the 4 way selector to the Bandsaw position
	2. The Controler-Board will Turn the dust collector off (if it was on), 
	3. Controler-Board will Send, via Serial Comm, an order to the Motor-Board to move the "mobile hole board" in the Bandsaw line position
	4. Controler-Board will Wait a few seconds for the Motor-board to accomplish its task
	5. Controler-Board will Turn the dust collector ON.
	6. Operator will use the Bandsaw
	7. Operator will turn the 4 way selector to the OFF position
	8. Controler-Board will Turn the dust collector OFF.

2. Use the Miter saw
	1. Whe assume that the 4 way selector is in the OFF position
	2. Operator will push the blast gate of the Miter saw (open position)
	3. Controler-Board will Turn the dust collector ON
	4. Operator will use the miter saw
	5. Operator will push the blast gate of the Miter saw (closed position)
	6. Controler-Board will Turn the dust collector OFF.

3. Typical woodworking use case
	1. Use Bandsaw multiple times (Operator manipulates the 4-way-selector)
	2. Use the Jointer multiple times  (Operator manipulates the 4-way-selector)
	3. Use the Table saw or Miter saw multiple times  (Operator manipulates the Miter saw blast gate)
	4. Use the workbench blast gate to connect and use the orbital sander  (Operator manipulates the Workbench blast gate)
	5. Use the workbench blast gate to connect and use the flexible pipe to clean the workbench (Operator manipulates the Workbench blast gate)
	
Note that we do not move the Mobile-hole-board to the Main line position when 4 way selector is in OFF position.
This allow us to use for example the bandsaw multiple times (switching 4 way selector from BandSaw to OFF to Bandsaw to OFF...) without
moving the Mobile-hole-board many times, saving time and saving the motor parts.