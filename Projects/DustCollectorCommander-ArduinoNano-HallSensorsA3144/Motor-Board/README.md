## Wiring Schema

![Wiring](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Motor-Board/motor-board.jpg)
  
## Components used
1. DC 12V wiper motor
2. VNH2SP30 1 motor controler, high current
3. Arduino Nano (or Uno), at least a 5V Arduino.

##Truth table to control the motor:

Action | Pin states
-------------------
STOP | D7 0, D8 0 & D7 1, D7 1
CCW | D7 0, D8 1 
CW | D7 1, D8 0