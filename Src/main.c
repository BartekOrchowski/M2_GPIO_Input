/*
 * main.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mateusz Salamon
 *		Kurs STM32 Na Rejestrach
 *			https://stm32narejestrach.pl
 *
 *		Blog: https://msalamon.pl
 *		Sklep z elektroniką: https://sklep.msalamon.pl
 *		Kursy Embedded: https://akademiaembedded.pl
 */

#include "main.h"
#include "sys_clocks.h"
#include "led.h"
#include "software_timers.h"
#include "button_hw.h"

SoftTimer_t TimerLD2;

void TaskLD2(void);

int main(void)
{
	SystemClockSetup();
	LED_LD2_Init();

//	SoftTimerAction(&TimerLD2, TaskLD2);
//	SoftTimerStart(&TimerLD2, 200);

	Key_UserB1_Init();

    /* Loop forever */
	while(1)
	{
		if(Key_UserB1_IsPressed())
		{
			LED_LD2_On();
		}
		else
		{
			LED_LD2_Off();
		}
//		SoftTimerEvent(&TimerLD2);
	}
}

//void TaskLD2(void)
//{
//	LED_LD2_Toggle();
//}



