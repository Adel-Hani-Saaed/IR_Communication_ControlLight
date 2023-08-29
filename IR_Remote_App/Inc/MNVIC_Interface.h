/*
 * MNVIC_Interface.h
 *
 *  Created on: May 30, 2023
 *      Author: omar.osman
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

#define NVIC_ENABLE_EXTI0    6

void NVIC_voidEnableInterrupt (u8 Copy_u8IntNum);

void NVIC_voidDisableInterrupt (u8 Copy_u8IntNum);

void NVIC_voidSetPendingFlag (u8 Copy_u8IntNum);
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNum);

void NVIC_voidSetInterruptPriority	(u8 Copy_IntNum ,u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

u8 NVIC_u8ReadActiveFlag (u8 Copy_u8IntNum);

void NVIC_voidInitGroupPriority (void);


#endif /* MNVIC_INTERFACE_H_ */
