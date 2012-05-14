/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_ADCMP.h
 **
 ** \brief ADC Start Compare Unit example head file
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

#ifndef EXMP_MFT_ADCMP_H
#define EXMP_MFT_ADCMP_H

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

/*! \brief ADC parameter struct */
typedef struct
{
    volatile int8_t WhichADCUnit; //!< Which ADC unit will be configured
                                              //!<(ADC sampling channel below is assigned to this ADC unit).
    volatile int8_t ChFunc[16]; //!< To describe channel function
    volatile int8_t TriggeredByWhichMFT; //!< This ADC unit is triggered by which MFT's which FRT
    volatile int8_t TriggeredByWhichFRT; //!< This ADC unit is triggered by which MFT's which FRT
    volatile uint8_t EnBuf; //!< Enable or disable ACCP buffer
    volatile uint8_t WhenToTransBuff; //!< When to transfer ADCP buffer data to ACCP
    volatile int32_t WhenToTrigger; //!< ADC trigger timing.
    volatile uint8_t TriggerSlope; //!< ADC is triggered at what count-slope
    volatile uint8_t EnINT; //!< Enable or disable interrupt
}_stConfADC;

//*****************************************************************************
//
// declare functions
//
//*****************************************************************************

/*!
 ******************************************************************************
 ** \brief  MFT module ADCMP unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_Initial(void);

/*!
 ******************************************************************************
 ** \brief  ADCMP unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialADCMP(void);

/*!
 ******************************************************************************
 ** \brief    ADCMP unit register configure
 **
 ** \param    _stParaForWFG ADCMP unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_ADCMPInitConfig(volatile _stConfADC *p);

#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
