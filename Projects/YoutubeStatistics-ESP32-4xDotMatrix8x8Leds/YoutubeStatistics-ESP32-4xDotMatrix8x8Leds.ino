////LIBRARIES
#include <stdio.h>
#include <MD_MAX72xx.h>
#include <YoutubeApi.h>
#include <SPI.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <vb-eeprom-esp32.h>

//================== MAX7219 dot matrix 8x8 STUFF ============================

// Votre type de matrices LED
#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW
// Le nombre de matrices LED connectées entre elles
#define MAX_DEVICES  4


// Pins de l'ESP32 connectés aux Matrix led
#define CLK_PIN   14  // or SCK
#define DATA_PIN  12  // or MOSI
#define CS_PIN    15  // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
#define  DELAYTIME  65  // in milliseconds

//================== EEPROM STUFF ============================
const int BUFSIZE = 64;
char buf[BUFSIZE];
char ssid[SSID_SIZE];
char ssid2[SSID_SIZE];
char password[PWD_SIZE];
char password2[PWD_SIZE];
// Clef a créer sur youtube après s'être enregistré
char API_KEY[YT_API_SIZE];
char CHANNEL_ID[YT_CHANNEL_SIZE];

//================== WIFI STUFF ============================
WiFiClientSecure client;

//================== NTP date time STUFF ============================

// Objets permettant de récupérer l'heure (et la date si on veut)
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//================== Youtube API STUFF ============================
// Objets permettant de récupérer les stats Youtube
YoutubeApi *api = NULL;

unsigned long api_mtbs = 300000; //mean time between api requests
unsigned long api_lasttime = 0L;   //last time api request has been done
bool first = true;
bool atLeastOneStat = false;
long isub = 0L;
long iview = 0L;
long icmt = 0L;
long ivid = 0L;

// Méthode copiée de https://github.com/amadej10/TrolaESP32
void scrollText(char *p) {
  uint8_t charWidth;
  uint8_t cBuf[8];

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

void displayYoutubeStat(char *msg, long stat) {
  char buf[80];
  sprintf(buf, " %s%ld ", msg, stat);
  scrollText(buf);
  delay(500);
}

// Recup stats youtube et affichage
void getYoutubeDataAndDisplay()
{
  bool statsOK = false;
  if (millis() < api_lasttime) {
    api_lasttime = millis();
  }
  if (first || millis() - api_lasttime > api_mtbs)  {
    Serial.println("---------Get Stats---------");
    statsOK = api->getChannelStatistics(CHANNEL_ID);
    if (statsOK) {
      atLeastOneStat = true;
      if (first) {
        isub = api->channelStats.subscriberCount;
        iview = api->channelStats.viewCount;
        icmt = api->channelStats.commentCount;
        ivid = api->channelStats.videoCount;
      }
    } else {
      Serial.println("---------Get Stats FAILED ---------");
      scrollText("Youtube Stats Fail");
      delay(500);
    }
    first = false;
  }

  if (atLeastOneStat) {
    // Print current stats
    Serial.println("---------Stats---------");
    displayYoutubeStat("Subs ", api->channelStats.subscriberCount);
    displayYoutubeStat("Vues ", api->channelStats.viewCount);
    displayYoutubeStat("Cmt ", api->channelStats.commentCount);
    displayYoutubeStat("Vid ", api->channelStats.videoCount);
      Serial.println("------------------------");
      // Print delta stats
      if (isub != 0) {
        displayYoutubeStat("Subs +", api->channelStats.subscriberCount - isub);
        displayYoutubeStat("Vues +", api->channelStats.viewCount - iview);
        displayYoutubeStat("Cmt +", api->channelStats.commentCount - icmt);
        displayYoutubeStat("Vid +", api->channelStats.videoCount - ivid);
      }
  }
  api_lasttime = millis();
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
  eeprom_read_string(offset, API_KEY, YT_API_SIZE);
  offset += YT_API_SIZE;
  eeprom_read_string(offset, CHANNEL_ID, YT_CHANNEL_SIZE);
  offset += YT_CHANNEL_SIZE;
  Serial.print("API_KEY=");
  Serial.println(API_KEY);
  Serial.print("CHANNEL_ID=");
  Serial.println(CHANNEL_ID);
  
  //eeprom_read_string(offset, API_KEY, OPENWEATHER_SIZE);
  //offset += OPENWEATHER_SIZE;
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
  // Luminosité 0-15 =>attention, plus c'est élevé, plus cela consomme de courant...
  // compter entre 67 et 200mA par carré 8x8 leds lorsque allumé entièrement et plein pot.
  mx.control(MD_MAX72XX::INTENSITY, 1); 

  Serial.begin(115200);
  delay(2000);
  
  EEPROM.begin(EEPROM_SIZE);
  readEEPROM();
  
  api = new YoutubeApi(API_KEY, client);
  
  wifiConnexion();

}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    scrollText("No WIFI");
    delay(5000);
    // Re-essayer de se connecter au wifi
    wifiConnexion();
    return;
  }

  // Mise à jour des stats youtube
  getYoutubeDataAndDisplay();
  
  // Mise à jour de l'heure
  timeClient.update();
  String str = timeClient.getFormattedTime(); //Magic to cut seconds HH:MM:SS
  str.setCharAt(5, '\0');
  /*
  char *cstr = &str[0u];
  char subbuff[8];
  memcpy( subbuff, &cstr[0], 5 );
  subbuff[5] = ' ';
  subbuff[6] = '\0';
  subbuff[7] = '\0';
  scrollText(subbuff); //display time on screen for 5 seconds then update all
  */
  scrollText(const_cast<char*>(str.c_str()));
  delay(5000);
}
