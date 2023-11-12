/*
 * GPIO_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Lenovo
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
#include "BitMath.h"
#include "Std_Types.h"

#define		PORTA			0
#define		PORTB			1
#define		PORTC			2

#define		PIN0			0
#define		PIN1			1
#define		PIN2			2
#define		PIN3			3
#define		PIN4			4
#define		PIN5			5
#define		PIN6			6
#define		PIN7			7
#define		PIN8			8
#define		PIN9			9
#define		PIN10			10
#define		PIN11			11
#define		PIN12			12
#define		PIN13			13
#define		PIN14			14
#define		PIN15			15


#define		GPIO_HIGH		1
#define		GPIO_LOW		0



#define		GPIO_INPUT_ANALOG				0b0000
#define		GPIO_INPUT_FLOAT				0b0100
#define		GPIO_INPUT_PULL_UP_DOWN			0b1000

#define		GPIO_OUTPUT_10MHZ_PP			0b0001
#define		GPIO_OUTPUT_10MHZ_OD			0b0101
#define		GPIO_OUTPUT_10MHZ_AFPP			0b1001
#define		GPIO_OUTPUT_10MHZ_AFOD			0b1101

#define		GPIO_OUTPUT_2MHZ_PP				0b0010
#define		GPIO_OUTPUT_2MHZ_OD				0b0110
#define		GPIO_OUTPUT_2MHZ_AFPP			0b1010
#define		GPIO_OUTPUT_2MHZ_AFOD			0b1110

#define		GPIO_OUTPUT_50MHZ_PP			0b0011
#define		GPIO_OUTPUT_50MHZ_OD			0b0111
#define		GPIO_OUTPUT_50MHZ_AFPP			0b1011
#define		GPIO_OUTPUT_50MHZ_AFOD			0b1111


void	GPIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction);
void	GPIO_voidSetPinValue(u8 port, u8 pin, u8 Value);
u8		GPIO_u8GetPinValue(u8 port, u8 pin);
void    GPIO_voidSetPortDirection(u8 port, u8 Direction);
void	GPIO_voidSetPortValue(u8 port, u16 Value);
void    GPIO_voidTogglePinValue(u8 port, u8 pin);

#endif /* GPIO_INTERFACE_H_ */
