/*
 * KeyPad.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */



#ifndef KeyPad_H_
#define KeyPad_H_

#include "GPIO_interface.h"

#define KeyPad_Port PORTB

#define ROWS   4
#define ROW_1  PIN0S
#define ROW_2  PIN1
#define ROW_3  PIN2
#define ROW_4  PIN3

#define COLS   4
#define COL_1  PIN4
#define COL_2  PIN5
#define COL_3  PIN6
#define COL_4  PIN7

#define NO_KEY  'N'






void KeyPad_Init(void);
u8 KeyPad_GetKey(void);





#endif
