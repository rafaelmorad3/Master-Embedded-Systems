/*
 * Segment.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Lenovo
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include "GPIO_interface.h"

#define Seg_PORT PORTB
/*   BCD   */

#define Seg_PIN1  PIN0
#define Seg_PIN2  PIN1
#define Seg_PIN3  PIN2
#define Seg_PIN4  PIN3


/*  Control 7 Segment to display */
#define Seg_1  PIN4
#define Seg_2  PIN5
#define Seg_3  PIN6
#define Seg_4  PIN7


void Seg_Init(void);
void seg_mins (u8 mins);
void seg_sec (u8 sec);



#endif /* SEGMENT_H_ */
