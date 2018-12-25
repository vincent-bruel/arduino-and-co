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

## What is the procedure to program the ESP32 and make it work ?
1. Install Arduino IDE
2. Install ESP32 Plugin for Arduino IDE
3. Open CommonLibraries\LibEepromESP32\examples\ESP32-EEPROM-WRITE-WIFI-CONF ino file with Arduino IDE
4. Upload this ino to your ESP32
5. Sign in on https://openweathermap.org/api, get a free API key
5. Open Serial console, 115200 bauds, CR+LF, then enter SSID, PASSWORD, SSID2 or empty, PASSWORD2 or empty, empty, empty, OpenWeather API KEY
6. Upload CommonLibraries\LibEepromESP32\examples\ESP32-EEPROM-READ-WIFI-CONF to your ESP32
7. Open Serial console, 115200 bauds, check that values you previously entered are OK (not truncated for example)
	-> If truncated, raise the #define XXX_SIZE values in CommonLibraries\LibEepromESP32 and restart this procedure at level 3. 
8. Upload  Projects\OpenWeather-ESP32-4xDotMatrix8x8Leds ino file to your ESP32
9. Enjoy

## Troubleshooting WIFI
If no wifi can be reached you will see a message "Wifi NOK"
Further attempts to make another connexion will be tried as the loop goes on.
If WIFI is OK then NOK (power outage) then OK, the connexion will also be re-established in a few seconds (NOT TESTED)
Recheck you API keys SSID and PASSWORD like indicated in stage 6.

## Troubleshooting URL or OpenWeather API KEY
You will have to wait a certain amount of time between the key creation and the effectivness of this KEY.
Open a browser and enter http://api.openweathermap.org/data/2.5/forecast?q=evreux,FR&cnt=3&appid=YOUR_API_KEY
It should respond with a JSON result where you could see temperatures, and even city population
