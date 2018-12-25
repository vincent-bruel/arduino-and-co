## This Library is a brick to build a heater system with a DS3231-AT24C32-32Ko-I2C-EEPROM
## Manages heater consignes in EEPROM (read, write, update, delete, swap).
## Consignes are defined by Web (as String) or via an Consigne Object
## Computes the best consigne for a given time.
## Low memory footprint (suitable to a MKR1000)
## Library is configured to manage 10 consigned max out of the box. See .h to modify according to your needs.
## EEPROM adress is 0x57. See .h to modify it if needed.
## A consigne defines:
1. Priority
2. Days of the week for which the consigne is activated
3. Start hour & minute
4. Float temperature: the heater consigne