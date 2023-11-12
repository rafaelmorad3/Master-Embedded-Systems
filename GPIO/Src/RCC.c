/*
 * RCC.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Lenovo
 */


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "RCC_int.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize RCC	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void MRCC_voidInit(void)
{


		#if 	CLOCK_TYPE == HSI
		/* internal 8 MHZ RC oscillator 			*/
		/*	HSI clock enable						*/
	          SETBIT(MRCC->CR,0);
	          /*	HSI Ready Flag					*/
	          while(!READBIT(MRCC->CR,1)){}

				/*HSI selected as system clock		*/
				CLRBIT(MRCC->CFGR,0);
				CLRBIT(MRCC->CFGR,1);
				/*	HSI Ready Flag		SWS			*/
				if((!READBIT(MRCC->CR,2))&&(!READBIT(MRCC->CR,3)))
				{

				}
				else{
					// NOT READY
				}


		#elif	CLOCK_TYPE == HSE
				/*	HSE clock enable				*/
				SETBIT(MRCC->CR,16);
				/*	HSE Ready Flag					*/
				while(!READBIT(MRCC->CR,17));
				/*HSE selected as system clock		*/
				SETBIT(MRCC->CFGR,0);
	     		CLRBIT(MRCC->CFGR,1);
				/*	HSE Ready Flag			SWS		*/
	     		if((READBIT(MRCC->CR,2))&&(!READBIT(MRCC->CR,3)))
	     		{

	     		}
	     		else{
	     			// NOT READY
	     		}

		#elif	CLOCK_TYPE == PLL
				/*	The PLL output frequency must not exceed 72 MHz */
				/*PLL selected as system clock		*/
	     		CLRBIT(MRCC->CFGR,0);
	     		SETBIT(MRCC->CFGR,1);

	     		/* PLL OFF   */
	     		CLRBIT(MRCC->CR,24);

		/*PLL multiplication factor*/
	     MRCC->CFGR&=~(15<<18);
		#if CLOCK_FACTOR == MULTIPLY_BY_2
		MRCC->CFGR|=((MULTIPLY_BY_2-2)<<18);
		#elif CLOCK_FACTOR == MULTIPLY_BY_3
	     MRCC->CFGR|=((MULTIPLY_BY_3-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_4
	     MRCC->CFGR|=((MULTIPLY_BY_4-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_5
	     MRCC->CFGR|=((MULTIPLY_BY_5-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_6
	     MRCC->CFGR|=((MULTIPLY_BY_6-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_7
	     MRCC->CFGR|=((MULTIPLY_BY_7-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_8
	     MRCC->CFGR|=((MULTIPLY_BY_8-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_9
	     MRCC->CFGR|=((MULTIPLY_BY_9-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_10
	     MRCC->CFGR|=((MULTIPLY_BY_10-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_11
	     MRCC->CFGR|=((MULTIPLY_BY_11-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_12
	     MRCC->CFGR|=((MULTIPLY_BY_12-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_13
	     MRCC->CFGR|=((MULTIPLY_BY_13-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_14
	     MRCC->CFGR|=((MULTIPLY_BY_14-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_15
	     MRCC->CFGR|=((MULTIPLY_BY_15-2)<<18);

		#elif CLOCK_FACTOR == MULTIPLY_BY_16
	     MRCC->CFGR|=((MULTIPLY_BY_16-2)<<18);

		#else
			#warning	"Wrong Multiplication factor!"

		#endif

					#if 	PLL_SOURCE	==	PLL_HSI_DIVIDED_BY_2
							/*PLL entry clock source is HSI divdided by 2		*/
							CLRBIT(MRCC->CFGR,16);
					#elif	PLL_SOURCE	==	PLL_HSE
							/*PLL entry clock source is HSE						*/
							SETBIT(MRCC->CFGR,16);
							/*HSE divider for PLL entry : clock not divided 	*/
							CLRBIT(MRCC->CFGR,17);
					#elif	PLL_SOURCE	==	PLL_HSE_DIVIDED_BY_2
							/*PLL entry clock source is HSE						*/
							SETBIT(MRCC->CFGR,16);
							/*HSE divider for PLL entry : clock divided		 	*/
							SETBIT(MRCC->CFGR,17);
					#endif

				/*	PLL clock enable	PLL ON			*/
			        	SETBIT(MRCC->CR,24);
				/*	PLL Ready Flag					*/
				while(!READBIT(MRCC->CR,25));
		#else

			#error		"Wrong Clock System type congiguration!"

		#endif
		/*FOR Clock Security System				*/
		#if		CLOCK_SECURITY_SYSTEM	==	OFF
			    CLRBIT(MRCC->CR,19);

		#elif	CLOCK_SECURITY_SYSTEM	==	ON
			    SETBIT(MRCC->CR,19);
		#else
				#warning	"Wrong clock security system configuration choice!"
		#endif

}

ERROR_status MRCC_enumSetPeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralName , u8 Copy_u8PeripheralState )
{
	ERROR_status LOC_enumstate = E_NOK ;
	switch( Copy_u8PeripheralState )
	{
		case	RCC_ENABLE 	:
							switch( Copy_u8PeripheralBus )
							{
								case AHB  :	SETBIT( MRCC->AHBENR  , Copy_u8PeripheralName  );break;
								case APB1 :	SETBIT( MRCC->APB1ENR , Copy_u8PeripheralName  );break;
								case APB2 : SETBIT( MRCC->APB2ENR , Copy_u8PeripheralName  );break;
								default	  :	break;
							}
							break;
		case	RCC_DISABLE :
							switch( Copy_u8PeripheralBus )
							{
								case AHB  :	CLRBIT( MRCC->AHBENR  , Copy_u8PeripheralName  );
								break;
								case APB1 :	CLRBIT( MRCC->APB1ENR  , Copy_u8PeripheralName  );
								break;
								case APB2 : CLRBIT( MRCC->APB2ENR  , Copy_u8PeripheralName  );
								break;
								default	  :
								break;
							}
							break;
		case	RCC_RESET	:
							switch( Copy_u8PeripheralBus )
							{
								case APB1 :	SETBIT( MRCC->APB1RSTR , Copy_u8PeripheralName  );break;
								case APB2 : SETBIT( MRCC->APB2RSTR , Copy_u8PeripheralName  );break;
								default	  :	break;
							}
							break;
	}
	return LOC_enumstate;
}
