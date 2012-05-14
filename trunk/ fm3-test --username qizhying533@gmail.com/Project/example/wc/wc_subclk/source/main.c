/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-21
 **
 ** \brief This file provides an example to operate the Watch Counter,
 **        which is sourced by sub clock.
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
#define GPIO_PIN_P1B                                  ((uint16_t)0x0800)

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void IOTest_Init(void);
static void IOTest_Polling(void);
/*---------------------------------------------------------------------------*/
/* Local data                                                               */
/*---------------------------------------------------------------------------*/
static uint8_t g_WcValidFlag = 0;

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
    WC_ConfigInfoT aConfigInfo = {0};  
    aConfigInfo.CntClkSel = WC_OUTPUT_CLOCK_WCCK3; /* Select WCCK3 */
    aConfigInfo.CntVal = 1;                        /* Set 1s interval */
    aConfigInfo.CntIntEn = ENABLE;          /* Open interrupt */
    aConfigInfo.pIntHandlerCallback = IOTest_Polling;
    /* select input clock */
    WCPRES_ClkInSel(WCPRES_INPUT_CLOCK_SUB_CLOCK);
    /* select output clock */
    WCPRES_ClkOutSel(WCPRES_OUTPUT_CLOCK_ARRAY0);
    /* Enable clock output */
    WCPRES_ClkEn(ENABLE);
    /* Config watch counter*/
    WC_Config(&aConfigInfo);
    /* Enable interrupt */
    NVIC_EnableIRQ(OSC_PLL_WC_IRQn);
    /* Start count */
    WC_Start();
    while(!g_WcValidFlag); /* wait until watch counter is valid */
    IOTest_Init();
    while(1);
}

/*!
 ******************************************************************************
 ** \brief  Initialize the IO (P1B) to be tested
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 */

void IOTest_Init(void)
{
    /* P1B/AN11/SOT4_1/IC01_1/MDATA11 -> P1B */
    FM3_GPIO->ADE &= ~GPIO_PIN_P1B;
    FM3_GPIO->PFR1 &= ~GPIO_PIN_P1B;
    FM3_GPIO->PDOR1 |= GPIO_PIN_P1B;
    FM3_GPIO->DDR1 |= GPIO_PIN_P1B;
    return;
}

/*!
 ******************************************************************************
 ** \brief  Polling the IO (P1B)
 **
 ** \param  none
 **
 ** \return none
 ******************************************************************************
 *
 */

void IOTest_Polling(void)
{
    /* ignore first trigger in order to synchronize with PCLK*/
    if(!g_WcValidFlag)
    {  
        g_WcValidFlag = 1; 
        return;
    }
    FM3_GPIO->PDOR1 ^= GPIO_PIN_P1B; /* polling IO to Flash LED */
    return;
}

/*****************************************************************************/
/* END OF FILE */
