## Subject: Get weather data and display it with 4x 8x8 dot matrix led with an ESP32
	
## Hardware
See CommonHardware\ESP32-4xDotMatrix8x8Leds

## You will need Plugins to manage ESP32:
	https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md => to program ESP32
		In arduino IDE, display File->Preferences then fill the URL field with https://dl.espressif.com/dl/package_esp32_index.json then close this page
		Then open Tools->Card type->Card manager, type esp32 and search (enter), click on the line
		Espressif ESP32 and click INSTALL button on this same line. Wait a bit ( 2min to 10min depending on your internet line).
		Now you can connect your ESP32 via the USB port to your PC and program it:
			Check that your specific card type is available in the list : Tools->Card type->put mouse on the down pointing black triangle to find your card type (DOIT ESP32 for me).
				
## Mandatory Libraries, to install BEFORE programming the sketch to the ESP32:
	https://github.com/bblanchon/ArduinoJson
	https://github.com/arduino-libraries/NTPClient
	https://github.com/MajicDesigns/MD_MAX72XX
	https://github.com/vincent-bruel/arduino-and-co/CommonLibraries/LibEepromESP32
		=> you will have to launch the .ino Write example and provide SSID/PASSWORD +OpenWeatherAPI key at least
		
## Pinout mapping

ESP32   | MAX7219 8x8 LED Matrix
------- | ----------------------
VIN     | VCC
GND     | GND
GPIO12  | DIN
GPIO15  | CS
GPIO14  | CLK