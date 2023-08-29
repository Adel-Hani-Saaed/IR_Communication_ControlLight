/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: EXTI		  	  *******************/
/*************** Date: 1/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


static void (* EXTI0_CallBack) (void) = NULL ;

void EXTI_voidEnableEXTI 	(EXTI_LINE_t Copy_etLineNumber)
{
	SET_BIT(EXTI->IMR ,Copy_etLineNumber );
}

void EXTI_voidDisnableEXTI  (EXTI_LINE_t Copy_etLineNumber)
{
	CLR_BIT(EXTI->IMR ,Copy_etLineNumber );

}

void EXTI_voidSetTriggerSource (EXTI_LINE_t Copy_etLineNumber ,EXTI_TRIG_t Copy_etTriggerSource )
{

	switch(Copy_etTriggerSource)
	{
	case	EXTI_RISING_EDGE	:	SET_BIT(EXTI -> RTSR , Copy_etLineNumber);	break;
	case	EXTI_FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , Copy_etLineNumber);	break;
	case	EXTI_ON_CHANGE		:	SET_BIT(EXTI -> RTSR , Copy_etLineNumber);
									SET_BIT(EXTI -> FTSR , Copy_etLineNumber);	break;
	default: break;
	}

	SET_BIT(EXTI -> IMR , Copy_etLineNumber);
}

void EXTI_voidSoftwareInterrupt (EXTI_LINE_t Copy_etLineNumber)
{
	SET_BIT(EXTI -> SWIER , Copy_etLineNumber);

}

void EXTI_voidExtiConfig (EXTI_LINE_t Copy_etLineNumber ,EXTI_PORT_t Copy_etPortNumber )
{
	switch(Copy_etLineNumber)
	{
	case EXTI_LINE_0 :  SYSCFG_EXTICR1 &= EXTI_CONFIG_MASK_1;
						SYSCFG_EXTICR1 |= Copy_etPortNumber ;
						break;

	case EXTI_LINE_1 :  SYSCFG_EXTICR1 &= EXTI_CONFIG_MASK_2;
						SYSCFG_EXTICR1 |= (Copy_etPortNumber <<4) ;
						break;

	case EXTI_LINE_2 :  SYSCFG_EXTICR1 &= EXTI_CONFIG_MASK_3;
						SYSCFG_EXTICR1 |= (Copy_etPortNumber <<8) ;
						break;

	case EXTI_LINE_4 :  SYSCFG_EXTICR1 &= EXTI_CONFIG_MASK_4;
						SYSCFG_EXTICR1 |= (Copy_etPortNumber <<12) ;
						break;
	default: break;
	}


}

void EXTI_voidCallBackFunctionRegisteration (void (*ptr)(void))
{
	EXTI0_CallBack = ptr ;
}

void EXTI0_IRQHandler(void)
{
	// Calling the function @ main
	EXTI0_CallBack();

	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);
}




