/*
 * MNVIC_Private.h
 *
 *  Created on: May 30, 2023
 *      Author: omar.osman
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_



#define MNVIC_u32_BASE_ADDRESS				 0xE000E100

#define     MSCB_AIRCR   (*(volatile u32*) 0xE000ED0C)   //Regiter Definaition

typedef struct MNVIC
{

	u32 ISER[8];
	u32 Reserved [24];
	u32 ICER[8];
	u32 Reserved1[24];
	u32 ISPR[8];
	u32 Reserved2[24];
	u32 ICPR[8];
	u32 Reseerved3[24];
	u32 IABR [8];
	u32 Reserved4[56];
	u8 IPR[240];
	u32 Reserved5[580];
	u32 STIR;
}NVIC_RegDef_t;

#define 	NVIC		((NVIC_RegDef_t *)(MNVIC_u32_BASE_ADDRESS))


//#define SCB_AIRCR	 *((volatile u32* )(SCB_u32_AIRCR))

#define SCB_VECTKEY			0x5FA




#endif /* MNVIC_PRIVATE_H_ */
