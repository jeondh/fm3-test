/*!
 ******************************************************************************
 **
 ** \file sample_uart.c
 **
 ** \brief UART demo application
 **
 ** \author FSLA AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-12-07
 **
 ** \brief This file provides an example to operate the UART
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

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "mb9bf50x_lib.h"
/*---------------------------------------------------------------------------*/
/* IO definition                                                             */
/*---------------------------------------------------------------------------*/
#define TestSize    10
/* UART TX State */
#define TXSTART     0
#define TXONGOING   1
#define TXFINISH    2
/* UART RX State */
#define RXSTART     0
#define RXONGOING   1
#define RXFINISH    2
/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static MFS_UART0ModeConfigT tUART0ModeConfigT = 
{
    115200,
    Uart0_DATABITS_8,
    Uart0_STOPBITS_1,
    Uart0_PARITY_NONE,
    Uart0_BITORDER_LSB,
    Uart0_NRZ,
};

/* The array to store the received data */
uint8_t cRcvString[32] = {0};
/* Count the receive byte number in INT */
static uint16_t sCount = 0;
/* The dedicated receive byte number */
static uint16_t sSize;
/* The array address to store the received data */
static uint8_t *pcRX;
/* RX State */
static uint8_t cRXState = RXSTART;

/* UART Int TX test string */
static uint8_t cTXStr[] = "UART TX Int Test!";
/* The string address which store the TX data */
static uint8_t *pcTX;
/* The Channel info for INT */
static uint8_t cCh;
/* TX State */
static uint8_t cTXState = TXSTART;
/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief  User defined TX ISR Callback function
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
static void UARTIrqTXCallback(void)
{
    /* TX */
    if(*pcTX != NULL)
    {
        MFS_UART0TXOneData(cCh, *pcTX++);
        cTXState = TXONGOING;
    }
    else/* TX finish */
    {
        /* TX process finished? */
        while(!MFS_UART0StatusGetTXBusIdle(cCh));
        /* Disable the TX int */
        MFS_UART0IntTXDisable(cCh);
        cTXState = TXFINISH;
    }
}
/*!
 ******************************************************************************
 ** \brief  User defined RX ISR Callback function
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
static void UARTIrqRXCallback(void)
{
    /* RX */
    if(sCount < sSize)
    {
        pcRX[sCount] = MFS_UART0RXOneData(cCh);
        sCount++;
        cRXState = RXONGOING;
    }
    else/* RX finish */
    {
        /* Disable the RX int */
        MFS_UART0IntRXDisable(cCh);
        cRXState = RXFINISH;
    }
}
/*!
 ******************************************************************************
 ** \brief  Initialize the I/O port for UART: select MFS ch2/SIN2_1 and SOT2_1
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
static void InitPort(void)
{
    FM3_GPIO->PFR2 = FM3_GPIO->PFR2 | 0x0030;
    FM3_GPIO->EPFR07 = FM3_GPIO->EPFR07 | 0x000a0000;
}
/*!
 ******************************************************************************
 ** \brief  Transmit the UART data through INT.
 **
 ** \param  Ch Requested channel
 ** \arg   MFS_Ch0-MFS_Ch7
 **
 ** \param *Str Transmit string address
 ** \arg   Address
 **
 ** \return none
 ******************************************************************************
 */
void UART0IntTX(uint8_t Ch, uint8_t *Str)
{
    MFS_UART0ISRCallbackT tUART0Callback;
    if(Str != NULL)
    {
        /* Get the string address for INT */
        pcTX = Str;
        /* Get the UART Channel for INT */
        cCh = Ch;
        /* Set the callback func address */
        tUART0Callback.pISRRXCallback = UARTIrqRXCallback;
        tUART0Callback.pISRTXCallback = UARTIrqTXCallback;
        MFS_UART0ConfigISRCallback(Ch, &tUART0Callback);
        /* Set the TX state as Start */
        cTXState = TXSTART;
        /* Enable the  TX */
        MFS_UART0TXEnable(Ch);
        /* Enable the TX int */
        MFS_UART0IntTXEnable(Ch);
        /* Enable the INT */
        NVIC_EnableIRQ((IRQn_Type)(MFS0TX_IRQn + (Ch*2)));
        /* Wait for the TX Finish */
        while(cTXState != TXFINISH);
        /* Disable the  TX */
        MFS_UART0TXDisable(cCh);
        /* Disable the INT */
        NVIC_DisableIRQ((IRQn_Type)(MFS0TX_IRQn + (Ch*2)));
    }
    return;
}
/*!
 ******************************************************************************
 ** \brief  Receive the UART data through INT.
 **
 ** \param  Ch Requested channel
 ** \arg   MFS_Ch0-MFS_Ch7
 **
 ** \param *Str Transmit string address
 ** \arg   Address
 **
 ** \param Size Dedicated receive data size
 ** \arg   size value
 **
 ** \return none
 ******************************************************************************
 */
void UART0IntRX(uint8_t Ch, uint8_t *Str, uint16_t Size)
{
    MFS_UART0ISRCallbackT tUART0Callback;
    if(Str != NULL)
    {
        /* Get the string address for INT */
        pcRX = Str;
        /* Get the UART Channel for INT */
        cCh = Ch;
        /* Get the receive size for INT */
        sSize = Size;
        /* Init the count */
        sCount = 0;
        /* Set the callback func address */
        tUART0Callback.pISRRXCallback = UARTIrqRXCallback;
        tUART0Callback.pISRTXCallback = UARTIrqTXCallback;
        MFS_UART0ConfigISRCallback(MFS_Ch2, &tUART0Callback);
        /* Set the RX state as Start */
        cRXState = RXSTART;
        /* Enable the RX */
        MFS_UART0RXEnable(MFS_Ch2);
        /* Enable the RX int */
        MFS_UART0IntRXEnable(MFS_Ch2);
        /* Enable the INT */
        NVIC_EnableIRQ(MFS2RX_IRQn);
        /* Wait for the RX Finish */
        while(cRXState != RXFINISH);
        /* Disable the  RX */
        MFS_UART0RXDisable(cCh);
        /* Disable the INT */
        NVIC_DisableIRQ((IRQn_Type)(MFS0RX_IRQn + (Ch*2)));
    }
    return;
}
/*!
 ******************************************************************************
 ** \brief  Transmit the UART data through polling mode.
 **
 ** \param  Ch Requested channel
 ** \arg   MFS_Ch0-MFS_Ch7
 **
 ** \param *Str Transmit string address
 ** \arg   Address
 **
 ** \return none
 ******************************************************************************
 */
void UART0PollTX(uint8_t Ch, uint8_t *Str)
{
    /* Check and send */
    if(Str != NULL)
    {
        /* Enable the  TX*/
        MFS_UART0TXEnable(Ch);
        while(*Str != NULL)
        {
            if(MFS_UART0StatusGetTXRegEmpty(Ch))
            {
                /* TX one byte */
                MFS_UART0TXOneData(Ch, *Str++);
            }
        }
        /* TX Finished? */
        while(!MFS_UART0StatusGetTXBusIdle(Ch));
        /* Disable the  TX after TX all bytes*/
        MFS_UART0TXDisable(Ch);
    }
    return;
}
/*!
 ******************************************************************************
 ** \brief  Receive the UART data through polling mode.
 **
 ** \param  Ch Requested channel
 ** \arg   MFS_Ch0-MFS_Ch7
 **
 ** \param *Str Transmit string address
 ** \arg   Address
 **
 ** \param Size Dedicated receive data size
 ** \arg   size value
 **
 ** \return none
 ******************************************************************************
 */
void UART0PollRX(uint8_t Ch, uint8_t *Str, uint16_t Size)
{
    uint16_t sCount = 0;
    /* Check and receive */
    if(Str != NULL)
    {
        /* Enable the  RX*/
        MFS_UART0RXEnable(Ch);
        while(sCount < Size)
        {
            if(MFS_UART0StatusGetRXRegFull(Ch))
            {
                *Str++ = MFS_UART0RXOneData(Ch);
                sCount++;
            }
        }
        /* Disable the  RX*/
        MFS_UART0RXDisable(Ch);
    }
    return;
}
/*!
 ******************************************************************************
 ** \brief  UART Example Code Entry
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void SampleUART(void)
{
    /* Init I/O port */
    InitPort();
    /* Set the UART mode */
    MFS_UART0ConfigMode(MFS_Ch2, &tUART0ModeConfigT);
    /* Test Example: choose anyone of the following function */
//    UART0PollTX(MFS_Ch2,cTXStr);
//    UART0PollRX(MFS_Ch2, cRcvString, 16);
//    UART0IntTX(MFS_Ch2,cTXStr);
    UART0IntRX(MFS_Ch2, cRcvString, 16);

    while(1);
}

/*****************************************************************************/
/* END OF FILE */
