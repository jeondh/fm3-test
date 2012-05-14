/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_adcmp_fm3.c
 **
 ** \brief  ADC Start Compare Unit all cell drivers file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-10 13:50
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
#include "mft_adcmp_fm3.h"

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FM3_MFT_ADCMP_TypeDef* pFM3_MFT_ADCMP_BASE[MFT_AMOUNT] =
{
    (FM3_MFT_ADCMP_TypeDef*)(FM3_MFT0_ADCMP_BASE),
    (FM3_MFT_ADCMP_TypeDef*)(FM3_MFT1_ADCMP_BASE)
};


/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Read register value that ADC channel connect to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return Which FRT channel to configure
 ** \retval  FRT_CH0, FRT_CH1, FRT_CH2
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetFRTCh(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint16_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ~(ADCMP_ACSA_CE0);
    	return (uint8_t)(temp >> 0);
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ~(ADCMP_ACSA_CE1);
    	return (uint8_t)(temp >> 2);
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ~(ADCMP_ACSA_CE2);
    	return (uint8_t)(temp >> 4);
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set ADCMP channel connects to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetFRTCh(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						   	   volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ADCMP_ACSA_CE0) | (WhichFRTCh << 0);
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ADCMP_ACSA_CE1) | (WhichFRTCh << 2);
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ADCMP_ACSA_CE2) | (WhichFRTCh << 4);
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read which count state FRT should be in to instruct AD conversion
 **  		to be started at each channel of ADCMP
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return Mode
 ** \retval ACCP_UPPEAKDOWN,ACCP_UP,ACCP_PEAKDOWN,ACCP_UP_ACCPDN_PEAKDOWN
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetStartMode(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint16_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ~(ADCMP_ACSA_SEL0);
    	return (uint8_t)(temp >> 8);
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ~(ADCMP_ACSA_SEL1);
    	return (uint8_t)(temp >> 10);
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ~(ADCMP_ACSA_SEL2);
    	return (uint8_t)(temp >> 12);
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set which count state FRT should be in to instruct AD conversion
 **  		to be started at each channel of ADCMP
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  Mode
 ** \arg    ACCP_UPPEAKDOWN,ACCP_UP,ACCP_PEAKDOWN,ACCP_UP_ACCPDN_PEAKDOWN
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetStartMode(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint8_t Mode)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ADCMP_ACSA_SEL0) | (Mode << 8);
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ADCMP_ACSA_SEL1) | (Mode << 10);
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSA & ADCMP_ACSA_SEL2) | (Mode << 12);
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read state of the buffer function of the ACCP0 and ACCPDN0 registers
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return En enable or not
 ** \retval TRUE, FALSE
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetACCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint16_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ~(ADCMP_ACSB_BDIS0);
    	return (uint8_t)(temp >> 0);
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ~(ADCMP_ACSB_BDIS1);
    	return (uint8_t)(temp >> 1);
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ~(ADCMP_ACSB_BDIS2);
    	return (uint8_t)(temp >> 2);
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Read state of the buffer function of the ACCP0 and ACCPDN0 registers
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetACCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ADCMP_ACSB_BDIS0) | (En << 0);
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ADCMP_ACSB_BDIS1) | (En << 1);
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ADCMP_ACSB_BDIS2) | (En << 2);
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the timing  of transferring data from the buffer register to
 **         the ACCP0 and ACCPDN0 registers when the buffer function is enabled
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return When
 ** \retval ADCMP_ZERO, ADCMP_PEAK
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint16_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ~(ADCMP_ACSB_BTS0);
    	return (uint8_t)(temp >> 4);
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ~(ADCMP_ACSB_BTS1);
    	return (uint8_t)(temp >> 5);
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ~(ADCMP_ACSB_BTS2);
    	return (uint8_t)(temp >> 6);
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set the timing  of transferring data from the buffer register to
 **         the ACCP0 and ACCPDN0 registers when the buffer function is enabled
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  When
 ** \arg    ADCMP_ZERO, ADCMP_PEAK
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint8_t When)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ADCMP_ACSB_BTS0) | (When << 4);
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ADCMP_ACSB_BTS1) | (When << 5);
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ACSB & ADCMP_ACSB_BTS2) | (When << 6);
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the timing of starting AD conversion(ACCP)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \retval ACCPValue
 *****************************************************************************
*/
uint16_t MFT_AdcmpAccpRead(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCP0;
    	return temp;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCP1;
    	return temp;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCP2;
    	return temp;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return temp;
    }
}

/*!
 ******************************************************************************
 ** \brief  Configure the timing of starting AD conversion(ACCP)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \retval none
 *****************************************************************************
*/
uint8_t MFT_AdcmpAccpWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint16_t value)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCP0 = value;
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCP1 = value;
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCP2 = value;
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the timing of starting AD conversion(ACCPDN)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \retval ACCPValue
 *****************************************************************************
*/
uint16_t MFT_AdcmpAccpdnRead(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCPDN0;
    	return temp;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCPDN1;
    	return temp;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCPDN2;
    	return temp;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return temp;
    }
}

/*!
 ******************************************************************************
 ** \brief  Configure the timing of starting AD conversion(ACCPDN)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \retval none
 *****************************************************************************
*/
uint8_t MFT_AdcmpAccpdnWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint16_t value)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCPDN0 = value;
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCPDN1 = value;
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ACCPDN2 = value;
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the start signal to be used to start the scan conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \return Origin
 ** \retval TRI_ADCMP,TRI_FRT
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetTriggerOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint16_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ~(ADCMP_ATSA_AD0S);
    	return (uint8_t)(temp >> 0);
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ~(ADCMP_ATSA_AD1S);
    	return (uint8_t)(temp >> 2);
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ~(ADCMP_ATSA_AD2S);
    	return (uint8_t)(temp >> 4);
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set the start signal to be used to start the scan conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 ** \param  Origin
 ** \arg    TRI_ADCMP,TRI_FRT
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetTriggerOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint8_t Origin)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ADCMP_ATSA_AD0S) | (Origin << 0);
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ADCMP_ATSA_AD1S) | (Origin << 2);
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ADCMP_ATSA_AD2S) | (Origin << 4);
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the start signal to be used to start priority conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \return Type
 ** \retval TRI_ADCMP,TRI_FRT
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetPriority(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint16_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ~(ADCMP_ATSA_AD0P);
    	return (uint8_t)(temp >> 8);
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ~(ADCMP_ATSA_AD1P);
    	return (uint8_t)(temp >> 10);
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	temp = pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ~(ADCMP_ATSA_AD2P);
    	return (uint8_t)(temp >> 12);
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
        return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set the start signal to be used to start priority conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 ** \param  Type
 ** \arg    TRI_ADCMP,TRI_FRT
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetPriority(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP, volatile uint8_t Type)
{
#if(DEBUG_MODE && DEBUG_DRV_ADC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((ADCMP_CH0 == WhichADCMP) || (ADCMP_CH1 == WhichADCMP) || (ADCMP_CH2 == WhichADCMP));
#endif

    uint8_t temp;
    if(ADCMP_CH0 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ADCMP_ATSA_AD0P) | (Type << 8);
    	temp = TRUE;
    }
    else if(ADCMP_CH1 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ADCMP_ATSA_AD1P) | (Type << 10);
    	temp = TRUE;
    }
    else if(ADCMP_CH2 == WhichADCMP)
    {
    	pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA =  (pFM3_MFT_ADCMP_BASE[WhichMFT]->ATSA & ADCMP_ATSA_AD2P) | (Type << 12);
    	temp = TRUE;
    }
    else
    {
    	temp = ADCMP_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_ADCMP)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*****************************************************************************/
/* END OF FILE */
