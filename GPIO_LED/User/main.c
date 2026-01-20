#include "stm32f10x.h"                  // Device header

void delay(uint32_t m){
	SysTick->LOAD = (SystemCoreClock / 1000) * m;
	SysTick->VAL = 0;
	SysTick->CTRL = 0x05; //set bit 0, 2 = 1
	
	while((SysTick->CTRL & (1<<16)) == 0); //counterflag on bit 16
	SysTick->CTRL = 0;
}

int main(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //push-pull
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All; //GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 ...
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	while(1){
		
		//**************flash*************
		/*
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		delay(100);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		delay(100);
		*/
		
		//***************Flowing Lights************
		
		GPIO_Write(GPIOA, ~0x0001); 
		delay(500);
		GPIO_Write(GPIOA, ~0x0002); 
		delay(500);
		GPIO_Write(GPIOA, ~0x0004); 
		delay(500);
		GPIO_Write(GPIOA, ~0x0008); 
		delay(500);
	}

}


