/*
 * Std_Types.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Lenovo
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_



typedef unsigned char                          u8;
typedef signed char                            s8;
typedef unsigned short                        u16;
typedef signed short                          s16;
typedef unsigned long                         u32;
typedef unsigned long long int                u64;
typedef signed long                           s32;
typedef float                                 f32;
typedef double                                d64;

typedef volatile unsigned char                 vu8;
typedef volatile signed char                   vs8;
typedef volatile unsigned short                vu16;
typedef volatile signed short                  vs16;
typedef volatile unsigned long                 vu32;
typedef volatile unsigned long long int        vu64;
typedef volatile signed long                   vs32;
typedef volatile float                         vf32;
typedef volatile double                        vd64;


typedef unsigned char*                         pu8;
typedef signed char*                           ps8;
typedef unsigned short*                        pu16;
typedef signed short*                          ps16;
typedef unsigned long*                         pu32;
typedef unsigned long long int*                pu64;
typedef signed long*                           ps32;
typedef float*                                 pf32;
typedef double*                                pd64;

typedef enum{
	E_OK,
	E_NOK
}ERROR_status;

#define NULL_PTR  ((void*)0)
#define NULL ((u8)0)
#define BUSY	2

#define Max_u8  ((u8)255)
#define Min_u8  ((u8)0)
#define Max_s8  ((s8)127)
#define Min_s8  ((s8)-128)





#endif /* STD_TYPES_H_ */
