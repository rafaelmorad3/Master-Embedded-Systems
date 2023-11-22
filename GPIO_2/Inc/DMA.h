/*
 * DMA.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Lenovo
 */

#ifndef DMA_H_
#define DMA_H_

/**
 * @headerfile DNVIC.h
 */
//#include "NVIC.h"

#include "Std_Types.h"

#define ENABLE_DMA			1
#define CHANNELS_MAX_NUMBER	7
#define COUNTER_MAX_NUMBER  65535






typedef struct
{
	u32 CCR;
	u32 CNDTR;
	u32 CPAR;
	u32 CMAR;
	u32 Reserved;
}DMA_Channel;
#define DMA_2_NVIC 11
typedef struct
{
	u32 			ISR;
	u32 			IFCR;
	DMA_Channel Channel[7];
}DMA_t;



/************************************************************************
 * Function name: D_DMA_Init
 *
 * parameters:  Input:  NA
 *
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to initialize DMA
 ***************************************************************************/

u8 D_DMA_Init(void);

/********************************************************************************************************************/

/*************************************
 *********DMA_CHANNEL_NUMBER**********
 *************************************/
#define CHANNEL_ONE		0
#define CHANNEL_TWO		1
#define CHANNEL_THREE	2
#define CHANNEL_FOUR	3
#define CHANNEL_FIVE	4
#define CHANNEL_SIX		5
#define CHANNEL_SEVEN	6

/************************************************************************
 * Function name: DRCC_SetBusPrescale
 *
 * parameters:  Input:
 *                 MemoryAddress
 *                     type: u32
 *                     Description: Takes Memory Address
 *                 PeripheralAddress
 *                     type: u32
 *                     Description: Takes Peripheral Address
 *                 Counter
 *                     type: u8
 *                     Description: Takes Counter of Data Transmission
 *                 ChannelNumber
 *                     type: u8
 *                     Description: DMA Channel Number ( CHANNEL_ONE   , CHANNEL_TWO
 *                                                       CHANNEL_THREE , CHANNEL_FOUR
 *                                                       CHANNEL_FIVE  , CHANNEL_SIX
 *                                                       CHANNEL_SEVEN             )
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to Make DMA Start Transfering Data according to it's Parameters
 ***************************************************************************/

u8 D_DMA_Start(u32 MemoryAddress,u32 PeripheralAddress,u32 Counter,u8 ChannelNumber);

/********************************************************************************************************************/

/*************************************
 *********DMA_CHANNEL_NUMBER**********
 *************************************/
#define CHANNEL_ONE		0
#define CHANNEL_TWO		1
#define CHANNEL_THREE	2
#define CHANNEL_FOUR	3
#define CHANNEL_FIVE	4
#define CHANNEL_SIX		5
#define CHANNEL_SEVEN	6

/*************************************
 *********DMA_POINTER_TO_FUNCTION*****
 *************************************/
typedef void (*TC_Notification)(void);
typedef void (*HTC_Notification)(void);
typedef void (*TE_Notification)(void);

/***************FLAGS_OF_DMA***********************/
typedef struct
{
	TC_Notification		TC;
	HTC_Notification	HTC;
	TE_Notification		TE;
}Notify_t;

/************************************************************************
 * Function name: DRCC_SetBusPrescale
 *
 * parameters:  Input:
 *                 MemoryAddress
 *                     type       : Notify_t ( Pointer To function )
 *                     Description: Takes Function to Execute
 *                 ChannelNumber
 *                     type: u8
 *                     Description: DMA Channel Number ( CHANNEL_ONE   , CHANNEL_TWO
 *                                                       CHANNEL_THREE , CHANNEL_FOUR
 *                                                       CHANNEL_FIVE  , CHANNEL_SIX
 *                                                       CHANNEL_SEVEN             )
 *
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to Set DMA Call Back Function
 ***************************************************************************/

u8 D_DMA_SetNotifyCbf(Notify_t *Notification, u8 Channel_Number);




#endif /* DMA_H_ */
