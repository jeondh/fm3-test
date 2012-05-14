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
 ** \brief This file provides an example to operate the Low voltage detection,
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
static void LVD_TestInt(void);

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
uint8_t lvd_int = 0; 

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
    LVD_ConfigInfoT configInfo = {0}; 
    /* Select  3.0V */
    configInfo.LvdVal = LVD_VOL_VAL_4_2; 	
    configInfo.pIntHandlerCallback = LVD_TestInt;              
    
    /* write protection mode release */
    LVD_CtlEnable();
    /*Config LVD */
    LVD_Config(&configInfo);
    /* Enable LVD interrupt */
    LVD_IntEnable();
    /* writing protection mode set */
    LVD_CtlDisable();

    
    /* Enable interrupt */
    NVIC_EnableIRQ(LVD_IRQn);
    while(1)
    {
        if(lvd_int == 1)
        {
            lvd_int = 0;
#ifdef DEBUG_MODE 
            printf("LVD interrupt is generated.\n");
#endif
	}	 
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
static void LVD_TestInt(void)
{
    lvd_int = 1;
    return;
}




/*****************************************************************************/
/* END OF FILE */
