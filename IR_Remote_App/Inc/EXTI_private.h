/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: EXTI		  	  *******************/
/*************** Date: 1/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/***********************************************************************************************************/
/*                          Object Like Macro For  Base Address Registers                                  */
/***********************************************************************************************************/

#define EXTI_BASE_ADDRESS      	 0x40013C00

/***********************************************************************************************************/
/*                                MEXTI Registers Definition by structure                                  */
/***********************************************************************************************************/
typedef struct
{
	volatile u32 IMR     ;
	volatile u32 EMR     ;
	volatile u32 RTSR    ;
	volatile u32 FTSR    ;
	volatile u32 SWIER   ;
	volatile u32 PR		 ;

}EXTI_RegName_t;


#define EXTI                 ((EXTI_RegName_t*)(EXTI_BASE_ADDRESS))


#define SYSCFG_EXTICR1		*((volatile u32*)0x40013800)

#define	EXTI_CONFIG_MASK_1	0xfffffff0
#define	EXTI_CONFIG_MASK_2	0xffffff0f
#define	EXTI_CONFIG_MASK_3	0xfffff0ff
#define	EXTI_CONFIG_MASK_4	0xffff0fff



#endif /* EXTI_PRIVATE_H_ */
