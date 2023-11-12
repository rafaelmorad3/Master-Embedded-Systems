/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <LCD_Interface.h>
#include <stdint.h>
#include "RCC_int.h"
#include "Systick.h"
#define Clock 8000000ul

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void ticks (void){
	static u8 sec=0;
	sec++;
	GPIO_voidTogglePinValue(PORTA,PIN7);
	if(sec/5&&(sec%5==0)){
		LCD_GoTo(0,0);
		LCD_SendString("G6 Group");

	}
	else{
				LCD_Clear();
		}
	if(sec==10){
		LCD_GoTo(1,0);
		LCD_SendString("free Plastine");

		sec=0;
	}



}
int main(void)
{
	MRCC_voidInit();
			MRCC_enumSetPeripheralClock(APB2, GPIOA, RCC_ENABLE);
			GPIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_10MHZ_PP);
			GPIO_voidSetPinValue(PORTA, PIN7, GPIO_HIGH);
			LCD_Init();
			LCD_GoTo(0,0);
			LCD_SendChar('A');
			SYSTICK_Init ();
			SYSTICK_SetCallback (ticks);
			SYSTICK_SetTime (1,Clock);
			SYSTICK_Start ();
		    /* Loop forever */
			for(;;){

			}
}
