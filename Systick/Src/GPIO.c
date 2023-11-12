/*
 * GPIO.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Lenovo
 */

#include "GPIO_interface.h"
#include "GPIO_private.h"

void	GPIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction)
{
	if(pin<PIN8){
		switch(port){
		case PORTA:
			GPIOA_CRL&=~(0x0F<<(pin*4));
			GPIOA_CRL|=(Direction<<(pin*4));
			break;
		case PORTB:
			GPIOB_CRL&=~(0x0F<<(pin*4));
			GPIOB_CRL|=(Direction<<(pin*4));
			break;
		case PORTC:
			GPIOC_CRL&=~(0x0F<<(pin*4));
			GPIOC_CRL|=(Direction<<(pin*4));
			break;
		}
	}
	else{
		switch(port){
		case PORTA:
			GPIOA_CRH&=~(0x0F<<((pin-8)*4));
			GPIOA_CRH|=(Direction<<(pin*4));
			break;
		case PORTB:
			GPIOB_CRH&=~(0x0F<<((pin-8)*4));
			GPIOB_CRH|=(Direction<<(pin*4));
			break;
		case PORTC:
			GPIOC_CRH&=~(0x0F<<((pin-8)*4));
			GPIOC_CRH|=(Direction<<(pin*4));
			break;
		}
	}
}

void	GPIO_voidSetPinValue(u8 port, u8 pin, u8 Value)
{
	if(Value==GPIO_HIGH){
			switch(port){
			case PORTA:
				 GPIOA_BSRR= 1<<pin;
				break;
			case PORTB:
				 GPIOB_BSRR= 1<<pin;
				break;
			case PORTC:
				if(pin<PIN3){
					 GPIOC_BSRR= 1<<pin;
				}
				break;
			}
		}
		else if(Value==GPIO_LOW){
			switch(port){
			case PORTA:
				GPIOA_BSRR= 1<<(pin+16);
				break;
			case PORTB:
				GPIOB_BSRR= 1<<(pin+16);
				break;
			case PORTC:
				if(pin<PIN3){
					GPIOC_BSRR= 1<<(pin+16);
				}
				break;
			}
		}
	/*if(Value==GPIO_HIGH){
		switch(port){
		case PORTA:
			 BITBAND_PERIPH(GPIOA_BSRR,pin) =1;
		     //SETBIT(GPIOA_BSRR,pin);
			break;
		case PORTB:
			BITBAND_PERIPH(GPIOB_BSRR,pin)=1;
			//SETBIT(GPIOB_BSRR,pin);
			break;
		case PORTC:
			BITBAND_PERIPH(GPIOB_BSRR,pin)=1;
			//SETBIT(GPIOC_BSRR,pin);

			break;
		}
	}
	else if(Value==GPIO_LOW){
		switch(port){
		case PORTA:
			BITBAND_PERIPH(GPIOB_BSRR,(pin+16))=1;
			//SETBIT(GPIOA_BRR,pin);
			break;
		case PORTB:
			BITBAND_PERIPH(GPIOB_BSRR,(pin+16))=1;
			//SETBIT(GPIOB_BRR,pin);
			break;
		case PORTC:
			BITBAND_PERIPH(GPIOB_BSRR,(pin+16))=1;
			//SETBIT(GPIOA_BSRR,pin);

		}
	}*/
}

u8		GPIO_u8GetPinValue(u8 port, u8 pin)
{
	u8 READ = GPIO_LOW;
	switch(port){
	case PORTA:
		READ=READBIT(GPIOA_IDR,pin);
		break;
	case PORTB:
		READ=READBIT(GPIOB_IDR,pin);
		break;
	case PORTC:

			READ=READBIT(GPIOC_IDR,pin);

		break;
	}
	return READ;
}

void    GPIO_voidSetPortDirection(u8 port, u8 Direction){

	switch(port){
			case PORTA:
				for(u8 i=0;i<8;i++){
				GPIOA_CRL&=~(0x0F<<(i*4));
				GPIOA_CRL|=(Direction<<(i*4));
				}
				for(u8 i=0;i<8;i++){
					GPIOA_CRH&=~(0x0F<<(i*4));
					GPIOA_CRH|=(Direction<<(i*4));
					}
				break;
			case PORTB:
				for(u8 i=0;i<8;i++){
						GPIOB_CRL&=~(0x0F<<(i*4));
						GPIOB_CRL|=(Direction<<(i*4));
				    }
					for(u8 i=0;i<8;i++){
						GPIOB_CRH&=~(0x0F<<(i*4));
						GPIOB_CRH|=(Direction<<(i*4));
					}
				break;
			case PORTC:
				for(u8 i=0;i<8;i++){
						GPIOC_CRL&=~(0x0F<<(i*4));
						GPIOC_CRL|=(Direction<<(i*4));
					}
					for(u8 i=0;i<8;i++){
						GPIOC_CRH&=~(0x0F<<(i*4));
				    	GPIOC_CRH|=(Direction<<(i*4));
					}
				break;
			}
}
void	GPIO_voidSetPortValue(u8 port, u16 Value){

	switch(port){
			case PORTA:

				GPIOA_BSRR=Value;
				break;
			case PORTB:

				GPIOB_BSRR=Value;
				break;
			case PORTC:

				GPIOC_BSRR=Value;

				break;
			}

}
void    GPIO_voidTogglePinValue(u8 port, u8 pin){
	u8 value = GPIO_u8GetPinValue(port, pin);
	switch(value){
		case GPIO_LOW:
			GPIO_voidSetPinValue(port, pin, GPIO_HIGH);
			break;
		case GPIO_HIGH:
			GPIO_voidSetPinValue(port, pin, GPIO_LOW);
			break;
	}

}
void delay_ms (u32 d)
{
	volatile u32 i=0,c=(d*350);
	for(i=0 ;i<c ;i++);
}

