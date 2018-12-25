#include <Consigne.h>

void setup() {
	// Fills a consigne
	ajouterConsigneStr("0101011 17h54 18.9 1", true);
	Consigne consigne2 = new Consigne(4, true, "1110011, 18, 45, 19.5, 1);
	ajouterConsigneBlynk(4, consigne2);
	// Write consigne to EEPROM
	// Write consignes to EEPROM
	// Read consignes from EEPROM
	// Print consignes
	
}

void loop() {
}