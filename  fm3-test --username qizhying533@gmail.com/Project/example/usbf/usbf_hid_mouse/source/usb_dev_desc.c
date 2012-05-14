/*!
 ******************************************************************************
 **
 ** \file usb_dev_desc.c
 **
 ** \brief This file provides all USB desciptors
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
#include "usb_desc_fm3.h"

/*! \brief USB Standard Device Descriptor */
//#pragma data_alignment=4
const USB_StandardDeviceDescriptorStrT g_UsbStandardDeviceDescriptorStr =
{
    sizeof(USB_StandardDeviceDescriptorStrT),
    UsbDescriptorDevice,
    0x200,
    0,
    0,
    0,
    Ep0MaxSize,
    0xFFFF,
    0x0040,
    0x0000,
    iManufacturerStr,
    iProductStr,
    iSerialNumberStr,
    1,
};

/*! \brief USB HID Report Descriptor */
//#pragma data_alignment=4
const uint8_t g_HidReportDescriptor[] =
{
    0x05, 0x01, // Usage Page (Generic Desktop)
    0x09, 0x02, // Usage (Mouse)
    0xA1, 0x01, // Collection (Application)
    0x09, 0x01, //  Usage (Pointer)
    0xA1, 0x00, //  Collection (Physical)
    0x05, 0x09, //    Usage Page (Buttons)
    0x75, 0x01, //    Report Size (1)
    0x95, 0x03, //    Report Count (3)
    0x19, 0x01, //    Usage Minimum?(01)
    0x29, 0x03, //    Usage Maximum (05)
    0x15, 0x00, //    Logical Minimum (0)
    0x25, 0x01, //    Logical Maximum (1)
    0x81, 0x02, //    Input(Data,Var,Abs)
    0x75, 0x05, //    Report Size (5)
    0x95, 0x01, //    Report Count (1)
    0x81, 0x03, //    Input(Const,Var,Abs)
    0x05, 0x01, //    Generic desktop
    0x75, 0x08, //    Report Size (8)
    0x95, 0x02, //    Report Count (2)
    0x09, 0x30, //    Usage(X)
    0x09, 0x31, //    Usage(Y)
    0x15, 0x80, //    Logical Minimum (-128)
    0x25, 0x7F, //    Logical Maximum (127)
    0x81, 0x06, //    Input(Data,Var,Rel)
    0xC0, 0xC0, // End collection x2
};

/*! \brief USB HID Descriptor */
//#pragma data_alignment=4
const uint8_t g_HidDescriptor[] =
{
    sizeof(USB_HidDescriptorT),
    Hid,
    _2BL(0x0111),
    0,
    1,
    HidReport,
    _2BL(sizeof(g_HidReportDescriptor)),
};

/*! \brief USB Configuration Descriptor */
//#pragma data_alignment=4
static const uint8_t g_UsbFS_Cfg0[] =
{
    sizeof(USB_StandardConfigurationDescriptorT),
    UsbDescriptorConfiguration,
    _2BL(sizeof(USB_StandardConfigurationDescriptorT)+
    sizeof(USB_StandardInterfaceDescriptorT)+
    sizeof(USB_HidDescriptorT)+
    sizeof(USB_StandardEpDescriptorT)),
    1,
    1,
    0,
    UsbConfigurationCommmonAttr | (USB_REMOTE_WAKEUP?UsbRemoteWakeup:0) | (USB_SELF_POWERED?UsbSelfPowered:0),
    USB_ConfigPower_mA(100),

    sizeof(USB_StandardInterfaceDescriptorT),
    UsbDescriptorInterface,
    HID_INTERFACE_0,
    0,
    1,
    UsbDeviceClassHumanInterface,
    HID_BOOT_DEVICE?BootInterfaceSubclass:NoSubclass,
    HID_BOOT_DEVICE?Mouse:0,
    0,

    sizeof(USB_HidDescriptorT),
    Hid,
    _2BL(0x0111),
    0,
    1,
    HidReport,
    _2BL(sizeof(g_HidReportDescriptor)),

    sizeof(USB_StandardEpDescriptorT),
    UsbDescriptorEp,
    USB_EpIn(ReportEpHid>>1),
    UsbEpTransferInterrupt,
    _2BL(ReportEpMaxSize),
    ReportEpPollingPeriod,
    0,
};

/*! \brief USB Configuration Array */
static const uint8_t * const g_UsbFS_CfgArray[] =
{
    g_UsbFS_Cfg0,
    NULL,
};

/*! \brief USB Endpoint Extent Descriptor */
static const UsbEP_ExtDescT g_UsbEPExt_Cfg0EP1 =
{
    1,                        // Configuration
    USB_EpIn(ReportEpHid>>1),  // EP address
    {
    0
    }
};

/*! \brief USB Endpoint Extent Descriptor Array */
static const UsbEP_ExtDescT * const g_UsbFS_EPExtArray[] =
{
    &g_UsbEPExt_Cfg0EP1,
    NULL,
};

/*! \brief USB Languages String Descriptor */
//#pragma data_alignment=4
const uint8_t g_UsbLanguagesStr [] =
{
    // Length of LanguagesStr + 2
    4,
    // Desciptor Type
    UsbDescriptorString,
    // Languages  ID
    // Languages1 ID English
    0x09,0x04,
};

/*! \brief USB Manufacture String Descriptor */
//#pragma data_alignment=4
const uint8_t g_ManufacturerStrLan1 [] =
{
    38, // length
    UsbDescriptorString,  // Descriptor
    'F',0,'U',0,'J',0,'I',0,'T',0,'S',0,'U',0,'S',0,'E',0,'M',0,
    'I',0,'C',0,'O',0,'N',0,'D',0,'U',0,'C',0,'T',0
};

/*! \brief USB Product String Descriptor */
//#pragma data_alignment=4
const uint8_t g_ProductStrLan1 [] =
{
    70, //length
    UsbDescriptorString, // Descriptor
    'F',0,'M',0,'3',0,' ',0,'P',0,'e',0,'r',0,'i',0,'p',0,'h',0,
    'e',0,'r',0,'a',0,'l',0,' ',0,'L',0,'i',0,'b',0,'r',0,'a',0,
    'r',0,'y',0,' ',0,'H',0,'I',0,'D',0,' ',0,'e',0,'x',0,'a',0,
    'm',0,'p',0,'l',0,'e',0
};

/*! \brief USB Serial Number String Descriptor */
//#pragma data_alignment=4
const uint8_t g_SerialNumberStrLan1 [] =
{
    18, //length
    UsbDescriptorString, // Descriptor
    '0',0,'0',0,'0',0,'0',0,'0',0,'0',0,'0',0,'1',0, // Str
};

/*! \brief USB String Descriptor Array */
const uint8_t * const g_UsbLanguages1Strings[] =
{
    // iManufacturerStr
    g_ManufacturerStrLan1,
    // iProductStr
    g_ProductStrLan1,
    // iSerialNumberStr
    g_SerialNumberStrLan1,
    // Terminator
    NULL
};

/*! \brief USB String Descriptor Array */
static const uint8_t * const * const g_UsbFS_StringArray[] =
{
    g_UsbLanguages1Strings,
    NULL,
};

/*! \brief Descriptor Array */
const void * const g_UsbDescArray[] =
{
    g_UsbFS_CfgArray,
    g_UsbFS_EPExtArray,
    g_UsbLanguagesStr,
    g_UsbFS_StringArray,
    NULL,
};

/*****************************************************************************/
/* END OF FILE */