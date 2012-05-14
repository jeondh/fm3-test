/*!
 ******************************************************************************
 **
 ** \file cr_fm3.c
 **
 ** \brief cr trimming driver
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
#include "Cr_fm3.h"

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

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
 ** \brief Enable CRC trimming setting
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */ 
void CR_RegUnLock(void)
{
    FM3_CRTRIM->MCR_RLR = CR_UNLOCK;
    return;
}


/*!
 ******************************************************************************
 ** \brief Disable CRC trimming setting
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */ 
void CR_RegLock(void)
{
    FM3_CRTRIM->MCR_RLR = 0;
    return;
}



/*!
 ******************************************************************************
 ** \brief Set the frequency trimmin value
 **
 ** \param TrimData CR Trimming data
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void CR_SetTrimData(int16_t TrimData)
{
    CR_RegUnLock();
    FM3_CRTRIM->MCR_FTRM = TrimData;
    CR_RegLock();
    return;
}


/*!
 ******************************************************************************
 ** \brief Set CR oscillation Frequency division
 **
 ** \param FrqDiv Frequency divsion ratio
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void CR_SetFreqConfig(uint8_t FrqDiv)
{
    /* Check the parameter*/
    ASSERT (IS_CRC_FQR_DIV(FrqDiv));

    FM3_CRTRIM->MCR_PSR = FrqDiv;	 
    return;
}




/*!
 ******************************************************************************
 ** \brief Get CR trimming data in flash
 **
 ** \param None
 ** 
 ** \return CRC trimming data
 **
 ******************************************************************************
 */
int16_t CR_GetTrimData(void)
{
    return FM3_FLASH_IF->CRTRMM;
}


/*!
 ******************************************************************************
 ** \brief Caculate CR trimming data
 **
 ** \param None
 ** 
 ** \return CRC trimming data
 **
 ******************************************************************************
 */
int16_t CR_DataCal(void)
{
    int16_t trimdata = 0;
    //To do
    return trimdata;
}



/*!
 ******************************************************************************
 ** \brief Initialize CR trimming data
 **
 ** \param None
 ** 
 ** \retval None
 **
 ******************************************************************************
 */
void CR_Init(void)
{
    uint16_t trimdata = 0; 
    trimdata = CR_GetTrimData();
    CR_SetTrimData(trimdata);
}



 /*****************************************************************************/
/* END OF FILE */