/*
 * Segment.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */
#include "Segment.h"
void Seg_Init(void){
	for(u8 i=0;i<8;i++){
	GPIO_voidSetPinDirection(Seg_PORT,i ,GPIO_OUTPUT_10MHZ_PP);
	}
}
void Display(u8 d){
	GPIO_voidSetPortValue(Seg_PORT,GPIO_u16GetPortValue(Seg_PORT)&0xFFF0);
	GPIO_voidSetPortValue(Seg_PORT,GPIO_u16GetPortValue(Seg_PORT)| d);

}
void seg_mins (u8 mins){

	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_LOW);
	GPIO_voidSetPinValue(Seg_PORT,Seg_2,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_3,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_4,GPIO_HIGH);
	Display(mins%10);
	delay_ms(1);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_LOW);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_HIGH);
	Display(mins/10);
	delay_ms(1);
}
void seg_sec (u8 sec){

	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_LOW);
	GPIO_voidSetPinValue(Seg_PORT,Seg_2,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_3,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_4,GPIO_HIGH);
	Display(sec%10);
	delay_ms(1);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_HIGH);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_LOW);
	GPIO_voidSetPinValue(Seg_PORT,Seg_1,GPIO_LOW);
	Display(sec/10);
	delay_ms(1);
}
