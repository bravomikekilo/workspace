/*
 * stm32f10x_it.c
 *
 *  Created on: 2017Äê11ÔÂ21ÈÕ
 *      Author: B
 */

#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "stm32f10x_adc.h"
#include "usart_io.h"

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		GPIOE->ODR = ~GPIOE->ODR;
		uio_puts_sync(USART1, " hello, ");
	}
}


void ADC1_2_IRQHandler(void)
{
	if(ADC_GetITStatus(ADC1, ADC_IT_EOC) != RESET){
		uint16_t value = ADC_GetConversionValue(ADC1);
		GPIOE->ODR = value;
	}
}
