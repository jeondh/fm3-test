/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_WFG.h
 **
 ** \brief Waveform Generator Unit all cell drivers testing head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 18:50
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */
#ifndef TEST_MFT_WFG_H
#define TEST_MFT_WFG_H

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
 ** \brief  WFG unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFGRegisterTest(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit DCK register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DCK_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit TMD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_TMD_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit GATE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_GATE_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit PSEL register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_PSEL_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit PGEN register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_PGEN_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit DMOD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DMOD_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit WFTM register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_WFTM_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit DTIE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DTIE_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit DTIFandDTIC register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DTIFandDTIC_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit TMIFandTMIC register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_TMIFandTMIC_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit TMIE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_TMIE_Test(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit NWS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_NWS_Test(void);

/*!
 ******************************************************************************
 ** \brief  Print the WFG test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str);


#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
