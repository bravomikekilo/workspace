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
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
			
void GPIO_config();
void RCC_config();
void TIM_config();

int main(void)
{

	for(;;);
}

void GPIO_config()
{
	GPIO_InitTypeDef E_init;
	E_init.GPIO_Mode = GPIO_Mode_Out_PP;
	E_init.GPIO_Pin  = GPIO_Pin_All;
	E_init.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOE, &E_init);
}

void RCC_config()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
}

void TIM_config()
{
	uint16_t prescaler = (uint16_t) (SystemCoreClock / 24000000) - 1;
	TIM_TimeBaseInitTypeDef base_init;
	base_init.TIM_ClockDivision = 0;
	base_init.TIM_CounterMode = TIM_CounterMode_Up;
	base_init.TIM_Period = 65535;
	base_init.TIM_Prescaler = prescaler;

	TIM_TimeBaseInit(TIM9, &base_init);
}

void NVIC_config()
{
	NVIC_InitTypeDef n_init;
	n_init.NVIC_IRQChannel = TIM2_IRQn;
	n_init.NVIC_IRQChannelCmd = ENABLE;
	n_init.NVIC_IRQChannelPreemptionPriority = 0;
	n_init.NVIC_IRQChannelSubPriority = 0;
}
