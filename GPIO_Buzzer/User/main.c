#include "stm32f10x.h"                  // Device header

void delay(uint32_t m){
	SysTick->LOAD = (SystemCoreClock / 1000) * m;
	SysTick->VAL = 0;
	SysTick->CTRL = 0x05; //set bit 0, 2 = 1
	
	while((SysTick->CTRL & (1<<16)) == 0); //counterflag on bit 16
	SysTick->CTRL = 0;
}

int main(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //push-pull
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	while(1){
		
		GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);
		delay(100);
		GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);
		delay(100);
		
	}

}


