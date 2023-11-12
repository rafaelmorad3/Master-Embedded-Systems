/*
 * Std_Types.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Lenovo
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char  u8;
typedef signed char  s8;
typedef unsigned short  u16;
typedef signed short  s16;
typedef unsigned long  u32;
typedef signed long  s32;

typedef float  f32;
typedef double  d64;

typedef enum{
	E_OK,
	E_NOK
}ERROR_status;

#define NULL_PTR  ((void*)0)
#define NULL ((u8)0)

#define Max_u8  ((u8)255)
#define Min_u8  ((u8)0)
#define Max_s8  ((s8)127)
#define Min_s8  ((s8)-128)





#endif /* STD_TYPES_H_ */
