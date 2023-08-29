/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: IR_COMM	  	  *******************/
/*************** Date: 29/8/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#define IR_OFF		69
#define IR_MODE		70

#define IR_NUMBER_0		22
#define IR_NUMBER_1		12
#define IR_NUMBER_2		24
#define IR_NUMBER_3		94
#define IR_NUMBER_4		8


void IR_voidInit(void);

void IR_voidGetFram(void);		//Function call back EXTI0

void IR_voidTakeStart(void);	//Function call back Systick_timer

void IR_voidSetCallBack(void (*FunctionCallBack_APP)(void));


#endif /* IR_INTERFACE_H_ */
