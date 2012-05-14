/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_OCU.h
 **
 ** \brief Output Compare Unit all cell drivers testing head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 11:10
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
 ** \brief  OCU unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCURegisterTest(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit OCFS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OCFS_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit CSF register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_CST_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit BDIS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_BDIS_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit IOE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_IOE_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit IOP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_IOP_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit OTD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OTD_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit CMOD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_CMOD_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit BTS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_BTS_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit OCSC register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OCSC_Test(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit OCCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OCCP_Test(void);

/*!
 ******************************************************************************
 ** \brief  Print the OCU test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str);


#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
