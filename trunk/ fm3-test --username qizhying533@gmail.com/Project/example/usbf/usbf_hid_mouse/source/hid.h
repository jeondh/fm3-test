/*!
 ******************************************************************************
 **
 ** \file hid.h
 **
 ** \brief USB HID head file
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
 **
 ** \note Other information.
 **
 ******************************************************************************
 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "usb_comm.h"

#ifndef __HID_H
#define __HID_H

/*!
 ******************************************************************************
 ** \brief USB HID Request enumeration
 ******************************************************************************
 */
typedef enum _HID_RequestT
{
    HID_GET_REPORT = 1, HID_GET_IDLE, HID_GET_PROTOCOL,
    HID_SET_REPORT = 9, HID_SET_IDLE, HID_SET_PROTOCOL,
} HID_RequestT;

/*!
 ******************************************************************************
 ** \brief USB HID Report enumeration
 ******************************************************************************
 */
typedef enum _HID_ReportTypeT
{
    HID_INPUT = 1, HID_OUTPUT, HID_FEATURE,
} HID_ReportTypeT;

/*!
 ******************************************************************************
 ** \brief USB HID Subclass enumeration
 ******************************************************************************
 */
typedef enum _HID_SubclassCodesT
{
    NoSubclass = 0, BootInterfaceSubclass
} HID_SubclassCodesT;

/*!
 ******************************************************************************
 ** \brief USB HID protocol codes enumeration
 ******************************************************************************
 */
typedef enum _HID_ProtocolCodesT
{
    None = 0, Keyboard, Mouse
} HID_ProtocolCodesT;

/*!
 ******************************************************************************
 ** \brief USB HID class descriptor enumeration
 ******************************************************************************
 */
typedef enum _HID_ClassDescriptorTypesT
{
    Hid = 0x21, HidReport, HidPhysical,
} HID_ClassDescriptorTypesT;

/*!
 ******************************************************************************
 ** \brief USB HID mouse protocol enumeration
 ******************************************************************************
 */
typedef enum _HID_MouseProtocolT
{
    BootProtocol = 0, ReportProtocol
} HID_MouseProtocolT;

/*! \brief USB HID report size  */
#define BootReportMaxSize   3
/*
 Byte 0 - bit 0 - Button 1
          bit 1 - Button 2
          bit 2 - Button 3
          bit 3 - 7 - device specific
 Byte 1 - X
 Byte 2 - Y
 Byte 3 - n - Device specific
*/

#pragma pack(1)

/*!
 ******************************************************************************
 ** \brief USB HID descriptor structure
 ******************************************************************************
 */
typedef struct _USB_HidDescriptorT
{
    uint8_t       bLength;                           //!< Descriptor length
    uint8_t       bDescriptorType;                   //!< HID descriptor type
    uint8_t       bcdHID[2];                         //!< HID Class Specification release number
    uint8_t       bCountryCode;                      //!< Hardware target country
    uint8_t       bNumDescriptors;                   //!< Number of HID class descriptors to follow
    uint8_t       bDescriptorHidType;                //!< Report descriptor type
    uint16_t      wDescriptorLength;                 //!< Total length of Report descriptor
} USB_HidDescriptorT, * pUSB_HidDescriptorT;  
#pragma pack()

/*!
 ******************************************************************************
 ** \brief USB HID vendors pages enumeration
 ******************************************************************************
 */
typedef enum _HID_VendorsPagesT
{
    HID_VENDOR_PAGE_0 = 0, HID_VENDOR_PAGE_1, HID_VENDOR_PAGE_2,
    HID_FLASHLOADER_PAGE = 13,
} HID_VendorsPagesT;


#endif //__HID_H
