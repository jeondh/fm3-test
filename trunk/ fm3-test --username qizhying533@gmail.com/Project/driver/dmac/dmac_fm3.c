/*!
 ******************************************************************************
 **
 ** \file dmac_fm3.c
 **
 ** \brief this file provides all DMA drivers
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-18
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor(Shanghai) Co.,Ltd.
 **
 ******************************************************************************
 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/

#include "dmac_fm3.h"

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief specify DMA irq 
 ******************************************************************************
 */
IRQn_Type irqn;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA0 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */ 
uint8_t NormSoftTrigFlag0=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA1 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag1=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA2 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag2=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA3 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag3=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA4 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag4=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA5 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag5=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA6 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag6=0;
/*!
 ******************************************************************************
 ** \brief flags for indicating DMA7 busy on normal data transfer by software trigger mode
 ******************************************************************************
 */
uint8_t NormSoftTrigFlag7=0;

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief DMA callback function array
 ******************************************************************************
 */ 
DMA_Callback DMA_IrqCallback[] = 
{ 
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};
/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief normal data transfer by software trigger
 **
 ** \param src source address.
 **        This parameter can be one of the following values:
 ** \arg   physical_adress e.g. 0x20000100

 ** \param des destination address.
 **        This parameter can be one of the following values:
 ** \arg   physical_adress e.g. 0x20000800

 ** \param bytes data counts.
 **        This parameter can be one of the following values:
 ** \arg   byt_counts range:0x0000-0xFFFF

 ** \param ch
 **        This parameter can be one of the following values:
 ** \arg   0x00: DMA channel 0
 ** \arg   0x01: DMA channel 1
 ** \arg   0x02: DMA channel 2
 ** \arg   0x03: DMA channel 3
 ** \arg   0x04: DMA channel 4
 ** \arg   0x05: DMA channel 5
 ** \arg   0x06: DMA channel 6
 ** \arg   0x07: DMA channel 7
 **         
 **
 ** \retval None
 **
 ******************************************************************************
 */
void DMA_NrmlDataTrsfBySftTrig(uint32_t src, uint32_t des, 
                               uint16_t bytes, uint8_t ch)
{
    /* Check the parameter */
    ASSERT(IS_DMA_CH_VALID(ch));
    
    FM3_DMAC->DMACR = 0x80000000;//enable DMAC
    switch (ch)
    {
        case 0:
            NormSoftTrigFlag0=1;
            irqn = DMAC0_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA0 = src;
            FM3_DMAC->DMACDA0 = des;
            FM3_DMAC->DMACB0 = 0x00180000;
            FM3_DMAC->DMACA0 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA0_EB = 1;
            bFM3_DMAC_DMACA0_ST = 1;
        break;
        case 1:
            NormSoftTrigFlag1=1;
            irqn = DMAC1_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA1 = src;
            FM3_DMAC->DMACDA1 = des;
            FM3_DMAC->DMACB1 = 0x00180000;
            FM3_DMAC->DMACA1 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA1_EB = 1;
            bFM3_DMAC_DMACA1_ST = 1;
        break;
        case 2:
            NormSoftTrigFlag2=1;
            irqn = DMAC2_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA2 = src;
            FM3_DMAC->DMACDA2 = des;
            FM3_DMAC->DMACB2 = 0x00180000;
            FM3_DMAC->DMACA2 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA2_EB = 1;
            bFM3_DMAC_DMACA2_ST = 1;
        break;
        case 3:
            NormSoftTrigFlag3=1;
            irqn = DMAC3_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA3 = src;
            FM3_DMAC->DMACDA3 = des;
            FM3_DMAC->DMACB3 = 0x00180000;
            FM3_DMAC->DMACA3 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA3_EB = 1;
            bFM3_DMAC_DMACA3_ST = 1;
        break;
        case 4:
            NormSoftTrigFlag4=1;
            irqn = DMAC4_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA4 = src;
            FM3_DMAC->DMACDA4 = des;
            FM3_DMAC->DMACB4 = 0x00180000;
            FM3_DMAC->DMACA4 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA4_EB = 1;
            bFM3_DMAC_DMACA4_ST = 1;
        break;
        case 5:
            NormSoftTrigFlag5=1;
            irqn = DMAC5_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA5 = src;
            FM3_DMAC->DMACDA5 = des;
            FM3_DMAC->DMACB5 = 0x00180000;
            FM3_DMAC->DMACA5 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA5_EB = 1;
            bFM3_DMAC_DMACA5_ST = 1;
        break;
        case 6:
            NormSoftTrigFlag6=1;
            irqn = DMAC6_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA6 = src;
            FM3_DMAC->DMACDA6 = des;
            FM3_DMAC->DMACB6 = 0x00180000;
            FM3_DMAC->DMACA6 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA6_EB = 1;
            bFM3_DMAC_DMACA6_ST = 1;
        break;
        case 7:
            NormSoftTrigFlag7=1;
            irqn = DMAC7_IRQn;
            NVIC_EnableIRQ(irqn);
            NVIC_SetPriority(irqn, 0);
            FM3_DMAC->DMACSA7 = src;
            FM3_DMAC->DMACDA7 = des;
            FM3_DMAC->DMACB7 = 0x00180000;
            FM3_DMAC->DMACA7 = (0x0000FFFF & bytes);
            bFM3_DMAC_DMACA7_EB = 1;
            bFM3_DMAC_DMACA7_ST = 1;
        break;
        default:
            
        break;
    }
    
}

/*!
 ******************************************************************************
 ** \brief check DMA channel0 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch0(void)
{
    if( NormSoftTrigFlag0 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel1 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch1(void)
{
    if( NormSoftTrigFlag1 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel2 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch2(void)
{
    if( NormSoftTrigFlag2 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel3 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch3(void)
{
    if( NormSoftTrigFlag3 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel4 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch4(void)
{
    if( NormSoftTrigFlag4 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel5 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch5(void)
{
    if( NormSoftTrigFlag5 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel6 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch6(void)
{
    if( NormSoftTrigFlag6 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief check DMA channel7 busy status on normal software trigger mode
 **
 ** \param none
 **
 ** \retval 1 busy
 ** \retval 0 not busy
 **
 ******************************************************************************
 */
uint8_t DMA_IsNormSoftTrigBusy_Ch7(void)
{
    if( NormSoftTrigFlag7 == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*!
 ******************************************************************************
 ** \brief DMA0 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC0_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB0 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB0 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB0 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB0 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB0 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB0 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[0]!=NULL )
    {
        DMA_IrqCallback[0](tpye);
    }
    
    FM3_DMAC->DMACB0 &= 0xFFF8FFFF;//clear SS bit
    NormSoftTrigFlag0=0;
}

/*!
 ******************************************************************************
 ** \brief DMA1 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC1_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB1 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB1 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB1 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB1 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB1 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB1 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[1]!=NULL )
    {
        DMA_IrqCallback[1](tpye);
    }
    
    FM3_DMAC->DMACB1 &= 0xFFF8FFFF;
    NormSoftTrigFlag1=0;
}

/*!
 ******************************************************************************
 ** \brief DMA2 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC2_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB2 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB2 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB2 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB2 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB2 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB2 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[2]!=NULL )
    {
        DMA_IrqCallback[2](tpye);
    }
    
    FM3_DMAC->DMACB2 &= 0xFFF8FFFF;
    NormSoftTrigFlag2=0;
}

/*!
 ******************************************************************************
 ** \brief DMA3 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC3_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB3 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB3 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB3 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB3 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB3 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB3 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[3]!=NULL )
    {
        DMA_IrqCallback[3](tpye);
    }
    
    FM3_DMAC->DMACB3 &= 0xFFF8FFFF;
   NormSoftTrigFlag3=0;
}

/*!
 ******************************************************************************
 ** \brief DMA4 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC4_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB4 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB4 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB4 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB4 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB4 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB4 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[4]!=NULL )
    {
        DMA_IrqCallback[4](tpye);
    }
    
    FM3_DMAC->DMACB4 &= 0xFFF8FFFF;
    NormSoftTrigFlag4=0;
}

/*!
 ******************************************************************************
 ** \brief DMA5 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC5_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB5 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB5 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB5 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB5 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB5 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB5 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[5]!=NULL )
    {
        DMA_IrqCallback[5](tpye);
    }
    
    FM3_DMAC->DMACB5 &= 0xFFF8FFFF;
    NormSoftTrigFlag5=0;
}

/*!
 ******************************************************************************
 ** \brief DMA6 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC6_Handler(void)
{
    
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB6 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB6 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB6 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB6 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB6 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB6 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[6]!=NULL )
    {
        DMA_IrqCallback[6](tpye);
    }
    
    FM3_DMAC->DMACB6 &= 0xFFF8FFFF;
    NormSoftTrigFlag6=0;
}

/*!
 ******************************************************************************
 ** \brief DMA7 handler function
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void DMAC7_Handler(void)
{
    DMAIntType tpye;
    if( (FM3_DMAC->DMACB7 & 0x00070000) == 0x00010000 )
    {
        tpye=ErrAddOverflow;
    }
    else if( (FM3_DMAC->DMACB7 & 0x00070000) == 0x00020000 )
    {
        tpye=StopRqst;
    }
    else if( (FM3_DMAC->DMACB7 & 0x00070000) == 0x00030000 )
    {
        tpye=ErrSrsAddErr;
    }
    else if( (FM3_DMAC->DMACB7 & 0x00070000) == 0x00040000 )
    {
        tpye=ErrDesAddErr;
    }
    else if( (FM3_DMAC->DMACB7 & 0x00070000) == 0x00050000 )
    {
        tpye=Success;
    }
    else if( (FM3_DMAC->DMACB7 & 0x00070000) == 0x00070000 )
    {
        tpye=Pause;
    }
    
    if( DMA_IrqCallback[7]!=NULL )
    {
        DMA_IrqCallback[7](tpye);
    }
    
    FM3_DMAC->DMACB7 &= 0xFFF8FFFF;
    NormSoftTrigFlag7=0;
}




