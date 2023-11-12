/*
 * NVIC.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Lenovo
 */



/**
 * @headerfile DNVIC.h
 */
#include "NVIC.h"

/**
 * @brief NV pointer to struct NVIC_t
 */
NVIC_t   *NV =NVIC_BASE_ADDRESS;

u8 DNVIC_EnableIRQ(u8 IRQn)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	NV->ISER[IRQn/32]=1<<(IRQn%32);
		}
			return Error;
}


u8 DNVIC_DisableIRQ(u8 IRQn)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	NV->ICER[IRQn/32]=1<<(IRQn%32);
		}
			return Error;
}

u8 DNVIC_SetPendingIRQ (u8 IRQn)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	NV->ISPR[IRQn/32]=1<<(IRQn%32);
		}
			return Error;
}

u8 DNVIC_ClearPendingIRQ (u8 IRQn)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	NV->ICPR[IRQn/32]=1<<(IRQn%32);
		}
			return Error;

}

u8 DNVIC_GetPendingIRQ (u8 IRQn, u8 *Val)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	*Val =READBIT(NV->ISPR[IRQn/32],(IRQn%32));
		}
			return Error;


}

u8 DNVIC_GetActive (u8 IRQn, u8 *Val)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	*Val =READBIT(NV->IABR[IRQn/32],(IRQn%32));
		}
			return Error;
}

u8 DNVIC_SetPriorityGrouping(PriorityGrouping priority_grouping)
{	ERROR_status Error =E_NOK;
	if(priority_grouping < 8){
	Error =E_OK;
	SCB_AIRCR=PASSWORD_MASK;
	SCB_AIRCR&=~0x7<<PriorityGrouping_POSITION;
	SCB_AIRCR|=priority_grouping<<PriorityGrouping_POSITION;
	}
		return Error;
}

u8 DNVIC_SetPriority (u8 IRQn, u8 priority)
{
	ERROR_status Error =E_NOK;
	if(IRQn<80){
		Error =E_OK;
	//NV->IPR[IRQn/4]=priority<<((IRQn%4)*8+4);
		NV->IPR[IRQn/4]=(priority<<4)&0xF0;
	}
	return Error;
}

u8 DNVIC_GetPriority (u8 IRQn, u8 *priority)
{
	ERROR_status Error =E_NOK;
		if(IRQn<80){
			Error =E_OK;
	//*priority=(NV->IPR[IRQn/4]>>((IRQn%4)*8+4))&0x0f;
			*priority=((NV->IPR[IRQn/4])>>4)&0x0F;
		}
			return Error;
}


/* must develop after reading ch7 and ending the task needed */
void DNVIC_voidDisableAllPeripherals(void)
{
	__asm ("mov r0, #1 \n\t"
			"msr PRIMASK, r0");
}


void DNVIC_voidEnableAllPeripherals(void)
{
	__asm ("mov r0, #0 \n\t"
		   "msr PRIMASK, r0");
}

void DNVIC_voidDisableAllFaults(void)
{
	__asm ("mov r0, #0 \n\t"
			   "msr FAULTMASK, r0");

}


void DNVIC_voidEnableAllFaults(void)
{
	__asm ("mov r0, #1 \n\t"
		   "msr FAULTMASK, r0");
}

void DNVIC_voidSetBASEPRI(u8 priority)
{
	__asm ("mov r0, %0 "
			:"+r"(priority) );
	__asm ("msr BASEPRI, r0");
}
void DNVIC_voidChangeVectorOffset (u32 offset)
{
	SCB_VTOR= (offset<<OFFSET_POSITION)&OFFSET_MASK;
}

void DNVIC_voidSysReset(void)
{

	SCB_AIRCR=PASSWORD_MASK;
	SCB_AIRCR|= RESET_MASK;

}


