/*
 * Systick.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Lenovo
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "BitMath.h"
#include "Std_Types.h"


#define SYSTICK_ENABLE   0x00000001
#define SYSTICK_DISABLE  0xFFFFFFFE

#define OK       0
#define NOT_OK   1

#define SYSTICK_CLK_AHB  	   0x00000004
#define SYSTICK_CLK_AHB_DIV_8  0x00000000


#define SYSTICK_TICK_INT_ENABLE  0x00000002
#define SYSTICK_TICK_INT_DISABLE 0x00000000

typedef void (*systickcbf_t) (void);
u8 SYSTICK_Init (void);
u8 SYSTICK_Start (void);
u8 SYSTICK_Stop (void);
u8 SYSTICK_SetCallback (systickcbf_t cbf);
u8 SYSTICK_SetTime (u8 timeus,u32 clk);
u8 SYSTICK_SetPrescale (u32 prescale);

#endif /* SYSTICK_H_ */
