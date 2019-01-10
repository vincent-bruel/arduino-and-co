## Subject: Switch board to with a 20A contactor to turn ON/OFF the dust collector.

WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

## Electrical diagram for the 230V switch board

![Diagram](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Switch-Board/switch-board.png)

## Example of switch board
Here the 2A switch has been forgotten, if you compare to the Electrical diagram.

![Diagram](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Switch-Board/20181201_124000.jpg)

## How does it work ?
When the Controler-Board receives order from sensors (Hall sensors, Manual switches), it
turns the relay ON, which puts the Contactor 20A ON, which makes 230V live OK into the triggered plug
for the dust collector blower.