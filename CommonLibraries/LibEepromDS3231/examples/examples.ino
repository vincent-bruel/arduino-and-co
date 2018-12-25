
#include <vb-eeprom-ds3231.h>

/**
  * Example to write a consigne to EEPROM and read it just after
  */
  
typedef struct {
  int index;
  bool valide; // if consigne is valid (EEPROM slot is filled)
  char jour[8]; // days of the week toggles 0=off 1=on, +1 char for '\0'
  int heure; // hour of the day (0-23)
  int minute; // minute of the hour (0-59)
  float temp; // Consigne temperature
  int priorite; // Priority of this consigne (1= greater priority, 2=lesser priority, ...)
} TConsigneData;

void setup() {
	Serial.begin(115200);
	
	// Write consigne to EEPROM
    TConsigneData wdata;
	strcpy(&wdata.jour[0], "0101011");
	wdata.index = 0;
	wdata.valide = true;
	wdata.heure=19;
	wdata.minute=59;
	wdata.temp = 18.5;
	wdata.priorite = 1;
	i2c_eeprom_write_page( 0x57, 0*32, (byte*)& wdata, sizeof(TConsigneData));
	
	// Read consigne from EEPROM
    TConsigneData data;
    i2c_eeprom_read_buffer(0x57, 0*32, (byte*)&data, sizeof(TConsigneData));
	Serial.print("valid=");
	Serial.println(data.valide);
	Serial.print("d=");
	Serial.println(data.jour);
	Serial.print("h=");
	Serial.println(data.heure);
	Serial.print("m=");
	Serial.println(data.minute);
	Serial.print("temp=");
	Serial.println(data.temp);
}

void loop() {

}
