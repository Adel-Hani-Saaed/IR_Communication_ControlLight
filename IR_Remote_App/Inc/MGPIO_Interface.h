#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


#define   MGPIOA_PORT      0U
#define   MGPIOB_PORT      1U
#define   MGPIOC_PORT      2U
#define   MGPIOD_PORT      3U
#define   MGPIOE_PORT      4U
#define   MGPIOH_PORT      5U


#define  MGPIO_PIN0        0U
#define  MGPIO_PIN1        1U
#define  MGPIO_PIN2        2U
#define  MGPIO_PIN3        3U
#define  MGPIO_PIN4        4U
#define  MGPIO_PIN5        5U
#define  MGPIO_PIN6        6U
#define  MGPIO_PIN7        7U
#define  MGPIO_PIN8        8U
#define  MGPIO_PIN9        9U
#define  MGPIO_PIN10      10U
#define  MGPIO_PIN11      11U
#define  MGPIO_PIN12      12U
#define  MGPIO_PIN13      13U
#define  MGPIO_PIN14      14U
#define  MGPIO_PIN15      15U

#define  MGPIO_MODE_INPUT       (0b00)			//0
#define  MGPIO_MODE_OUTPUT      (0b01)			//1
#define  MGPIO_MODE_ALTF        (0b10)			//2
#define  MGPIO_MODE_ANALOG      (0b11)			//3


#define   MGPIO_OUTPUT_TYPE_PUSH_PULL          0U
#define   MGPIO_OUTPUT_TYPE_OPEN_DRAIN         1U


#define MGPIO_OUTPUT_SPEED_LOW               (0b00)
#define MGPIO_OUTPUT_SPEED_MEDUIM            (0b01)
#define MGPIO_OUTPUT_SPEED_HIGH              (0b10)
#define MGPIO_OUTPUT_SPEED_VERY_HIGH         (0b11)

#define MGPIO_PULL_FLOATING                   (0b00)
#define MGPIO_PULL_UP                         (0b01)
#define MGPIO_PULL_DOWN                       (0b10)


#define MGPIO_HIGH                            (1U)
#define MGPIO_LOW                             (0U)


#define GPIOx_AF0  0
#define GPIOx_AF1  1
#define GPIOx_AF2  2
#define GPIOx_AF3  3
#define GPIOx_AF4  4
#define GPIOx_AF5  5
#define GPIOx_AF6  6
#define GPIOx_AF7  7
#define GPIOx_AF8  8
#define GPIOx_AF9  9
#define GPIOx_AF10 10
#define GPIOx_AF11 11
#define GPIOx_AF12 12
#define GPIOx_AF13 13
#define GPIOx_AF14 14
#define GPIOx_AF15 15


void MGPIO_voidSetPinMode		(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  );
void MGPIO_voidSetOutputType	(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutTypeMode ) ;
void MGPIO_voidSetOutputSpeed	(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8SpeedMode  );
void MGPIO_voidSetPullState		(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType  );
u8   MGPIO_u8GetPInValue		(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void MGPIO_voidSetPinValue		(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue);
void MGPIO_voidSetPinAlternativeFunction (u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Alt_Func);




#endif //_GPIO_INTERFACE_H

