/*!
 ******************************************************************************
 **
 ** \file lvd_fm3.c
 **
 ** \brief low voltage detection function driver
 **
 ** 
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-8
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
#include "Lvd_fm3.h"

/*---------------------------------------------------------------------------*/
/* Bit definition                                                            */
/*---------------------------------------------------------------------------*/

/*! \brief  CTL */
#define  CTL_SVHI_INIT         ((uint8_t)0xc0)


/*! \brief Watch counter Callback function */
static LVD_IntHandlerCallback_CB *pLVD_IntCallback = NULL;

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/
static void LVD_SetVal(uint8_t LVDVal);

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
 
 
/*!
 ******************************************************************************
 ** \brief Enable Low voltage detection interrupt
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void LVD_IntEnable(void)
{
    bFM3_LVD_LVD_CTL_LVDIE = 1;
    return;
}


/*!
 ******************************************************************************
 ** \brief Disable Low voltage detection interrupt
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void LVD_IntDisable(void)
{
    bFM3_LVD_LVD_CTL_LVDIE = 0;
    return;
}

/*!
 ******************************************************************************
 ** \brief Set specified voltage 
 **
 ** \param LVDVal low-voltage detection interrupt voltage
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void LVD_SetVal(uint8_t LVDVal)
{
    uint8_t  tmpVal = 0;
	 
    /* Check the parameter */
    ASSERT(IS_LVD_VAL(LVDVal));

    tmpVal = FM3_LVD->LVD_CTL;
    tmpVal &= CTL_SVHI_INIT;
    tmpVal |= LVDVal <<2;
    FM3_LVD->LVD_CTL = tmpVal;
		
    return;
}
 
 
 /*!
 ******************************************************************************
 ** \brief Clear Low voltage detection interrupt
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
 void LVD_ClrInt(void)
{
    bFM3_LVD_LVD_CLR_LVDCL = 0; 
    return; 
}
 

 /*!
 ******************************************************************************
 ** \brief  Release write protection mode 
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void LVD_CtlEnable(void)
{
    FM3_LVD->LVD_RLR = LVD_UNLOCK;
    return;
}



 /*!
 ******************************************************************************
 ** \brief Enable writing protection mode
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void LVD_CtlDisable(void)
{
    FM3_LVD->LVD_RLR = 0;
    return;
}

 /*!
 ******************************************************************************
 ** \brief Get low voltage detection interrupt cause 
 **
 ** \param None
 ** 
 ** \return Interrupt cause
 ** \retval RESET
 ** \retval SE        			
 **
 ******************************************************************************
 */
IntStatusT LVD_GetIntFlag (void)
{
    return (IntStatusT)bFM3_LVD_LVD_STR_LVDIR;
}
 


/*!
 ******************************************************************************
 ** \brief Get the operation status of LVD interrupt
 **
 ** \param None
 ** 
 ** \return Interrupt cause
 ** 
 **           			
 **
 ******************************************************************************
 */
IntStatusT LVD_GetIntStat (void)
{
    return (IntStatusT)bFM3_LVD_LVD_STR2_LVDIRDY;
}
 

/*!
 ******************************************************************************
 ** \brief LVD interrupt handler
 **
 ** \param None
 **         
 ** \retval None
 ** 
 **
 ******************************************************************************
 */ 
void LVD_Handler(void)
{
    if(LVD_GetIntFlag() == SET )
    {
        LVD_ClrInt();
        if(pLVD_IntCallback != NULL) 
        {
            pLVD_IntCallback();
        }
    }

}


/*!
 ******************************************************************************
 ** \brief LVD configuration
 **
 ** \param *pConfigInfo point to LVD configuration structure
 **         
 ** \retval None
 ** 
 **
 ******************************************************************************
 */ 
void LVD_Config(LVD_ConfigInfoT *pConfigInfo)
{
    LVD_SetVal(pConfigInfo->LvdVal);
    pLVD_IntCallback = pConfigInfo->pIntHandlerCallback;
    return;
}


 /*****************************************************************************/
/* END OF FILE */
 