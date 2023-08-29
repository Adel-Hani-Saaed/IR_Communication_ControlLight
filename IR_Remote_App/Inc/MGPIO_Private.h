
/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H


/*******************************************************************************************************/
/*                                    Macros Base Address Of GPI0x Registers                           */
/*******************************************************************************************************/


#define  GPIOA_BASE_ADDRESS         0x40020000
#define  GPIOB_BASE_ADDRESS         0x40020400
#define  GPIOC_BASE_ADDRESS         0x40020800 
#define  GPIOD_BASE_ADDRESS 		0x40020C00
#define  GPIOE_BASE_ADDRESS 		0x40021000
#define  GPIOH_BASE_ADDRESS 		0x40021C00

typedef struct{
	 volatile u32 MODER  ;  /*!< GPIO port mode register,               Address offset: 0x00      */
	 volatile u32 OTYPER ;  /*!< GPIO port output type register,        Address offset: 0x04      */
	 volatile u32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	 volatile u32 PUPDR  ;  /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	 volatile u32 IDR    ;  /*!< GPIO port input data register,         Address offset: 0x10      */
	 volatile u32 ODR    ;  /*!< GPIO port output data register,        Address offset: 0x14      */
	 volatile u32 BSRR   ;  /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	 volatile u32 LCKR   ;  /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	 volatile u32 AFRL   ;  /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
	 volatile u32 AFRH   ;
}GPIOx_t;

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of GPIOA                               */
/*******************************************************************************************************/

#define MGPIOA        ((GPIOx_t *) GPIOA_BASE_ADDRESS )

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of GPIOB                              */
/*******************************************************************************************************/

  
#define MGPIOB         ((GPIOx_t *) GPIOB_BASE_ADDRESS )

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of GPIOC                               */
/*******************************************************************************************************/

#define MGPIOC        ((GPIOx_t *) GPIOC_BASE_ADDRESS )

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of GPIOCD                              */
/*******************************************************************************************************/

#define MGPIOD       ((GPIOx_t *) GPIOD_BASE_ADDRESS )


/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of GPIOE                               */
/*******************************************************************************************************/

#define MGPIOE         ((GPIOx_t *) GPIOE_BASE_ADDRESS )

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of GPIOH                               */
/*******************************************************************************************************/

#define MGPIOH        ((GPIOx_t *) GPIOH_BASE_ADDRESS )



#define _LUCKED_PIN 16U
#endif //_GPIO_PRIVATE_H

