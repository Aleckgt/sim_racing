#ifndef HX711_H_
#define HX711_H_

#include "stm32f1xx_hal.h"

typedef struct _hx711
{
	GPIO_TypeDef* gpioSck;
	GPIO_TypeDef* gpioData;
	uint16_t pinSck;
	uint16_t pinData;
	uint32_t offset;
	int gain;
	// 1: channel A, gain factor 128
	// 2: channel B, gain factor 32
    // 3: channel A, gain factor 64
} HX711;


void HX711_Init(HX711 data);
HX711 HX711_Tare(HX711 data);
uint32_t HX711_Value(HX711 data);
int HX711_AverageValue(HX711 data, int times);

#endif /* HX711_H_ */
