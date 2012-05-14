/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_ADCMP.c
 **
 ** \brief ADC Start Compare Unit example source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-30 10:30
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
#include "EXMP_MFT_ADCMP.h"

/*!
 ******************************************************************************
 ** \brief  MFT module ADCMP unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_Initial(void)
{
    //SystemInit();       /* Initialize system */
    InitialADCMP();    /* Initialize ADCMP module */

    return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialADCMP(void)
{
    _stConfADC stConfADC;

    stConfADC.WhichADCUnit = ADC_UNIT0;
    stConfADC.TriggeredByWhichMFT = MFT0;
    stConfADC.TriggeredByWhichFRT = FRT_CH0; // ACCP/ACCPDN compare with which FRT channel.
                                                          // Usually this value should agree with
                                                          // the value in ConfFRT()
    stConfADC.WhenToTrigger = 0; // FRT count to this value will trigger ADC unit
    stConfADC.TriggerSlope = ACCP_UPPEAKDOWN;
    stConfADC.EnBuf = FALSE; // ACCP/ACCPDN buffer
    stConfADC.WhenToTransBuff = 0;
    stConfADC.EnINT = TRUE;

    MFT_ADCMPInitConfig(&stConfADC);
    
    return;
}

/*!
 ******************************************************************************
 ** \brief    ADCMP unit register configure
 **
 ** \param    _stParaForWFG ADCMP unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_ADCMPInitConfig(volatile _stConfADC *p)
{
    volatile int32_t WhenToTrigger;
    volatile int8_t WhichADCUnit;
    volatile int8_t WhichMFT, WhichFRT;
    volatile int8_t TriggerSlope,WhenToTransBuff;
    volatile uint8_t EnINT, EnBuf;

    WhichMFT = p->TriggeredByWhichMFT;

    /* Get user configuration */   
    WhichADCUnit = p->WhichADCUnit;
    WhichFRT = p->TriggeredByWhichFRT;
    WhenToTrigger = p->WhenToTrigger;
    TriggerSlope = p->TriggerSlope;
    EnBuf = p->EnBuf;
    WhenToTransBuff = p->WhenToTransBuff;
    EnINT = p->EnINT;

    /* Allocate channel to ADC */
    MFT_AdcmpSetFRTCh(WhichMFT, WhichFRT,WhichADCUnit);
    /* configure the trigger count-slope for ADC unit */
    MFT_AdcmpSetStartMode(WhichMFT,WhichADCUnit, TriggerSlope);
    /* configure trigger timing for ADC unit */
    MFT_AdcmpAccpWrite(WhichMFT,WhichADCUnit,WhenToTrigger);
    /* configure Enable or disable ACCP buffer for ADC unit */
    MFT_AdcmpSetACCPBufFnct(WhichMFT,WhichADCUnit,EnBuf);
    /* configure When to transfer ADCP buffer data to ACCP for ADC unit */
    MFT_AdcmpSetTimeSendBuff(WhichMFT,WhichADCUnit,WhenToTransBuff);

   return;
}

/*****************************************************************************/
/* END OF FILE */


