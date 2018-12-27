#ifndef IS_DEFINED_SENSOR_HTU21D
#define IS_DEFINED_SENSOR_HTU21D 1

#include "Arduino.h"
#include <Wire.h>
#include "SparkFunHTU21D.h"

#ifdef __cplusplus
extern "C" {
#endif

void setupSensorHtu21d();
void sensorHtu21dLoop();
float getSensorHtu21dTemperature();
float getSensorHtu21dHumidity();

#ifdef __cplusplus
}
#endif
#endif
