/*!
 ******************************************************************************
 **
** \file lpcm_fm3.h
 **
 ** \brief head file of low power consumption drivers
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-18
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor(Shanghai) Co.,Ltd.
 **
 ******************************************************************************
 */
 
/*!
 ******************************************************************************
 ** \brief Low Power Mode type structure
 ******************************************************************************
 */

#ifndef _LPCM_FM3_H_
#define _LPCM_FM3_H_

#include "fm3_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
******************************************************************************
 ** \brief define standby mode type
******************************************************************************
*/
typedef enum LowPwrMode
{
    STB_SlpMode=1,    //!< standby sleep mode
    STB_TimerMode,    //!< standby timer mode
    STB_RTCMode,      //!< standby RTC mode
    STB_StopMode,     //!< standby stop mode
    DPSTB_RTCMode,    //!< deep standby RTC mode
    DPSTB_StopMode    //!< deep standby stop mode
} LowPwrModeType;

/*
******************************************************************************
 ** go to standby mode
******************************************************************************
*/
void LowPwrCon_GoToStandByMode(LowPwrModeType, uint8_t);

#ifdef __cplusplus
}
#endif

#endif