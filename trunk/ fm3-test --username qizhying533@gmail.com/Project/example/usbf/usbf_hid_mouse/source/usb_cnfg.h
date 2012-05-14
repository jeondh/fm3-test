/*!
 ******************************************************************************
 **
 ** \file usb_cnfg.h
 **
 ** \brief This file provides USB configuration options
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

#ifndef __USB_CNFG_H
#define __USB_CNFG_H

/*! \brief USB High Speed support  */
#define USB_HIGH_SPEED                  0

/*! \brief USB interrupt priority  */
#define USB_INTR_PRIORITY               0

/*! \brief USB SOF Events support  */
#define USB_SOF_EVENT                   0

/*! \brief USB DMA transfer support  */
#define USB_DMA                         0  

/*!
 ******************************************************************************
 ** \brief Endpoint DMA channel enumeration
 ******************************************************************************
 */
typedef enum 
{
	EP1_DMA = 2,         //!< Use DMA channel 2 for Endpoint 1        
	EP2_DMA,             //!< Use DMA channel 3 for Endpoint 2    
	EP3_DMA,             //!< Use DMA channel 4 for Endpoint 3    
	EP4_DMA,             //!< Use DMA channel 5 for Endpoint 4    
	EP5_DMA              //!< Use DMA channel 6 for Endpoint 5    
}EpDmaChT;

/*!
 ******************************************************************************
 ** \brief USB endpoint direction
 ******************************************************************************
 */
typedef enum
{
	UsbEpDirOut = 0,     //!< Endpoint In 
	UsbEpDirIn           //!< Endpoint Out
}UsbEpDirT;

/*! \brief USB Device power attribution  */
#define USB_SELF_POWERED                1
/*! \brief USB remote wakeup option  */
#define USB_REMOTE_WAKEUP               0

/*! \brief Max Interfaces number  */
#define USB_MAX_INTERFACE               1

/*!
 ******************************************************************************
 ** \brief Endpoints definition
 ******************************************************************************
 */
/*! \brief Endpoint 0 maximum size  */
#define ENP0_MAX_SIZE                   8

/*! \brief Endpoint 1 maximum size  */
#define ENP1_MAX_SIZE                   64
/*! \brief Endpoint 1 transfer type  */
#define ENP1_TYPE                       UsbEpTransferBulk
/*! \brief Endpoint 1 direction  */
#define ENP1_DIR                        UsbEpDirIn

/*! \brief Endpoint 2 maximum size  */
#define ENP2_MAX_SIZE                   64
/*! \brief Endpoint 2 transfer type  */
#define ENP2_TYPE                       UsbEpTransferBulk
/*! \brief Endpoint 2 direction  */
#define ENP2_DIR                        UsbEpDirIn

/*! \brief Endpoint 3 maximum size  */
#define ENP3_MAX_SIZE                   64
/*! \brief Endpoint 3 transfer type  */
#define ENP3_TYPE                       UsbEpTransferBulk
/*! \brief Endpoint 3 direction  */
#define ENP3_DIR                        UsbEpDirIn

/*! \brief Endpoint 4 maximum size  */
#define ENP4_MAX_SIZE                   64
/*! \brief Endpoint 4 transfer type  */
#define ENP4_TYPE                       UsbEpTransferInterrupt
/*! \brief Endpoint 4 direction  */
#define ENP4_DIR                        UsbEpDirIn

/*! \brief Endpoint 5 maximum size  */
#define ENP5_MAX_SIZE                   3
/*! \brief Endpoint 5 transfer type  */
#define ENP5_TYPE                       UsbEpTransferInterrupt
/*! \brief Endpoint 5 direction  */
#define ENP5_DIR                        UsbEpDirIn

/*!
 ******************************************************************************
 ** \brief User Endpoints definition
 ******************************************************************************
 */
/*! \brief Endpoint 0 maximum size  */
#define Ep0MaxSize                      ENP0_MAX_SIZE
/*! \brief HID report endpoint  */
#define ReportEpHid                     ENP5_IN
/*! \brief HID report endpoint maximum size  */
#define ReportEpMaxSize                 ENP5_MAX_SIZE
/*! \brief Report endpoint polling period */
#define ReportEpPollingPeriod           2   // resolution 1ms

/*!
 ******************************************************************************
 ** \brief HID class definition
 ******************************************************************************
 */
/*! \brief HID interface number */
#define HID_INTERFACE_0                 0
/*! \brief HID boot device */
#define HID_BOOT_DEVICE                 1
/*! \brief HID idle option */
#define HID_IDLE_SUPP                   1
/*! \brief HID ID number */
#define HID_ID_NUMB                     0
/*! \brief HID mouse ID */
#define HID_MOUSE_ID                    0

/* Other defenitions */

#endif //__USB_CNFG_H

