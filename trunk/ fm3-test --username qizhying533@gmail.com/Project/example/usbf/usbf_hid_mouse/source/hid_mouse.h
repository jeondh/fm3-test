/*!
 ******************************************************************************
 **
 ** \file hid_mouse.h
 **
 ** \brief HID mouse head file
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
#include "hid.h"

#ifndef __HID_MOUSE_H
#define __HID_MOUSE_H

#ifdef HID_GLOBAL
#define HID_EXTERN
#else
#define HID_EXTERN extern
#endif

/*! \brief HID report descriptor external declare */
extern const uint8_t g_HidReportDescriptor[];
/*! \brief HID descriptor external declare */
extern const uint8_t g_HidDescriptor[];

/*! \brief HID report descriptor size  */
#define SIZE_OF_HID_MOUSE_DESC  50
/*! \brief HID descriptor size  */
#define SIZE_OF_HID_DESC        (sizeof(USB_HidDescriptorT))

/*!
 ******************************************************************************
 ** \brief HID idle control structure
 ******************************************************************************
 */
typedef struct _HID_IdleCtrlT
{
	uint8_t Dly;                        //!< HID delay time
	uint8_t Cnt;                        //!< HID count time
} HID_IdleCtrlT, * pHID_IdleCtrlT;

#pragma pack(1)
/*!
 ******************************************************************************
 ** \brief HID mouse report structure
 ******************************************************************************
 */
typedef struct _HID_MouseReportT
{
#if HID_ID_NUMB > 0
  const uint8_t ID;                          //!< HID report ID
#endif // HID_ID_NUMB > 0
  uint8_t Buttons;                           //!< Button state
  int8_t X;                                  //!< X axes location
  int8_t Y;                                  //!< Y axes location
} HID_MouseReportT, *pHID_MouseReportT;

#pragma pack()

/*! \brief HID Configuration Flag  */
HID_EXTERN uint8_t g_HidCnfg;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
void HID_Init (void);
void HID_CnfgInit (pUSB_DevCtrlT pDev);
USB_CommStatusT HID_UsbClassHidDescriptor (pUSB_SetupPacketT pSetup);
USB_CommStatusT HID_UsbClassHidRequest (pUSB_SetupPacketT pSetup);
void HID_MouseSendReport (int8_t X, int8_t Y, uint8_t Buttons);
#ifdef __cplusplus
}
#endif
#endif //__HID_MOUSE_H

/*****************************************************************************/
/* END OF FILE */