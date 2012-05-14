/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_WFG.h
 **
 ** \brief Waveform Generator Unit example head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-29 18:30
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef EXMP_MFT_WFG_H
#define EXMP_MFT_WFG_H

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

/*! \brief WFG parameter struct */
typedef struct
{
    volatile int8_t WhichMFT; //!< Which MFT channel will be configured.
    volatile int8_t WhichPhase; //!<  Which WFG channel pairs is used for controlling
    volatile int8_t FreqDivForAPB1; //!< Frequency division factor for APB1 clock
    volatile float DeadTime; //!< deadtime (ms).
    volatile int8_t EnINT; //!< Enable or disable OCU timer interrupt
}_stParaForWFG;

/*! \brief DTTI parameter struct */
typedef struct
{
    volatile int8_t WhichMFT; //!< Which MFT channel will be configured.
    volatile int8_t NoiseTolerance; //!< DTTI noise tolerance.
    volatile int8_t EnINT; //!< Enable or disable DTTI interrupt
}_stParaForDTTI;

//*****************************************************************************
//
// declare functions
//
//*****************************************************************************

/*!
 ******************************************************************************
 ** \brief  MFT module WFG unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_Initial(void);

/*!
 ******************************************************************************
 ** \brief  WFG unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialWFG(void);

/*!
 ******************************************************************************
 ** \brief    WFG unit register configure
 **
 ** \param    _stParaForWFG WFG unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_WFGInitConfig(volatile _stParaForWFG *p);

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg WFG_INT_CH10
 ** \arg WFG_INT_CH32
 ** \arg WFG_INT_CH54
 **
 ** \return none
 **
 ******************************************************************************
 */
static void WFG_Callback(uint8_t IntType);

/*!
 ******************************************************************************
 ** \brief  DTTI unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialDTTI(void);

/*!
 ******************************************************************************
 ** \brief    DTTI unit register configure
 **
 ** \param    _stParaForDTTI DTTI unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_DTTIInitConfig(volatile _stParaForDTTI *p);

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 **
 ** \return none
 **
 ******************************************************************************
 */
static void DTTI_Callback(void);

#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
