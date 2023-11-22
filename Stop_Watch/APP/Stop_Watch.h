/*
 * Stop_Watch.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */

#ifndef STOP_WATCH_H_
#define STOP_WATCH_H_
#include "KeyPad.h"
#include "LCD_Interface.h"
#include "Segment.h"



void delay_ms (u32 d);

typedef enum{
	idle_state,
	edit_time_state,
	start_state,
	reset_state
}state_mode;

typedef enum{
	edit_minuts,
	edit_secs
}state_edit_time;

#define Edit_Mode_Port			PORTB

#define MINUTE_EDIT_BUTTON		PIN8
#define SECONDS_EDIT_BUTTON		PIN9
#define START_BUTTON			'='
#define SET_VALUE_BUTTON		'0'
#define RESET_BUTTON			'c'

#define max    		60

#define idle    	0

#define ONE_SECOND 	1000000
void Stop_Watch_Init(void);
void STOPWATCH_SyncApp(void); /* for working synchronously counting seconds in background */

void Stop_Watch(void);



#endif /* STOP_WATCH_H_ */
