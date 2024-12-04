/*
 * button_hw.c
 *
 *  Created on: Oct 1, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */
#include "main.h"
#include "button_hw.h"

void Key_UserB1_Init(void)
{
	// PC13
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
}

uint8_t Key_UserB1_IsPressed(void)
{
	// Idle - 0
	// Pushed - 1
	if(GPIOC->IDR & GPIO_IDR_IDR_13)
	{
		return 1;
	}
	return 0;
}
