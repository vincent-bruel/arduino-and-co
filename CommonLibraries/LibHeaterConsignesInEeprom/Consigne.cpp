#include "Consigne.h"
#include "vb-eeprom-ds3231.h"
#include "vb-i18n.h"
/**
  * V.BRUEL
  */
// Note: these are static vars
// Array of consignes
Consigne *Consigne::allConsignes[MAX_NB_CONSIGNES];
// Default consigne
Consigne *Consigne::consigneDefaut = NULL;
// Current heater mode
EHeaterMode Consigne::heaterMode;

// Call this method in the setup() method
void Consigne::setupConsigne() {
  // Mode at program startup
  Consigne::heaterMode = MODE_AUTO;

  for (int i = 0; i < MAX_NB_CONSIGNES; i++) {
    Consigne::allConsignes[i] = new Consigne(i, false, "0000000", 255, 255, 17.0, 9);
  }
  if (Consigne::consigneDefaut == NULL) {
    Consigne::consigneDefaut = new Consigne(-1, true, "1111111", 8, 10, 17.1, 9);
  }
}

Consigne::Consigne(int index_p, bool valid_p, char* jour_p, int heure_p, int minute_p, float temp_p, int priorite_p) {
  data.index = index_p;
  data.valide = valid_p;
  strcpy(data.jour, jour_p);
  data.heure = heure_p;
  data.minute = minute_p;
  data.priorite = priorite_p;
  data.temp = temp_p;
}

Consigne::Consigne(int index_p) {
  data.index = index_p;
  data.valide = false;
}

void Consigne::daysToString(char *buf) {
  buf[0] = data.jour[0] == '1' ? I18N_DAY_MON : '-';
  buf[1] = data.jour[1] == '1' ? I18N_DAY_TUE : '-';
  buf[2] = data.jour[2] == '1' ? I18N_DAY_WED : '-';
  buf[3] = data.jour[3] == '1' ? I18N_DAY_THU : '-';
  buf[4] = data.jour[4] == '1' ? I18N_DAY_FRI : '-';
  buf[5] = data.jour[5] == '1' ? I18N_DAY_SAT : '-';
  buf[6] = data.jour[6] == '1' ? I18N_DAY_SUN : '-';
  buf[7] = '\0';
}

String Consigne::toString() {
  String str = String("[");
  str += data.index + 1;
  str += "] ";
  str += data.jour;
  str += " ";
  str += data.heure;
  str += "h";
  str += data.minute;
  str += " ";
  str += data.temp;
  str += " ";
  str += data.priorite;
  return str;
}

// Assert is: D2 >= D1
float deltaMinutes(int d1, int h1, int m1, int d2, int h2, int m2) {
  float t1 = 24 * 60 * d1 + 60 * h1 + m1;
  float t2 = 24 * 60 * d2 + 60 * h2 + m2;
  return t2 - t1;
}

// Returns delta in minutes from the consigne relative to the current time.
// The delta is positive if actual time is superior, or negative if actual time is inferior to the consigne time.
// NB: if negative, this consigne will not be taken into account for best consigne,
// because this consigne is in the future, and as we search the most recent but passed consigne.
// Example: consigne Thursday 17h and current time Friday 6h => delta = 24-17+6 = 13h
float Consigne::ecartMatch(int jour_p, int heure_p, int minute_p, bool *resultValid) {
  if (data.valide == false) {
    *resultValid = false;// pas prise en compte
    return -1.0;
  }
  float ecart1 = -1.0;
  // We find inside the consigne the nearest passed day (if there is one)
  int chj;
  for (chj = jour_p; chj >= 0; chj--) {
    if (data.jour[chj] == '1') // this day is ON
    {
      // Consigne has the same day: return delta in minutes
      if (chj == jour_p && (data.heure * 60 + data.minute) > heure_p * 60 + minute_p) {
        continue;
      }
      ecart1 = deltaMinutes(chj, data.heure, data.minute, jour_p, heure_p, minute_p);
      *resultValid = true;
      return ecart1;
    }
  }
  // Found no day in the past but if we are Tuesday and Sunday is set on the consigne then it should work
  // (because we consider it is sunday of the previous week)
  // Instead of starting from current day to go to monday, we start from sunday till the current day
  float ecart2 = -1.0;
  for (chj = 6; chj >= jour_p; chj--) {
    if (data.jour[chj] == '1') // jour positionné
    {
      if (chj == jour_p && (data.heure * 60 + data.minute) < heure_p * 60 + minute_p) {
        continue;
      }
      ecart2 = 7 * 24 * 60 - deltaMinutes(jour_p, heure_p, minute_p, chj, data.heure, data.minute);
      *resultValid = true;
      return ecart2;
    }
  }

  *resultValid = false;

  return -1;
}

// Finds best consigne for current day/hour/minute
// dow_p: [0-6] 0 for monday
Consigne *Consigne::getBestConsigne(int dow_p, int hour_p, int min_p) {
	if (Consigne::heaterMode == MODE_OFF) {
		// We should not pass here
		return NULL;
	} else if (Consigne::heaterMode == MODE_MANUAL) {
		// In manual mode, we use default consigne to store manual temp defined by the user
		return Consigne::consigneDefaut;
	}
	
  // Assume heaterMode is MODE_AUTO
	
  float bestEcart = 2 * 7 * 24 * 60.0;

  Consigne *bestConsigne = NULL;

  for (int i = 0; i < MAX_NB_CONSIGNES; i++) {
    if (Consigne::allConsignes[i]->data.valide == true) {
      bool resultValid = false;
      float ecart = Consigne::allConsignes[i]->ecartMatch(dow_p, hour_p, min_p, &resultValid);//jour heure minute
      if (resultValid && ecart < bestEcart) {
        bestEcart = ecart;
        bestConsigne = Consigne::allConsignes[i];
      }
    }
  }
  return (bestConsigne == NULL) ? Consigne::consigneDefaut : bestConsigne;
}


// swaps two consignes
void Consigne::permuterConsignes(int idx1, int idx2) {
  // Swap slots
  Consigne *temp = Consigne::allConsignes[idx1];
  Consigne::allConsignes[idx1] = Consigne::allConsignes[idx2];
  Consigne::allConsignes[idx2] = temp;
  writeAllConsignes();
}



// add a consigne (via interface blynk)
bool Consigne::ajouterConsigneBlynk(int numCons_p, Consigne *cons_p) {
  Consigne *pt = Consigne::allConsignes[numCons_p];
  if (pt != NULL) {
    delete pt;
  }
  Consigne::allConsignes[numCons_p] = cons_p;
  writeAllConsignes();
}

// add a consigne (via web interface, post consigne as a string )
// str: "1010111 17h54 18.9 3"
// str: "<daysBits> <hour>h<minute> <tempInt>.<tempDec> <priority>"

// Stages for decoding string:
//    stage=1 (jours)
//    stage=2 (heure)
//    stage=3 (minutes)
//    state=4 (tempInt)
//    stage=5 (tempDec)
//    stage=6 (priorite)
bool Consigne::ajouterConsigneStr(char *str, bool save_p) {
  char f[10];
  Consigne *c = NULL;
  int idx = 0;
  for (; idx < MAX_NB_CONSIGNES; idx++) {
    if (Consigne::allConsignes[idx]->data.valide == false) {
      c = Consigne::allConsignes[idx];
      break;
    }
  }
  if (c == NULL) {
    return false;
  }
  int stage = 1; // lecture jours = stage1
  int nombreCourant = 0;
  int ifi = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ' || str[i] == '.' || str[i] == ':' || str[i] == 'h' || str[i] == 'H') {
      // Field separator: finish current stage
      f[ifi] = '\0';
      switch (stage) {
        case 1:
          // New field "0101000"
          strcpy(c->data.jour, f);
          break;
        case 2: c->data.heure = atoi(f); break; // "18"
        case 3: c->data.minute = atoi(f); break;// "55"
        case 4: c->data.temp = atoi(f); break; // "17"
        case 5: c->data.temp += (f[0] - '0') / 10.0; break; // "9C" de "17.9C" => 9/10 = 0.9
          // Managed after \0 so outside/after this loop
          //case 6: c->data.priorite = atoi(f); break; // "1"
      }
      ifi = 0;
      f[0] = '\0';
      stage++;
      nombreCourant = 0;
      continue;
    }
    f[ifi++] = str[i];
  }
  // Manage stage 6
  f[ifi] = '\0';
  c->data.priorite = atoi(f);

  c->data.valide = true;
  if (save_p) {
    writeAllConsignes();
  }
  return true;
}

// deletes a consigne (via blynk)
// numCons starts à 0
bool Consigne::supprimerConsigneBlynk(int numCons_p) {
  if (numCons_p >= 0 && numCons_p < MAX_NB_CONSIGNES) {
	Consigne::allConsignes[numCons_p]->data.valide = false;
	writeAllConsignes();
  }
}
// deletes a consigne (via interface web)
bool Consigne::supprimerConsigneStr(char *str) {
  // "6" => '6'-'0' => 6
  int idx = (str[0] - '0');
  if (idx >= 0 && idx < MAX_NB_CONSIGNES) {
    Consigne::allConsignes[idx]->data.valide = false;
    writeAllConsignes();
  }
}

void Consigne::setModeManual(float temp) {
  Consigne::heaterMode = MODE_MANUAL;
  // Don't change default consigne temp unless required temp is wise.
  if (temp >= 7.0 && temp <= 26.0) {
   Consigne::consigneDefaut->data.temp = temp;
  }
}

void Consigne::setHeaterMode(EHeaterMode mode_p) {
  Consigne::heaterMode = mode_p;
}

// rolling between modes
// this allows us to change the mode by just pushing a button
void Consigne::nextHeaterMode() {
	
	if (Consigne::heaterMode == MODE_AUTO) {
		// Go into manual mode
        Consigne::setHeaterMode(MODE_MANUAL);
        Consigne::setModeManual(Consigne::consigneDefaut->data.temp);
	} else if (Consigne::heaterMode == MODE_MANUAL) {
		// Go into OFF mode
		Consigne::heaterMode = MODE_OFF;
	} else if (Consigne::heaterMode == MODE_OFF) {
		// Go into AUTO mode
		Consigne::heaterMode = MODE_AUTO;
	} 
}

EHeaterMode Consigne::getHeaterMode() {
	return Consigne::heaterMode;
}

void Consigne::putHeaterModeString(char *msg) {
  if (Consigne::heaterMode == MODE_OFF) {
    strcpy(msg , "OFF");
  } else if (Consigne::heaterMode == MODE_AUTO) {
    strcpy(msg, "AUTO");
  } else if (Consigne::heaterMode == MODE_MANUAL) {
    strcpy(msg, "MANUAL");
  }
}

/**
  * Read consignes from EEPROM
  */
void Consigne::readAllConsignes() {
  for (int i = 0; i < MAX_NB_CONSIGNES; i++) {
    if (Consigne::allConsignes[i] == NULL) {
      Consigne::allConsignes[i] = new Consigne(i); // consigne is initially invalid
      Consigne::allConsignes[i]->data.valide = false;
    }
    TConsigneData data;
    i2c_eeprom_read_buffer(I2C_DS3231_ADDR, i*32, (byte*)&data, sizeof(TConsigneData));
    if (data.valide == true && data.temp >= 7.0 && data.temp <= 24.0 && data.heure >= 0 && data.heure <= 24 && data.minute >= 0 && data.minute <= 60) {
      // valid in EEPROM
    } else {
      // invalid in EEPROM
      data.valide = false;
	  /*
      if (data.valide == false) {
        //IF_SERIAL(" Bad valid: ");
        //IF_SERIALN_NOF(data.valide); 
      } else {
        //IF_SERIAL(" OK valid: ");
        //IF_SERIALN_NOF(data.valide); 
      }
      if (data.temp < 7.0 || data.temp > 24.0) {
        //IF_SERIAL("  Bad temp: "); 
        //IF_SERIALN_NOF(data.temp); 
      } else {
        //IF_SERIAL("  OK temp: "); 
        //IF_SERIALN_NOF(data.temp); 
      }
      if (data.heure < 0 || data.heure > 24) {
        //IF_SERIAL("  Bad heure: "); 
        //IF_SERIALN_NOF(data.heure); 
      } else {
        //IF_SERIAL("  OK heure: "); 
        //IF_SERIALN_NOF(data.heure); 
      }
      if (data.minute < 0 || data.minute > 60) {
        //IF_SERIAL("  Bad minute: "); 
        //IF_SERIALN_NOF(data.minute); 
      } else {
        //IF_SERIAL("  OK minute: "); 
        //IF_SERIALN_NOF(data.minute); 
      }*/
    }
    memcpy(&(Consigne::allConsignes[i]->data), &data, sizeof(TConsigneData));
  }
}

/**
  *  Write consignes to DS3231 EEPROM
  */
void Consigne::writeAllConsignes() {
  for (int i = 0; i < MAX_NB_CONSIGNES; i++) {
    i2c_eeprom_write_page(I2C_DS3231_ADDR, i*32, (byte *)(&(Consigne::allConsignes[i]->data)), sizeof(TConsigneData));
    delay(10);
  }

void Consigne::dumpConsignes() {
   for (int i = 0; i < MAX_NB_CONSIGNES; i++) {
		Serial.print("Consigne[");
		Serial.print(i);
		Serial.print("]=");
	   if (Consigne::allConsignes[i]) == NULL) {
		   Serial.println("NULL");
	   } else {
		   Serial.println(Consigne::allConsignes[i]->toString());
	   }
   }
 }

}

