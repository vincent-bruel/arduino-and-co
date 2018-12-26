## Subject
Common Hardware platform used in several of my projects (see Projects directory)
I did not found the exact fritzing part for the dot matrix module 4x8x8.
So the pins are ordered as they are in my build, but does not correspond to the pin names in
the fritzing schema.
![Schema](https://github.com/vincent-bruel/arduino-and-co/blob/master/CommonHardware/ESP32-4xDotMatrix8x8Leds/ESP32-4x8x8%20dot%20matrix%20led%20max7219_bb.jpg)

![Schema](https://github.com/vincent-bruel/arduino-and-co/blob/master/CommonHardware/ESP32-4xDotMatrix8x8Leds/20181225_112027.jpg)

## Hardware list
1x PCB prototype board, space 2.54mm between holes
1x ESP32, for example DOIT ESP32
1x module of 4x8x8 matrix dot led (red), with MAX7219 chip.
2x headers (2.54mm spacing) to remove easily ESP32 from PCB 

## Pinout mapping

ESP32   | MAX7219 8x8 LED Matrix
------- | ----------------------
VIN     | VCC
GND     | GND
GPIO12  | DIN
GPIO15  | CS
GPIO14  | CLK

## Powering this platform
Two choices:
1-Plug micro usb cable in the ESP32
2-If you solder the optional female jack barrel, plug regulated 5V-1A male jack in it.

## Troubleshooting
If Arduino IDE cannot see your ESP32 after installing the plugin, look at the chipset which is near
the ESP32 micro usb port:
1. It is square: chances are that it has a CP2102 chipset => install the driver for CP2102
2. It is rectangle: chances are that it has a CH340G or CH341 chipset => install the driver for CH340G or CH341
