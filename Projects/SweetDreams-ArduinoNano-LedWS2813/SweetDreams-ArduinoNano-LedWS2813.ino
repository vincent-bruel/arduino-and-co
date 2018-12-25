/*
  V.BRUEL
  Subject: Help to get asleep.
*/

#include <LowPower.h>
#include <Adafruit_NeoPixel.h>
// <= 255
#define MAX_LED_POWER 150
// In darkness (like cinema), it's enough and not disturbing
#define MIN_LED_POWER 5

#define STRIP_COUNT 1
#define PIXEL_COUNT 1
Adafruit_NeoPixel strip[STRIP_COUNT] = {
  Adafruit_NeoPixel(PIXEL_COUNT, 6/*D6*/, NEO_GRB + NEO_KHZ800)
};

int ledIntensity = 180;
int COLOR_ACTIVATED[3] = { ledIntensity * 2 / 3, ledIntensity / 3, ledIntensity}; // sort of rose
int COLOR_BLACK[3] = { 0, 0, 0}; // black
int COLOR_RED[3] = { ledIntensity, 0, 0}; // red
int COLOR_ORANGE[3] = { ledIntensity, ledIntensity * 165 / 255, 0}; // orange
int COLOR_GREEN[3] = { 0, ledIntensity, 0}; // green
int COLOR_TRAFFIC[3][3] = {
  { ledIntensity, 0, 0}, //red
  { ledIntensity, ledIntensity * 165 / 255, 0}, // orange
  { 0, ledIntensity, 0} // green
};
#define RGB_MINE(COLOR_TAB) COLOR_TAB[0],COLOR_TAB[1],COLOR_TAB[2]
#define PERCENT_RGB(COLOR_TAB, percent) COLOR_TAB[0]*percent/100,COLOR_TAB[1]*percent/100,COLOR_TAB[2]*percent/100

// 15min
#define DELAY_TO_END_PROGRAM 15*60*1000
long start;

void setup() {
  Serial.begin(115200);
  
  strip[0].begin();
  strip[0].show();
  for (int c = 0; c < 3; c++) {
    for (int i = 0; i < 7; i++) {
      strip[0].setPixelColor(0, strip[0].Color(RGB_MINE(COLOR_TRAFFIC[c])));
      strip[0].show();
      delay(150);
      strip[0].setPixelColor(0, strip[0].Color(RGB_MINE(COLOR_BLACK)));
      strip[0].show();
      delay(150);
    }
  }
  start = millis();
}

void rampUp(int percentMin, int percentMax, int color[], int count) {
  Serial.print("RampUp min=");
  Serial.print(percentMin);
  Serial.print(" max=");
  Serial.print(percentMax);
  Serial.print(" count=");
  Serial.print(count);
  
  for (int i = 1; i <= count; i++) {
    int percent = map(i, 1, count, percentMin, percentMax);
    strip[0].setPixelColor(0, strip[0].Color(PERCENT_RGB(color, percent)));
    strip[0].show();
    delay(1000);
  }
}

void loop() {
  if (millis() - start > DELAY_TO_END_PROGRAM) {
    // shutdown
    Serial.println("POWER DOWN");
    delay(50);
    strip[0].setPixelColor(0, strip[0].Color(RGB_MINE(COLOR_BLACK)));
    strip[0].show();
    delay(150);
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
    // we never get there
    return;
  }
  /*
    Pour s'endormir en un clin d'œil, le secret serait de moduler sa respiration.
    Voici la marche à suivre:

    1. On peut faire cet exercice dans n'importe quelle position,
    mais si vous vous asseyez, installez-vous le dos bien droit et les pieds au sol.
    Puis touchez votre palais du bout de la langue,
    juste derrière les incisives du haut. Et tenez cette position durant l'exercice.

    2. Expirez par la bouche tout l'air de vos poumons.
    Vous êtes maintenant prêt pour expérimenter le 4-7-8.
  */

  //3. Fermez la bouche et inspirez tranquillement par le nez en comptant (dans votre tête) jusqu'à 4.*
  rampUp(10, 100, COLOR_RED, 4);

  //4. Retenez votre souffle en comptant jusqu'à 7.
  rampUp(100, 100, COLOR_ORANGE, 7);

  //5. Expirez bruyamment par la bouche en comptant jusqu'à 8.
  rampUp(100, 10, COLOR_GREEN, 8);
}

