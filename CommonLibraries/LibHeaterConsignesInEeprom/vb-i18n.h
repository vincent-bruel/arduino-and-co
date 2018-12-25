#ifndef _I18N_H_
#define _I18N_H_ 1

// Comment this if you are english
#define I_AM_FRENCH 1

#ifdef I_AM_FRENCH
#define I18N_DAY_MON 'L'
#define I18N_DAY_TUE 'M'
#define I18N_DAY_WED 'M'
#define I18N_DAY_THU 'J'
#define I18N_DAY_FRI 'V'
#define I18N_DAY_SAT 'S'
#define I18N_DAY_SUN 'D'
#else
#define I18N_DAY_MON 'M'
#define I18N_DAY_TUE 'T'
#define I18N_DAY_WED 'W'
#define I18N_DAY_THU 'T'
#define I18N_DAY_FRI 'F'
#define I18N_DAY_SAT 'S'
#define I18N_DAY_SUN 'S'
#endif
#endif

