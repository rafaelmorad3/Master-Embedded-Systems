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

#include "RCC_int.h"
#include "GPIO_interface.h"
#include "NVIC.h"
#include "LCD_Interface.h"
#include "Systick.h"
#include "KeyPad.h"
#include "Segment.h"
#include "Stop_Watch.h"
#include <stdint.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
/*
void delay_ms (u32 d)
{
	volatile u32 i=0,c=(d*360);
	for(i=0 ;i<c ;i++);
}

*/
int main(void)
{
	MRCC_voidInit();
		MRCC_enumSetPeripheralClock(APB2, GPIOA, RCC_ENABLE);
		MRCC_enumSetPeripheralClock(APB2, GPIOB, RCC_ENABLE);
		GPIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_10MHZ_PP);
		GPIO_voidSetPinValue(PORTA, PIN7, GPIO_HIGH);
		LCD_Init();
		KeyPad_Init();
		LCD_GoTo(0,0);
		LCD_SendChar('A');
		Stop_Watch_Init();
	    /* Loop forever */
		for(;;){
			//delay_ms(500);

			LCD_GoTo(1, 0);
			u8 c = KeyPad_GetKey();
			if(c!='N'){

			LCD_writeNumber(c);
			Stop_Watch();
			}
			//GPIO_voidTogglePinValue(PORTA,PIN7);
		}
}
