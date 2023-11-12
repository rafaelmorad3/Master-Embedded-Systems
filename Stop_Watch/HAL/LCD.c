/*
 * LCD.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Lenovo
 */



#include "LCD_Interface.h"




#define LCD_CONFIG_WORD             (0x30)

#define LCD_CLR                     (0x01)

#define LCD_CURSOR_HOME             (0x02)

#define LCD_SET_ENTRY_MODE          (0x40)
#define LCD_INCREMENT_CURSOR        (0x02)
#define LCD_DECREMENT_CURSOR        (0x00)
#define LCD_DISPLAY_SHIFT_ON        (0x01)
#define LCD_DISPLAY_SHIFT_OFF       (0x00)

#define LCD_DISPLAY_CONTROL         (0x08)
#define LCD_DISPLAY_ON              (0x04)
#define LCD_DISPLAY_OFF             (0x00)
#define LCD_CURSOR_ON               (0x02)
#define LCD_CURSOR_OFF              (0x00)
#define LCD_CURSOR_BLINK_ON         (0x01)
#define LCD_CURSOR_BLINK_OFF        (0x00)

#define LCD_CURSOR_DISPLAY_CONTROL  (0x10)
#define LCD_SHIFT_CURSOR            (0x00)
#define LCD_SHIFT_DISPLAY           (0x08)
#define LCD_SHIFT_LEFT              (0x00)
#define LCD_SHIFT_RIGHT             (0x04)

#define LCD_FUNCTION_SET            (0x20)
#define LCD_DATA_LENGTH_4           (0x00)
#define LCD_DATA_LENGTH_8           (0x10)
#define LCD_ONE_LINE                (0x00)
#define LCD_TWO_LINES               (0x08)
#define LCD_SMALL_FONT              (0x00)
#define LCD_LARGE_FONT              (0x04)

#define LCD_SET_CGRAM_ADDRESS       (0x40)

#define LCD_SET_DDRAM_ADDRESS       (0x80)

#define LCD_DDRAM_LINE_SIZE         (0x28)
#define LCD_DDRAM_LINE_2_ADDRESS    (0x40)

static void LCD_SendCommand(u8 command);
static void LCD_SendData(u8 character);



void LCD_Init(void)
{
	/* Add your code here */
	/* Initialize Pins */


	for(volatile u8 i = 1 ;i <7 ; i++){
		GPIO_voidSetPinDirection(PORTA, i, GPIO_OUTPUT_10MHZ_PP	);
		delay_ms(5);
        GPIO_voidSetPinValue(PORTA, i, GPIO_HIGH);
	}



	/* Initialization sequence */

	/* Initial LCD commands */
	/* Select data length = 8 bits, 2 lines LCD and small font */

	/* Turn display , cursor and blinking OFF */

	/* Clear LCD */

	/* Increment cursor and turn off display shift */

	/* Turn display ON */
	   delay_ms(15);
		LCD_SendCommand(0x02);
		delay_ms(2);
		LCD_SendCommand(0x28);
		delay_ms(2);
		LCD_SendCommand(0x0c);
		LCD_SendCommand(0x06);
		LCD_SendCommand(0x01);
		delay_ms(2);

	/* End of your code !*/
}
void LCD_SendChar(u8 ch)
{
	/* Add your code here */
	/* Change position and send character */
	LCD_SendData(ch);
	/* End of your code !*/

}

void LCD_SendString(char * str)
{
	u8 i;
	/* Add your code here */
	for (i=0;str[i];i++)
	{
		LCD_SendData(str[i]);
	}
	/* Clear screen and send character by character to the LCD */

	/* End of your code !*/
}

static void LCD_SendCommand(u8 command)
{

	u8		GPIO_u8GetPinValue(u8 port, u8 pin);
	void    GPIO_voidSetPortDirection(u8 port, u8 Direction);
//	GPIO_voidSetPortValue(PORTA, (command>>4)&0x000f);
//	GPIO_voidSetPortValue(PORTA, (command)&0x000f);
	/* Add your code here */
	GPIO_voidSetPinValue(RS, GPIO_LOW);
	GPIO_voidSetPinValue(LCD_PIN_1,READBIT(command,4));
	GPIO_voidSetPinValue(LCD_PIN_2,READBIT(command,5));
	GPIO_voidSetPinValue(LCD_PIN_3,READBIT(command,6));
	GPIO_voidSetPinValue(LCD_PIN_4,READBIT(command,7));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	// _delay_ms(1);
	GPIO_voidSetPinValue(EN, GPIO_LOW);
	// _delay_ms(1);
	GPIO_voidSetPinValue(LCD_PIN_1,READBIT(command,0));
	GPIO_voidSetPinValue(LCD_PIN_2,READBIT(command,1));
	GPIO_voidSetPinValue(LCD_PIN_3,READBIT(command,2));
	GPIO_voidSetPinValue(LCD_PIN_4,READBIT(command,3));
	GPIO_voidSetPinValue(EN, GPIO_HIGH);
	// _delay_ms(1);
	GPIO_voidSetPinValue(EN, GPIO_LOW);
	// _delay_ms(1);
	/* End of your code !*/

}

static void LCD_SendData(u8 character)
{
	/* Add your code here */
	GPIO_voidSetPinValue(RS,GPIO_HIGH);
	GPIO_voidSetPinValue(LCD_PIN_1,READBIT(character,4));
	GPIO_voidSetPinValue(LCD_PIN_2,READBIT(character,5));
	GPIO_voidSetPinValue(LCD_PIN_3,READBIT(character,6));
	GPIO_voidSetPinValue(LCD_PIN_4,READBIT(character,7));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	// _delay_ms(1);
	GPIO_voidSetPinValue(EN,GPIO_LOW);
	// _delay_ms(1);
	GPIO_voidSetPinValue(LCD_PIN_1,READBIT(character,0));
	GPIO_voidSetPinValue(LCD_PIN_2,READBIT(character,1));
	GPIO_voidSetPinValue(LCD_PIN_3,READBIT(character,2));
	GPIO_voidSetPinValue(LCD_PIN_4,READBIT(character,3));
	GPIO_voidSetPinValue(EN,GPIO_HIGH);
	// _delay_ms(1);
	GPIO_voidSetPinValue(EN,GPIO_LOW);
	// _delay_ms(1);
	/* End of your code !*/
}

void LCD_GoTo(u8 line, u8 column)
{
	u8 address = 0;
	/* Calculate address in DDRAM */
	switch(line){
		case 0: address = (column); break;;
		case 1: address = (column+0x40); break;;
		case 2: address = (column+0x14); break;;
		case 3: address = (column+0x54); break;;
	}
	LCD_SendCommand(address|(0x80));
	/* Send address to LCD */

	/* End of your code !*/

}

void LCD_CustomChar(u8 address,u8*pattern)
{
	u8 i;
	LCD_SendCommand(0x40+(address*8));
	for(i=0;i<8;i++){
		LCD_SendData(pattern[i]);
	}
	LCD_SendCommand(0x80);
}

void LCD_Clear(void)
{
	LCD_SendCommand(0x01);
}

/*
void LCD_writeNumber(s32 num)
{
	u32 n=0;
	u8 flag=0,rem=0;
	if(num<0){
		LCD_SendChar('-');
		num=num*(-1);
	}
	if(num==0){
		LCD_SendChar('0');
	}
	else{
		while(num){
			rem=num%10;
			if(n==0 && rem==0){
				flag++;
			}
			n=(n*10)+rem;
			num=num/10;
		}
		while(n){
			rem=n%10;
			LCD_SendChar('0'+rem);
			n=n/10;
		}
		while(flag){
			LCD_SendChar('0');
			flag--;
		}
	}
}
*/
void LCD_writeNumber(s32 num)
{
	u8 str[20];
	u8 i=0;
	s8 j;
	if(num==0)
	{
		LCD_SendChar('0');
		return;
	}
	if(num<0)
	{
		LCD_SendChar('-');
		num=num*(-1);
	}
	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_SendChar(str[j]);
	}
}
