#ifndef _SHAREDCONSIGNEDATA_
#define _SHAREDCONSIGNEDATA_ 1

typedef struct {
  int index;
  bool valide; // if consigne is valid (EEPROM slot is filled)
  char jour[8]; // days of the week toggles 0=off 1=on, +1 char for '\0'
  int heure; // hour of the day (0-23)
  int minute; // minute of the hour (0-59)
  float temp; // Consigne temperature
  int priorite; // Priority of this consigne (1= greater priority, 2=lesser priority, ...)
} TConsigneData;

// size of buffer that stores a line of text for the Consigne commands + null terminator
// 1010111 18h55 19.5 3 => 20 chars + 1 for '\0'
#define CONSIGNE_WEB_BUF_SZ   21
// Max consignes stored in EEPROM.
#define MAX_NB_CONSIGNES 10

#endif
