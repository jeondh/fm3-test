/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_ocu_fm3.c
 **
 ** \brief Output Compare Unit all cell drivers file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-11 10:15
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
#include "mft_ocu_fm3.h"

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void OCU_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue);

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FM3_MFT_OCU_TypeDef* pFM3_MFT_OCU_BASE[MFT_AMOUNT] =
{
    (FM3_MFT_OCU_TypeDef*)(FM3_MFT0_OCU_BASE),
    (FM3_MFT_OCU_TypeDef*)(FM3_MFT1_OCU_BASE)
};

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
OCU_CallbackT OCU_IntCallback[] = { NULL, NULL};


/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Read register value that OCU channel connect to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Which FRT channel to configure
 ** \retval  FTR_CH0, FTR_CH1, FTR_CH2
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetFrtCh(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 & ~(OCU_OCFS_FSO0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCFS32 & ~(OCU_OCFS_FSO0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCFS54 & ~(OCU_OCFS_FSO0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp);
    }
    else
    {
        if(WhichOCCh == OC_CH1)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 & ~(OCU_OCFS_FSO1);
        }
        else if(WhichOCCh == OC_CH3)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCFS32 & ~(OCU_OCFS_FSO1);
        }
        else if(WhichOCCh == OC_CH5)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCFS54 & ~(OCU_OCFS_FSO1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 4);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set register value that OCU channel connect to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetFrtCh(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
    ASSERT((FRT_CH0 == WhichFRTCh) || (FRT_CH1 == WhichFRTCh) || (FRT_CH2 == WhichFRTCh));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 & OCU_OCFS_FSO0) | (WhichFRTCh << 0);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCFS32 & OCU_OCFS_FSO0) | (WhichFRTCh << 0);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCFS54 & OCU_OCFS_FSO0) | (WhichFRTCh << 0);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH1)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 & OCU_OCFS_FSO1) | (WhichFRTCh << 4);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH3)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCFS32 & OCU_OCFS_FSO1) | (WhichFRTCh << 4);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH5)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCFS10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCFS54 & OCU_OCFS_FSO1) | (WhichFRTCh << 4);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get state of OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetState(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_CST0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_CST0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_CST0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp);
    }
    else
    {
        if(WhichOCCh == OC_CH1)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_CST1);
        }
        else if(WhichOCCh == OC_CH3)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_CST1);
        }
        else if(WhichOCCh == OC_CH5)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_CST1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 1);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set state of OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetState(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_CST0) | (En << 0);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_CST0) | (En << 0);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_CST0) | (En << 0);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_CST1) | (En << 1);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_CST1) | (En << 1);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_CST1) | (En << 1);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Start OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_OcuStart(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif
    
    MFT_OcuSetState(WhichMFT, WhichOCCh, TRUE);

    return;
}

/*!
 ******************************************************************************
 ** \brief  Stop OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_OcuStop(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif
    
    MFT_OcuSetState(WhichMFT, WhichOCCh, FALSE);

    return;
}

/*!
 ******************************************************************************
 ** \brief  Get OCCP buffer enable state for OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetOCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_BDIS0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_BDIS0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_BDIS0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 2);
    }
    else
    {
        if(WhichOCCh == OC_CH1)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_BDIS1);
        }
        else if(WhichOCCh == OC_CH3)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_BDIS1);
        }
        else if(WhichOCCh == OC_CH5)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_BDIS1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 3);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set OCCP buffer enable state for OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetOCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_BDIS0) | (En << 2);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_BDIS0) | (En << 2);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_BDIS0) | (En << 2);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_BDIS1) | (En << 3);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_BDIS1) | (En << 3);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_BDIS1) | (En << 3);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get interrupt is enabled or disabled for each OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_IOE0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_IOE0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_IOE0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 4);
    }
    else
    {
        if(WhichOCCh == OC_CH1)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_IOE1);
        }
        else if(WhichOCCh == OC_CH3)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_IOE1);
        }
        else if(WhichOCCh == OC_CH5)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_IOE1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 5);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set enable or disable interrupt for each OCU channel when OCCP matches FRT count
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
    ASSERT((TRUE == En) || (FALSE == En));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_IOE0) | (En << 4);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_IOE0) | (En << 4);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_IOE0) | (En << 4);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_IOE1) | (En << 5);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_IOE1) | (En << 5);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_IOE1) | (En << 5);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get interrupt flag for each OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_IOP0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_IOP0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_IOP0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 6);
    }
    else
    {
        if(WhichOCCh == OC_CH1)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & ~(OCU_OCSA_IOP1);
        }
        else if(WhichOCCh == OC_CH3)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & ~(OCU_OCSA_IOP1);
        }
        else if(WhichOCCh == OC_CH5)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & ~(OCU_OCSA_IOP1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 7);
    }
}

/*!
 ******************************************************************************
 ** \brief  Clear interrupt flag for each OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuClrIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_IOP0) | (0 << 6);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_IOP0) | (0 << 6);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_IOP0) | (0 << 6);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA10 & OCU_OCSA_IOP1) | (0 << 7);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA32 & OCU_OCSA_IOP1) | (0 << 7);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSA54 & OCU_OCSA_IOP1) | (0 << 7);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the initial output level for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Level initial output level
 ** \retval HIGH_LEVEL, LOW_LEVEL
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetOutputLevel(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & ~(OCU_OCSB_OTD0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & ~(OCU_OCSB_OTD0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & ~(OCU_OCSB_OTD0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 0);
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & ~(OCU_OCSB_OTD1);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & ~(OCU_OCSB_OTD1);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & ~(OCU_OCSB_OTD1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 1);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set the initial output level for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  Level initial output level
 ** \arg    HIGH_LEVEL, LOW_LEVEL
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetOutputLevel(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t Level)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
    ASSERT((HIGH_LEVEL == Level) || (LOW_LEVEL == Level));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & OCU_OCSB_OTD0) | (Level << 0);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & OCU_OCSB_OTD0) | (Level << 0);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & OCU_OCSB_OTD0) | (Level << 0);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & OCU_OCSB_OTD1) | (Level << 1);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & OCU_OCSB_OTD1) | (Level << 1);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & OCU_OCSB_OTD1) | (Level << 1);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the CMOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return register value
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetCMODReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if((WhichOCCh == OC_CH0) || (WhichOCCh == OC_CH1))
    {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & ~(OCU_OCSB_CMOD);
    }
    else if((WhichOCCh == OC_CH2) || (WhichOCCh == OC_CH3))
    {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & ~(OCU_OCSB_CMOD);
    }
    else if((WhichOCCh == OC_CH4) || (WhichOCCh == OC_CH5))
    {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & ~(OCU_OCSB_CMOD);
    }
    else
    {
            temp = OC_NONE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
    ASSERT(FALSE);
#endif
    }
    return (temp >> 4);
}

/*!
 ******************************************************************************
 ** \brief  Set the CMOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetCMODReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if((WhichOCCh == OC_CH0) || (WhichOCCh == OC_CH1))
    {
        pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & OCU_OCSB_CMOD) | (En << 4);
        temp = TRUE;
    }
    else if((WhichOCCh == OC_CH2) || (WhichOCCh == OC_CH3))
    {
        pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & OCU_OCSB_CMOD) | (En << 4);
        temp = TRUE;
    }
    else if((WhichOCCh == OC_CH4) || (WhichOCCh == OC_CH5))
    {
        pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & OCU_OCSB_CMOD) | (En << 4);
        temp = TRUE;
    }
    else
    {
        temp = FALSE;
#if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
    ASSERT(FALSE);
#endif
    }
    return temp ;
}

/*!
 ******************************************************************************
 ** \brief  Get the timing when data in OCCP buffer send to OCCP for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return When Timing of send buffer
 ** \retval CNT_TOP, CNT_BOTTOM
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & ~(OCU_OCSB_BTS0);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & ~(OCU_OCSB_BTS0);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & ~(OCU_OCSB_BTS0);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 5);
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & ~(OCU_OCSB_BTS1);
        }
        else if(WhichOCCh == OC_CH2)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & ~(OCU_OCSB_BTS1);
        }
        else if(WhichOCCh == OC_CH4)
        {
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & ~(OCU_OCSB_BTS1);
        }
        else
        {
            temp = OC_NONE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
        return (temp >> 6);
    }
}

/*!
 ******************************************************************************
 ** \brief  Set the timing when data in OCCP buffer send to OCCP for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  When Timing of send buffer
 ** \arg CNT_TOP, CNT_BOTTOM
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t When)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
    ASSERT((CNT_TOP == When) || (CNT_BOTTOM == When));
#endif

    uint8_t temp;
    if(0 == WhichOCCh % 2)
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & OCU_OCSB_BTS0) | (When << 5);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & OCU_OCSB_BTS0) | (When << 5);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & OCU_OCSB_BTS0) | (When << 5);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    else
    {
        if(WhichOCCh == OC_CH0)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB10 & OCU_OCSB_BTS1) | (When << 6);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH2)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB32 & OCU_OCSB_BTS1) | (When << 6);
            temp = TRUE;
        }
        else if(WhichOCCh == OC_CH4)
        {
            pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSB54 & OCU_OCSB_BTS1) | (When << 6);
            temp = TRUE;
        }
        else
        {
            temp = FALSE;
    #if(DEBUG_MODE && DEBUG_DRV_MFT_OCU)
        ASSERT(FALSE);
    #endif
        }
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Get the MOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return When Timing of send buffer
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetMODOperateReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    uint8_t temp = 0;
    temp = (pFM3_MFT_OCU_BASE[WhichMFT]->OCSC >> WhichOCCh) & 0x01;
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Set the MOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetMODOperateReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t En)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif

    if(En == TRUE)
    {
        pFM3_MFT_OCU_BASE[WhichMFT]->OCSC = pFM3_MFT_OCU_BASE[WhichMFT]->OCSC | (1 << WhichOCCh);
    }
    else
    {
        pFM3_MFT_OCU_BASE[WhichMFT]->OCSC = pFM3_MFT_OCU_BASE[WhichMFT]->OCSC | ~(1 << WhichOCCh);
    }
    return 1;
}

/*!
 ******************************************************************************
 ** \brief  Set work mode for RTx.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  COMD
 ** \arg    TRUE, FALSE
 ** \param  MOD
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_OcuSetWorkMode(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint8_t CMODE, volatile uint8_t MOD)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT((0 == CMODE) || (1 == CMODE));
    ASSERT((0 == MOD) || (1 == MOD));
#endif

    MFT_OcuSetCMODReg(WhichMFT,WhichOCCh,CMODE);
    MFT_OcuSetMODOperateReg(WhichMFT,WhichOCCh,MOD);

    return;
}

/*!
 ******************************************************************************
 ** \brief  Get OCCP value for RTx corresponding to OC channelx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \retval RegVal Register value
 **
 *****************************************************************************
*/
uint16_t MFT_OcuOCCPValueRead(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif
    uint16_t temp;
    switch(WhichOCCh)
    {
    case OC_CH0:
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCCP0;
            break;
    case OC_CH1:
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCCP1;
            break;
    case OC_CH2:
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCCP2;
            break;
    case OC_CH3:
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCCP3;
            break;
    case OC_CH4:
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCCP4;
            break;
    case OC_CH5:
            temp = pFM3_MFT_OCU_BASE[WhichMFT]->OCCP5;
            break;
    default:
            temp = OC_NONE;
            break;
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief  Set OCCP value for RTx corresponding to OC channelx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  RegVal
 **
 ** \retval none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuOCCPValueWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh, volatile uint16_t RegVal)
{
#if(DEBUG_MODE && DEBUG_DRV_MFT_OC)
    ASSERT((MFT0 == WhichMFT) || (MFT1 == WhichMFT));
    ASSERT(WhichOCCh <= OC_CH5);
#endif
    
    uint8_t temp;
    switch(WhichOCCh)
    {
    case OC_CH0:
            pFM3_MFT_OCU_BASE[WhichMFT]->OCCP0 = RegVal;
            temp = TRUE;
            break;
    case OC_CH1:
    	    pFM3_MFT_OCU_BASE[WhichMFT]->OCCP1 = RegVal;
            break;
    case OC_CH2:
			pFM3_MFT_OCU_BASE[WhichMFT]->OCCP2 = RegVal;
			temp = TRUE;
            break;
    case OC_CH3:
			pFM3_MFT_OCU_BASE[WhichMFT]->OCCP3 = RegVal;
			temp = TRUE;
            break;
    case OC_CH4:
			pFM3_MFT_OCU_BASE[WhichMFT]->OCCP4 = RegVal;
			temp = TRUE;
            break;
    case OC_CH5:
			pFM3_MFT_OCU_BASE[WhichMFT]->OCCP5 = RegVal;
			temp = TRUE;
            break;
    default:
            temp = FALSE;
            break;
    }
    return temp;
}

/*!
 ******************************************************************************
 ** \brief OCU interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_Ocu_IRQHandler(void)
{
    uint16_t irq;

    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint16_t)(FM3_INTREQ->IRQ30MON);

    if((irq & 0x003F) != 0)
    {
        OCU_IrqHandler(MFT0,irq);
    }

    if((irq & 0x0FC0) != 0)
    {
        OCU_IrqHandler(MFT1,irq);
    }

    return;
}

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief   OCU interrupt handler sub function
 **
 ** \param   WhichMFT Which MFT will be configured
 ** \arg     MFT0,MFT1
 ** \param   IrqValue irq number value
 **
 ** \retval  None
 **
 ******************************************************************************
 */
static void OCU_IrqHandler(volatile uint8_t WhichMFT,volatile uint16_t IrqValue)
{
     /* Trigger OCU channel 0 Interrupt */
     if(SET == (IrqValue >> (0 + WhichMFT*6)))
     {
          /* Clear Interrupt */
          MFT_OcuClrIntFlag(WhichMFT,OC_CH0);
          if(OCU_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              OCU_IntCallback[WhichMFT](OCU_INT_CH0);
          }
     }

     /* Trigger OCU channel 1 Interrupt */
     if(SET == (IrqValue >> (1 + WhichMFT*6)))
     {
          /* Clear Interrupt */
           MFT_OcuClrIntFlag(WhichMFT,OC_CH2);
          if(OCU_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              OCU_IntCallback[WhichMFT](OCU_INT_CH1);
          }
     }

     /* Trigger OCU channel 2 Interrupt */
     if(SET == (IrqValue >> (2 + WhichMFT*6)))
     {
           /* Clear Interrupt */
           MFT_OcuClrIntFlag(WhichMFT,OC_CH3);
          if(OCU_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              OCU_IntCallback[WhichMFT](OCU_INT_CH2);
          }
     }

     /* Trigger OCU channel 3 Interrupt */
     if(SET == (IrqValue >> (3 + WhichMFT*6)))
     {
          /* Clear Interrupt */
           MFT_OcuClrIntFlag(WhichMFT,OC_CH4);
          if(OCU_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              OCU_IntCallback[WhichMFT](OCU_INT_CH3);
          }
     }

     /* Trigger OCU channel 4 Interrupt */
     if(SET == (IrqValue >> (4 + WhichMFT*6)))
     {
          /* Clear Interrupt */
           MFT_OcuClrIntFlag(WhichMFT,OC_CH5);
          if(OCU_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              OCU_IntCallback[WhichMFT](OCU_INT_CH4);
          }
     }

     /* Trigger OCU channel 5 Interrupt */
     if(SET == (IrqValue >> (5 + WhichMFT*6)))
     {
          /* Clear Interrupt */
           MFT_OcuClrIntFlag(WhichMFT,OC_CH5);
          if(OCU_IntCallback[WhichMFT] != NULL)
          {
               /* Call CallBackIrq */
              OCU_IntCallback[WhichMFT](OCU_INT_CH5);
          }
     }

     return;
}

/*****************************************************************************/
/* END OF FILE */
