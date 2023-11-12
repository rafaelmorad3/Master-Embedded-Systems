/*
 * Systick.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Lenovo
 */


#include "Systick.h"
#include "Systick_priv.h"
#include "Systick_config.h"

systickcbf_t APPcbf ;

u8 SYSTICK_Init (void)
{
	/* CLK source and interrupt enable */
	STK_CTRL|=SYSTICK_CLK_AHB|SYSTICK_TICK_INT_ENABLE;
	return OK;
}
u8 SYSTICK_Start (void)
{
	/* enable counter */
	STK_CTRL|= SYSTICK_ENABLE;
	return OK;
}
u8 SYSTICK_Stop (void)
{
	/* disable counter */
	STK_CTRL&= SYSTICK_DISABLE;
	return OK;
}
u8 SYSTICK_SetCallback (systickcbf_t cbf)
{
	/* callback function */
	if(cbf)
		{
			APPcbf = cbf;
			return OK;
		}
		else
		{
			return NOT_OK;
		}


}
u8 SYSTICK_SetTime (u8 timeus,u32 clk)
{
	/* add value to STK LOAD */
	if (STK_CTRL & SYSTICK_CLK_AHB)
		{
			STK_LOAD=(timeus * clk)/1;
		}
		else if (!(STK_CTRL & SYSTICK_CLK_AHB))
		{
			STK_LOAD=(timeus * (d64)clk)/8;
		}
		else
		{
			return NOT_OK;
		}
		return OK;

}
void SysTick_Handler(void)
{
	if(APPcbf!=NULL_PTR){
		APPcbf();
		}
}
