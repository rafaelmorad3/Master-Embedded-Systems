/*
 * Flash.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Lenovo
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "Std_Types.h"
#define OK 		0
#define NOT_OK 	1

/**
 * @typedef		Flash_t
 * @brief		Struct of All Registers in Flash Driver
 *				Registers :
 *				 		FLASH_ACR   	-> configuration register
 * 						FLASH_KEYR	 	-> input data register
 * 						FLASH_OPTKEYR  	-> output data register
 *						FLASH_SR 		-> bit set/reset register
 * 						FLASH_CR 		-> bit reset register
 * 						FLASH_AR 		-> configuration lock register
 * 						FLASH_RESERVED	->
 * 						FLASH_OPR 		->
 * 						FLASH_WRPR		->
 */
typedef struct{
	volatile u32 FLASH_ACR          ;
	volatile u32 FLASH_KEYR         ;
	volatile u32 FLASH_OPTKEYR      ;
	volatile u32 FLASH_SR           ;
	volatile u32 FLASH_CR           ;
	volatile u32 FLASH_AR           ;
	volatile u32 FLASH_RESERVED    ;
	volatile u32 FLASH_OPR          ;
	volatile u32 FLASH_WRPR         ;
}Flash_t;

/**
 * @def 	HALF_WORD_LEN
 * @brief 	HNo of bytes of Half Word
 */
#define HALF_WORD_LEN  2
/**
 *	@def  	KEY1
 *  @brief 	KEY1 to unlock Flash to write on it
 */
#define KEY1 ( 0x45670123 )
/**
 *	@def  	KEY2
 *  @brief 	KEY2 to unlock Flash to write on it
 */
#define KEY2 ( 0xcdef89ab )


/* CR Register*/
/**
 * @def 	LOCK
 * @brief 	used to lock Flash
 */
#define LOCK 						0x00000080
/**
 * @def 	START
 * @brief 	used to trigger an ERASE operation when set
 */
#define START  						0x00000040
/**
 * @def 	MASS_ERASE
 * @brief 	used to earse all the Flash
 */
#define MASS_ERASE 					0x00000004
/**
 * @def 	PAGE_ERASE
 * @brief 	used to earse page
 */
#define PAGE_ERASE 					0x00000002
/**
 * @def 	PROGRAM_ENABLE
 * @brief 	used to enable  falsh programming
 */
#define PROGRAM_ENABLE  			0x00000001
/**
 * @def 	MER_RESET
 * @brief 	used to reset Mass Erase bit.
 */
#define MER_RESET					0x00001FFB
/* SR Register */
/**
 * @def 	EOP
 * @brief 	used to indicate that a Flash operation is completed
 */
#define EOP							0x00000020
/*lock
unlock
write
erase
mass erase
write page
write word
*/

/**
 * @brief   Function to Lock The Flash
 * @param   NA
 * @return  NA
 */
void Flash_Lock(void);

/**
 * @brief   Function to Unlock The Flash
 * @param   NA
 * @return  NA
 */
void Flash_Unlock(void);

/**
 * @brief   Function to erase all The Flash
 * @param   NA
 * @return  NA
 */
void Flash_MassErase(void);

/**
 * @brief   Function to erase page from flash
 * @param   NA
 * @return  NA
 */
void Flash_ErasePage(u32 PageAddress);

/**
 * @brief   Function to write Full Data
 * @param   StartAddress  pointer to void , Start address to write
 * @param   DataAddress   pointer to void , Address of buffer of data
 * @param   DataLength    variabe of u32 , Length of Data to be written
 * @return  NA
 */
void Flash_ProgramWrite(void * StartAddress,void * DataAddress,u32 DataLength);

/**
 * @brief   Function to write Half Word Data
 * @param   StartAddress  pointer to u16 , Start address to write
 * @param   Data          variabe of u16 , Data to be written
 * @return  NA
 */
void Flash_HalfWord(u16 * StartAddress,u16 Data);

/**
 * @brief   Function to  write Full Word Data
 * @param   StartAddress  pointer to u32 , Start address to write
 * @param   Data          variabe of u32 , Data to be written
 * @return  NA
 */
void Flash_FullWord(u32 * StartAddress,u32 Data);

#endif /* FLASH_H_ */
