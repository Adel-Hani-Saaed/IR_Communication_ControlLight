/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SYSTICK	  	  *******************/
/*************** Date: 1/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/
#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_


#define SYSTICK_BASE_ADDRESS	0xE000E010

typedef struct
{

	volatile u32 STK_CTRL	;
	volatile u32 STK_LOAD	;
	volatile u32 STK_VAL	;
	volatile u32 STK_CALIB	;

}STK_RegName_t;

#define SYSTICK 		((STK_RegName_t*)(SYSTICK_BASE_ADDRESS))


#define  AHB_DividedBy8			1
#define  AHB           			2

#define SINGLE_INTERVAL_MODE 	1
#define PERIODIC_INTERVAL_MODE	2


#endif /* SYSTICK_PRIVATE_H_ */
