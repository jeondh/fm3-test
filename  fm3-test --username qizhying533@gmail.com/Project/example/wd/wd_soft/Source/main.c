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
static void WD_SoftTestInt(void);


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
    uint16_t ResetCause;

    /* Read causes of resets, reading the register clears all bits */
    ResetCause = FM3_CRG->RST_STR;
    
    /* Software watchdog reset is generated */
    if((ResetCause & 0x0010) == 0x0010)
    {    
#ifdef DEBUG_MODE 
        printf("Software Watchdog reset is generated.\n");
#endif
    }

    WD_SoftConfigInfoT ConfigInfo = {0};  
    ConfigInfo.SWDVal = 0xfff;
    ConfigInfo.pSWDIntHandlerCallback = WD_SoftTestInt;
	    
    /* Config SWD */
    WD_SoftConfig(&ConfigInfo);
    /* Enable SWD interrupt */
    WD_SoftIntEnable();
    /* Enable interrupt */
    NVIC_EnableIRQ(SWDT_IRQn);
    while(1);   
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
static void WD_SoftTestInt(void)
{

    return;

}




/*****************************************************************************/
/* END OF FILE */
