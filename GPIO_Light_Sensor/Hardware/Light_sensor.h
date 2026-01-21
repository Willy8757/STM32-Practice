#include "stm32f10x.h"                  // Device header

#ifndef __LIGHT_SENSOR_H
#define __LIGHT_SENSOR_H

void Light_sensor_init(void);
uint8_t Light_sensor_get(void);

#endif

