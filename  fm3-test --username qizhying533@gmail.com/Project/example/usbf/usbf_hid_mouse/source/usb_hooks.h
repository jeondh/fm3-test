/*!
 ******************************************************************************
 **
 ** \file usb_hooks.h
 **
 ** \brief USB hooks file
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-24
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor(Shanghai) Co.,Ltd.
 **
 ******************************************************************************
 **
 ** \note Other information.
 **
 ******************************************************************************
 */
#include "includes.h"

#ifndef __USB_HOOKS_H
#define __USB_HOOKS_H

#ifdef USB_HOOKS_GLOBAL
#define USB_HOOKS_EXTERN
#else
#define USB_HOOKS_EXTERN extern
#endif

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
void USB_IntEnterHook (void);
void USB_IntExitHook (void);
void USB_ErrorHook (uint32_t Error);
void USB_FrameHook (uint32_t Number);
void USB_ConnectHook (uint8_t Connect);
void USB_SuspendHook (uint8_t Suspend);
void USB_ResetHook (void);
void USB_ConfigureHook (pUSB_DevCtrlT pDev);
void USB_EpStallHook (USB_EpIndexT EP);
void USB_EpUnstallHook (USB_EpIndexT EP);
USB_CommStatusT USB_GetDescriptorHook (pUSB_SetupPacketT pSetup);
USB_CommStatusT USB_ClassRequestHook (pUSB_SetupPacketT pSetup);
USB_CommStatusT USB_VendorRequestHook (pUSB_SetupPacketT pSetup);
#ifdef __cplusplus
}
#endif

#endif
/*****************************************************************************/
/* END OF FILE */

