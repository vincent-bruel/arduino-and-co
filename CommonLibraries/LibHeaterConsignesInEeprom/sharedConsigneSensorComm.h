#ifndef _SHAREDCONSIGNESENSORCOMM_
#define _SHAREDCONSIGNESENSORCOMM_ 1

#include "sharedConsigneData.h"
#include "vb-time.h"

// size of buffer that stores a line of text for the Consigne commands + null terminator
// 1010111 18h55 19.5 3 => 20 chars + 1 for '\0'
#define CONSIGNE_WEB_BUF_SZ   21
// Max consignes stored in EEPROM.
#define MAX_NB_CONSIGNES 10

#endif
