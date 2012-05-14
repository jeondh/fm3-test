/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_ADCMP.h
 **
 ** \brief ADC Start Compare Unit drivers test head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 15:50
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef TEST_MFT_ADCMP_H
#define TEST_MFT_ADCMP_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef  __cplusplus
}
#endif

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"
#include "mb9bf50x_lib.h"

//*****************************************************************************
//
// declare functions
//
//*****************************************************************************


/*!
 ******************************************************************************
 ** \brief  ADCMP unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMPRegisterTest(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit CEx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_CEx_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit SELx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_SELx_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit BDIS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_BDIS_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit BTS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_BTS_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ACCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ACCP_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ACCPDN register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ACCPDN_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ADxS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ADxS_Test(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ADxP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ADxP_Test(void);

/*!
 ******************************************************************************
 ** \brief  Print the ADCMP test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str);


#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
