

WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

## Electrical diagram for the 230V switch board

![Diagram](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/Switch-Board/switch-board.png)

## How does it work ?
When the Controler-Board receives order from sensors (Hall sensors, Manual switches), it
turns the relay ON, which puts the Contactor 20A ON, which makes 230V live OK into the triggered plug
for the dust collector blower.