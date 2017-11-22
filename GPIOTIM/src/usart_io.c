/*
 * usart_io.c
 *
 *  Created on: 2017��11��22��
 *      Author: B
 */

#include "usart_io.h"


void uio_puts_sync(USART_TypeDef *dev, const char *str)
{
	for(;*str; ++str)
	{
		USART_SendData(dev, *str);
		while(USART_GetFlagStatus(dev, USART_FLAG_TXE) == RESET);
	}
}



void uio_put_uint16_sync(USART_TypeDef* dev, uint16_t in)
{
	if(in == 0)
	{
		uio_put_char_sync(dev, '0');
		return;
	}

	uint16_t base = 10000;
	char flag = 0;
	for(;base > 0; base /= 10){
		uint16_t a = in / base;
		if(a != 0) {
			flag = 1;
		}
		if(flag){
			USART_SendData(USART1, a + '0');
			while(USART_GetFlagStatus(dev, USART_FLAG_TXE) == RESET);
			in -= a * base;
		}
	}
}

void uio_put_char_sync(USART_TypeDef *dev, char c)
{
	USART_SendData(dev, c);
	while(USART_GetFlagStatus(dev, USART_FLAG_TXE) == RESET);
}
