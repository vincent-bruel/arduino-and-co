#ifndef _VB_EEPROM_ESP32_
#define _VB_EEPROM_ESP32_ 1

/**
   V.BRUEL 23/12/2018
   Manages wifi parameters and some API key in EEPROM
   EEPROM read and write functions are from https://gist.github.com/smching/05261f11da11e0a5dc834f944afd5961
*/
#include <EEPROM.h>

// These are max sizes
// Size according to https://serverfault.com/questions/45439/what-is-the-maximum-length-of-a-wifi-access-points-ssid
#define SSID_SIZE 32
#define PWD_SIZE 64

// STore youtube keys
#define YT_API_SIZE 40
#define YT_CHANNEL_SIZE 32
// Store openweather data key
#define OPENWEATHER_SIZE 34
// Total eeprom size used
#define EEPROM_SIZE (2*SSID_SIZE+2*PWD_SIZE+YT_API_SIZE+YT_CHANNEL_SIZE+OPENWEATHER_SIZE)

/**
  * Setup the EEPROM use (use this in setup())
  */
void setupEEPROMESP32();

/**
  * Reads a buffer from EEPROM
  */
boolean eeprom_read_string(int addr, char* buffer, int bufSize);

/**
  * Writes buffer to EEPROM
  */
boolean eeprom_write_string(int addr, const char* string);


#endif

