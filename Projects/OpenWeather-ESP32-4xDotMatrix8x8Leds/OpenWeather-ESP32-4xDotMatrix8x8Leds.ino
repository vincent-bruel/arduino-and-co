////LIBRARIES
#include <stdio.h>
#include <MD_MAX72xx.h>
#include <YoutubeApi.h>
#include <SPI.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <vb-eeprom-esp32.h>

/**
  * V.BRUEL 22 dec 2018
  * Subject: get weather data for NOW, NOW+3h, NOW+6h, and display it on dot 4x matrix 8x8 red led
  * driven by a ESP32.
  */
  
//================== EEPROM STUFF ============================
const int BUFSIZE = 64;
char buf[BUFSIZE];
char ssid[SSID_SIZE];
char ssid2[SSID_SIZE];
char password[PWD_SIZE];
char password2[PWD_SIZE];
// Key to create on openweatherdata.com after signin in
char API_KEY[OPENWEATHER_SIZE];
//================== MAX7219 dot matrix 8x8 STUFF ============================

// Your matrix LED type (change it if it does not work)
#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW
// Number of matrix LED chained
#define MAX_DEVICES  4


// Pins of ESP32 connected to Matrix led
#define CLK_PIN   14  // or SCK
#define DATA_PIN  12  // or MOSI
#define CS_PIN    15  // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
#define  DELAYTIME  65  // in milliseconds


//================== WEATHER API STUFF ============================


// URL to reach to get weather data is:
// http://api.openweathermap.org/data/2.5/forecast?q=evreux,FR&cnt=3&appid=YOUR_API_KEY
// Data back is JSON

/*
  String location = "Cavalaire-sur-mer,FR";
  String location = "La Garde-Freinet,FR";
  String location = "Hyeres,FR";
  String location = "Toulon,FR";
  String location = "Le Neubourg,FR";
  String location = "Rouen,FR";
*/
String location = "Evreux,FR";

char server[] = "api.openweathermap.org";
long api_lasttime = 0;
long api_mtbs = 3 * 60 * 1000; // 3min
bool first = true;
bool atLeastOneStat = false;

//================== WIFI STUFF ============================

WiFiClient client;
int status = WL_IDLE_STATUS;

//================== NTP DATE TIME STUFF ============================
// Objets permettant de récupérer l'heure (et la date si on veut)
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Méthod copied from https://github.com/amadej10/TrolaESP32
void scrollText(char *p) {
  uint8_t charWidth;
  uint8_t cBuf[8];
  Serial.print("Display:");
  Serial.println(p);
  mx.clear();

  while (*p != '\0') {
    charWidth = mx.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);

    for (uint8_t i = 0; i <= charWidth; i++) {
      mx.transform(MD_MAX72XX::TSL);
      if (i < charWidth) {
        mx.setColumn(0, cBuf[i]);
      }
      delay(DELAYTIME);
    }
  }
}

void displayFloatValue(char *msg, double stat) {
  char buf[80];
  sprintf(buf, " %s%3.1f ", msg, stat);
  scrollText(buf);
  delay(500);
}

// NB: this methode is not internationalized, specially in the String array
// FRENCH: Convertit une direction en degrés du vent vers une chaine de caracteres
String windFloatToString(float val) {
  int quarter = (int) (val / 22.5 + 0.5);
  String arr[16] = {"Nord", "Nord-NordEst", "Nord-Est", "Est-NordEst", "Est", "Est-SudEst", "Sud-Est", "Sud-SudEst", "Sud", "Sud-Sud-Ouest", "Sud-Ouest", "Ouest-SudOuest", "Ouest", "Ouest-NordOuest", "Nord-Ouest", "Nord-NordOuest"};
  return arr[quarter];
}

// NB: this method is not internationalized, specially in the for() loop
// Get  youtube stats and display, for NOW, NOW+3h, NOW+6h
void getWeatherDataAndDisplay()
{
  bool statsOK = false;
  if (millis() < api_lasttime) {
    api_lasttime = millis();
  }
  if (first || millis() - api_lasttime > api_mtbs)  {
    Serial.println("---------Get Stats---------");
    if (client.connect(server, 80)) {
      Serial.println("connected to server");
      // Make a HTTP request:
      client.print("GET /data/2.5/forecast?");
      client.print("q=" + location);
      client.print("&appid=");
      client.print(API_KEY);
      client.print("&cnt=3");
      client.println("&units=metric");
      client.println("Host: api.openweathermap.org");
      client.println("Connection: close");
      client.println();
      statsOK = true;
    } else {
      Serial.println("unable to connect");
      statsOK = false;
    }
    delay(1000);
    String line = "";
    while (client.connected()) {
      line = client.readStringUntil('\n');
      Serial.println(line);
    }
    if (statsOK) {
      atLeastOneStat = true;
      Serial.println("parsing JSON Values");
      //create a json buffer where to store the json data
      StaticJsonBuffer<5000> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(line);
      if (!root.success()) {
        Serial.println("parseObject() failed");
        return;
      }
      //get the data from the json tree
      for (int i = 0; i < 3; i++) {
        String nextWeatherTime0 = root["list"][i]["dt_txt"];
        String nextWeather0 = root["list"][i]["weather"][0]["description"];
        String temp0 = root["list"][i]["main"]["temp"];
        String nextTemp0 = String("Temp:") + temp0 + String("C ");
        String hum0 = root["list"][i]["main"]["humidity"];
        String nextHumidity0 = String("Humidite:") + hum0 + String("/100 ");
        String wind0 = root["list"][i]["wind"]["speed"];
        String nextWind0 = String("Vent:") + wind0 + String("km/h Dir:");
        String windDir0 = root["list"][i]["wind"]["deg"];
        float windDegrees0 = windDir0.toFloat();
        String totalWind0 = nextWind0 + windFloatToString(windDegrees0);
        Serial.println("parsing OK");
        // Print values.
        scrollText(const_cast<char*>(nextWeatherTime0.c_str()));
        scrollText(const_cast<char*>(nextWeather0.c_str()));
        scrollText(const_cast<char*>(nextTemp0.c_str()));
        scrollText(const_cast<char*>(nextHumidity0.c_str()));
        scrollText(const_cast<char*>(totalWind0.c_str()));
      }
      api_lasttime = millis();
    } else {
      Serial.println("---------Get Stats FAILED ---------");
      scrollText("Youtube Stats Fail");
      delay(500);
    }
    first = false;
  }
  mx.clear();
}

void readEEPROM() {
  int offset = 0;
  eeprom_read_string(offset, ssid, SSID_SIZE);
  offset += SSID_SIZE;
  eeprom_read_string(offset, password, PWD_SIZE);
  offset += PWD_SIZE;
  eeprom_read_string(offset, ssid2, SSID_SIZE);
  offset += SSID_SIZE;
  eeprom_read_string(offset, password2, PWD_SIZE);
  offset += PWD_SIZE;
  
  // Skip youtube stuff as we don't need it there
  offset += YT_API_SIZE;
  offset += YT_CHANNEL_SIZE;
  
  eeprom_read_string(offset, API_KEY, OPENWEATHER_SIZE);
  offset += OPENWEATHER_SIZE;
}
/**
   WIFI connexion using SSID and password previously entered in EEPROM using another sketch
*/
void wifiConnexion() {
  int tryCount = 0;

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to <");
  Serial.print(ssid);
  Serial.print("> with pwd=");
  Serial.println(password);
  WiFi.disconnect();
  WiFi.begin(ssid, password);

  char buf[80];
  scrollText(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    tryCount++;
    delay(500);
    Serial.print(".");
    scrollText("~");
    if (tryCount >= 30) {
      tryCount = 0;
      scrollText(ssid2);

      Serial.print("Connecting to <");
      Serial.print(ssid2);
      Serial.print("> with pwd=");
      Serial.println(password2);
      WiFi.disconnect();
      WiFi.begin(ssid2, password2);
      while (WiFi.status() != WL_CONNECTED) {
        tryCount++;
        delay(500);
        Serial.print(".");
        scrollText("~");
        if (tryCount >= 60) {
          break;
        }
      }
      break;
    }
  }
  if (WiFi.status() != WL_CONNECTED) {
    scrollText("Wifi NOK");
  } else {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    scrollText("Wifi OK");
    timeClient.begin();
    timeClient.setTimeOffset(3600);// GMT +1
  }
}

void setup() {
  mx.begin();
  // Luminosity 0-15 =>the highter the brighter, but more current is drawn...
  // Between 67 and 200mA per square of 8x8 leds when all leds are on.
  mx.control(MD_MAX72XX::INTENSITY, 1);

  Serial.begin(115200);

  setupEEPROMESP32();
  readEEPROM();
  
  delay(10);

  wifiConnexion();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    scrollText("No WIFI");
    Serial.print("Wifi Status: ");
    Serial.println(WiFi.status());
    delay(5000);
    // Re-try
    wifiConnexion();
    return;
  }

  // Update weather
  getWeatherDataAndDisplay();

  // Update Time
  timeClient.update();

  // Display time
  String strTime = timeClient.getFormattedTime();
  strTime.setCharAt(5, '\0'); // skip seconds
  scrollText(const_cast<char*>(strTime.c_str()));
  delay(5000);
}
