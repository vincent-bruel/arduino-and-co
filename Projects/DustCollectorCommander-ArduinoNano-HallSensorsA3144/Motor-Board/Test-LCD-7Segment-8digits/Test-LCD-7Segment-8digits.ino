/**
  * V.BRUEL
  *  Test to display the dust collection line names
  * We override the character table to display more characters.
  * This table is quite a standard modification to LedControl library.
  * I've just changed the way the 't' character is displayed: see ++MODIFIED-- tag below
  */
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(9,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=250;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

const static byte mycharTable[128] = {
    B00000000,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,
    B01111111,B01111011,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B10000000,B00000001,B10000000,B00000000,
    B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,
    B01111111,B01111011,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,B01011110,
    B00110111,B00010000,B00111100,B01010111,B00001110,B01110110,B00010101,B00011101,
    B01100111,B01101111,B00000101,B00011011,B01001111,B00011100,B00111110,B00111111,
    B00110111,B00111011,B01101100,B00000000,B00000000,B00000000,B00000000,B00001000,
    B00000000,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,B01011110,
    B00110111,B00010000,B00111100,B01010111,B00001110,B01110110,B00010101,B00011101,
    B01100111,B01101111,B00000101,B00011011,B00001111/*++MODIFIED--*/,B00011100,B00111110,B00111111,
    B00110111,B00111011,B01101100,B00000000,B00000000,B00000000,B00000000,B00000000
};
void writeString(char *str) {
  lc.clearDisplay(0);
  for(int i=0;*(str+i) != '\0';i++) {
    char c = *(str+i);
    lc.setRow(0,7-i,mycharTable[c]);

  }
}

void loop() { 
  writeString("BandSaw");
  delay(1000);
    writeString("Planer");
  delay(1000);
    writeString("Jointer");
  delay(1000);
    writeString("MainLine");
  delay(1000);
}
