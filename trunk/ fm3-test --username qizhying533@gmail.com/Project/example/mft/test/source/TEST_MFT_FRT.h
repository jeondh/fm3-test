/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_FRT.h
 **
 ** \brief Free-run Timer Unit all cell drivers testing head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 9:30
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef TEST_MFT_FRT_H
#define TEST_MFT_FRT_H

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
 ** \brief  FRT unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRTRegisterTest(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit CLK register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_CLK_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit MODE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_MODE_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit STOP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_STOP_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit BFE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_BFE_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit ICRE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ICRE_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit ICLR register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ICLR_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit IRQZE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_IRQZE_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit IRQZF register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_IRQZF_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit ECKE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ECKE_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit ADxE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ADxE_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit TCCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_TCCP_Test(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit TCDT register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_TCDT_Test(void);

/*!
 ******************************************************************************
 ** \brief  Print the FRT test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str);


#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
