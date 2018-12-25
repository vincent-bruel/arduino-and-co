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