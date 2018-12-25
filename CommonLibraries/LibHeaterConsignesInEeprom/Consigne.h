#ifndef _HAS_DEFINED_CONSIGNE_
#define _HAS_DEFINED_CONSIGNE_ 1

/**
  * V.BRUEL
  */
#include "Arduino.h"

// Defines number of consignes
#include "sharedConsigneData.h"

enum EHeaterMode {
	MODE_AUTO,
	MODE_MANUAL,
	MODE_OFF
};

#define I2C_DS3231_ADDR 0x57

// Define a temperature Consigne
class Consigne {
	
  public:
	static Consigne *allConsignes[MAX_NB_CONSIGNES];
	static Consigne *consigneDefaut;
	static EHeaterMode heaterMode;
	TConsigneData data;
  
  public:
	Consigne(int index_p);
	Consigne(int index_p, bool valid_p, char* jour_p, int heure_p, int minute_p, float temp_p, int priorite_p);
  float ecartMatch(int jour_p, int heure_p, int minute_p, bool *resultValid);
  void daysToString(char *buf);
  String toString();
  static void setupConsigne();
  static Consigne *getBestConsigne(int dow_p, int hour_p, int min_p);
  static void permuterConsignes(int idx1, int idx2);// swap two consignes 
  static bool ajouterConsigneStr(char *str, bool save_p);// add a consigne (via web interface )
  static bool ajouterConsigneBlynk(int numCons_p, Consigne *cons);// add a consigne (via interface blynk)
  static bool supprimerConsigneStr(char *str);// delete a consigne (via interface web)
  static bool supprimerConsigneBlynk(int numCons);// delete a consigne (via blynk) numcons={0..n}
  static void setModeManual(float temp);
  static void setHeaterMode(EHeaterMode mode);
  static EHeaterMode getHeaterMode();
  static void putHeaterModeString(char *msg);
  static void nextHeaterMode();// AUTO -> MANUAL -> OFF -> AUTO...
  static void readAllConsignes();
  static void writeAllConsignes();
  static void dumpConsignes();

};

#endif
