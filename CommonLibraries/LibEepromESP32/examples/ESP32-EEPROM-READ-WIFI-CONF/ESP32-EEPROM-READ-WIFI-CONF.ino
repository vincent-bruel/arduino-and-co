/**
   V.BRUEL 23/12/2018
   Just read and print wifi parameters and api keys from EEPROM
*/
#include <vb-eeprom-esp32.h>

const int BUFSIZE = 64;
char buf[BUFSIZE];

void setup() {
  Serial.begin(115200);

  // initialize EEPROM with predefined size
  setupEEPROMESP32();
  
  delay(2000);
  
    int offset = 0;
    
    Serial.print("Primary SSID:<");
    eeprom_read_string(offset, buf, SSID_SIZE);
    offset += SSID_SIZE;
    Serial.print(buf);
    Serial.println(">");
    
    Serial.print("Primary Password:<");
    eeprom_read_string(offset, buf, PWD_SIZE);
    offset += PWD_SIZE;
    Serial.print(buf);
    Serial.println(">");

    Serial.print("Secondary SSID:<");
    eeprom_read_string(offset, buf, SSID_SIZE);
    offset += SSID_SIZE;
    Serial.print(buf);
    Serial.println(">");
    
    Serial.print("Secondary Password:<");
    eeprom_read_string(offset, buf, PWD_SIZE);
    offset += PWD_SIZE;
    Serial.print(buf);
    Serial.println(">");
	
    Serial.print("Youtube API KEY:<");
    eeprom_read_string(offset, buf, YT_API_SIZE);
    offset += YT_API_SIZE;
    Serial.print(buf);
    Serial.println(">");

	Serial.print("Youtube CHANNEL ID:<");
    eeprom_read_string(offset, buf, YT_CHANNEL_SIZE);
    offset += YT_CHANNEL_SIZE;
    Serial.print(buf);
    Serial.println(">");

	Serial.print("OpenWeatherData API KEY:<");
    eeprom_read_string(offset, buf, OPENWEATHER_SIZE);
    offset += OPENWEATHER_SIZE;
    Serial.print(buf);
    Serial.println(">");

}

void loop() {
  delay(1000);
}
