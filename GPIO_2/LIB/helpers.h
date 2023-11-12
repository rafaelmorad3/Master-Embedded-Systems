/*
 * helpers.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Lenovo
 */

#ifndef HELPERS_H_
#define HELPERS_H_


// Base address of all regions


#define FLASH_BASE_ADDRESS           0x00000000
#define SRAM_BASE_ADDRESS            0x20000000
#define PERIPHERAL_BASE_ADDRESS      0x40000000
#define SRAM_BBR_BASE_ADDRESS        0x20000000
#define SRAM_BBA_BASE_ADDRESS        0x22000000
#define PERIPHERAL_BBR_BASE_ADDRESS  0x40000000
#define PERIPHERAL_BBA_BASE_ADDRESS  0x42000000





#define BIT_BAND(reg,bit)            *((vu32*)(PERIPHERAL_BBA_BASE_ADDRESS+(((vu32)reg-PERIPHERAL_BASE_ADDRESS)*32+(bit*4))))



#endif /* HELPERS_H_ */
