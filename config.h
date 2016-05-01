#ifndef _CONFIG_H
#define _CONFIG_H


//#define DEBUG_SINGLESTRIP 1

#define PIN_LEFT 3
#define PIN_MIDDLE 5
#define PIN_RIGHT 6

#ifdef DEBUG_SINGLESTRIP
#define N_LEDS 72
#else
#define N_LEDS 8
#endif

#define RESERVED 0

#endif
