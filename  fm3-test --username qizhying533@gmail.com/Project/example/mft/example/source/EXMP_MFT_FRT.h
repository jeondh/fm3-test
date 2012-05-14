/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_FRT.h
 **
 ** \brief Free-run Timer Unit example head file
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

#ifndef EXMP_MFT_FRT_H
#define EXMP_MFT_FRT_H

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
	volatile int8_t WhichFRTCh; //!< Which FRT channel will be configured.
	volatile int8_t CntMode; //!< Count mode
	volatile uint8_t EnBuf; //!< Enable or disable FRT buffer
	volatile float Cycle; //!< FRT running cycle (ms)
	volatile int8_t EnINT_MatchTop; //!< Enable or disable MatchTop interrupt
	volatile int8_t EnINT_MatchZero; //!< Enable or disable MatchZero interrupt
}_stParaForFRT;

//*****************************************************************************
//
// declare functions
//
//*****************************************************************************


/*!
 ******************************************************************************
 ** \brief  MFT module FRT unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_Initial(void);

/*!
 ******************************************************************************
 ** \brief  FRT unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialFRT(void);

/*!
 ******************************************************************************
 ** \brief    FRT unit register configure
 **
 ** \param    _stParaForFRT FRT unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_FRTInitConfig(volatile _stParaForFRT *p);

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg FRT_INT_TOP_CH0
 ** \arg FRT_INT_TOP_CH1
 ** \arg FRT_INT_TOP_CH2
 ** \arg FRT_INT_ZERO_CH0
 ** \arg FRT_INT_ZERO_CH1
 ** \arg FRT_INT_ZERO_CH2
 **
 ** \return none
 **
 ******************************************************************************
 */
static void FRT_Callback(uint8_t IntType);


#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
