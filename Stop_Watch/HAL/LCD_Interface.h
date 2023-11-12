/*
 * LCD_Interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: Lenovo
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "GPIO_interface.h"
/*****************************************************************************/
/*            LCD   configuration pins                                       */
/********************************************************************************/

#define   RS          PORTA,PIN5
#define   EN          PORTA,PIN6
#define   LCD_PIN_1   PORTA,PIN1
#define   LCD_PIN_2   PORTA,PIN2
#define   LCD_PIN_3   PORTA,PIN3
#define   LCD_PIN_4   PORTA,PIN4


void LCD_Init(void);
void LCD_SendChar(u8 ch);
void LCD_SendString(char * str);
void LCD_GoTo(u8 line, u8 column);
void LCD_CustomChar(u8 address,u8*pattern);
void LCD_Clear(void);
void LCD_writeNumber(s32 num);


#endif /* LCD_INTERFACE_H_ */
