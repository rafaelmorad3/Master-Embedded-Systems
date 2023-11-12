/*
 * KeyPad.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */



#include "KeyPad.h"

const  u8 KeysARR[ROWS][COLS]={{'7','8','9','/'},
                        {'4','5','6','*'},
                        {'1','2','3','-'},
                        {'c','0','=','+'}};
void KeyPad_Init(void)
{
	u8 r;
	for (r=0;r<ROWS;r++)
	{
		GPIO_voidSetPinDirection(KeyPad_Port, r, GPIO_OUTPUT_10MHZ_PP);
		GPIO_voidSetPinValue(KeyPad_Port,r,GPIO_HIGH);
	}
	for (r=0;r<COLS;r++)
		{
			GPIO_voidSetPinDirection(KeyPad_Port, r+4, GPIO_INPUT_PULL_UP_DOWN);

		}
}

u8 KeyPad_GetKey(void)
{
	u8 r,c,key=NO_KEY,NUM=NO_KEY;
	for (r=0;r<ROWS;r++)
	{
		GPIO_voidSetPinValue(KeyPad_Port,r,GPIO_HIGH);
		for (c=0;c<COLS;c++)
		{
			NUM=GPIO_u8GetPinValue(KeyPad_Port,c+4);
			if (NUM==GPIO_HIGH)
			{
				key=KeysARR[r][c];
				delay_ms(10);
				while(NUM==GPIO_HIGH){
					NUM=GPIO_u8GetPinValue(KeyPad_Port,c+4);
				}
			}
		}
		GPIO_voidSetPinValue(KeyPad_Port,r,GPIO_LOW);
	}
	return key;
}
