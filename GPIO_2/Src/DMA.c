/*
 * DMA.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Lenovo
 */
#include "DMA.h"
#include "DMA_Cfg.h"
#define DMA ((volatile DMA_t*)0x40020000)

Notify_t NotificationArray[7];
extern DMA_Config DMA_Configure[MAX_NUMBER_OF_CHANNELS];
