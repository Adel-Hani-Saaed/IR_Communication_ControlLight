/*
 * MNVIC_Prog.c
 *
 *  Created on: May 30, 2023
 *      Author: omar.osman
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MNVIC_Interface.h"
#include "MNVIC_Config.h"
#include "MNVIC_Private.h"

// enable interrupt no 60



void NVIC_voidEnableInterrupt (u8 Copy_u8IntNum)
{

	NVIC->ISER[ Copy_u8IntNum /32] = (1 << (Copy_u8IntNum % 32)) ;
}
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNum)
{
	NVIC->ICER[ Copy_u8IntNum /32] = (1 << (Copy_u8IntNum % 32)) ;
}

void NVIC_voidSetPendingFlag (u8 Copy_u8IntNum)
{
	NVIC->ISPR[ Copy_u8IntNum /32] = (1 << (Copy_u8IntNum % 32)) ;
}
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNum)
{
	NVIC->ICPR[ Copy_u8IntNum /32] = (1 << (Copy_u8IntNum % 32)) ;
}

void NVIC_voidSetInterruptPriority	(u8 Copy_IntNum ,u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
	NVIC->IPR[Copy_IntNum] = ((Copy_u8GroupPriority << 6 ) | (Copy_u8SubPriority << 4));
}

/*	Active flag => 1
 *  Not Active  => 0
 *
 *  */
u8 NVIC_u8ReadActiveFlag (u8 Copy_u8IntNum)
{
	return GET_BIT(NVIC->IABR[Copy_u8IntNum / 32] , (Copy_u8IntNum % 32));
}


void NVIC_voidInitGroupPriority (void)
{
	// Write the vext key
	MSCB_AIRCR = SCB_VECTKEY;


	MSCB_AIRCR = SCB_VECTKEY | (0b101<<8);



}
