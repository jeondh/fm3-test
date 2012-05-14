/*!
 ******************************************************************************
 **
 ** \file usb_dev_desc.h
 **
 ** \brief USB descriptor head file
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
#include "includes.h"

#ifndef __USB_DEV_DESC_H
#define __USB_DEV_DESC_H

/*!
 ******************************************************************************
 ** \brief USB Descriptor offset enumeration in the array
 ******************************************************************************
 */
typedef enum _USB_DescOffsetT
{
    USB_FS_CFG_ARRAY, USB_FS_EP_EXT_ARRAY, USB_FS_LANG_STR, USB_FS_STR_ARRAY, USB_FS_OTHER_CFG_ARRAY,
    USB_HS_CFG_ARRAY, USB_HS_EP_EXT_ARRAY, USB_HS_LANG_STR, USB_HS_STR_ARRAY, USB_HS_OTHER_CFG_ARRAY,
} USB_DescOffsetT;

/*!
 ******************************************************************************
 ** \brief USB Endpoint External Descriptor structure
 ******************************************************************************
 */
typedef struct _UsbEP_ExtDescT
{
    uint8_t           Configuration;         //!< Configuration flag
    uint8_t           EndpointAddress;       //!< Endpoint address
    UsbEP_ExtDataT    EP_ExtData;            //!< Ep external data structure
} UsbEP_ExtDescT, *pUsbEP_ExtDescT;

/*! \brief USB Standard Device Descriptor */
extern const USB_StandardDeviceDescriptorStrT g_UsbStandardDeviceDescriptorStr;

#if USB_HIGH_SPEED > 0
/*! \brief USB Standard Device Qualifier Descriptor */
extern const UsbStandardDeviceQualifierDescriptorT g_UsbQualifierDescriptor;
#endif // USB_HIGH_SPEED > 0

/*! \brief USB Descriptor Array */
extern const void * const g_UsbDescArray[];

#endif //__USB_DEV_DESC_H

/*****************************************************************************/
/* END OF FILE */