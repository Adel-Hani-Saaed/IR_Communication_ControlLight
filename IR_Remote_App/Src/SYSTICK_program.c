/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SYSTICK	  	  *******************/
/*************** Date: 1/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"

static void(*CallbackFunc)(void) = NULL ;

static u8 Global_u8IntervalMode = 0;


void STK_voidInit( void )
{

	// Choose the input CLK source.
#if CLK_SOURCE == AHB_DividedBy8

	CLR_BIT( SYSTICK->STK_CTRL, 2 ) ;

#elif CLK_SOURCE == AHB

	SET_BIT( SYSTICK->STK_CTRL, 2 ) ;

#endif
}


void STK_voidSetBusyWaitInterval (u32 Copy_u32Ticks)
{
	// Load Ticks to the load register.
	SYSTICK->STK_LOAD = Copy_u32Ticks ;

	// Disable the interrupt.
	CLR_BIT( SYSTICK->STK_CTRL, 1 ) ;

	// Start Timer.
	SET_BIT( SYSTICK->STK_CTRL, 0 ) ;

	// Busy Wait until the flag is raised.  
	while( GET_BIT( SYSTICK->STK_CTRL, 16 ) != 1 ) 
	{
		asm("NOP");
	}

	// Stop the timer.
	CLR_BIT( SYSTICK->STK_CTRL, 0 ) ;

	/*Clear Flag*/
	SET_BIT( SYSTICK->STK_CTRL, 16 ) ;


	// Clear the LOAD and VAL registers
	SYSTICK->STK_LOAD = 0 ;
	SYSTICK->STK_VAL  = 0 ;


}

void STK_voidDisableTimerAndClear(void)
{
	/*Disable timer because timer if call again must start again */
	// Stop the timer.
	CLR_BIT( SYSTICK->STK_CTRL, 0 ) ;
	// Load Ticks to the load register.
	SYSTICK->STK_VAL = 0 ;

}
void STK_voidSetSingleInterval( u32 Copy_u32Ticks)
{

	// Set interval mode to single.
	Global_u8IntervalMode = SINGLE_INTERVAL_MODE ;

	// Load Ticks to the load register.
	SYSTICK->STK_LOAD = Copy_u32Ticks ;

	// Enable the Interrupt.
	SET_BIT( SYSTICK->STK_CTRL, 1 ) ;

	// Start Timer.
	SET_BIT( SYSTICK->STK_CTRL, 0 ) ;
}



void STK_voidSetPeriodicInterval( u32 Copy_u32Ticks)
{
	// Set interval mode to single.
	Global_u8IntervalMode = PERIODIC_INTERVAL_MODE ;

	// Load Ticks to the load register.
	SYSTICK->STK_LOAD = Copy_u32Ticks ;

	// Enable the Interrupt.
	SET_BIT( SYSTICK->STK_CTRL, 1 ) ;

	// Start Timer.
	SET_BIT( SYSTICK->STK_CTRL, 0 ) ;
}

void STK_voidStopInterval( void )
{

	// Disable the interrupt.
	CLR_BIT( SYSTICK->STK_CTRL, 1 ) ;

	// Stop the timer.
	CLR_BIT( SYSTICK->STK_CTRL, 0 ) ;

	// Clear the LOAD and VAL registers
	SYSTICK->STK_LOAD = 0 ;
	SYSTICK->STK_VAL  = 0 ;
}

u32 STK_u32GetElapsedTime( void )
{

	u32 Local_u32ElapsedTime = 0 ;

	Local_u32ElapsedTime = (SYSTICK->STK_LOAD - SYSTICK->STK_VAL) ;

	return Local_u32ElapsedTime ;
}

u32 STK_u32GetRemainingTime( void )
{

	u32 Local_u32RemainingTime = 0 ;

	Local_u32RemainingTime = SYSTICK->STK_VAL ;

	return Local_u32RemainingTime ;
}

void MSTK_voidEnableInterrupt( void )
{
	// Enable the peripheral interrupt.
	SET_BIT( SYSTICK->STK_CTRL, 1 ) ;
}

void STK_voidDisableInterrupt( void )
{
	// Disable the peripheral interrupt.
	CLR_BIT( SYSTICK->STK_CTRL, 1 ) ;
}

void STK_voidSetCallBackRegisteration( void (*ptr)(void) )
{
	CallbackFunc = ptr;
}

void SysTick_Handler(void)
{
	// Callback notification.
	CallbackFunc( ) ;

	if( Global_u8IntervalMode == SINGLE_INTERVAL_MODE )
	{

		// Disable the IRQ.
		CLR_BIT( SYSTICK->STK_CTRL, 1 ) ;

		// Stop the timer.
		CLR_BIT( SYSTICK->STK_CTRL, 0 ) ;

		// Clear the LOAD and VAL registers
		SYSTICK->STK_LOAD = 0 ;
		SYSTICK->STK_VAL  = 0 ;
	}

	/*Clear Flag*/
	SET_BIT( SYSTICK->STK_CTRL , 16 );

}

