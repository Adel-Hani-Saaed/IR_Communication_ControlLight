/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SYSTICK	  	  *******************/
/*************** Date: 1/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void STK_voidInit( void );

void STK_voidSetBusyWaitInterval (u32 Copy_u32Ticks);

void STK_voidSetSingleInterval( u32 Copy_u32Ticks);

void STK_voidSetPeriodicInterval( u32 Copy_u32Ticks);

void STK_voidSetCallBackRegisteration( void (*ptr)(void) );

void STK_voidDisableTimerAndClear(void);   // USing in IR communication

void STK_voidStopInterval( void );

u32 STK_u32GetElapsedTime( void );

u32 STK_u32GetRemainingTime( void );

void MSTK_voidEnableInterrupt( void );


void STK_voidDisableInterrupt( void );

void SysTick_Handler(void);


#endif /* SYSTICK_INTERFACE_H_ */
