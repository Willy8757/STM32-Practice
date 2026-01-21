#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "Buzzer.h"
#include "Light_sensor.h"

int main(void){
	Buzzer_init();
	Light_sensor_init();
	
	
	while(1){
		if(Light_sensor_get() == 1){ //Dark
			Buzzer_on();
		}
		else Buzzer_off();
	}

}


