#ifndef _g27_shifter_H_
#define _g27_shifter_H_

#include "Arduino.h"
#include "Joystick.h"

//pins definition
#define DATA_IN_PIN		 2
#define MODE_PIN		 4
#define CLOCK_PIN        3
#define X_AXIS_PIN       18
#define Y_AXIS_PIN       19

// H-shifter mode analog axis thresholds
#define STICK_X_12       430
#define STICK_X_56R      670
#define STICK_Y_135      750
#define STICK_Y_246R     250

#define DI_REVERSE       1
#define NUM_BUTTONS 	 16

#define neutral     0
#define first   	1
#define second    	2
#define third  	   	3
#define fourth  	4
#define fifth  		5
#define sixth  	   	6
#define  reverse  	7

typedef struct {
	uint16_t x;
	uint16_t y;
} Coordinates;

int decode_shifter(Coordinates c, bool isStickDown);

#endif /* _g27_shifter_H_ */
