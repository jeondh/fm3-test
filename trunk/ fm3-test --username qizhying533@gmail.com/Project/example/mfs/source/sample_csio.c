/*!
 ******************************************************************************
 **
 ** \file sample_csio.c
 **
 ** \brief CSIO demo application
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-20
 **
 ** \brief This file provides an example to operate the CSIO (SPI)
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
/*SD Card IO*/
#define SD_CS         (1<<10)
#define SD_CS_PFR     FM3_GPIO->PFR4
#define SD_CS_DDR     FM3_GPIO->DDR4
#define SD_CS_PDOR    FM3_GPIO->PDOR4
#define SD_CP         (1<<11)
#define SD_CP_PFR     FM3_GPIO->PFR4
#define SD_CP_DDR     FM3_GPIO->DDR4
#define SD_CP_PDIR    FM3_GPIO->PDIR4
#define SD_WP         (1<<11)
#define SD_WP_PFR     FM3_GPIO->PFR5 
#define SD_WP_DDR     FM3_GPIO->DDR5
#define SD_WP_PDIR    FM3_GPIO->PDIR5
/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
uint8_t cChannel,cData;
uint16_t cCount,cSize;
MFS_CSIOModeConfigT tCSIOModeConfigT = 
{
    MFS_CSIO_SPI,
    CSIO_MASTER,
    400000,
    CSIO_DATABITS_8,
    CSIO_WAITBITS_0,
    CSIO_BITORDER_MSB,
    CSIO_CLK_INV,
};
typedef enum __SdSpiCmdInd_t
{
    _CMD0 = 0,  // Resets the MultiMediaCard
}_SdSpiCmdInd_t;

typedef enum __SdAgmType_t
{
    _SdNoArg = 0, _SdBlockLen, _SdDataAdd, _SdDummyWord
}_SdAgmType_t;

typedef enum __SdRespType_t
{
    _SdR1 = 0, _SdR1b, _SdR2, _SdR3, _SdR7
}_SdRespType_t;

typedef struct __SdCommads_t
{
    uint8_t         TxData;
    _SdAgmType_t  Arg;
    _SdRespType_t Resp;
}_SdCommads_t;

const _SdCommads_t _SdCmd[1] =
{
    // CMD0
    {0x40,_SdNoArg    ,_SdR1 },
};

#define _CS_L() SdChipSelect(1)
#define _CS_H() SdChipSelect(0); SdTranserByte(0xFF,0x01)

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  SPI IO Init
 **
 ** \param  none
 **
 ** \retval none
 ******************************************************************************
 */
void SPIIOInit(void)
{
    /* Chip select */
    /*Select CPIO function*/
    SD_CS_PFR &= ~(SD_CS);
    /*Set Pin to high level*/
    SD_CS_PDOR |= SD_CS;
    /*Make pin output*/
    SD_CS_DDR |= SD_CS;
    /* Cart present */
    /*Select CPIO function*/
    SD_CP_PFR &= ~(SD_CP);
    /*Make pin input*/
    SD_CP_DDR &= ~(SD_CP);
    /* Write protect */
    /*Select CPIO function*/
    SD_WP_PFR &= ~(SD_WP);
    /*Make pin input*/
    SD_WP_DDR &= ~(SD_WP);
    /*SPI pin configure*/
    /*Select Periferial function*/
    FM3_GPIO->PFR5 |= (1<<6) | (1<<7) | (1<<8);
    /*Use SIN1_0*/
    bFM3_GPIO_EPFR07_SIN1S0 = 0;
    bFM3_GPIO_EPFR07_SIN1S1 = 0;
    /*Use SOT1_0*/
    bFM3_GPIO_EPFR07_SOT1B0 = 1;
    bFM3_GPIO_EPFR07_SOT1B1 = 0;
    /*Use SCK1_0*/
    bFM3_GPIO_EPFR07_SCK1B0 = 1;
    bFM3_GPIO_EPFR07_SCK1B1 = 0;
}
/*!
 ******************************************************************************
 ** \brief  Transmit data through Int mode
 **
 ** \param  Ch Requested channel
 ** \arg MFS_Ch0-MFS_Ch7
 **
 ** \param  Data
 ** \arg data
 **
 ** \retval none
 ******************************************************************************
 */
void MFSCSIOOneDataTXIRQ(uint8_t Ch, uint8_t Data)
{
    cData = Data;
    cChannel = Ch;
    cCount = 0;
    MFS_CSIOTXEnable(Ch);
    MFS_CSIOIntTXEnable(Ch);
    while(cCount < 1);
}

/*!
 ******************************************************************************
 ** \brief  Receive data through Int mode
 **
 ** \param  Ch Requested channel
 ** \arg MFS_Ch0-MFS_Ch7
 **
 ** \retval none
 ******************************************************************************
 */
uint8_t MFSCSIOOneDataRXIRQ(uint8_t Ch)
{
    cChannel = Ch;
    cCount = 0;
    MFS_CSIOTXEnable(Ch);
    MFS_CSIOTXOneData(Ch, 0xFF);
    MFS_CSIORXEnable(Ch);
    MFS_CSIOIntRXEnable(Ch);
    while(cCount < 1);
    return cData;
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
void RX1Handler(void)
{
    cData = MFS_CSIORXOneData(cChannel);
    cCount++;
    if(cCount >= 1)
    {
      MFS_CSIORXDisable(cChannel);
      MFS_CSIOIntRXDisable(cChannel);
    }
    else
    {
      MFS_CSIOTXOneData(cChannel, 0xFF);
    }
}

/*!
 ******************************************************************************
 ** \brief  User defined TX ISR Callback function
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void TX1Handler(void)
{
    if(cCount < 1)
    {
        MFS_CSIOTXOneData(cChannel,cData);
        cCount++;
        {
            while(!MFS_CSIOStatusGetTXBusIdle(cChannel));
            MFS_CSIOIntTXDisable(cChannel);
        }
    }
}

/*!
 ******************************************************************************
 ** \brief  Init the CSIO as defined SPI
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void MFS_CSIOInit(void)
{
    MFS_CSIOProgramClr(1);
    MFS_CSIOConfigMode(1, &tCSIOModeConfigT);
    NVIC_EnableIRQ(MFS1RX_IRQn);
    NVIC_EnableIRQ(MFS1TX_IRQn);
}
/*!
 ******************************************************************************
 ** \brief  Transfer data function
 **
 ** \param  data transfer data
 ** \arg Data
 **
 ** \param  mode transfer mode: 0-> Polling mode; 1->TX INT; 2->RX INT
 ** \arg 0 - 2
 **
 ** \return none
 ******************************************************************************
 */
uint8_t SdTranserByte (uint8_t ch, uint8_t mode)
{
    volatile uint8_t read;
    if(mode == 0)
    {
        read = MFS_CSIOTransferOneData(1, ch);
    }
    else
    {
        if(mode == 1)
        {
            MFSCSIOOneDataTXIRQ(1,ch);//INT TX one byte
        }
        else
        {
            read = MFSCSIOOneDataRXIRQ(1);//INT RX one byte
        }
    }
    return read;
}
/*!
 ******************************************************************************
 ** \brief  Chip selection function
 **
 ** \param  Select Select or not
 ** \arg Selection
 **
 ** \return none
 ******************************************************************************
 */
void SdChipSelect (uint8_t Select)
{
    if(Select)
    {
        SD_CS_PDOR &= ~(SD_CS);
    }
    else
    {
        /*wait transmission ends*/
        while(!MFS_CSIOStatusGetTXBusIdle(1));
        SD_CS_PDOR |= (SD_CS);
        
        SdTranserByte(0xFF,0x01);
    }
}
/*!
 ******************************************************************************
 ** \brief  Send CMD to SD card
 **
 ** \param  ComdInd command index
 ** \arg 0 (in this example)
 **
 ** \param  pData command data
 ** \arg None (in this example)
 **
 ** \return none
 ******************************************************************************
 */
uint16_t _SdSendCmd(_SdSpiCmdInd_t ComdInd, uint8_t* pData)
{
    uint8_t ch = 0xFF;
    uint16_t i;
    // Chip Select
    _CS_L();
    // Send command code
    SdTranserByte(_SdCmd[ComdInd].TxData,0x01);
    // Send command's arguments
    if(_SdCmd[ComdInd].Arg == _SdNoArg)
    {
        SdTranserByte(0x00,0x01);
        SdTranserByte(0x00,0x01);
        SdTranserByte(0x00,0x01);
        SdTranserByte(0x00,0x01);
    }
    else
    {
        SdTranserByte(*pData >> 24,0x01);
        SdTranserByte(*pData >> 16,0x01);
        SdTranserByte(*pData >> 8,0x01 );
        SdTranserByte(*pData,0x01      );
    }
    // Send CRC
    if(_CMD0 == ComdInd)
    {
        SdTranserByte(0x95,0x01);
    }
    else
    {
        SdTranserByte(0xFF,0x01);
    }
    // wait for command response
    for(i = 9; i && (ch == 0xFF); --i) ch = SdTranserByte(0xFF,0x02);

    if (0 == i)
    {
        _CS_H();
        return((uint16_t)-1);
    }

    // Implement command response
    switch (_SdCmd[ComdInd].Resp)
    {
        case _SdR1b:
            for (ch = 0,i = 0; i && (ch != 0xFF); --i)
            {
              ch = SdTranserByte(0xFF,0x02);
            }
            break;
        case _SdR1:
            break;
        case _SdR2:
            ch  = ((uint16_t)ch << 8)     & 0x0000FF00;
            ch |= SdTranserByte(0xFF,0x02)  & 0x000000FF;
            break;
        default:
            *pData  = ((uint16_t)SdTranserByte(0xFF,0x02) << 24) & 0xFF000000;
            *pData |= ((uint16_t)SdTranserByte(0xFF,0x02) << 16) & 0x00FF0000;
            *pData |= ((uint16_t)SdTranserByte(0xFF,0x02) << 8 ) & 0x0000FF00;
            *pData |=          SdTranserByte(0xFF,0x02)        & 0x000000FF;
            break;
    }
    return(ch);
}
/*!
 ******************************************************************************
 ** \brief  CSIO Example Code Entry
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void SampleCSIO(void)
{
    MFS_CSIOISRCallbackT tCSIOCallback;
    uint16_t i;
    int16_t res;
    /* IO Init */
    SPIIOInit();
    /* CSIO: Init */
    MFS_CSIOInit();
    /* CSIO: Set the callback func address */
    tCSIOCallback.pISRRXCallback = RX1Handler;
    tCSIOCallback.pISRTXCallback = TX1Handler;
    MFS_CSIOConfigISRCallback(MFS_Ch1, &tCSIOCallback);
    /* CSIO: SD Operation Test */
    SdChipSelect(0); 
    
    SdTranserByte(0xFF,0x01);

    for(i = 10; i; --i) SdTranserByte(0xFF,0x01);

    res = _SdSendCmd(_CMD0,NULL);
    
    //If res == 1, success!
    if(res == 1)
    {
        while(1);
    }
}

/*****************************************************************************/
/* END OF FILE */
