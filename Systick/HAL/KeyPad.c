
#include "KeyPad.h"


void KeyPad_Init(void)
{
	u8 r;
	for (r=0;r<ROWS;r++)
	{
		GPIO_voidSetPinDirection(KeyPad_Port, r, GPIO_OUTPUT_10MHZ_PP);
		GPIO_voidSetPinValue(KeyPad_Port,r,GPIO_HIGH);
	}
	for (r=0;r<ROWS;r++)
		{
			GPIO_voidSetPinDirection(KeyPad_Port, r+4, GPIO_INPUT_PULL_UP_DOWN);

		}
}

u8 KeyPad_GetKey(void)
{
	u8 r,c,key=NO_KEY,NUM=NO_KEY;
	for (r=0;r<ROWS;r++)
	{
		GPIO_voidSetPinValue(KeyPad_Port,r,GPIO_LOW);
		for (c=0;c<COLS;c++)
		{
			NUM=GPIO_u8GetPinValue(KeyPad_Port,c+4);
			if (NUM==GPIO_LOW)
			{
				key=KeysARR[r][c];
				delay_ms(10);
				while(NUM==GPIO_LOW){
					NUM=GPIO_u8GetPinValue(KeyPad_Port,c+4);
				}
			}
		}
		GPIO_voidSetPinValue(KeyPad_Port,r,GPIO_HIGH);
	}
	return key;
}
