#include "stm32f10x.h"                  // Device header
#include "LED_driver.h"
#include "Delay.h"
#include "Key.h"

int main(void){
	LED_init();
	Key_init();
	uint8_t Key_num;
	while(1){
		/*
		Key_num = Key_getnum();
		if(Key_num == 1) LED_turn(GPIO_Pin_1);
		if(Key_num == 2) LED_turn(GPIO_Pin_2);*/
		
		while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)){
			LED_on(GPIO_Pin_1);
		}
		LED_off(GPIO_Pin_1);
		while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)){
			LED_on(GPIO_Pin_2);
		}
		LED_off(GPIO_Pin_2);
		
	}

}


