/*
 * NVIC_PRIV.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Lenovo
 */

#ifndef NVIC_PRIV_H_
#define NVIC_PRIV_H_

/**
 * @headerfile STD_TYPES.h
 */

#include "Std_Types.h"

/**
 * @headerfile BitMath.h
 */

#include "BitMath.h"
typedef enum {
	Group_16_NoSub = 3,
	Group_8_Sub_2,
	Group_4_Sub_4,
	Group_2_Sub_8,
	NoGroup_Sub_16,
}PriorityGrouping;


/**
 * @def 	NVIC_BASE_ADDRESS
 * @brief 	NVIC peripheral base address
 */
#define NVIC_BASE_ADDRESS  (( NVIC_t*) 0XE000E100)
/**
 * @def 	SCB_AIRCR
 * @brief 	NVIC Application Interrupt and Reset Control Register
 */
#define SCB_AIRCR *((volatile u32*) 0XE000ED0C)

/**
 * @def 	SCB_VTOR
 * @brief 	Vector Table Offset register
 */
#define SCB_VTOR  *((volatile u32*) 0xE000ED08)


/**
 * @typedef		NVIC_t
 * @brief		Struct of All Registers in NVIC Driver
 */
typedef struct
{
	u32 ISER[8];
	u32 Reserved[24];
	u32 ICER[8];
	u32 Reserved1[24];
	u32 ISPR[8];
	u32 Reserved2[24];
	u32 ICPR[8];
	u32 Reserved3[24];
	u32 IABR[8];
	u32 Reserved4[56];
	u8 IPR[240];
}NVIC_t;




#endif /* NVIC_PRIV_H_ */
