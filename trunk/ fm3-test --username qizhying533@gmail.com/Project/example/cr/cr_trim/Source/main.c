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
    int16_t cr_trimdata; 

    cr_trimdata = CR_GetTrimData();
#ifdef DEBUG_MODE
    printf("default cr trimming:%d\n", cr_trimdata);
#endif
	
    /* Enable CR out */
    FM3_GPIO->PFR2 |= 0x00000001;
    FM3_GPIO->EPFR00 |= 0x00000002; 
    /* test data */
    cr_trimdata = 0x1f00; 
    CR_SetTrimData(cr_trimdata);
#ifdef DEBUG_MODE
    printf("Measure CROUT pin(P20)");
#endif


    while(1);    
}



/*****************************************************************************/
/* END OF FILE */