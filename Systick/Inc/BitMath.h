/*
 * BitMath.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Lenovo
 */

#ifndef BITMATH_H_
#define BITMATH_H_
#define BITBAND_PERIPH_BASE      0x42000000
#define BITBAND_PERIPH_REF       0x40000000

#define  BITBAND_SRAM(address,bit)          (*(volatile u32*)   (BITBAND_SRAM_BASE   +   (((u32)address) - BITBAND_SRAM_REF)   * 32 + (bit) * 4)
#define  BITBAND_PERIPH(address,bit)        (*(volatile u32*)   (BITBAND_PERIPH_BASE +   ((((u32)address) - BITBAND_PERIPH_REF) * 32) + ((bit) * 4)))
#define SETBIT(reg,bit)  (reg=reg|(1<<bit))
#define ToggleBIT(reg,bit)  (reg^=(1<<bit))
#define CLRBIT(reg,bit)  (reg=reg&(~(1<<bit)))
#define READBIT(reg,bit)  ((reg>>bit)&1)



#endif /* BITMATH_H_ */
