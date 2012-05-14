/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_frt_fm3.c
 **
 ** \brief Free-run Timer Unit all cell drivers file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-9 10:50
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
#include "mft_frt_fm3.h"

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void FRT_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue);

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FM3_MFT_FRT_TypeDef* pFM3_MFT_FRT_BASE[MFT_AMOUNT] =
{
    (FM3_MFT_FRT_TypeDef*)(FM3_MFT0_FRT_BASE),
    (FM3_MFT_FRT_TypeDef*)(FM3_MFT1_FRT_BASE)
};

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
FRT_CallbackT FRT_IntCallback[] = { NULL, NULL};

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Read division value for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return  FRT division value
 ** \retval  [FRT_DIV0, FRT_DIV8]
 *****************************************************************************
*/
uint8_t MFT_FrtDivRead(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_CLK);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_CLK);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_CLK);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp);
}

/*!
 ******************************************************************************
 ** \brief  Configure division value for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Div Division value
 ** \arg 	[FRT_DIV0, FRT_DIV8]
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtDivWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t Div)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT(Div <= FRT_DIV8);
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_CLK) | Div;
    	temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_CLK) | Div;
    	temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_CLK) | Div;
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
     return temp;
}

/*!
 ******************************************************************************
 ** \brief  Initialize FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En  Enable or not
 ** \arg 	TRUE,FALSE
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtInit(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_SCLR) | (En << 4);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_SCLR) | (En << 4);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_SCLR) | (En << 4);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get count mode for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT count mode
 ** \retval CNT_MODE_UP
 ** \retval CNT_MODE_UPDOWN
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetCntMode(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_MODE);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_MODE);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_MODE);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 5);
}

/*!
 ******************************************************************************
 ** \brief  Set count mode for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Mode  Count mode.
 ** \arg    CNT_MODE_UP,CNT_MODE_UPDOWN
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetCntMode(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t Mode)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((CNT_MODE_UP == Mode) || (CNT_MODE_UPDOWN == Mode));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_MODE) | (Mode << 5);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_MODE) | (Mode << 5);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_MODE) | (Mode << 5);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
     return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get FRT STOP register state
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT STOP register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetStopReg(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_STOP);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_STOP);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_STOP);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }

    return (uint8_t)(temp >> 6);;
}

/*!
 ******************************************************************************
 ** \brief  Set FRT STOP register state
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetStopReg(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((TRUE == En) || (FALSE == En));
#endif
    
    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_STOP) | (En << 6);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_STOP) | (En << 6);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_STOP) | (En << 6);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
     return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get TCCP buffer enable state for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_BFE);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_BFE);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_BFE);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return (uint8_t)(temp >> 7); ;
}

/*!
 ******************************************************************************
 ** \brief  Set TCCP buffer enable state for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return TRUE,FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetTCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_BFE) | (En << 7);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_BFE) | (En << 7);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_BFE) | (En << 7);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get interrupt state for FRTx when TCCP matches FRT count value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTopIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_ICRE) ;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_ICRE) ;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_ICRE) ;
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return (uint8_t)(temp >> 8);
}

/*!
 ******************************************************************************
 ** \brief  Set interrupt function for FRTx when TCCP matches FRT count value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return TRUE,FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetTopIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_ICRE) | (En << 8);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_ICRE) | (En << 8);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_ICRE) | (En << 8);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;    
}

/*!
 ******************************************************************************
 ** \brief  Get FRT top-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTopIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_ICLR);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_ICLR);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_ICLR);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return (uint8_t)(temp >> 9); ;
}

/*!
 ******************************************************************************
 ** \brief  Clear FRT top-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtClrTopIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_ICLR) | 0;
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_ICLR) | 0;
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_ICLR) | 0;
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get interrupt state for FRTx when FRT count value reaches 0
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetZeroIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_IRQZE);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_IRQZE);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_IRQZE);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return (uint8_t)(temp >> 13); ;
}

/*!
 ******************************************************************************
 ** \brief  Set interrupt function for FRTx when FRT count value reaches 0
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetZeroIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_IRQZE) | (En << 13);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_IRQZE) | (En << 13);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_IRQZE) | (En << 13);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get FRT 0-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetZeroIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_IRQZF);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_IRQZF);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_IRQZF);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return (uint8_t)(temp >> 14);
}

/*!
 ******************************************************************************
 ** \brief  Clear FRT 0-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtClrZeroIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_IRQZF) | 0;
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_IRQZF) | 0;
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_IRQZF) | 0;
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the FRT’s count clock origin
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval InterClk
 ** \retval ExterClk
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetCLKOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & ~(FRT_ECKE);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & ~(FRT_ECKE);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & ~(FRT_ECKE);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return (uint8_t)(temp >> 15); ;
}

/*!
 ******************************************************************************
 ** \brief  Set the FRT’s count clock origin
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Origin the clock signal origin
 ** \arg    InterClk,ExterClk
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetCLKOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t Origin)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA0 & FRT_ECKE) | (Origin << 15);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA1 & FRT_ECKE) | (Origin << 15);
        temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
        pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSA2 & FRT_ECKE) | (Origin << 15);
        temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get state of output convert ADC start signal when 0-detected INT comes
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  WhichADC Start signal send to which ADC unit
 ** \arg    ADC_UNIT0, ADC_UNIT1, ADC_UNIT2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTrigADCFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
							     volatile uint8_t WhichADC)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((ADC_UNIT0 == WhichADC) || (ADC_UNIT1 == WhichADC) || (ADC_UNIT2 == WhichADC));
#endif
    
    uint16_t temp;
    if((ADC_UNIT0 == WhichADC)&&((WhichFRTCh == FRT_CH0)||(WhichFRTCh == FRT_CH1)||(WhichFRTCh == FRT_CH2)))
    {
        temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 & ~(FRT_AD0E);
        return (uint8_t)(temp);
    }
    else if((ADC_UNIT1 == WhichADC)&&((WhichFRTCh == FRT_CH0)||(WhichFRTCh == FRT_CH1)||(WhichFRTCh == FRT_CH2)))
    {
        temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 & ~(FRT_AD1E);
        return (uint8_t)(temp >> 1);
    }
    else if((ADC_UNIT2 == WhichADC)&&((WhichFRTCh == FRT_CH0)||(WhichFRTCh == FRT_CH1)||(WhichFRTCh == FRT_CH2)))
    {
        temp = pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 & ~(FRT_AD2E);
        return (uint8_t)(temp >> 2);
    }
    else 
    {
      return (temp = FALSE);
    }
}

/*!
 ******************************************************************************
 ** \brief  Enable output convert ADC start signal when 0-detected INT comes.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Origin the clock signal origin
 ** \arg    InterClk,ExterClk
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetTrigADCFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
			   volatile uint8_t WhichADC, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
    ASSERT((ADC_UNIT0 == WhichADC) || (ADC_UNIT1 == WhichADC) || (ADC_UNIT2 == WhichADC));
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if((ADC_UNIT0 == WhichADC)&&((WhichFRTCh == FRT_CH0)||(WhichFRTCh == FRT_CH1)||(WhichFRTCh == FRT_CH2)))
    {
		pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 & FRT_AD0E) | (En << 0) ;
		temp = TRUE;
    }
    else if((ADC_UNIT1 == WhichADC)&&((WhichFRTCh == FRT_CH0)||(WhichFRTCh == FRT_CH1)||(WhichFRTCh == FRT_CH2)))
    {
		pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 & FRT_AD1E) | (En << 1) ;
		temp = TRUE;
    }
    else if((ADC_UNIT2 == WhichADC)&&((WhichFRTCh == FRT_CH0)||(WhichFRTCh == FRT_CH1)||(WhichFRTCh == FRT_CH2)))
    {
		pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 = (pFM3_MFT_FRT_BASE[WhichMFT]->TCSB0 & FRT_AD2E) | (En << 2) ;
		temp = TRUE;
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Read FRTx count peak value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TCCP value
 **
 *****************************************************************************
*/
uint16_t MFT_FrtTCCPRead(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = (pFM3_MFT_FRT_BASE[WhichMFT]->TCCP0);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = (pFM3_MFT_FRT_BASE[WhichMFT]->TCCP1);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = (pFM3_MFT_FRT_BASE[WhichMFT]->TCCP2);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Write FRTx count peak value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  val
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtTCCPWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint16_t val)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCCP0 = val;
    	temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCCP1 = val;
    	temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCCP2 = val;
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Reads FRT’s current count value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TCDT value
 **
 *****************************************************************************
*/
uint16_t MFT_FrtTCDTRead(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint16_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	temp = (pFM3_MFT_FRT_BASE[WhichMFT]->TCDT0);
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	temp = (pFM3_MFT_FRT_BASE[WhichMFT]->TCDT1);
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	temp = (pFM3_MFT_FRT_BASE[WhichMFT]->TCDT2);
    }
    else
    {
    	temp = FRT_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Clean FRT’s current count value(set current count value as 0)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TRUE,FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtClrTCDT(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint8_t temp;
    if(WhichFRTCh == FRT_CH0)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCDT0 = 0;
    	temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH1)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCDT1 = 0;
    	temp = TRUE;
    }
    else if(WhichFRTCh == FRT_CH2)
    {
    	pFM3_MFT_FRT_BASE[WhichMFT]->TCDT2 = 0;
    	temp = TRUE;
    }
    else
    {
    	temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT(FALSE);
#endif
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Start FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_FrtStart(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    MFT_FrtSetStopReg(WhichMFT, WhichFRTCh, FALSE);
    MFT_FrtInit(WhichMFT, WhichFRTCh, FALSE);

    return;
}

/*!
 ******************************************************************************
 ** \brief  Stop FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_FrtStop(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    MFT_FrtSetStopReg(WhichMFT, WhichFRTCh, TRUE);
    MFT_FrtInit(WhichMFT, WhichFRTCh, TRUE);

    MFT_FrtClrTCDT(WhichMFT, WhichFRTCh);// set count value to zero

    return;
}

/*!
 ******************************************************************************
 ** \brief  Set count cycle for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  ms count cycle(ms)
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_FrtSetCntCycle(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile float ms)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_FRT)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif
    volatile uint8_t mode = 0;
    volatile uint8_t Div = 0;
    volatile uint8_t PCLK = 0;
    volatile uint16_t TCCPvalue = 0;

    mode = MFT_FrtGetCntMode(WhichMFT,WhichFRTCh);
    Div = MFT_FrtDivRead(WhichMFT,WhichFRTCh);
    PCLK = SystemCoreClock/(uint32_t)(&FM3_CRG->APBC1_PSR);

    if(CNT_MODE_UP == mode)
    {
        TCCPvalue = (uint16_t)((ms * PCLK * 1000 ) / (1 << Div));
        MFT_FrtTCCPWrite(WhichMFT,WhichFRTCh, TCCPvalue);
    }

    if(CNT_MODE_UPDOWN == mode)
    {
        TCCPvalue = (uint16_t)((ms * PCLK * 500 ) / (1 << Div));
        MFT_FrtTCCPWrite(WhichMFT,WhichFRTCh, TCCPvalue);
    }

    return;
}

/*!
 ******************************************************************************
 ** \brief FRT interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_Frt_IRQHandler(void)
{
    uint16_t irq;

    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint16_t)(FM3_INTREQ->IRQ28MON);

    if((irq & 0x003F) != 0)
    {
        FRT_IrqHandler(MFT0,irq);
    }

    if((irq & 0x0FC0) != 0)
    {
        FRT_IrqHandler(MFT1,irq);
    }

    return;
}

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief   FRT interrupt handler sub function
 **
 ** \param   WhichMFT Which MFT will be configured
 ** \arg     MFT0,MFT1
 ** \param   IrqValue irq number value
 **
 ** \retval  None
 **
 ******************************************************************************
 */
static void FRT_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue)
{
     /* Trigger FRT channel 0 top Interrupt */
     if(SET == (IrqValue >> (0 + WhichMFT*6)))
     {
          /* Clear Interrupt */
          MFT_FrtClrTopIntFlag(WhichMFT,FRT_CH0);
          if(FRT_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              FRT_IntCallback[WhichMFT](FRT_INT_TOP_CH0);
          }
     }

     /* Trigger FRT channel 1 top Interrupt */
     if(SET == (IrqValue >> (1 + WhichMFT*6)))
     {
          /* Clear Interrupt */
          MFT_FrtClrTopIntFlag(WhichMFT,FRT_CH1);
          if(FRT_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              FRT_IntCallback[WhichMFT](FRT_INT_TOP_CH1);
          }
     }

     /* Trigger FRT channel 2 top Interrupt */
     if(SET == (IrqValue >> (2 + WhichMFT*6)))
     {
           /* Clear Interrupt */
          MFT_FrtClrTopIntFlag(WhichMFT,FRT_CH2);
          if(FRT_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              FRT_IntCallback[WhichMFT](FRT_INT_TOP_CH2);
          }
     }

     /* Trigger FRT channel 0 zero Interrupt */
     if(SET == (IrqValue >> (3 + WhichMFT*6)))
     {
          /* Clear Interrupt */
          MFT_FrtClrZeroIntFlag(WhichMFT,FRT_CH0);
          if(FRT_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              FRT_IntCallback[WhichMFT](FRT_INT_ZERO_CH0);
          }
     }

     /* Trigger FRT channel 1 zero Interrupt */
     if(SET == (IrqValue >> (4 + WhichMFT*6)))
     {
          /* Clear Interrupt */
          MFT_FrtClrZeroIntFlag(WhichMFT,FRT_CH1);
          if(FRT_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              FRT_IntCallback[WhichMFT](FRT_INT_ZERO_CH1);
          }
     }

     /* Trigger FRT channel 2 zero Interrupt */
     if(SET == (IrqValue >> (5 + WhichMFT*6)))
     {
          /* Clear Interrupt */
          MFT_FrtClrZeroIntFlag(WhichMFT,FRT_CH2);
          if(FRT_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              FRT_IntCallback[WhichMFT](FRT_INT_ZERO_CH2);
          }
     }

     return;
}

/*****************************************************************************/
/* END OF FILE */
