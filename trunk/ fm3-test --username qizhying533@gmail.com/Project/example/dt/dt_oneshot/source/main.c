/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \brief Dual timer demo application
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-07
 **
 ** \brief This file provides the examples to operate the Dual timer
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

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                               */
/*---------------------------------------------------------------------------*/
uint32_t ltmp = 0;
DT_ConfigT tDT_ConfigTOneShot = 
{
    DT_MODE_ONESHOT,
    DT_PRE_BY_256,
    DT_CNT_SIZE_32,
    40000000,
    0,
    1000,/*ms*/
    0,/*ms*/
};
DT_ConfigT tDT_ConfigTFreeRun = 
{
    DT_MODE_FREERUN,
    DT_PRE_BY_1,
    DT_CNT_SIZE_32,
    40000000,
    0,
    1000,/*ms*/
    0,/*ms*/
};
DT_ConfigT tDT_ConfigTPeriodic = 
{
    DT_MODE_PERIOD,
    DT_PRE_BY_1,
    DT_CNT_SIZE_32,
    0,
    0,
    1000,/*ms*/
    5000,/*ms*/
};
/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Dual timer ISR callback
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
static void DTIrqCallback(void)
{
    ltmp++;
}
/*!
 ******************************************************************************
 ** \brief  One shot Dual timer example
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void DTOneShot(void)
{
    DT_ConfigMode(DT_CH_1, &tDT_ConfigTOneShot);
    DT_ConfigISRCallback(DT_CH_1, DTIrqCallback);
    DT_ConfigTimerEnable(DT_CH_1);
    DT_IntEnable(DT_CH_1);
    NVIC_EnableIRQ(DTIM_QDU_IRQn);
    while(1);
}
/*!
 ******************************************************************************
 ** \brief  Free run Dual timer example
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void DTFreeRun(void)
{
    DT_ConfigmsMode(DT_CH_1, &tDT_ConfigTFreeRun);
    DT_ConfigISRCallback(DT_CH_1, DTIrqCallback);
    DT_ConfigTimerEnable(DT_CH_1);
    DT_IntEnable(DT_CH_1);
    NVIC_EnableIRQ(DTIM_QDU_IRQn);
    while(1);
}
/*!
 ******************************************************************************
 ** \brief  Periodic Dual timer example
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */
void DTPeriodic(void)
{
    DT_ConfigmsMode(DT_CH_1, &tDT_ConfigTPeriodic);
    DT_ConfigISRCallback(DT_CH_1, DTIrqCallback);
    DT_ConfigTimerEnable(DT_CH_1);
    DT_IntEnable(DT_CH_1);
    NVIC_EnableIRQ(DTIM_QDU_IRQn);
    while(1);
}
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
//    DTOneShot();
//    DTFreeRun();
    DTPeriodic();
}

/*****************************************************************************/
/* END OF FILE */
