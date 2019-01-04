
/**
   V.BRUEL 31/12/2018
   Pseudo Algorithm for moving the mobile hole linear

  1. If motor is not moving and no hall sensor is activated => ERROR
  Because we always stop the motor in front of a hole position, so the magnet is always in front of a hall sensor.
  2. Current hole number = Current hall sensor activated.
  3. Desired hole number = 4-way-selector analog read
  4. If (current hole number == Desired hole number) STOP MOTOR
  4. If Desired hole number > Current hole number MOVE MOTOR Counter-Wise
  5. If Desired hole number < Current hole number MOVE MOTOR Counter-Clock-Wise
  7. Goto 2.

*/

#define UNIT_TEST_NO_MOTOR 1
#define UNIT_TEST_NO_HALL_SENSOR 1
//======================= HALL SENSORS ========
// Hole definitions
#define SENSOR_NUMBER 4
// From 0 to SENSOR_NUMBER-1
int currentHoleIndex = 0;
// From 0 to SENSOR_NUMBER-1
// Stable state at startup
volatile int desiredHoleNumber = currentHoleIndex;
volatile int temporaryDesiredHoleNumber = currentHoleIndex;
// Table of hall sensor pins used
int hallPin[SENSOR_NUMBER] = { A1, A2, A3, A4 };

//======================= ROTARY ENCODER ========
#include <encodeurv4.h>
// Swap the ENC_INT0 and ENC_INT1 if the rotary does not fit your needs
#define ENC_INT0 3
#define ENC_INT1 2
#define ENC_SWITCH 4
void onRotaryPressed(int code) {

  if (code == 2) {
	// BUTTON LONG:
  } else {
	// SHORT PRESS
	desiredHoleNumber = getEncodeurValue();
	Serial.print("Encoder press desiredHoleNumber=");
	Serial.println(desiredHoleNumber);
  }
}

void onRotaryTurned(int val, int lastVal) {
	Serial.print("Encoder newVal=");
	Serial.println(val);
  if (val >= 0 && val < SENSOR_NUMBER) {
    temporaryDesiredHoleNumber = val;
  }
}

//======================= 8 digits 7 segments LED ===========
#include "LedControl.h"
#define DIG8_CLK 9
#define DIG8_CS 10
#define DIG8_DIN 11
LedControl lc=LedControl(DIG8_CLK,DIG8_DIN,DIG8_CS,1);

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

char * dustLineStrings[] = {
	"BandSaw",
	"Planer",
	"Jointer",
	"MainLine"
};

void writeString(char *str) {
  lc.clearDisplay(0);
  for(int i=0;*(str+i) != '\0';i++) {
    char c = *(str+i);
    lc.setRow(0,7-i,mycharTable[c]);

  }
}
//======================= MOTOR ========

#define ABS(val) ((val) > 0) ? (val) : -(val)
#define BRAKE 0
#define CW    1       // Counter wise
#define CCW   2       // Counter clock wise
// Set it to  MIN(powerSupplyMaxAmps, motorMaxAmps)
#define CS_THRESHOLD 15 // Maximum current allowed

//MOTOR 1              //  CW  | CCW
#define MOTOR_A1_PIN 7 // HIGH | LOW   
#define MOTOR_B1_PIN 8 // LOW  | HIGH 

// PWM pin
#define PWM_MOTOR_1 6

// Current sensor pin
#define CURRENT_SEN_1 A5

// Enable pin
#define EN_PIN_1 A0



//======================= MOTOR ========
void motorGo(uint8_t direct, uint8_t pwm) {
  if (direct == CW) {
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, HIGH);
  }
  else if (direct == CCW) {
    digitalWrite(MOTOR_A1_PIN, HIGH);
    digitalWrite(MOTOR_B1_PIN, LOW);
  }
  else {
    // STOP
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, LOW);
  }
  analogWrite(PWM_MOTOR_1, pwm);
}

//======================= SETUP ========
void setup() {
  Serial.begin(115200);
  
  // ============ Motor pins =================
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN_PIN_1, OUTPUT);

  // ============ Hall sensor pins ============
  for (int i = 0; i < SENSOR_NUMBER; i++) {
#ifdef UNIT_TEST_NO_HALL_SENSOR
  pinMode(hallPin[i], INPUT_PULLUP);
#else
  pinMode(hallPin[i], INPUT);
#endif
  }
  
  //======== ROTARY ENCODER SETUP =============
  // Values goes 1 by 1, from min to max included, with no loop.
  // Note that rotary encodeur uses  pins 2 and 3 because they are INT0 et INT1 (like in PROMINI)
  // so we can do attachInterrupt() on these pins.
  setupEncodeur(ENC_INT0, ENC_INT1, ENC_SWITCH, 1 /*stepEncodeur_p*/, 0/*initial*/, 0 /*valMin_p*/, SENSOR_NUMBER/*int valMax_p*/, false /* circle_p*/);
  
  //======== 8 DIGITs 7 SEGMENTS LED ==========
  // MAX72XX is in power-saving mode at startup
  lc.shutdown(0,false);
  // Set the brightness to a medium values (0-15=>8)
  lc.setIntensity(0,8);
  // and clear the display 
  lc.clearDisplay(0);
}

//======================= LOOP ========
void loop() {
  // Speed
  int speed = 0;
  // Direction
  int direct = BRAKE;

  
  digitalWrite(EN_PIN_1, HIGH);

  //-------------------------------Check rotary encoder Pressed
  loopEncodeurPressed(onRotaryPressed);
  //-------------------------------Check rotary encoder TURNED
  loopEncodeurTurned(onRotaryTurned);

  writeString(dustLineStrings[temporaryDesiredHoleNumber]);

  // Read hall sensors
  int newCurrentHoleIndex = -1;
  for (int i = 0; i < SENSOR_NUMBER; i++) {
    bool state = digitalRead(hallPin[i]);
#ifdef UNIT_TEST_NO_HALL_SENSOR
    if (state == HIGH) {
#else
    if (state == LOW) {
#endif
      newCurrentHoleIndex = i;
      break;
    }
  }
  if (newCurrentHoleIndex != currentHoleIndex) {
      currentHoleIndex = newCurrentHoleIndex;
      Serial.print("New Hall sensor activated number=> ");
      Serial.println(currentHoleIndex);
  }
  
#ifdef UNIT_TEST_NO_MOTOR
  bool tooMuchCurrent = false;
#else
  bool tooMuchCurrent = analogRead(CURRENT_SEN_1) > CS_THRESHOLD;

  if (currentHoleIndex == desiredHoleNumber || tooMuchCurrent) {
    if (direct != BRAKE) {
      Serial.println("Stopping motor");
    }
    // Desired hole reached: Stop the motor
    direct = BRAKE;
    speed = 0;
  } else {
    if (currentHoleIndex > desiredHoleNumber) {
      direct = CW;
    } else if (currentHoleIndex < desiredHoleNumber) {
      direct = CCW;
    }
    // Full speed when far from hole, reduced speed when near the destination hole
    speed = ABS(currentHoleIndex - desiredHoleNumber) > 1 ? 255 : 255 / 2;
    Serial.print("Moving motor dir=");
    Serial.print(direct);
    Serial.print(" speed=");
    Serial.println(speed);
  }
  // Move the motor
  motorGo(direct, speed);
#endif

  if (tooMuchCurrent) {
    Serial.println("Wait 10s after too much current");
    delay(10000);
  }
}

