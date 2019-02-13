#include "g27_shifter.h"

int buttons[16];
int prevGear = 0;
bool isShifterPressed;
Coordinates c;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 19, 0,
false, false, false, false, false, false,
false, false, false, false, false);

int decode_shifter(Coordinates c, bool isStickDown) {
	if (c.x < STICK_X_12) {
		if (c.y > STICK_Y_135) {
			return first;
		} else if (c.y < STICK_Y_246R) {
			return second;
		}
	}

	if (c.x > STICK_X_56R) {
		if (c.y > STICK_Y_135) {
			return fifth;
		} else if (c.y < STICK_Y_246R) {
			if (isStickDown) {
				return reverse;
			}
			return sixth;
		}
	}

	if (c.y > STICK_Y_135) {
		return third;
	}

	if (c.y < STICK_Y_246R) {
		return fourth;
	}
	return neutral;
}

void printDebugInfo() {
	Serial.print(" X axis: ");
	Serial.print(c.x);
	Serial.print("; Y axis: ");
	Serial.print(c.y);
	Serial.print("; Digital inputs: ");
	for (int i = 0; i < 16; i++) {
		Serial.print(buttons[i]);
	}
	Serial.print("; Gear: ");
	Serial.print(decode_shifter(c, buttons[1] == 1));
	Serial.print("; PrevGear: ");
	Serial.print(prevGear);
	Serial.print("\n");
}

void setup() {
	pinMode(X_AXIS_PIN, INPUT_PULLUP);
	pinMode(Y_AXIS_PIN, INPUT_PULLUP);

	pinMode(DATA_IN_PIN, INPUT);
	pinMode(MODE_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);

	digitalWrite(MODE_PIN, HIGH);
	digitalWrite(CLOCK_PIN, HIGH);

	//Serial.begin(57600);

	Joystick.begin();
}

void loop() {
	digitalWrite(MODE_PIN, LOW);
	delayMicroseconds(10);
	digitalWrite(MODE_PIN, HIGH);

	for (int i = 0; i < NUM_BUTTONS; i++) {
		digitalWrite(CLOCK_PIN, LOW);
		delayMicroseconds(10);

		buttons[i] = digitalRead(DATA_IN_PIN);

		digitalWrite(CLOCK_PIN, HIGH);
		delayMicroseconds(10);
	}

	isShifterPressed = buttons[1] == 1;

	// Reading of shifter position
	c.x = analogRead(0);                 // X axis
	c.y = analogRead(1);                 // Y axis

	int gear = decode_shifter(c, isShifterPressed);

	if (gear == 0) {
		Joystick.releaseButton(0);
		Joystick.releaseButton(1);
		Joystick.releaseButton(2);
		Joystick.releaseButton(3);
		Joystick.releaseButton(4);
		Joystick.releaseButton(5);
		Joystick.releaseButton(6);
	} else {
		Joystick.pressButton(gear - 1);
	}

	for (int i = 0; i < 12; i++) {
		Joystick.setButton(i + 7, buttons[i + 4]);
	}
	//printDebugInfo();

}

