This lib is a fork of https://gist.github.com/smching/05261f11da11e0a5dc834f944afd5961
but sligthly modified for my needs:
Manages ESP32 EEPROM to store:
	-Primary WIFI SSID & PASSWORD (32+64)
	-Secondary WIFI SSID & PASSWORD	(32+64)
	-Youtube  API Key
	-Youtube  Channel ID
	-OpenWeather data API Key (32)
This allows me to not reveal theses passwords and api keys in the sketches I put on github.

NB: there is a \0 added so 1 more character than the strlen of the key provided is stored...

This library should work for other type of cards (ESP8266 or simple arduino).
For Arduino you don't have to call the setupEEPROMESP32() function to reserve the memory.