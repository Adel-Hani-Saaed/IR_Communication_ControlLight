/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: EXTI		  	  *******************/
/*************** Date: 1/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef enum
{
	EXTI_LINE_0   ,
	EXTI_LINE_1   ,
	EXTI_LINE_2   ,
	EXTI_LINE_3   ,
	EXTI_LINE_4   ,
	EXTI_LINE_5   ,
	EXTI_LINE_6   ,
	EXTI_LINE_7   ,
	EXTI_LINE_8   ,
	EXTI_LINE_9   ,
	EXTI_LINE_10  ,
	EXTI_LINE_11  ,
	EXTI_LINE_12  ,
	EXTI_LINE_13  ,
	EXTI_LINE_14  ,
	EXTI_LINE_15

}EXTI_LINE_t;

typedef enum
{
	EXTI_PORTA	,
	EXTI_PORTB	,
	EXTI_PORTC

}EXTI_PORT_t;


typedef enum
{
   EXTI_RISING_EDGE     ,
   EXTI_FALLING_EDGE    ,
   EXTI_ON_CHANGE

}EXTI_TRIG_t ;


void EXTI_voidEnableEXTI 	(EXTI_LINE_t Copy_etLineNumber);

void EXTI_voidDisnableEXTI  (EXTI_LINE_t Copy_etLineNumber);

void EXTI_voidSetTriggerSource (EXTI_LINE_t Copy_etLineNumber ,EXTI_TRIG_t Copy_etTriggerSource );

void EXTI_voidSoftwareInterrupt (EXTI_LINE_t Copy_etLineNumber);

void EXTI_voidExtiConfig (EXTI_LINE_t Copy_etLineNumber ,EXTI_PORT_t Copy_etPortNumber );

void EXTI_voidCallBackFunctionRegisteration (void (*ptr)(void));


#endif /* EXTI_INTERFACE_H_ */
