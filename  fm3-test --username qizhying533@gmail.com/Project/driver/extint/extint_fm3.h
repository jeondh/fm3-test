/*!
 ******************************************************************************
 **
 ** \file extint_fm3.h
 **
 ** \brief external interrupt drivers head file
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-29
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
 
#ifndef _extint_FM3_H_
#define _extint_FM3_H_


/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 0
 **          argument to several of the APIs.
 ******************************************************************************
 */

//#define GPIO_ALL_PIN           0x00000000  /* GPIO pin 0~F */
#define GPIO_PIN0              0x00000001   /* GPIO pin 0 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 1
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN1              0x00000002   /* GPIO pin 1 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 2
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN2              0x00000004   /* GPIO pin 2 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 3
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN3              0x00000008   /* GPIO pin 3 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 4
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN4              0x00000010   /* GPIO pin 4 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 5
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN5              0x00000020   /* GPIO pin 5 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 6
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN6              0x00000040   /* GPIO pin 6 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 7
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN7              0x00000080   /* GPIO pin 7 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 8
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN8              0x00000100   /* GPIO pin 8 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin 9
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIN9              0x00000200   /* GPIO pin 9 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin A
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PINA              0x00000400   /* GPIO pin A */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin B
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PINB              0x00000800   /* GPIO pin B */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin C
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PINC              0x00001000   /* GPIO pin C */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin D
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PIND              0x00002000   /* GPIO pin D */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin E
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PINE              0x00004000   /* GPIO pin E */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Pin F
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_PINF              0x00008000   /* GPIO pin F */


/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 0
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P00_BASE         0x00  /* GPIO Port P00 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 1
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P10_BASE           0x01  /* GPIO Port P10 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 2
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P20_BASE           0x02  /* GPIO Port P20 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 3
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P30_BASE           0x03  /* GPIO Port P30 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 4
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P40_BASE           0x04  /* GPIO Port P40 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 5
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P50_BASE           0x05  /* GPIO Port P50 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 6
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P60_BASE           0x06  /* GPIO Port P60 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 7
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P70_BASE           0x07  /* GPIO Port P70 */
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Port 8
 **          argument to several of the APIs.
 ******************************************************************************
 */
#define GPIO_P80_BASE           0x08  /* GPIO Port P80 */

/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT00_0
 ******************************************************************************
 */
#define  INT00_0      0x00000001  
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT00_1
 ******************************************************************************
 */
#define  INT00_1      0x00000002
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT00_2
 ******************************************************************************
 */
#define  INT00_2      0x00000003
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT01_0
 ******************************************************************************
 */
#define  INT01_0      0x00000004  
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT01_1
 ******************************************************************************
 */
#define  INT01_1      0x00000008
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT01_2
 ******************************************************************************
 */
#define  INT01_2      0x0000000C
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT02_0
 ******************************************************************************
 */
#define  INT02_0      0x00000010  
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT02_1
 ******************************************************************************
 */
#define  INT02_1      0x00000020
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT02_2
 ******************************************************************************
 */
#define  INT02_2      0x00000030
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT03_0
 ******************************************************************************
 */
#define  INT03_0      0x00000040 
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT03_1
 ******************************************************************************
 */
#define  INT03_1      0x00000080
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT03_2
 ******************************************************************************
 */
#define  INT03_2      0x000000C0
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT04_0
 ******************************************************************************
 */
#define  INT04_0      0x00000100  
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT04_1
 ******************************************************************************
 */
#define  INT04_1      0x00000200
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT04_2
 ******************************************************************************
 */
#define  INT04_2      0x00000300
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT05_0
 ******************************************************************************
 */
#define  INT05_0      0x00000400  
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT05_1
 ******************************************************************************
 */
#define  INT05_1      0x00000800
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT05_2
 ******************************************************************************
 */
#define  INT05_2      0x00000C00
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT06_0
 ******************************************************************************
 */
#define  INT06_0      0x00001000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT06_1
 ******************************************************************************
 */
#define  INT06_1      0x00002000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT06_2
 ******************************************************************************
 */
#define  INT06_2      0x00003000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT07_0
 ******************************************************************************
 */
#define  INT07_0      0x00004000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT07_1
 ******************************************************************************
 */
#define  INT07_1      0x00008000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT07_2
 ******************************************************************************
 */
#define  INT07_2      0x0000C000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT08_0
 ******************************************************************************
 */
#define  INT08_0      0x00010000  
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT08_1
 ******************************************************************************
 */
#define  INT08_1      0x00020000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT08_2
 ******************************************************************************
 */
#define  INT08_2      0x00030000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT09_0
 ******************************************************************************
 */
#define  INT09_0      0x00040000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT09_1
 ******************************************************************************
 */
#define  INT09_1      0x00080000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT09_2
 ******************************************************************************
 */
#define  INT09_2      0x000C0000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT10_0
 ******************************************************************************
 */
#define  INT10_0      0x00100000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT10_1
 ******************************************************************************
 */
#define  INT10_1      0x00200000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT10_2
 ******************************************************************************
 */
#define  INT10_2      0x00300000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT11_0
 ******************************************************************************
 */
#define  INT11_0      0x00400000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT11_1
 ******************************************************************************
 */
#define  INT11_1      0x00800000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT11_2
 ******************************************************************************
 */
#define  INT11_2      0x00C00000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT12_0
 ******************************************************************************
 */
#define  INT12_0      0x01000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT12_1
 ******************************************************************************
 */
#define  INT12_1      0x02000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT12_2
 ******************************************************************************
 */
#define  INT12_2      0x03000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT13_0
 ******************************************************************************
 */
#define  INT13_0      0x04000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT13_1
 ******************************************************************************
 */
#define  INT13_1      0x08000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT13_2
 ******************************************************************************
 */
#define  INT13_2      0x0C000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT14_0
 ******************************************************************************
 */
#define  INT14_0      0x10000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT14_1
 ******************************************************************************
 */
#define  INT14_1      0x20000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT14_2
 ******************************************************************************
 */
#define  INT14_2      0x30000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT15_0
 ******************************************************************************
 */
#define  INT15_0      0x40000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT15_1
 ******************************************************************************
 */
#define  INT15_1      0x80000000
/*!
 ******************************************************************************
 ** \brief The EPFR06 register assigns functions to external interrupt pins --INT15_2
 ******************************************************************************
 */
#define  INT15_2      0xC0000000

/*!
 ******************************************************************************
 ** \brief Init for register clear to 0
 ******************************************************************************
 */
#define  INT_INIT      0x0000

/*!
 ******************************************************************************
 ** \brief The EPFR00 register assigns functions to external interrupt pins --NMIX
 ******************************************************************************
 */
#define  INT_NMI_EPFR      0x0001

/*!
 ******************************************************************************
 ** \brief Init for register
 ******************************************************************************
 */
#define  INT_NMI_Port      0x8000


/*!
 ******************************************************************************
 ** \brief for register bit0
 ******************************************************************************
 */
#define  INT_BIT0     0x0001
/*!
 ******************************************************************************
 ** \brief The following values define the bit field for the Int port
 **          argument to several of the APIs.
 ******************************************************************************
 */
typedef enum
{
    INT00 = 0,  
    INT01 = 1,  
    INT02 = 2,  
    INT03 = 3, 
    INT04 = 4,  
    INT05 = 5,  
    INT06 = 6,  
    INT07 = 7, 
    INT08 = 8,  
    INT09 = 9,  
    INT10 = 10,  
    INT11 = 11, 
    INT12 = 12,  
    INT13 = 13,  
    INT14 = 14,  
    INT15 = 15, 
}INT_T;



/*!
 ******************************************************************************
 ** \brief  choose for external interrupt type--Interrupt on low level
 ******************************************************************************
 */
#define GPIO_LOW_LEVEL        0x00000000  // Interrupt on low level
/*!
 ******************************************************************************
 ** \brief  choose for external interrupt type--Interrupt on high level
 ******************************************************************************
 */
#define GPIO_HIGH_LEVEL         0x00000001  // Interrupt on high level
/*!
 ******************************************************************************
 ** \brief  choose for external interrupt type--Interrupt on rising edge  
 ******************************************************************************
 */
#define GPIO_RISING_EDGE       0x00000002  // Interrupt on rising edge  
/*!
 ******************************************************************************
 ** \brief  choose for external interrupt type-- Interrupt on falling edge
 ******************************************************************************
 */
#define GPIO_FALLING_EDGE      0x00000003  // Interrupt on falling edge


/*!
 ******************************************************************************
 ** \brief  external interrupt channel number
 ******************************************************************************
 */
#define EXTINT_CH_NUM   8


/*!
 ******************************************************************************
 ** \brief  Check parameter Pin
 ******************************************************************************
 */

#define IS_IO_PIN_VALID(Pin) ((Pin == GPIO_PIN0)\
                            ||(Pin == GPIO_PIN1)\
                            ||(Pin == GPIO_PIN2)\
                            ||(Pin == GPIO_PIN3)\
                            ||(Pin == GPIO_PIN4)\
                            ||(Pin == GPIO_PIN5)\
                            ||(Pin == GPIO_PIN6)\
                            ||(Pin == GPIO_PIN7)\
                            ||(Pin == GPIO_PIN8)\
                            ||(Pin == GPIO_PIN9)\
                            ||(Pin == GPIO_PINA)\
                            ||(Pin == GPIO_PINB)\
                            ||(Pin == GPIO_PINC)\
                            ||(Pin == GPIO_PIND)\
                            ||(Pin == GPIO_PINE)\
                            ||(Pin == GPIO_PINF))

/*!
 ******************************************************************************
 ** \brief  Check parameter Port
 ******************************************************************************
 */

#define IS_IO_PORT_VALID(Port) ((Port == GPIO_P00_BASE)\
                                ||(Port == GPIO_P10_BASE)\
                                ||(Port == GPIO_P20_BASE)\
                                ||(Port == GPIO_P30_BASE)\
                                ||(Port == GPIO_P40_BASE)\
                                ||(Port == GPIO_P50_BASE)\
                                ||(Port == GPIO_P60_BASE)\
                                ||(Port == GPIO_P70_BASE)\
                                ||(Port == GPIO_P80_BASE))

/*!
 ******************************************************************************
 ** \brief  Check parameter Int channel
 ******************************************************************************
 */

#define IS_INT_CH_VALID(Int) ((Int == INT00)\
                            ||(Int == INT01)\
                            ||(Int == INT02)\
                            ||(Int == INT03)\
                            ||(Int == INT04)\
                            ||(Int == INT05)\
                            ||(Int == INT06)\
                            ||(Int == INT07)\
                            ||(Int == INT08)\
                            ||(Int == INT09)\
                            ||(Int == INT10)\
                            ||(Int == INT11)\
                            ||(Int == INT12)\
                            ||(Int == INT13)\
                            ||(Int == INT14)\
                            ||(Int == INT15))



/*!
 ******************************************************************************
 ** \brief  Check parameter Int type
 ******************************************************************************
 */

#define IS_INT_TYPE_VALID(IntType) ((IntType == GPIO_LOW_LEVEL)\
                                    ||(IntType == GPIO_HIGH_LEVEL)\
                                    ||(IntType == GPIO_RISING_EDGE)\
                                    ||(IntType == GPIO_FALLING_EDGE))
                                   
/*!
 ******************************************************************************
 ** \brief  Check parameter EPFR06 for Int
 ******************************************************************************
 */

#define IS_EPFR06_INT_VALID0(Int) ((Int == INT00_0)||(Int == INT01_0)\
                                    ||(Int == INT02_0)||(Int == INT07_2)\
                                    ||(Int == INT08_2)||(Int == INT09_2)\
                                    ||(Int == INT03_2)||(Int == INT04_2)\
                                    ||(Int == INT05_2)||(Int == INT04_0)\
                                    ||(Int == INT08_1)||(Int == INT09_1)\
                                    ||(Int == INT10_1)||(Int == INT11_1)\
                                    ||(Int == INT12_1)||(Int == INT13_1)\
                                    ||(Int == INT14_1)||(Int == INT06_2)\
                                    ||(Int == INT13_2)||(Int == INT14_2)\
                                    ||(Int == INT15_2)||(Int == INT02_1)\
                                    ||(Int == INT03_1)||(Int == INT04_1)\
                                    ||(Int == INT05_1)||(Int == INT02_2)\
                                    ||(Int == INT01_2)||(Int == INT06_1)\
                                    ||(Int == INT05_0)||(Int == INT00_1)\
                                    ||(Int == INT01_1)||(Int == INT00_2)\
                                    ||(Int == INT12_2)||(Int == INT11_2)\
                                    ||(Int == INT10_2)||(Int == INT03_0)\
                                    ||(Int == INT15_1))


                                 




/*!
 ******************************************************************************
 ** \brief external callback function.
 **
 ** \param CH the external interrupt channel
 **
 **
 ******************************************************************************
 */

typedef void (*EXTINT_CallbackT)(int16_t CH);


/*!
 ******************************************************************************
 ** \brief NMI callback function.
 **
 ** \param None
 **
 ******************************************************************************
 */
typedef void (*NMI_CallbackT)(void);

/*!
 ******************************************************************************
 ** \brief structure for external configuration
 ******************************************************************************
 */
typedef struct
{
    INT_T          ExtInt_Ch; //!< Extenal channel
    uint32_t       ExtInt_Type;//!< Extenal interrupt type
    EXTINT_CallbackT ExtInt_ConfigIrqCallback;//!< Extenal interrupt callback
    NMI_CallbackT NMIInt_ConfigIrqCallback;//!< NMI interrupt callback
}ExtInt_Config;


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
/* external interrupt */
void EXTINT_GPIOInit(int32_t IOPort, int32_t IOPin);
void EXTINT_Init(uint32_t IntPin, ExtInt_Config *Ext_Init);
void EXTINT_IntEnable(int16_t CH);
void EXTINT_IntDisable(int16_t CH);
void EXTINT_IntClr(uint16_t CH);
void EXTINT_IntSetType(ExtInt_Config *Ext_Int);

/* NMI */
void NMI_IntInit(ExtInt_Config *Ext_Init);


#ifdef __cplusplus
}
#endif


#endif /* _extint_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */
