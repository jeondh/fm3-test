/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_ICU.h
 **
 ** \brief Input Capture Unit all cell drivers testing head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2012-01-09 11:10
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */
#ifndef TEST_MFT_OCU_H
#define TEST_MFT_OCU_H

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
 ** \brief  ICU unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCURegisterTest(void);

/*!
 ******************************************************************************
 ** \brief  ICU unit ICFS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICFS_Test(void);

/*!
 ******************************************************************************
 ** \brief  ICU unit EG register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_EG_Test(void);

/*!
 ******************************************************************************
 ** \brief  ICU unit ICEx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICEx_Test(void);

/*!
 ******************************************************************************
 ** \brief  ICU unit ICPx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICPx_Test(void);

/*!
 ******************************************************************************
 ** \brief  ICU unit IEIx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_IEIx_Test(void);

/*!
 ******************************************************************************
 ** \brief  ICU unit ICCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICCP_Test(void);

/*!
 ******************************************************************************
 ** \brief  Print the ICU test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str);

/*****************************************************************************/
/* END OF FILE */
