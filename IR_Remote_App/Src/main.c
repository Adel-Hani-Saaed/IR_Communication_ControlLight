#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "EXTI_interface.h"
#include "MNVIC_Interface.h"
#include "SYSTICK_interface.h"
#include "IR_interface.h"

extern u8 Global_u8DataStorgeFrame;

void IR_voidAppPlay(void);

int main(void)
{
	/*Enable clock System*/
	MRCC_voidInitSystemClk();

	IR_voidInit();

	IR_voidSetCallBack(&IR_voidAppPlay);

	/*LED Config is low if interrupt is high */
	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN1, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN2, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN3, MGPIO_MODE_OUTPUT);


	/* Loop forever */
	for(;;);
}


void IR_voidAppPlay (void)
{
	/*Turn on the Red LED*/
	if (Global_u8DataStorgeFrame == IR_NUMBER_1)
	{
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN1, MGPIO_HIGH);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN2, MGPIO_LOW);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN3, MGPIO_LOW);

	}

	/*Turn on the GREEN LED*/
	else if (Global_u8DataStorgeFrame == IR_NUMBER_2)
	{
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN2, MGPIO_HIGH);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN1, MGPIO_LOW);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN3, MGPIO_LOW);
	}

	/*Turn on the BLUE LED*/
	else if (Global_u8DataStorgeFrame == IR_NUMBER_3)
	{
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN3, MGPIO_HIGH);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN1, MGPIO_LOW);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN2, MGPIO_LOW);
	}

	/*Turn on the BLUE & RED LED*/
	else if (Global_u8DataStorgeFrame == IR_NUMBER_4)
	{
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN3, MGPIO_HIGH);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN1, MGPIO_HIGH);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN2, MGPIO_LOW);
	}

	/*Turn off all */
	else if (Global_u8DataStorgeFrame == IR_OFF)
	{
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN3, MGPIO_LOW);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN1, MGPIO_LOW);
		MGPIO_voidSetPinValue(MGPIOA_PORT, MGPIO_PIN2, MGPIO_LOW);
	}
}
