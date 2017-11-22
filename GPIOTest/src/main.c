/**
  ******************************************************************************
  * @file    main.c

  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
			
void RCC_configuration();
void GPIO_configuration();

int main(void)
{
	RCC_configuration();
	GPIO_configuration();

	while(1)
	{
		GPIOE->ODR = 0xFFFF;
		int i;
		for(i = 0; i < 100000;)
		{
			i += 1;
		}

		GPIOE->ODR = 0x0000;
		for(i = 0; i < 100000;)
		{
			i += 1;
		}


	}
}

void RCC_configuration(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
}

void GPIO_configuration(){
	GPIO_InitTypeDef EIO_init;
	EIO_init.GPIO_Pin = GPIO_Pin_All;
	EIO_init.GPIO_Mode = GPIO_Mode_Out_PP;
	EIO_init.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOE, &EIO_init);
}
