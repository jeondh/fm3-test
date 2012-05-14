/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_OCU.h
 **
 ** \brief Output Compare Unit example head file
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

#ifndef EXMP_MFT_OCU_H
#define EXMP_MFT_OCU_H

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


/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/
typedef struct
{
    volatile int8_t WhichMFT; //!< Which MFT channel will be configured.
    volatile int8_t WhichOCCPCh;//!< Which OCCP channel will be configured.
    volatile int8_t WhichFRTCh; //!< Which FRT channel will be configured.
    volatile int8_t OCSB_CMODE; //!< OCU work mode determined by bits of TCSA.MODE, OCSB.CMODE and OCSC.MOD
    volatile int8_t OCSC_MOD; //!< OCU work mode determined by bits of TCSA.MODE, OCSB.CMODE and OCSC.MOD
    volatile int8_t EnBuf; //!< Enable or disable OCCP buffer
    volatile int8_t EnINT; //!< Enable or disable OCCP matches FRT interrupt
}_stParaForOCCP;

//*****************************************************************************
//
// declare functions
//
//*****************************************************************************

/*!
 ******************************************************************************
 ** \brief  MFT module OCU unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_Initial(void);

/*!
 ******************************************************************************
 ** \brief  OCU unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialOCU(void);

/*!
 ******************************************************************************
 ** \brief    OCU unit register configure
 **
 ** \param    _stParaForOCCP OCU unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_OCUInitConfig(volatile _stParaForOCCP *p);

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg OCU_INT_CH0
 ** \arg OCU_INT_CH1
 ** \arg OCU_INT_CH2
 ** \arg OCU_INT_CH3
 ** \arg OCU_INT_CH4
 ** \arg OCU_INT_CH5
 **
 ** \return none
 **
 ******************************************************************************
 */
static void OCU_Callback(uint8_t IntType);

#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
