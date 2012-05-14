/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_FRT.c
 **
 ** \brief Free-run Timer Unit example source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-28 14:30
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
#include "EXMP_MFT_FRT.h"

/*!
 ******************************************************************************
 ** \brief  MFT module FRT unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_Initial(void)
{
    //SystemInit();       /* Initialize system */
    InitialFRT();    /* Initialize FRT module */
   // NVIC_EnableIRQ(FRTIM_IRQn);   /* Enable FRT interrupt */

    return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialFRT(void)
{
    _stParaForFRT stParaForFRT;

    stParaForFRT.WhichMFT = MFT0;
    stParaForFRT.WhichFRTCh = FRT_CH0;
    stParaForFRT.CntMode = CNT_MODE_UPDOWN;
    stParaForFRT.Cycle = 0.20;     // ms
    stParaForFRT.EnBuf = FALSE;
    stParaForFRT.EnINT_MatchTop = FALSE;
    stParaForFRT.EnINT_MatchZero = TRUE;

    MFT_FRTInitConfig(&stParaForFRT);

    return;
}

/*!
 ******************************************************************************
 ** \brief    FRT unit register configure
 **
 ** \param    _stParaForFRT FRT unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_FRTInitConfig(volatile _stParaForFRT *p)
{
    volatile int8_t WhichMFT, WhichFRTCh, CntMode, EnBuf;
    volatile float Cycle;
    volatile uint8_t EnINT_MatchZero, EnINT_MatchTop;
    volatile uint8_t temp;
    
    WhichMFT = p->WhichMFT;
    WhichFRTCh = p->WhichFRTCh;
    CntMode = p->CntMode;
    EnBuf = p->EnBuf;
    Cycle = p->Cycle;
    EnINT_MatchZero = p->EnINT_MatchZero;
    EnINT_MatchTop = p->EnINT_MatchTop;

    MFT_FrtSetCntMode(WhichMFT, WhichFRTCh, CntMode); /* count mode */
    MFT_FrtDivWrite(WhichMFT, WhichFRTCh, FRT_DIV0); /* division value */
    MFT_FrtSetCntCycle(WhichMFT, WhichFRTCh, Cycle); /* count cycle (ms) */
    MFT_FrtSetTCCPBufFnct(WhichMFT, WhichFRTCh, EnBuf); /* enable/disable TCCP buffer */
    MFT_FrtSetZeroIntFnct(WhichMFT, WhichFRTCh, EnINT_MatchZero); /* enable/disable 0-detect interrupt */
    MFT_FrtSetTopIntFnct(WhichMFT, WhichFRTCh, EnINT_MatchTop); /* enable/disable top-detect interrupt */
    MFT_FrtStart(WhichMFT,WhichFRTCh);  /* start counter */

    FRT_IntCallback[WhichMFT] = FRT_Callback;

    return;
}

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg FRT_INT_TOP_CH0
 ** \arg FRT_INT_TOP_CH1
 ** \arg FRT_INT_TOP_CH2
 ** \arg FRT_INT_ZERO_CH0
 ** \arg FRT_INT_ZERO_CH1
 ** \arg FRT_INT_ZERO_CH2
 **
 ** \return none
 **
 ******************************************************************************
 */
static void FRT_Callback(uint8_t IntType)
{
    switch(IntType)
    {
        case FRT_INT_TOP_CH0:
             printf("FRT channel 0 top interrupt \n");
             break;
        case FRT_INT_TOP_CH1:
             printf("FRT channel 1 top interrupt \n");
             break;
        case FRT_INT_TOP_CH2:
             printf("FRT channel 2 top interrupt \n");
             break;
        case FRT_INT_ZERO_CH0:
             printf("FRT channel 0 zero interrupt \n");
             break;
        case FRT_INT_ZERO_CH1:
             printf("FRT channel 1 zero interrupt \n");
             break;
        case FRT_INT_ZERO_CH2:
             printf("FRT channel 2 zero interrupt \n");
             break;

        default:
            break;
    }

    return;
}

/*****************************************************************************/
/* END OF FILE */
