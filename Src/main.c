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

SoftTimer_t TimerLD2;

void TaskLD2(void);

int main(void)
{
	SystemClockSetup();
	LED_LD2_Init();

	SoftTimerAction(&TimerLD2, TaskLD2);
	SoftTimerStart(&TimerLD2, 200);

    /* Loop forever */
	while(1)
	{
		SoftTimerEvent(&TimerLD2);
	}
}

void TaskLD2(void)
{
	LED_LD2_Toggle();
}



