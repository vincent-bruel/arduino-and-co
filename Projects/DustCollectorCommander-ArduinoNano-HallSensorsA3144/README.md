## Subject: Control a dust collector (Jet DC110A-M 230V 1.5HP) via magnetic sensors on blast gates and/or with 4 way line selector
Note that the relay controled by the Arduino Nano does not control directly the dust collector: it controls a power Contactor that controls the dust collector power.
You can use regular ethernet cables (with or without rj45 connectors) to plug sensors and switches to the PCB hosting the Arduino and the relay.

The magnetic detection is made with hall sensors (cheap A3144).

WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

Note: 06 janv 2019: The Controler-Board and Switch-Board schema are used and work very well since several weeks.
The Motor-Board is still in development (almost the mechanical rack and pinion have to be finalized, and the algorithm has not been tested)

All video below are in FRENCH language but have ENGLISH native subtitles (as opposed to automatic garbage/random subtitles)

1 - Presentation
![Presentation](https://youtu.be/Z6V0JRFPG_k}

2 - Schemas and source code on GITHUB
![Schemas and source code on GITHUB](https://youtu.be/-QdaTGBWYwc)

3 - The JET DC1100 blower
![The JET DC1100 blower](https://youtu.be/g1BsIPjSJYs)

4 - The mobile linear plate
![The mobile linear plate](https://youtu.be/00rngfceFSk)

5 - Electronic components
![Electronic components](https://youtu.be/vBWDjufKLEc)

6 - Outdoor SILO
![Outdoor SILO](https://youtu.be/YXTrqXZPfOM)

7 - Program the Arduino
![Program the Arduino](https://youtu.be/8uKOoJBHGeQ)


## Logical Architecture choice

**ONE-LINE**: If your workshop is a small area, you will have only one main dust collection line, 
so no need for a Motor-Board nor a Mobile-Hole-Linear-Plate (see description below).

**SEVERAL-LINES**:If your workshop is a big area, or if you want to optimize/maximize 
the dust collection airflow you will have to shorten the dust collection lines 
for the big producers of shavings: in this case you will need a manual Mobile-Hole-Linear-Plate (you slide it manually) or
a motorized one with a Motor-Board.

## Logical Architecture "ONE-LINE": only one dust collection line
![Logical Architecture](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/DustCollectorCommander-architecture-one-line.jpg)


The above schema shows the logical architecture.
It shows:

1. The Controler-Board: Arduino Nano and relay. Input: magnetic sensors on each blast gate. Output: live to the Switch-Board.
2. The Switch-Board: 230V box with a 20A contactor triggered by the relay which is inside the Controler-Board.
3. The Blast gates with magnetic sensor: DIY wood blast gate, with a A3144 sensor, a 10Kohm resistor and a magnet
4. The flexible pipes: thin metallic flexible pipes 125mm diameter
5. The non flexible pipes: standard 100mm PVC pipes (grey ones).
6. The green lines: they are made of RJ45 cables with three cables used for 5V, GND, and return SIGNAL.
7. The red lines: they are made of 3x1.5mm flexible cable for 230V, with only 2 cables used on the Controler-Board to Switch-board path.

## Logical Architecture "SEVERAL-LINES": several dust collection lines
![Logical Architecture](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/DustCollectorCommander-architecture-four-lines.jpg)

The above schema shows the logical architecture.
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
The motor board for the "Mobile hole board" movement based on a Arduino Nano also and a powerfull DC motor driver (Wiper motor certainly):
1. "Mobile hole board" movement will be bound/connected to the blast gate detector (via Serial Comm) 
to select the main dust collection line when activated: currently I have to manually move the "mobile hole board" in front of the main line hole.
2. Nowadays a simple switch is used to turn the dust collector on after manually having moved the "mobile hole board" for the non-main-line dust producers
3. This simple switch will be replaced by a 4 way selector (rotary encoder) to select which line to align with the "mobile hole board".
4. When operator activates a blast-gate (on), the Controler-Board sends a message to the Motor-Board via Serial-Com to tell it to move to
the Main-Line position.


## Some use cases for the "ONE-LINE"

1. Use the Miter saw (or any other device of the main-line)
	1. Operator will push the blast gate of the Miter saw (open position)
	2. Controler-Board will Turn the dust collector ON
	3. Operator will use the miter saw
	4. Operator will push the blast gate of the Miter saw (closed position)
	5. Controler-Board will Turn the dust collector OFF.

3. Typical woodworking meta use case 
	1. Use Miter saw (or any other device) multiple times 
	2. Use the workbench blast gate to connect and use the orbital sander  (Operator manipulates the Workbench blast gate)
	3. Use the workbench blast gate to connect and use the flexible pipe to clean the workbench (Operator manipulates the Workbench blast gate)
	
## Some use cases for the "SEVERAL-LINES"
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

3. Typical woodworking meta use case (use case using the two previous uses cases)
	1. Use Bandsaw multiple times (Operator manipulates the 4-way-selector)
	2. Use the Jointer multiple times  (Operator manipulates the 4-way-selector)
	3. Use the Table saw or Miter saw multiple times  (Operator manipulates the Miter saw blast gate)
	4. Use the workbench blast gate to connect and use the orbital sander  (Operator manipulates the Workbench blast gate)
	5. Use the workbench blast gate to connect and use the flexible pipe to clean the workbench (Operator manipulates the Workbench blast gate)
	
Note that we do not move the Mobile-hole-board to the Main line position when 4 way selector is in OFF position.
This allow us to use for example the bandsaw multiple times (switching 4 way selector from BandSaw to OFF to Bandsaw to OFF...) without
moving the Mobile-hole-board many times, saving time and saving the motor parts.