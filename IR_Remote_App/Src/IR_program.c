/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: IR_COMM	  	  *******************/
/*************** Date: 29/8/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/
#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "EXTI_interface.h"
#include "MNVIC_Interface.h"
#include "SYSTICK_interface.h"
#include "IR_interface.h"

static void (* IR_CommCallBack) (void) = NULL ;

volatile u8  Global_u8Flag 			 = 0;     //For first FALLING EDGE
volatile u32 Arr_u32FramData [33]    ={0};	  //for Store Time for all bits frame
volatile u8 Gloabal_u8CounterForEdge = 0;	  //for Counting the bits data
volatile u8 Global_u8DataStorgeFrame = 0;	  //for Data in frame

void IR_voidInit(void)
{
	/*Enable RCC GPIOA*/
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERAL_EN_GPIOA);
	/*Enable RCC Systemgen*/
	MRCC_voidEnablePeripheralClock(APB2, MRCC_PERIPHERAL_EN_SYSTEMGEN);

	/*Config pin interrupt 0  */
	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN0, MGPIO_MODE_INPUT);
	MGPIO_voidSetPullState(MGPIOA_PORT, MGPIO_PIN0,MGPIO_PULL_UP );

	/*Interrupt Setting 0 */
	EXTI_voidCallBackFunctionRegisteration(IR_voidGetFram);
	EXTI_voidExtiConfig(EXTI_LINE_0, EXTI_PORTA);
	EXTI_voidSetTriggerSource(EXTI_LINE_0, EXTI_FALLING_EDGE);
	EXTI_voidEnableEXTI(EXTI_LINE_0);

	/*Enable NVIC for EXTI0*/
	NVIC_voidEnableInterrupt(NVIC_ENABLE_EXTI0);

	/*Systick Timer Init */
	STK_voidInit();					/*Tick Timer = 0.5 Microsecond*/
}



void IR_voidGetFram(void)
{
	/*For first falling edge*/
	if (Global_u8Flag == 0)
	{
		/*Start Timer*/
		STK_voidSetCallBackRegisteration(IR_voidTakeStart);

		/* for Half second (For waiting until Frame is done) any time bus must is bigger than
		 * Timer of frame to avoid the Overflow
		 *  */
		STK_voidDisableTimerAndClear();
		STK_voidSetSingleInterval(1000000);

		Global_u8Flag = 1;
	}

	else
	{
		/*For the Time how many ticks from Half Second*/
		Arr_u32FramData[Gloabal_u8CounterForEdge] = STK_u32GetElapsedTime();

		/*Start Timer Again*/
		STK_voidSetCallBackRegisteration(IR_voidTakeStart);

		/*for Half second (For waiting until Frame is done)
		 * if Frame is done with EXTI last falling edge(Frame is finished)
		 * after 0.5 second the interrupt timer is fire  */
		STK_voidDisableTimerAndClear();
		STK_voidSetSingleInterval(1000000);

		/*Increment counter for Frame Bits */
		Gloabal_u8CounterForEdge++;
	}
}

void IR_voidTakeStart(void)
{
	/*For sure the pressed only one time*/
	Global_u8DataStorgeFrame = 0;

	/*Step 1 : Check is valid Frame -> start bit
	 *  	       13500 MicroSecond and I have Tick Time = 0.5s  than = 27000*/
	if (Arr_u32FramData[0] >= 20000 && Arr_u32FramData[0] <= 28000)
	{
		/*Collect 8 bit IR_DATA*/
		for (u8 Local_counter = 0 ; Local_counter <8  ; Local_counter++)
		{
			/*Write Logical Zero   TickTime = 2250  */
			if (Arr_u32FramData[17+Local_counter] >= 4000 && Arr_u32FramData[17+Local_counter] <= 4600)
			{
				SET_BIT(Global_u8DataStorgeFrame,Local_counter);
			}
			else
			{
				CLR_BIT(Global_u8DataStorgeFrame,Local_counter);
			}
		}
		IR_CommCallBack();
	}

	/*Frame is finished after 0.5 and EXTI0 not detected falling edge again */
	else
	{
		/*Invalid Frame*/
	}

	/*After Frame is finished restart all options again*/

	Global_u8Flag 			 = 0;
	Gloabal_u8CounterForEdge = 0;
	Arr_u32FramData[0] 		 = 0;
	Global_u8DataStorgeFrame = 0;
}

void IR_voidSetCallBack(void (*FunctionCallBack_APP)(void))
{
	IR_CommCallBack = FunctionCallBack_APP;
}

