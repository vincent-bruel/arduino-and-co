Blast gates are DIY wood blast gate with 5 components added:

1. A RJ45 cable coming (and of course going to) the Controler-Board
2. A hall sensor (A3144, three pins)
3. A 10kohm resistor
4. A piece of steel glued to the blast gate handle with some polyurethan glue.
It is important to use glue that has more force than your 2.2kg magnet of 1cm2 (so more than 2kg per cm2)
Polyurethan glue can handle 25kg per cm2
5. A magnet on this piece of metal. A 2.2kg neodym magnet should be enough.

The small circuit hosting the A3144 + the resistor must be glued to the non-moving part of the blast gate.
I used hot glue.
The magnet should be aligned in front of the A3144 sensor: they must be coplanar in a certain way, and their center must be aligned within around 2mm.
Note that the magnetic detection will only work on one pole of the magnet.
So if it does not work, simply flip the magnet on itself to present the other magnetic pole to the A3144.


## Example of blast gates
![The blast gate](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Blast-Gate/20181206_091216.jpg)

![Zoom on the hall sensor and the magnet](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Blast-Gate/20181201_123920.jpg)
