/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_WFG.c
 **
 ** \brief Waveform Generator Unit example source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-29 18:30
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "EXMP_MFT_WFG.h"


/*!
 ******************************************************************************
 ** \brief  MFT module WFG unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_Initial(void)
{
    //SystemInit();       /* Initialize system */
    InitialWFG();    /* Initialize WFG module */
    InitialDTTI();   /* Initialize DTTI module */
   // NVIC_EnableIRQ(WFG_IRQn);   /* Enable WFG interrupt */

    return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialWFG(void)
{
    _stParaForWFG stParaForWFG;

    stParaForWFG.WhichMFT = MFT0;
    stParaForWFG.FreqDivForAPB1 = WFG_DIV2;
    stParaForWFG.DeadTime = 0.0026; // ms
    stParaForWFG.EnINT = TRUE;

    MFT_WFGInitConfig(&stParaForWFG);
}

/*!
 ******************************************************************************
 ** \brief    WFG unit register configure
 **
 ** \param    _stParaForWFG WFG unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_WFGInitConfig(volatile _stParaForWFG *p)
{
    volatile int8_t WhichMFT;
    volatile int8_t WhichPhase;
    volatile int8_t FreqDivForAPB1;
    volatile float  DeadTime;
    volatile uint16_t TimeVal;
    volatile int8_t  EnINT;
    volatile uint8_t Temp1[] = { 1, 2, 4, 8, 16, 32, 64 };

    WhichMFT = p->WhichMFT;
    WhichPhase = p->WhichPhase;
    FreqDivForAPB1 = p->FreqDivForAPB1;
    DeadTime = p->DeadTime;
    EnINT = p->EnINT;

    /* Set I/O Port (PWM) */
    /* UH/UL : P3.10/P3.11 */
    FM3_GPIO->PCR3   = (FM3_GPIO->PCR3 & ~(0x00000C00));       /* pull-up off */
    FM3_GPIO->DDR3   = (FM3_GPIO->DDR3 | 0x00000C00);          /* output */
    FM3_GPIO->PFR3   = (FM3_GPIO->PFR3 | 0x00000C00);          /* uses a pin as peripheral functions */
    FM3_GPIO->PDOR3  = (FM3_GPIO->PDOR3 & ~(0x00000C00));      /* Write bit data from port LOW*/

    /* configure WFG macro */
    volatile int8_t WFGChPairs = MFT_WfgGetPolarity(WhichMFT,WhichPhase); /* Determine WFG channel pairs according
                                                                             to user given WFG output pin */
    MFT_WfgSetWorkMode(WhichMFT, WFGChPairs, MODE_RT_DEAD_TIMER);/* work mode */
    MFT_WfgDivWrite(WhichMFT, WFGChPairs, FreqDivForAPB1); /* count frequency to count the deadtime */
    TimeVal = (uint16_t)DeadTime*1000*((uint32_t)(&FM3_CRG->APBC1_PSR)) / Temp1[FreqDivForAPB1];
    MFT_WfgTimerValueWrite(WhichMFT, WFGChPairs, TimeVal); /* overflow period (ms)*/

    WFG_IntCallback[WhichMFT] = WFG_Callback;

   return;
}

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg WFG_INT_CH10
 ** \arg WFG_INT_CH32
 ** \arg WFG_INT_CH54
 **
 ** \return none
 **
 ******************************************************************************
 */
static void WFG_Callback(uint8_t IntType)
{
    switch(IntType)
    {
        case WFG_INT_CH10:
                printf(" WFG timer 10 Interrupt \n");
                break;
        case WFG_INT_CH32:
                printf(" WFG timer 32 Interrupt \n");
                break;
        case WFG_INT_CH54:
                printf(" WFG timer 54 Interrupt \n");
                break;
        default:
                break;
    }

    return;
}

/*!
 ******************************************************************************
 ** \brief  DTTI unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialDTTI(void)
{
    _stParaForDTTI stParaForDTTI;

    stParaForDTTI.WhichMFT = MFT0;
    stParaForDTTI.NoiseTolerance = DTTI_NOISE_TIME4;
    stParaForDTTI.EnINT = TRUE;
    MFT_DTTIInitConfig(&stParaForDTTI);
}

/*!
 ******************************************************************************
 ** \brief    DTTI unit register configure
 **
 ** \param    _stParaForDTTI DTTI unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_DTTIInitConfig(volatile _stParaForDTTI *p)
{
    volatile int8_t WhichMFT;
    volatile int8_t NoiseTolerance;
    volatile int8_t  EnINT;

    WhichMFT = p->WhichMFT;
    NoiseTolerance = p->NoiseTolerance;
    EnINT = p->EnINT;

    /* Set I/O Port (PWM) */
    /* UH/UL : P1.14*/
    FM3_GPIO->PCR1   = (FM3_GPIO->PCR1 |   0x00004000);       /* pull-up off */
    FM3_GPIO->DDR1   = (FM3_GPIO->DDR1 & ~(0x00004000));          /* input */
    FM3_GPIO->PFR1   = (FM3_GPIO->PFR1 |   0x00004000);          /* uses a pin as peripheral functions */
    FM3_GPIO->PDOR1  = (FM3_GPIO->PDOR1 & ~(0x00004000));      /* Write bit data from port LOW*/

    MFT_WfgSetDtifIntFnct(WhichMFT,EnINT);
    MFT_WfgSetNoiseCancelWidth(WhichMFT, NoiseTolerance); // DTTI noise tolerance
    DTTI_IntCallback[WhichMFT] = DTTI_Callback;
}

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 **
 ** \return none
 **
 ******************************************************************************
 */
static void DTTI_Callback(void)
{
    printf(" DTTI  Interrupt \n");

    return;
}

/*****************************************************************************/
/* END OF FILE */
