#include "vb-eeprom-esp32.h"
/** 
  * V.BRUEL 23 dec 2018
  * Subject: Manages wifi parameters and some API key in EEPROM
  * This lib is a fork of https://gist.github.com/smching/05261f11da11e0a5dc834f944afd5961
  * Only EEPROM read and write functions are from this fork.
  * Just modified:
  * 	-to skip \r and \n and 0xFF characters at the end, 
  *     -and to add a \0 at the end which is fundamental if you want to write your EEPROM more than once otherwise it will NOT work.
  */

void setupEEPROMESP32() {
  EEPROM.begin(EEPROM_SIZE);
}



// Absolute min and max eeprom addresses. Actual values are hardware-dependent.
// These values can be changed e.g. to protect eeprom cells outside this range.
const int EEPROM_MIN_ADDR = 0;
const int EEPROM_MAX_ADDR = 511;

// Returns true if the address is between the
// minimum and maximum allowed values, false otherwise.
//
// This function is used by the other, higher-level functions
// to prevent bugs and runtime errors due to invalid addresses.
boolean eeprom_is_addr_ok(int addr) {
  return ((addr >= EEPROM_MIN_ADDR) && (addr <= EEPROM_MAX_ADDR));
}

// Reads a string starting from the specified address.
// Returns true if at least one byte (even only the string terminator one) is read.
// Returns false if the start address falls outside the allowed range or declare buffer size is zero.
//
// The reading might stop for several reasons:
// - no more space in the provided buffer
// - last eeprom address reached
// - string terminator byte (0x00) encountered.
boolean eeprom_read_string(int addr, char* buffer, int bufSize) {
  byte ch; // byte read from eeprom
  int bytesRead; // number of bytes read so far
  if (!eeprom_is_addr_ok(addr)) { // check start address
    return false;
  }

  if (bufSize == 0) { // how can we store bytes in an empty buffer ?
    return false;
  }
  // is there is room for the string terminator only, no reason to go further
  if (bufSize == 1) {
    buffer[0] = 0;
    return true;
  }
  bytesRead = 0; // initialize byte counter
  ch = EEPROM.read(addr + bytesRead); // read next byte from eeprom
  buffer[bytesRead] = ch; // store it into the user buffer
  bytesRead++; // increment byte counter
  // stop conditions:
  // - the character just read is the string terminator one (0x00) or return
  // - we have filled the user buffer
  // - we have reached the last eeprom address
  while ( ch != '\r' && ch != '\n' && ch != 0xFF && (ch != 0x00) && (bytesRead < bufSize) && ((addr + bytesRead) <= EEPROM_MAX_ADDR) ) {
    // if no stop condition is met, read the next byte from eeprom
    ch = EEPROM.read(addr + bytesRead);
    buffer[bytesRead] = ch; // store it into the user buffer
    bytesRead++; // increment byte counter
  }
  // make sure the user buffer has a string terminator, (0x00) as its last byte
  if ((ch != 0x00) && (bytesRead >= 1)) {
    buffer[bytesRead - 1] = 0;
  }
  /*
  for (int k = 0; k < strlen(buffer); k++) {
    Serial.print("CHAR ");
    Serial.println(buffer[k], HEX);
  }
  */
  return true;
}


// Writes a sequence of bytes to eeprom starting at the specified address.
// Returns true if the whole array is successfully written.
// Returns false if the start or end addresses aren't between
// the minimum and maximum allowed values.
// When returning false, nothing gets written to eeprom.
boolean eeprom_write_bytes(int startAddr, const byte* array, int numBytes) {
  // counter
  int i;
  // both first byte and last byte addresses must fall within
  // the allowed range
  if (!eeprom_is_addr_ok(startAddr) || !eeprom_is_addr_ok(startAddr + numBytes)) {
    return false;
  }
  for (i = 0; i < numBytes; i++) {
    if (array[i] == '\n' || array[i] == '\r') {
      break;
    }
    EEPROM.write(startAddr + i, array[i]);
  }
  EEPROM.write(startAddr + i, '\0');

  return true;
}

// Writes a string starting at the specified address.
// Returns true if the whole string is successfully written.
// Returns false if the address of one or more bytes fall outside the allowed range.
// If false is returned, nothing gets written to the eeprom.
boolean eeprom_write_string(int addr, const char* string) {

  int numBytes; // actual number of bytes to be written
  //write the string contents plus the string terminator byte (0x00)
  numBytes = strlen(string) + 1;
  return eeprom_write_bytes(addr, (const byte*)string, numBytes);
}
