/*!
 ******************************************************************************
 **
 ** \file io_fm3.h
 **
 ** \brief head file of io  driver
 **
 ** 
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-8
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor(Shanghai) Co.,Ltd.
 **
 ******************************************************************************
 **
 ** \note Other information.
 **
 ******************************************************************************
 */
 
#ifndef _IO_FM3_H_
#define _IO_FM3_H_
 
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"
 
 
 
/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/*! \brief GPIO all pins 0~F */
#define GPIO_ALL_PIN            0x0000ffff  // GPIO pin 0~F
/*! \brief GPIO all pin 0 */
#define GPIO_PIN_0              0x00000001  // GPIO pin 0
/*! \brief GPIO all pin 1 */
#define GPIO_PIN_1              0x00000002  // GPIO pin 1
/*! \brief GPIO all pin 2 */
#define GPIO_PIN_2              0x00000004  // GPIO pin 2
/*! \brief GPIO all pin 3 */
#define GPIO_PIN_3              0x00000008  // GPIO pin 3
/*! \brief GPIO all pin 4 */
#define GPIO_PIN_4              0x00000010  // GPIO pin 4
/*! \brief GPIO all pin 5 */
#define GPIO_PIN_5              0x00000020  // GPIO pin 5
/*! \brief GPIO all pin 6 */
#define GPIO_PIN_6              0x00000040  // GPIO pin 6
/*! \brief GPIO all pin 7 */
#define GPIO_PIN_7              0x00000080  // GPIO pin 7
/*! \brief GPIO all pin 8 */
#define GPIO_PIN_8              0x00000100  // GPIO pin 8
/*! \brief GPIO all pin 9 */
#define GPIO_PIN_9              0x00000200  // GPIO pin 9
/*! \brief GPIO all pin A */
#define GPIO_PIN_A              0x00000400  // GPIO pin A
/*! \brief GPIO all pin B */
#define GPIO_PIN_B              0x00000800  // GPIO pin B
/*! \brief GPIO all pin C */
#define GPIO_PIN_C              0x00001000  // GPIO pin C
/*! \brief GPIO all pin D */
#define GPIO_PIN_D              0x00002000  // GPIO pin D
/*! \brief GPIO all pin E */
#define GPIO_PIN_E              0x00004000  // GPIO pin E
/*! \brief GPIO all pin F */
#define GPIO_PIN_F              0x00008000  // GPIO pin F
/*! \brief Check parameter */
#define IS_GPIO_PIN(gpiopin)                    ((gpiopin == GPIO_ALL_PIN) \
	                                            ||(gpiopin == GPIO_PIN_0)\
	                                            ||(gpiopin == GPIO_PIN_1)\
	                                            ||(gpiopin == GPIO_PIN_2)\
	                                            ||(gpiopin == GPIO_PIN_3)\
	                                            ||(gpiopin == GPIO_PIN_4)\
	                                            ||(gpiopin == GPIO_PIN_5)\
	                                            ||(gpiopin == GPIO_PIN_6)\
	                                            ||(gpiopin == GPIO_PIN_7)\
	                                            ||(gpiopin == GPIO_PIN_8)\
	                                            ||(gpiopin == GPIO_PIN_9)\
	                                            ||(gpiopin == GPIO_PIN_A)\
	                                            ||(gpiopin == GPIO_PIN_B)\
	                                            ||(gpiopin == GPIO_PIN_C)\
	                                            ||(gpiopin == GPIO_PIN_D)\
                                                ||(gpiopin == GPIO_PIN_E)\
                                                ||(gpiopin == GPIO_PIN_F))   




/*! \brief GPIO Port P00 */
#define GPIO_PORT0           0x00  
/*! \brief GPIO Port P10 */
#define GPIO_PORT1           0x01 
/*! \brief GPIO Port P20 */
#define GPIO_PORT2           0x02  
/*! \brief GPIO Port P30 */
#define GPIO_PORT3           0x03 
/*! \brief GPIO Port P40 */ 
#define GPIO_PORT4           0x04  
/*! \brief GPIO Port P50 */
#define GPIO_PORT5           0x05 
/*! \brief GPIO Port P60 */ 
#define GPIO_PORT6           0x06  
/*! \brief GPIO Port P70 */
#define GPIO_PORT7           0x07  
/*! \brief GPIO Port P80 */
#define GPIO_PORT8           0x08  
/*! \brief Check parameter */
#define IS_GPIO_PORT(gpioport)                  ((gpioport == GPIO_PORT0) \
	                                            ||(gpioport == GPIO_PORT1)\
	                                            ||(gpioport == GPIO_PORT2)\
	                                            ||(gpioport == GPIO_PORT3)\
	                                            ||(gpioport == GPIO_PORT4)\
	                                            ||(gpioport == GPIO_PORT5)\
	                                            ||(gpioport == GPIO_PORT6)\
	                                            ||(gpioport == GPIO_PORT7)\
	                                            ||(gpioport == GPIO_PORT8))



/*! \brief GPIO Port low level */
#define LOW_LEVEL 	0
/*! \brief GPIO Port high level */
#define HIGH_LEVEL 	1
/*! \brief Check parameter */
#define IS_GPIO_LEVEL(gpiolevel)                ((gpiolevel == LOW_LEVEL) \
                                                ||(gpiolevel == HIGH_LEVEL))



/*! \brief GPIO Port output */
#define IO_GPIO_MODE	       0x00000000 
/*! \brief Peripheral function port */
#define IO_PERIPHERAL_MODE     0x00000001  
/*! \brief Check parameter */
#define IS_IO_MODE(mode)                      ((mode == IO_GPIO_MODE) \
                                                ||(mode == IO_PERIPHERAL_MODE))
                                              
/*! \brief Port pull-up connect */
#define IO_PULLUP_CONN	       0x00000000 
/*! \brief Port pull-up disconnect */
#define IO_PULLUP_DISCONN      0x00000001  
/*! \brief Check parameter */
#define IS_IO_PULLUP(mode)                   ((mode == IO_PULLUP_CONN) \
                                                ||(mode == IO_PULLUP_DISCONN))

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

void IO_ConfigPort(uint8_t ioport, uint32_t iopin, uint8_t iomode);
void IO_GPIOSetInput(uint8_t ioport, uint32_t iopin);
void IO_GPIOSetOutput(uint8_t ioport, uint32_t iopin);
uint32_t IO_GPIOReadData(uint8_t ioport, uint32_t iopin);
void IO_GPIOWriteData(uint8_t ioport, uint32_t iopin, uint32_t iodata);
void IO_GPIOConfigPullup(uint8_t ioport, uint32_t iopin, uint8_t pulltype);




#ifdef __cplusplus
}
#endif


#endif /* _LVD_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */
 