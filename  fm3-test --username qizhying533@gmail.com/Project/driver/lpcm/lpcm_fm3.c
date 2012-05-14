/*!
 ******************************************************************************
 **
** \file lpcm_fm3.c
 **
 ** \brief this file provides all low power consumption drivers
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

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/

#include "lpcm_fm3.h"

/*!
 ******************************************************************************
 ** \brief define SCR address
 ******************************************************************************
 */
#define CM3_Core_CSR  *((volatile unsigned int*)(0xE000ED10UL))

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief go to standby mode
 **
 ** \param tp the one type of standby mode.
 **        This parameter can be one of the following values:
 ** \arg   STB_SlpMode sleep mode
 ** \arg   STB_TimerMode timer mode
 ** \arg   STB_RTCMode RTC mode
 ** \arg   DPSTB_RTCMode deep RTC mode
 ** \arg   DPSTB_StopMode deep stop mode

 ** \param io_stus set io status when enter standby mode.
 **        This parameter can be one of the following values:
 ** \arg   0 keep io tatus
 **        1 keep hi-z
 **
 ** \retval None
 **
 ******************************************************************************
 */
void LowPwrCon_GoToStandByMode(LowPwrModeType tp, uint8_t io_stus)
{
    switch (tp)
    {
        case STB_SlpMode:
            CM3_Core_CSR &= 0xFFFFFFFFB;
            __WFI();
        break;
        //////////////////////////////////
        case STB_TimerMode:
            if( io_stus == 0 )
            {
                FM3_CRG->STB_CTL = 0x1ACC0000;
            }
            else
            {
                FM3_CRG->STB_CTL = 0x1ACC0010;
            }
            CM3_Core_CSR |= 0x00000004;
            __WFI();
        break;
        //////////////////////////////////
        case STB_RTCMode:
            
        break;
        /////////////////////////////////
        case STB_StopMode:
            if( io_stus == 0 )
            {
                FM3_CRG->STB_CTL = 0x1ACC0002;
            }
            else
            {
                FM3_CRG->STB_CTL = 0x1ACC0012;
            }
            CM3_Core_CSR &= 0xFFFFFFFFB;
            __WFI();
        break;
        //////////////////////////////////
        case DPSTB_RTCMode:
            
        break;
        /////////////////////////////////
        case DPSTB_StopMode:
            
        break;
        //////////////////////////////////
        default:
            
        break;
    }
}
