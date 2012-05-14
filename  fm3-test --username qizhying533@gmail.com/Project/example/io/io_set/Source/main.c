/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-18
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
    uint32_t readdata;
	
    /*config port */
    IO_ConfigPort(GPIO_PORT1,GPIO_ALL_PIN,IO_GPIO_MODE);
    /* Write data   */
    IO_GPIOWriteData(GPIO_PORT1,GPIO_ALL_PIN,0xaaaa);
    /*output setting */
    IO_GPIOSetOutput(GPIO_PORT1,GPIO_ALL_PIN);
    /*pull-up setting */
    IO_GPIOConfigPullup(GPIO_PORT1,GPIO_ALL_PIN,IO_PULLUP_DISCONN);
    /*Read data */
    readdata = IO_GPIOReadData(GPIO_PORT1,GPIO_ALL_PIN);
#ifdef DEBUG_MODE
    printf("Read data:%d", readdata);
#endif
    while(1);
}



/*****************************************************************************/
/* END OF FILE */