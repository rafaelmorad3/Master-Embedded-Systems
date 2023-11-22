/*
 * Stop_Watch.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */
#include "Std_Types.h"
#include "Stop_Watch.h"
#include "Systick.h"

static void STOPWATCH_EnterTimeValue(void);

static void STOPWATCH_Edit_Time(void);

static void STOPWATCH_START(void);
/*
static u8 update (u8 n){
	u8 k=0;
	while(k!='f'){
		k= get_key();
		n=n*10+k;

	}
}*/

void Stop_Watch_Init(void){
	Seg_Init();
}






u8 sec=0,min=0,sec_set_value=0,minute_set_value=0,c=0,key='N';    //00:00

state_mode current_state=edit_time_state;
state_edit_time edit_state=edit_secs;


void STOPWATCH_SyncApp(void)
{
	if(sec==0)
	{
		min--;
		sec=60;
	}
	sec--;
}


static void STOPWATCH_EnterTimeValue(void)
{
	static u8 digits[4]={0,0,0,0};
	if(edit_state == edit_secs && key>='0' && key<='9' )
	{
		if(c==0)
		{
			digits[3]=key-'0';
			sec_set_value=digits[3];
			sec=sec_set_value;
			c++;
		}
		else if(c==1)
		{
			if(key<='5')   					//to not enter more than 60 in seconds digits
			{
				digits[2]=key-'0';
				sec_set_value=sec_set_value+(digits[2]*10);
				sec=sec_set_value;
				c=0;
			}
		}
	}
	else if(edit_state == edit_minuts && key>='0' && key<='9' )
	{
		if(c==0)
		{
			digits[1]=key-'0';
			minute_set_value=digits[1];
			min=minute_set_value;
			c++;
		}
		else if(c==1)
		{
			digits[0]=key-'0';
			minute_set_value=minute_set_value+(digits[0]*10);
			min=minute_set_value;
			c=0;
		}
	}
	seg_mins (min);
	seg_sec (sec);
}


static void STOPWATCH_Edit_Time(void)
{
	static u8 sw_flag1=0,sw_flag2=1,editflag=1;
		if(GPIO_u8GetPinValue(PORTB, MINUTE_EDIT_BUTTON)==GPIO_HIGH)
		{
			if(sw_flag1==0)
			{
				sw_flag1=1;
				edit_state=edit_minuts;
				c=0;
				LCD_GoTo(1,0);
				LCD_SendString("-enter minutes");
			}
		}
		else
		{
			sw_flag1=0;
		}
		if(GPIO_u8GetPinValue(PORTB, SECONDS_EDIT_BUTTON)==GPIO_HIGH)
		{
			if(sw_flag2==0)
			{
				sw_flag2=1;
				edit_state=edit_secs;
				c=0;
				LCD_GoTo(1,0);
				LCD_SendString("-enter seconds");
			}
		}
		else
		{
			sw_flag2=0;
		}
		if(editflag==1)
		{
			editflag=0;
			LCD_GoTo(1,0);
			LCD_SendString("-enter seconds");
		}
		STOPWATCH_EnterTimeValue();
}



static void STOPWATCH_START(void)
{
	edit_state=edit_secs;
	if(current_state==reset_state)
	{
		min=minute_set_value;
		sec=sec_set_value;
	}
	current_state=idle_state;
}


void Stop_Watch(void)
{
	key= KeyPad_GetKey();
	if(key!='N')
	{
		if(key == SET_VALUE_BUTTON) // '0'
		{
			key='N';
			current_state=edit_time_state;
		}
		else if(key == START_BUTTON)
		{
			current_state=start_state;
		}
		else if(key == RESET_BUTTON)
		{
			current_state=reset_state;
		}
	}
	LCD_GoTo(0, 6);
	switch(current_state)
	{
	case idle_state:
		 seg_mins (min);
		seg_sec (sec);
		break;
	case edit_time_state:
		SYSTICK_Stop();
		LCD_SendString("Paused  ");
		STOPWATCH_Edit_Time();
		break;
	case start_state:
		LCD_Clear();
		LCD_GoTo(0, 6);
		LCD_SendString("Running ");
		STOPWATCH_START();
		SYSTICK_Start ();
		break;
	case reset_state:
		STOPWATCH_START();
		break;
	}
}









