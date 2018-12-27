#include "sensor_htu21d.h"

//Create an instance of the object
HTU21D myHumidity;
#define HTU21D_UNDEFINED_VALUE -999.0
float temp = HTU21D_UNDEFINED_VALUE;
float hum = HTU21D_UNDEFINED_VALUE;

void setupSensorHtu21d() {
  myHumidity.begin();
}

void sensorHtu21dLoop() {
  temp = myHumidity.readTemperature();
  hum = myHumidity.readHumidity();
}

float getSensorHtu21dTemperature() {
  if (temp == HTU21D_UNDEFINED_VALUE) {
    sensorHtu21dLoop();
  }
  return temp;
}

float getSensorHtu21dHumidity() {
  if (hum == HTU21D_UNDEFINED_VALUE) {
    sensorHtu21dLoop();
  }
  return hum;
}

