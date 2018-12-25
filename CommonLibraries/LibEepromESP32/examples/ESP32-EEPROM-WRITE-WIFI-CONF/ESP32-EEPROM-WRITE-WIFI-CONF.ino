/**
   V.BRUEL 23/12/2018
   Enter two wifi config (ssid & password) and api keys via serial into the EEPROM.
   You can skip previously entered values (leave empty fields and type enter).
   You will have to configure your serial console to 115200 bauds, with "Both NL & CR" to see readable characters.
*/
#include <vb-eeprom-esp32.h>

void setup() {
  Serial.begin(115200);

  // initialize EEPROM with predefined size
  setupEEPROMESP32();
 
  delay(5000);
  int offset = 0;
  Serial.println("Please enter parameters");
  Serial.print("Primary SSID:");
  while (Serial.available() <= 0) { delay(10); }
  String ssid1 = Serial.readString();
  if (ssid1.length() > 2) eeprom_write_string(offset, const_cast<char*>(ssid1.c_str()));
  else Serial.println("Skipped");
  offset += SSID_SIZE;
  Serial.println("");

  Serial.print("Primary Password:");
  while (Serial.available() <= 0) { delay(10); }
  String pwd1 = Serial.readString();
  if (pwd1.length() > 2) eeprom_write_string(offset, const_cast<char*>(pwd1.c_str()));
  else Serial.println("Skipped");
  offset += PWD_SIZE;
  Serial.println("");

  Serial.print("Secondary SSID (just enter to set an empty one):");
  while (Serial.available() <= 0) { delay(10); }
  String ssid2 = Serial.readString();
  if (ssid2.length() > 2) eeprom_write_string(offset, const_cast<char*>(ssid2.c_str()));
  else Serial.println("Skipped");
  offset += SSID_SIZE;
  Serial.println("");

  Serial.print("Secondary Password (just enter to set an empty one):");
  while (Serial.available() <= 0) { delay(10); }
  String pwd2 = Serial.readString();
  if (pwd2.length() > 2) eeprom_write_string(offset, const_cast<char*>(pwd2.c_str()));
  else Serial.println("Skipped");
  offset += PWD_SIZE;
  Serial.println("");
  
  Serial.print("Youtube API KEY:");
  while (Serial.available() <= 0) { delay(10); }
  String ytapi = Serial.readString();
  if (ytapi.length() > 2) eeprom_write_string(offset, const_cast<char*>(ytapi.c_str()));
  else Serial.println("Skipped");
  offset += YT_API_SIZE;
  Serial.println("");

  Serial.print("Youtube CHANNEL ID:");
  while (Serial.available() <= 0) { delay(10); }
  String ytchannel = Serial.readString();
  if (ytchannel.length() > 2) eeprom_write_string(offset, const_cast<char*>(ytchannel.c_str()));
  else Serial.println("Skipped");
  offset += YT_CHANNEL_SIZE;
  Serial.println("");

  Serial.print("OpenWeatherData API KEY:");
  while (Serial.available() <= 0) { delay(10); }
  String owdak = Serial.readString();
  if (owdak.length() > 2) eeprom_write_string(offset, const_cast<char*>(owdak.c_str()));
  else Serial.println("Skipped");
  offset += OPENWEATHER_SIZE;
  Serial.println("");

  EEPROM.commit();
  
  Serial.println("Done");
}

void loop() {
  delay(1000);
}
