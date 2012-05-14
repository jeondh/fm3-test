/*!
 ******************************************************************************
 **
 ** \file usb_hooks.c
 **
 ** \brief USB hook functions
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-22
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

#define USB_HOOKS_GLOBAL
#include "usb_hooks.h"

/*!
 ******************************************************************************
 ** \brief USB interrupt entry hook function
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_IntEnterHook (void)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief USB interrupt exit hook function
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_IntExitHook (void)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called at USB error
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_ErrorHook (uint32_t Error)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called at USB SOF
 **
 ** \param Number Frame number
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_FrameHook (uint32_t Number)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called at USB connect status change
 **
 ** \param Connect Indicate whether the device is connected or not
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_ConnectHook (uint8_t Connect)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called at USB suspend status change
 **
 ** \param Suspend USB suspend status
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_SuspendHook (uint8_t Suspend)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called at USB reset
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_ResetHook (void)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called when configuration change
 **
 ** \param pDev Device control information
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_ConfigureHook (pUSB_DevCtrlT pDev)
{
	// Add code here ...
	HID_CnfgInit(pDev);
}

/*!
 ******************************************************************************
 ** \brief Called when configuration change
 **
 ** \param pDev Device control information
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_EpStallHook (USB_EpIndexT EP)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called when EP unstalled
 **
 ** \param pDev Device control information
 **
 ** \return None
 **
 ******************************************************************************
 */
void USB_EpUnstallHook (USB_EpIndexT EP)
{
  // Add code here ...
}

/*!
 ******************************************************************************
 ** \brief Called when get desriptor receiving
 **
 ** \param pSetup USB setup packet
 **
 ** \return USB common status
 **
 ******************************************************************************
 */
USB_CommStatusT USB_GetDescriptorHook (pUSB_SetupPacketT pSetup)
{
  // Add code here ...
  return(HID_UsbClassHidDescriptor(pSetup));
  //return(UsbFault);
}

/*!
 ******************************************************************************
 ** \brief Called when class request receiving
 **
 ** \param pSetup USB setup packet
 **
 ** \return USB common status
 **
 ******************************************************************************
 */
USB_CommStatusT USB_ClassRequestHook (pUSB_SetupPacketT pSetup)
{
  // Add code here ...
  return(HID_UsbClassHidRequest(pSetup));
  //return(UsbFault);
}

/*!
 ******************************************************************************
 ** \brief Called when vendor request receiving
 **
 ** \param pSetup USB setup packet
 **
 ** \return USB common status
 **
 ******************************************************************************
 */
USB_CommStatusT USB_VendorRequestHook (pUSB_SetupPacketT pSetup)
{
  // Add code here ...
  return(UsbFault);
}
