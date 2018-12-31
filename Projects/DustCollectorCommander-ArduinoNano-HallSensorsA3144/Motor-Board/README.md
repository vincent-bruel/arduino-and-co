## Wiring Schema

![Wiring](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Motor-Board/motor-board.jpg)


## Pseudo Algorithm for moving the mobile hole linear

1. If motor is not moving and no hall sensor is activated => ERROR
Because we always stop the motor in front of a hole position, so the magnet is always in front of a hall sensor.
2. Current hole number = Current hall sensor activated.
3. Wait for 4-way-selector to be moved (ie different value than the actual one), when operator wants to select another hole/dust line. This gives us a Desired hole number
4. If Desired hole number > Current hole number move motor Counter-Wise
5. If Desired hole number < Current hole number move motor Counter-Clock-Wise
6. Stop motor when a different hall sensor is activated
7. Goto 2.

## Components used
1. DC 12V wiper motor
2. VNH2SP30 1 motor controler, high current
3. Arduino Nano (or Uno), at least a 5V Arduino.


## Truth table to control the motor:

Action | Pin states
-------|-----------
STOP   | D7 0, D8 0 & D7 1, D7 1
CCW    | D7 0, D8 1 
CW     | D7 1, D8 0