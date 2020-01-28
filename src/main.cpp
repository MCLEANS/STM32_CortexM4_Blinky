/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
			

int main(void)
{

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//set to general purpose output mode
	GPIOA->MODER |= GPIO_MODER_MODER6_0;
	GPIOA->MODER |= GPIO_MODER_MODER7_0;
	//set speed to medium
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6_0;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7_0;
	//output register type
	GPIOA->OTYPER |= GPIO_OTYPER_OT_6;
	GPIOA->OTYPER |= GPIO_OTYPER_OT_7;

	//ENABLE RCC FOR BUTTON GPIO
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	//RESET STATE IS INPUT
	//SET AS PULL-UP
	GPIOE->PUPDR |= GPIO_PUPDR_PUPDR4_0;
	GPIOE->PUPDR |= GPIO_PUPDR_PUPDR3_0;


	unsigned long duration = 200000;

	while(1){

		bool k0_is_high = (GPIOE->IDR & (1<<4));
		bool k1_is_high = (GPIOE->IDR & (1<<3));


		if(!k0_is_high){
			duration += 100000;
		}

		if(!k1_is_high){
			duration-=100000;
		}

		GPIOA->ODR ^= (1<<6);
		GPIOA->ODR ^= (1<<7);
		for(unsigned long i = 0; i < duration ; i++){}


	}
}
