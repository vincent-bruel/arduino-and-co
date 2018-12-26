## Subject: Backlight a photo :camera: (inside a wood or aluminium frame :framed_picture:), 
and place behind some leds and a lcd 16x2 chars
to point/highlight some locations into the photo.
		

## Schema
![Schema](https://github.com/vincent-bruel/arduino-and-co/blob/master/Projects/LuminousPhotoFrame-Leonardo-74HC795-2x16LCDSerial/LuminousFrameFritzing_bb.jpg)
  
  
## Mandatory Libraries, to install BEFORE programming the sketch to the Arduino:
	Arduino standard SoftwareSerial
	
## Hardware
1. Arduino Leonardo or any Arduino that works with 5V (Nano, Mega, ...)
2. 16 Red led (16 is a maximum)
3. 16 resistor 220ohms 1/4W (16 is a maximum)
4. 2 shift register 74HC795 (each drives 8 leds)
5. Some cable (length depending of your frame's width in centimeters)	
6. A 5V power supply (500mA should be large enough)

## Pinout mapping
See file LuminousFrameFritzing.jpg

## What do you have to tune ?
1. Place leds behind you photo (2cm behind to obtain a sweet spot of approx 1cm on the photo)
2. Change names in the .ino according to the place names or buildings/things you have put a led behind.

