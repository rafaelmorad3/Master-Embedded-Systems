/*
 * Systick_priv.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Lenovo
 */

#ifndef SYSTICK_PRIV_H_
#define SYSTICK_PRIV_H_
#include "Std_Types.h"

#define STK_CTRL	*((volatile u32*)0xE000E010)
#define STK_LOAD	*((volatile u32*)0xE000E014)
#define STK_VAL		*((volatile u32*)0xE000E018)


#endif /* SYSTICK_PRIV_H_ */
