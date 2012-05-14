/*!
 ******************************************************************************
 **
 ** \file sample_main.c
 **
 ** \brief DMA main.c file
 **
 ** \author FSLA AE Team 
 **
 ** \version V0.10
 **
 ** \date 2011-11-21
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

#include "mb9bf50x_lib.h"

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief DMA channel0 callback function
 **
 ** \param DMA_interrupt_type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh0(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel1 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh1(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel2 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh2(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel3 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh3(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel4 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh4(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel5 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh5(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel6 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh6(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA channel7 callback function
 **
 ** \param DMA interrupt type (no need specify)
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
static void DMAIrqCallbackCh7(uint8_t inttype)
{
    uint8_t type;
    type=inttype;
  
    switch (type) 
    {
        case ErrAddOverflow:
            //user code 
            break;
        case StopRqst:
            //user code 
            break;
        case ErrSrsAddErr:
            //user code 
            break;
        case ErrDesAddErr:
            //user code 
            break;
        case Success:
            //user code 
            break;
        case Pause:
            //user code 
            break;
        default:
            break;
    }    
}

/*!
 ******************************************************************************
 ** \brief DMA main function
 **
 ** \param none
 **         
 ** \retval none
 **
 ******************************************************************************
 */ 
int32_t main(void)
{
    
    DMA_IrqCallback[0] = DMAIrqCallbackCh0;
    DMA_IrqCallback[1] = DMAIrqCallbackCh1;
    DMA_IrqCallback[2] = DMAIrqCallbackCh2;
    DMA_IrqCallback[3] = DMAIrqCallbackCh3;
    DMA_IrqCallback[4] = DMAIrqCallbackCh4;
    DMA_IrqCallback[5] = DMAIrqCallbackCh5;
    DMA_IrqCallback[6] = DMAIrqCallbackCh6;
    DMA_IrqCallback[7] = DMAIrqCallbackCh7;
    DMA_NrmlDataTrsfBySftTrig(0x20000100, 0x20000800, 0xFF, 7);
    while(1){
      ;
    } /* end of loop */

}
