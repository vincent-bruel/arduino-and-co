
#include <SoftwareSerial.h>
SoftwareSerial lcd(7,6); // TX, RX

//Pin connected to ST_CP of 74HC595
int latchPin = 10;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

//holder for infromation you're going to pass to shifting function
byte data = 0; 

void clearLCD() {
  lcd.write(254); // move cursor to beginning of first line
  lcd.write(128);

  lcd.write("                "); // clear display
  lcd.write("                "); // clear display
}

void displayLCD(char * str) {
  char x1[16]; int o1=0;
  char x2[16]; int o2=0;
  int deuxieme=0;
  
  for (int i = 0; i < strlen(str); i++) {
    if (str[i]=='@') {
      deuxieme=1;
      continue;
    }
    if (deuxieme == 0) x1[o1++]=str[i];
    else x2[o2++]=str[i];
   }
   x1[o1]='\0';
   x2[o2]='\0';
  setLCDpos(1, 1);
  lcd.write(x1); // clear display
  setLCDpos(1, 2);
  lcd.write(x2); // clear display
}
 
 // xpos={1-16}
 // ypos={1-2}
void setLCDpos(int xpos, int ypos) {
    int pos;
    switch (ypos){
    case 1: 
        pos = 127+xpos; 
        break;
    case 2: 
        pos = 191+xpos; 
        break;
    }
    lcd.write(0xFE);
    lcd.write(pos);
}

void setBrightness(int lev) {
    lcd.write(0x7C);
    lcd.write(lev+127);
    delay(1);
}

void resetLCD() {
   lcd.begin(9600); // set up serial port for 9600 baud
   lcd.print(0x12);
   delay(500);

 
}

void disableSplashScreenLCD() {
      lcd.write(0x7C);
    lcd.write(9);
}

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  resetLCD();
  // wait for display to boot up
  delay(500); 
}

char * mystrings[] = {
          "Usines@Petrochimiques",
          "Pont Mathilde",
          "Pont Pierre@Corneille",
          "Pont Boieldieu",
          "Pont@Jeanne d'Arc",
          "Pont Guillaume@le Conquerant",
          "Pont Flaubert",
          "Cathedrale@Notre-Dame",
          "Hopital - CHU",
          "Chapelle@du CHU",
          "Tour des@archives",
          "---",
          "---",
          "Eglise@St-Vivien",
          "Eglise@St-Nicaise",
          "Abbattiale@St-Ouen"
};
char val[16];

void loop() {        
        while (1) {
        displayLCD("Rouen la ville@aux 100 clochers");
        blinkAll_2Bytes(1,500);
        for (int i = 0; i <= 15; i++) {
            clearLCD();
            displayLCD(mystrings[i]);
            //ground latchPin and hold low for as long as you are transmitting
            digitalWrite(latchPin, 0);
            //move 'em out
            for (int k = 0; k <= 15; k++) {
              if (k == i) val[k] = '1';
              else val[k] = '0';
            }
            shiftOut(dataPin, clockPin, val);   
            //return the latch pin high to signal chip that it 
            //no longer needs to listen for information
            digitalWrite(latchPin, 1);
            delay(2000);
       }
       }
}


// shiftOutCode, Dual One By One                           
// Author  : Carlyn Maw, Tom Igoe
void shiftOut(int myDataPin, int myClockPin, char *pins) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
//  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
 // for (i=15; i>=0; i--)  {
  for (i = 0; i <= 15; i++) { 
   digitalWrite(myClockPin, 0);
   digitalWrite(myClockPin, 1);
}
  for (i = 0; i <= 15; i++) { 
    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if (pins[i]=='1') {
      pinState= 1;
    }
    else {	
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 0);
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}


//blinks both registers based on the number of times you want to 
//blink "n" and the pause between them "d"
//starts with a moment of darkness to make sure the first blink
//has its full visual effect.
void blinkAll_2Bytes(int n, int d) {
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, "0000000000000000");

  digitalWrite(latchPin, 1);
  delay(200);
  for (int x = 0; x < n; x++) {
    digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, "1111111111111111");
    digitalWrite(latchPin, 1);
    delay(d);
    digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, "0000000000000000");
    digitalWrite(latchPin, 1);
    delay(d);
  }
}
