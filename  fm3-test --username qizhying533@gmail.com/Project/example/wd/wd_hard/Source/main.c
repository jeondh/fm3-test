/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-12
 **
 ** \brief This file provides an example to operate the Watchdog Timer
 **       
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
/* IO definition                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void WD_HardTestInt(void);


/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief  Main function of project for MB9B506 series.
 **
 ** \param  none
 **
 ** \retval uint32_t return value, if needed
 ******************************************************************************
 */

int32_t main(void)
{
    //test();
    uint16_t ResetCause;

    /* Read causes of resets, reading the register clears all bits */
    ResetCause = FM3_CRG->RST_STR;
    
    /* Hard watchdog reset is generated */
    if ((ResetCause & 0x0020) == 0x0020)
    {    
#ifdef DEBUG_MODE 
        printf("Hardware Watchdog reset is generated.\n");
#endif
    }
    bFM3_GPIO_PFR5_P0 = 0;
    bFM3_GPIO_DDR5_P0 = 1; 
    bFM3_GPIO_PDOR5_P0 =1; 
    
    WD_HardConfigInfoT ConfigInfo = {0};  
    ConfigInfo.HWDVal = 0xff;
    ConfigInfo.pHWDIntHandlerCallback = WD_HardTestInt;
   
    /* Config HWD */
    WD_HardConfig(&ConfigInfo);
    /* Enable HWD interrupt */
    WD_HardResetEnable();
    /* Enable interrupt */
    NVIC_EnableIRQ(NMI_IRQn);
    while(1)
    {
     
    }
}



/*!
 ******************************************************************************
 ** \brief  Test interrupt program
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void WD_HardTestInt(void)
{
    bFM3_GPIO_PDOR5_P0 = ~bFM3_GPIO_PDOR5_P0;
    return;
}


/*****************************************************************************/
/* END OF FILE */
