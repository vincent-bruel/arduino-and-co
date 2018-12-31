This page describes the motorized mobile hole linear plate

## The mobile hole linear plate is inspired from this video

![AskWoodMan](https://www.youtube.com/watch?v=DTT-PUUXmUc&t=4s)

## Motorized it !

I just motorized it with a Motor-Board (see the dedicated directory) to control a DC 12V motor and some rack and pinion.
How do the Motor-Board know in which position the wood plate is ?
This is done with 4 hall sensor (the same type as the one I used on blast gates) and 1 magnet.

## Pseudo Algorithm

1. If motor is not moving and no hall sensor is activated => ERROR
Because we always stop the motor in front of a hole position, so the magnet is always in front of a hall sensor.
2. Current hole number = Current hall sensor activated.
3. Wait for 4-way-selector to be moved (ie different value than the actual one), when operator wants to select another hole/dust line. This gives us a Desired hole number
4. If Desired hole number > Current hole number move motor Counter-Wise
5. If Desired hole number < Current hole number move motor Counter-Clock-Wise
6. Stop motor when a different hall sensor is activated
7. Goto 2.


