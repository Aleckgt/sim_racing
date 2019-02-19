/*
 * WheelButtonBox.cpp
 *
 *  Created on: 13 февр. 2019 г.
 *      Author: aleck
 */
#include <WheelButtonBox.h>

void setup() {
	joystick.begin();
	pinMode(0, INPUT_PULLUP);
	pinMode(1, INPUT_PULLUP);
}

void encoderToButton(char button) {
	joystick.pressButton(button);
	delay(50);
	joystick.releaseButton(button);
}

void loop() {
	unsigned char res;
	for (int i = 0; i < ENCODERS_COUNT; i++) {
		res = encoders[i].rotary.process();
		if (res == DIR_CCW) {
			encoderToButton(encoders[i].ccw_button);
		}
		if (res == DIR_CW) {
			encoderToButton(encoders[i].cw_button);
		}
	}
	if (!digitalRead(0)) {
		joystick.pressButton(1);
	} else {
		joystick.releaseButton(1);
	}
	if (!digitalRead(1)) {
		joystick.pressButton(0);
	} else {
		joystick.releaseButton(0);
	}
	if (buttonBox.getKeys()) {
		for (int i = 0; i < LIST_MAX; i++) {
			if (buttonBox.key[i].stateChanged) {
				switch (buttonBox.key[i].kstate) {
				case PRESSED:
				case HOLD:
					joystick.pressButton(buttonBox.key[i].kchar);
					break;
				case RELEASED:
				case IDLE:
					joystick.releaseButton(buttonBox.key[i].kchar);
					break;
				}
			}
		}
	}
}
