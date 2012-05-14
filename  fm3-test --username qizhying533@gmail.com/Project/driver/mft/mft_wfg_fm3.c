/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_wfg_fm3.c
 **
 ** \brief Waveform Generator Unit all cell drivers file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-12 14:15
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
#include "mft_wfg_fm3.h"

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void WFG_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue);
static void DTTI_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue);

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FM3_MFT_WFG_TypeDef* pFM3_MFT_WFG_BASE[MFT_AMOUNT] =
{
    (FM3_MFT_WFG_TypeDef*)(FM3_MFT0_WFG_BASE),
    (FM3_MFT_WFG_TypeDef*)(FM3_MFT1_WFG_BASE)
};

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
/*! \brief WFG callback function */
WFG_CallbackT WFG_IntCallback[] = { NULL, NULL};
/*! \brief DTTI callback function */
DTTI_CallbackT DTTI_IntCallback[] = { NULL, NULL};

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief  Read division value for WFGxx (WFSA_DCK bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  Division value
 ** \retval  [WFG_DIV0, WFG_DIV8]
 *****************************************************************************
*/
uint8_t MFT_WfgDivRead(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & ~(WFG_WFSA_DCK);
    }
    else if(WhichWFGxx == FRT_CH1)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & ~(WFG_WFSA_DCK);
    }
    else if(WhichWFGxx == FRT_CH2)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & ~(WFG_WFSA_DCK);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp);
}

/*!
 ******************************************************************************
 ** \brief  Write division value for WFGxx (WFSA_DCK bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Div Division value
 ** \arg    [WFG_DIV0, WFG_DIV8]
 **
 ** \return  none
 *****************************************************************************
*/
uint8_t MFT_WfgDivWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t Div)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT(Div <= WFG_DIV6);
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & WFG_WFSA_DCK) | Div;
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & WFG_WFSA_DCK) | Div;
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & WFG_WFSA_DCK) | Div;
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
     return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get work mode for WFGxx (WFSA_TMD bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  Mode value
 ** \retval  MODE_THROUGH,MODE_RT_PPG,MODE_TIME_PPG,MODE_RT_DEAD_TIMER,MODE_PPG_DEAD_TIMER
 *****************************************************************************
*/
uint8_t MFT_WfgGetWorkMode(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & ~(WFG_WFSA_TMD);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & ~(WFG_WFSA_TMD);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & ~(WFG_WFSA_TMD);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 3);
}

/*!
 ******************************************************************************
 ** \brief  Set work mode for WFGxx (WFSA_TMD bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Mode value
 ** \arg    MODE_THROUGH,MODE_RT_PPG,MODE_TIME_PPG,MODE_RT_DEAD_TIMER,MODE_PPG_DEAD_TIMER
 **
 ** \return  none
 *****************************************************************************
*/
uint8_t MFT_WfgSetWorkMode(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t Mode)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT((Mode == MODE_RT_DEAD_TIMER));
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & WFG_WFSA_TMD) | (Mode << 3);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & WFG_WFSA_TMD) | (Mode << 3);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & WFG_WFSA_TMD) | (Mode << 3);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Check the CH_GATE signal generate or not (WFSA_GATE bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg    MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg    [WFG_CH10, WFG_CH54]
 **
 ** \retval Gaten value. if value is 0, Does not generate the CH_GATE signal,
 ** 		or not, the signal was be generate
 *****************************************************************************
*/
uint8_t MFT_WfgGetChGateEnFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & ~(WFG_WFSA_GTEN);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & ~(WFG_WFSA_GTEN);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & ~(WFG_WFSA_GTEN);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 6);
}

/*!
 ******************************************************************************
 ** \brief  Check the CH_GATE signal generate or not (WFSA_GATE bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg    MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg    [WFG_CH10, WFG_CH54]
 ** \param  Gaten value,
 ** 
 ** \retval none
 **
 *****************************************************************************
*/
uint8_t MFT_WfgSetChGateEnFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t Gaten)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & WFG_WFSA_GTEN) | (Gaten << 6);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & WFG_WFSA_GTEN) | (Gaten << 6);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & WFG_WFSA_GTEN) | (Gaten << 6);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the PPG timer unit to be used at each channel of WFG.(WFSA_PSEL bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  timer value
 ** \retval  PPG_TMR0,PPG_TMR2,PPG_TMR4,PPG_DIS
 *****************************************************************************
*/
uint8_t MFT_WfgGetPPGTimerUnit(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT(Div <= WFG_DIV6);
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & ~(WFG_WFSA_PSEL);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & ~(WFG_WFSA_PSEL);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & ~(WFG_WFSA_PSEL);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 8);
}

/*!
 ******************************************************************************
 ** \brief  Set the PPG timer unit to be used at each channel of WFG.(WFSA_PSEL bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  timer value
 ** \arg    PPG_TMR0,PPG_TMR2,PPG_TMR4,PPG_DIS
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetPPGTimerUnit(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t timer)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT(Div <= WFG_DIV6);
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & WFG_WFSA_PSEL) | (timer << 8);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & WFG_WFSA_PSEL) | (timer << 8);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & WFG_WFSA_PSEL) | (timer << 8);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the CH_PPG signal that is input to each channel of WFG on WFG output(WFSA_PGEN bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  state value 0 -  Does not reflect; others - reflect, in combination with WFSA.TMD[2:0]
 *****************************************************************************
*/
uint8_t MFT_WfgGetChGateFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT(Div <= WFG_DIV6);
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & ~(WFG_WFSA_PGEN);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & ~(WFG_WFSA_PGEN);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & ~(WFG_WFSA_PGEN);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 10);
}

/*!
 ******************************************************************************
 ** \brief  Set the CH_PPG signal that is input to each channel of WFG on WFG output(WFSA_PGEN bit register)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  state
 ** \arg    0, others
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetChGateFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t state)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT(Div <= WFG_DIV6);
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & WFG_WFSA_PGEN) | (state << 10);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & WFG_WFSA_PGEN) | (state << 10);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & WFG_WFSA_PGEN) | (state << 10);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read non-overlapped output signal polarity for WFGxx.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return polarity  Non-overlapped output signal polarity
 ** \retval    LEVEL_LOW, LEVEL_HIGH
 *****************************************************************************
*/
uint8_t MFT_WfgGetPolarity(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT((HIGH_LEVEL == Level) || (LOW_LEVEL == Level));
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & ~(WFG_WFSA_DMOD);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & ~(WFG_WFSA_DMOD);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & ~(WFG_WFSA_DMOD);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 12);
}

/*!
 ******************************************************************************
 ** \brief  Set non-overlapped output signal polarity for WFGxx.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  polarity  Non-overlapped output signal polarity
 ** \arg    LEVEL_LOW, LEVEL_HIGH
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetPolarity(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t Polarity)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
    ASSERT((LEVEL_HIGH == Polarity) || (LEVEL_LOW == Polarity));
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA10 & WFG_WFSA_DMOD) | (Polarity << 12);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA32 & WFG_WFSA_DMOD) | (Polarity << 12);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 = (pFM3_MFT_WFG_BASE[WhichMFT]->WFSA54 & WFG_WFSA_DMOD) | (Polarity << 12);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the initial value of the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \retval Val initial value of the WFG timer
 *****************************************************************************
*/
uint16_t MFT_WfgTimerValueRead(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
#endif

    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = (pFM3_MFT_WFG_BASE[WhichMFT]->WFTM10);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = (pFM3_MFT_WFG_BASE[WhichMFT]->WFTM32);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = (pFM3_MFT_WFG_BASE[WhichMFT]->WFTM54);
    }
    else
    {
    	temp = WFG_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Configure the initial value of the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Val initial value of the WFG timer
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgTimerValueWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint16_t Val)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichWFGxx <= WFG_CH54);
#endif

    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFTM10 = Val;
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFTM32 = Val;
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFTM54 = Val;
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the state of DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return En
 ** \retval TRUE,FALSE
 *****************************************************************************
*/
uint8_t MFT_WfgGetDtifIntFnct(volatile uint8_t WhichMFT)
{
    uint16_t temp;

    temp = pFM3_MFT_WFG_BASE[WhichMFT]->NZCL & ~(WFG_NZCL_DTIE);
    return (uint8_t)(temp);
}

/*!
 ******************************************************************************
 ** \brief  Set the state of DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  En
 ** \arg    TRUE,FALSE
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetDtifIntFnct(volatile uint8_t WhichMFT,volatile uint8_t En)
{
	pFM3_MFT_WFG_BASE[WhichMFT]->NZCL  = (pFM3_MFT_WFG_BASE[WhichMFT]->NZCL & WFG_NZCL_DTIE) | En;
    return 1;
}

/*!
 ******************************************************************************
 ** \brief  Read the noise-canceling width of the noise-canceler for the
 **         DTTIX pin input signal(NWS)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return width
 ** \retval [DTTI_NOISE_TIME0, DTTI_NOISE_TIME4]
 *****************************************************************************
*/
uint8_t MFT_WfgGetNoiseCancelWidth(volatile uint8_t WhichMFT)
{
    uint16_t temp;
    temp = pFM3_MFT_WFG_BASE[WhichMFT]->NZCL & ~(WFG_NZCL_NWS);

    return (uint8_t)(temp >> 1);
}

/*!
 ******************************************************************************
 ** \brief   Sets the noise-canceling width of the noise-canceler for the
 **          DTTIX pin input signal(NWS)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  width
 ** \arg    [DTTI_NOISE_TIME0, DTTI_NOISE_TIME4]
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetNoiseCancelWidth(volatile uint8_t WhichMFT,volatile uint8_t width)
{
	pFM3_MFT_WFG_BASE[WhichMFT]->NZCL  = (pFM3_MFT_WFG_BASE[WhichMFT]->NZCL & WFG_NZCL_NWS) | (width << 1);
    return 1;
}

/*!
 ******************************************************************************
 ** \brief  Forcibly generates DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetForceDtifIsr(volatile uint8_t WhichMFT)
{
	pFM3_MFT_WFG_BASE[WhichMFT]->NZCL  = (pFM3_MFT_WFG_BASE[WhichMFT]->NZCL & WFG_NZCL_SDTI) | (1 << 4);
    return 1;
}

/*!
 ******************************************************************************
 ** \brief  Read the state of DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return En
 ** \retval TRUE,FALSE
 *****************************************************************************
*/
uint8_t MFT_WfgGetDtifIntFlag(volatile uint8_t WhichMFT)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
#endif

    uint16_t temp;
    temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & ~(WFG_WFIR_DTIF);

    return (uint8_t)(temp >> 0);
}

/*!
 ******************************************************************************
 ** \brief  Clean the DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgClrDtifIntFlag(volatile uint8_t WhichMFT)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
#endif

	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_DTIC) | (1 << 1);
    return 1;
}

/*!
 ******************************************************************************
 ** \brief  Get the flag of WFG timer interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return En
 ** \retval TRUE,FALSE
 *****************************************************************************
*/
uint8_t MFT_WfgGetTmrIntFlag(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx)
{
    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & ~(WFG_WFIR_TMIF10);
    	return (uint8_t)(temp >> 4);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & ~(WFG_WFIR_TMIF32);
    	return (uint8_t)(temp >> 8);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & ~(WFG_WFIR_TMIF54);
    	return (uint8_t)(temp >> 12);
    }
    else
    {
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif

    temp = WFG_NONE;
    return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Clear the flag of WFG timer interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgClrTmrIntFlag(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx)
{
    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIC10) | (1 << 5);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIC32) | (1 << 9);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIC54) | (1 << 13);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read the state of WFG(starts or not)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return state
 ** \retval  WFG_STOP, WFG_OPER
 *****************************************************************************
*/
uint8_t MFT_WfgGetTmrState(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx)
{
    uint16_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & ~(WFG_WFIR_TMIE10);
    	return (uint8_t)(temp >> 6);
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & ~(WFG_WFIR_TMIE32);
    	return (uint8_t)(temp >> 10);
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	temp = pFM3_MFT_WFG_BASE[WhichMFT]->WFIR &= ~(WFG_WFIR_TMIE54);
    	return (uint8_t)(temp >> 14);
    }
    else
    {
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif

    temp = WFG_NONE;
    return (uint8_t)(temp);
    }
}

/*!
 ******************************************************************************
 ** \brief  Start the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  state
 ** \arg    WFG_STOP, WFG_OPER
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetTmrState(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx,volatile uint8_t En)
{
    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIE10) | (1 << 6);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIE32) | (1 << 10);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIE54) | (1 << 14);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Stop the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgStopTmr(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx)
{
    uint8_t temp;
    if(WhichWFGxx == WFG_CH10)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR  = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIS10) | (1 << 7);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH32)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIS32) | (1 << 11);
    	temp = TRUE;
    }
    else if(WhichWFGxx == WFG_CH54)
    {
    	pFM3_MFT_WFG_BASE[WhichMFT]->WFIR = (pFM3_MFT_WFG_BASE[WhichMFT]->WFIR & WFG_WFIR_TMIS54) | (1 << 15);
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_WFG)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief WFG interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_Wfg_IRQHandler(void)
{
    uint16_t irq;

    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint16_t)(FM3_INTREQ->IRQ03MON);

    if((irq & 0x000E) != 0)
    {
        WFG_IrqHandler(MFT0,irq);
    }

    if((irq & 0x00E0) != 0)
    {
        WFG_IrqHandler(MFT1,irq);
    }

    return;
}

/*!
 ******************************************************************************
 ** \brief DTTI interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_DTTI_IRQHandler(void)
{
    uint16_t irq;

    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint16_t)(FM3_INTREQ->IRQ03MON);

    if((irq & 0x0001) != 0)
    {
    	DTTI_IrqHandler(MFT0,irq);
    }

    if((irq & 0x0010) != 0)
    {
    	DTTI_IrqHandler(MFT1,irq);
    }

    return;
}

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief   WFG interrupt handler sub function
 **
 ** \param   WhichMFT Which MFT will be configured
 ** \arg     MFT0,MFT1
 ** \param   IrqValue irq number value
 **
 ** \retval  None
 **
 ******************************************************************************
 */
static void WFG_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue)
{
    /* Trigger WFG timer 10 Interrupt */
     if(SET == (IrqValue >> (1 + WhichMFT*4)))
     {
        /* Clear Interrupt */
         MFT_WfgClrTmrIntFlag(WhichMFT,WFG_CH10);
        if(WFG_IntCallback[WhichMFT] != NULL)
        {
             /* Call CallBackIrq */
            WFG_IntCallback[WhichMFT](WFG_INT_CH10);
        }
     }

     /* Trigger WFG timer 32 Interrupt */
     if(SET == (IrqValue >> (2 + WhichMFT*4)))
     {
        /* Clear Interrupt */
         MFT_WfgClrTmrIntFlag(WhichMFT,WFG_CH32);
        if(WFG_IntCallback[WhichMFT] != NULL)
        {
             /* Call CallBackIrq */
            WFG_IntCallback[WhichMFT](WFG_INT_CH32);
        }
     }

     /* Trigger WFG timer 54 Interrupt */
     if(SET == (IrqValue >> (3 + WhichMFT*4)))
     {
         /* Clear Interrupt */
         MFT_WfgClrTmrIntFlag(WhichMFT,WFG_CH54);
        if(WFG_IntCallback[WhichMFT] != NULL)
        {
             /* Call CallBackIrq */
            WFG_IntCallback[WhichMFT](WFG_INT_CH54);
        }
     }

     return;
}

/*!
 ******************************************************************************
 ** \brief   WFG interrupt handler sub function
 **
 ** \param   WhichMFT Which MFT will be configured
 ** \arg     MFT0,MFT1
 ** \param   IrqValue irq number value
 **
 ** \retval  None
 **
 ******************************************************************************
 */
static void DTTI_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue)
{
    /* Trigger WFG timer 10 Interrupt */
     if(SET == (IrqValue >> WhichMFT*4 ))
     {
        /* Clear Interrupt */
         MFT_WfgClrDtifIntFlag(WhichMFT);
        if(DTTI_IntCallback[WhichMFT] != NULL)
        {
               /* Call CallBackIrq */
              DTTI_IntCallback[WhichMFT]();
        }
     }

     return;
}

/*****************************************************************************/
/* END OF FILE */
