#ifndef _VB_EEPROM_DS3231_
#define _VB_EEPROM_DS3231_ 1


#include "Arduino.h"
/**
  * V.BRUEL
  * Read & Write functions taken from https://playground.arduino.cc/code/I2CEEPROM
  */
/**
  * Setup the EEPROM use (use this in setup())
  */
void setupEEPROMDS3231();
/**
  * Writes a byte to EEPROM
  */
void i2c_eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data );
/**
  * Writes a page to EEPROM (I think data must be less than 32 bytes)
  */
void i2c_eeprom_write_page( int deviceaddress, unsigned int eeaddresspage, byte* data, byte length );
/**
  * Reads a byte  from EEPROM
  */
byte i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress );
/**
  * Reads a buffer from EEPROM
  */
void i2c_eeprom_read_buffer( int deviceaddress, unsigned int eeaddress, byte *buffer, int length );

#endif

