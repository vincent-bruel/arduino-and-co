## Subject: bypass the on/off switch of the Jet DC1100-A-M

After that modification your blower will be ON forever (but it is a reversible modification), which
means it's ON/OFF state can be controlled by another board that is outside of the blower case.


WARNING: do not attempt to wire/solder anything unless you have the required skills to do it: this project
requires 230V wiring, that can be dangerous and cause serious injury/death/...

## Example of switch to bypass
![The switch mounted](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/BlowerSwitchBypass/20181122_134940.jpg)

![The switch unmounted](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/DustCollectorCommander-ArduinoNano-HallSensorsA3144/BlowerSwitchBypass/20181122_145118.jpg)

## The modification
1. Unplug the blower !
2. Remove the 2 Philips screws (one on top, one on the bottom of the yellow plastic)
3. Connect a cable from pin 1 to 2
4. Connect a cable from pin 3 to 4
5. Put back the screws in their original place
