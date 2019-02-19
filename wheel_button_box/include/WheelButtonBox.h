/*
 * WheelButtonBox.h
 *
 *  Created on: 13 февр. 2019 г.
 *      Author: aleck
 */

#ifndef SRC_WHEELBUTTONBOX_H_
#define SRC_WHEELBUTTONBOX_H_

#include <Joystick.h>
#include <Keypad.h>
#include <Rotary.h>

#define ENCODERS_COUNT 4
#define BUTTONS_COUNT 12
#define BUTTONS_ROWS 4
#define BUTTONS_COLS 3

Joystick_ joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 22, 0,
		false, false, false, false, false, false, false, false, false, false, false);



typedef struct {
	Rotary rotary;
	byte cw_button;
	byte ccw_button;
} Encoder;

Encoder encoders[ENCODERS_COUNT] = {
	{ Rotary(2, 3), 14, 15},
	{ Rotary(4, 5), 16, 17},
	{ Rotary(6, 7), 18, 19},
	{ Rotary(8, 9), 20, 21}
};

byte buttons[BUTTONS_ROWS][BUTTONS_COLS] = {
	{ 2, 3, 4 },
	{ 5, 6, 7 },
	{ 8, 9, 10 },
	{ 11, 12, 13}

};

byte rowPins[BUTTONS_ROWS] = { 10, 16, 14, 15 };
byte colPins[BUTTONS_COLS] = { A0, A1, A2 };

Keypad buttonBox(makeKeymap(buttons), rowPins, colPins, BUTTONS_ROWS, BUTTONS_COLS);

#endif /* SRC_WHEELBUTTONBOX_H_ */
