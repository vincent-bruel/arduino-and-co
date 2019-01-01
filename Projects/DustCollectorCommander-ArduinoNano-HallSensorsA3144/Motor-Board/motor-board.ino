
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
#define PWM_MOTOR_1 5

// Current sensor pin
#define CURRENT_SEN_1 A2

// Enable pin
#define EN_PIN_1 A0

// Four way selector
#define FOUR_WAY_PIN 9

// Hole definitions
#define SENSOR_NUMBER 4
// From 0 to SENSOR_NUMBER-1
int currentHoleIndex = 0;
// From 0 to SENSOR_NUMBER-1
// Stable state at startup
int desiredHoleNumber = currentHoleIndex;
int hallPin[SENSOR_NUMBER] = { 2, 3, 4, 6 };

void setup() {
  // Motor pins
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN_PIN_1, OUTPUT);

  // Hall sensor pins
  for (int i = 0; i < SENSOR_NUMBER; i++) {
    pinMode(hallPin[i], INPUT);
  }
  Serial.begin(115200);
}

void loop() {
  // Speed
  int speed = 0;
  // Direction
  int direct = BRAKE;

  delay(20);
  digitalWrite(EN_PIN_1, HIGH);

  currentHoleIndex = -1;

  // Read hall sensors
  for (int i = 0; i < SENSOR_NUMBER; i++) {
    bool state = digitalRead(hallPin[i]);
    if (state == LOW) {
      currentHoleIndex = i;
      Serial.print("SENSOR D");
      Serial.println(hallPin[i]);
      break;
    }
  }
  // Read 4-way detector
  int fourWay = analogRead(FOUR_WAY_PIN);
  Serial.print("ANALOG 4WAY=");
  Serial.println(fourWay);

  // Analog to 4-way conversion
  desiredHoleNumber = map(fourWay, 0, 1024, 0, SENSOR_NUMBER);
  bool tooMuchCurrent = analogRead(CURRENT_SEN_1) > CS_THRESHOLD;

  if (currentHoleIndex == desiredHoleNumber || tooMuchCurrent) {
    Serial.println("Stopping motor");
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
    Serial.print(speed);
  }
  // Move the motor
  motorGo(direct, speed);

  if (tooMuchCurrent) {
    Serial.println("Wait 10s after too much current");
    delay(10000);
  }
}


void motorGo(uint8_t direct, uint8_t pwm) {
  if (direct == CW)
  {
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, HIGH);
  }
  else if (direct == CCW)
  {
    digitalWrite(MOTOR_A1_PIN, HIGH);
    digitalWrite(MOTOR_B1_PIN, LOW);
  }
  else
  {
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, LOW);
  }

  analogWrite(PWM_MOTOR_1, pwm);
}
