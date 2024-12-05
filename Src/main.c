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
#include "button.h"

SoftTimer_t TimerLD2;
TButton BlueKey;

void TaskLD2(void);

int main(void)
{
	SystemClockSetup();

	LED_LD2_Init();

//	SoftTimerAction(&TimerLD2, TaskLD2);
//	SoftTimerStart(&TimerLD2, 500);

	Key_UserB1_Init();

	// Button Library Setup
	ButtonRegisterSystemTickCallback(GetSystemTick);

	//(struktura przycisku, wskaznik do funkcji sprawdzającej, debounce, czas dlugiego przycisniecia, repeat?)
	ButtonInitKey(&BlueKey, Key_UserB1_IsPressed, 30, 2000, 500);
	ButtonRegisterPressCallback(&BlueKey, LED_LD2_On);
	ButtonRegisterLongPressCallback(&BlueKey, LED_LD2_Off);
	ButtonRegisterRepeatCallback(&BlueKey, LED_LD2_Toggle);

    /* Loop forever */
	while(1)
	{
//		SoftTimerEvent(&TimerLD2);
		ButtonTask(&BlueKey);
	}
}

void TaskLD2(void)
{
	LED_LD2_Toggle();
}



