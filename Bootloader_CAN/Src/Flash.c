/*
 * Flash.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Lenovo
 */


/*
 * FLITF.c
 *
 *  Created on: May 17, 2020
 *      Author: Amr Ibrahim
 */
#include "Flash.h"
/**
 * @def		pFlash
 * @brief 	Casting Base Address of Flash Driver as Pointer to struct Flash_t
 *
 */
#define pFlash ((Flash_t *)(0x40022000))

void Flash_Lock(void){
	pFlash->FLASH_CR |= LOCK;
}

void Flash_Unlock(void){
	pFlash->FLASH_KEYR = (u32)KEY1;

	pFlash->FLASH_KEYR = (u32)KEY2;

}

void Flash_MassErase(void){
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_CR |= MASS_ERASE;
	pFlash->FLASH_CR |= START;
	pFlash->FLASH_CR &= MER_RESET;
}


void Flash_ErasePage(u32 PageAddress){
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_CR |= PAGE_ERASE;
	pFlash->FLASH_AR  = PageAddress;
	pFlash->FLASH_CR |= START;
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_SR |= EOP;
	pFlash->FLASH_CR &= ~PAGE_ERASE;
}

void Flash_ProgramWrite(void * StartAddress,void * DataAddress,u32 DataLength){
	u32 Iterator=0;
	u16 temp;
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_CR |= PROGRAM_ENABLE;
	while((DataLength - 2*Iterator) >= HALF_WORD_LEN ){
		( ( u16 *) StartAddress )[Iterator]  = ( ( u16 *) DataAddress )[Iterator];
		Iterator ++;
	}
	if((DataLength - 2*Iterator)){
		temp =(( (u8 *) DataAddress )[2*Iterator])  | 0xff00;
		( (u16 *) StartAddress )[Iterator] =temp ;
	}
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_SR |= EOP;
	pFlash->FLASH_CR &= ~PROGRAM_ENABLE;

}

void Flash_HalfWord(u16 * StartAddress,u16 Data){
	pFlash->FLASH_KEYR = (u32)KEY2;
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_CR |= PROGRAM_ENABLE;
	*StartAddress = Data;
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_SR |= EOP;
	pFlash->FLASH_CR &= ~PROGRAM_ENABLE;
}

void Flash_FullWord(u32 * StartAddress,u32 Data){
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_CR |= PROGRAM_ENABLE;
	*StartAddress = Data;
	while(pFlash->FLASH_SR & BUSY);
	pFlash->FLASH_SR |= EOP;
	pFlash->FLASH_CR &= ~PROGRAM_ENABLE;
}


