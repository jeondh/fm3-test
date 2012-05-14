/*!
 ******************************************************************************
 **
 ** \file hid_mouse.c
 **
 ** \brief Implement USB HID mouse function
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
#define HID_GLOBAL

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "hid_mouse.h"

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*! \brief Mouse report data  */
static HID_MouseReportT g_MouseReport =
{
#if HID_ID_NUMB > 0
    HID_MOUSE_ID,     //!< Report ID
#endif // HID_ID_NUMB > 0
    0,                //!< Buttons
    0,                //!< X
    0,                //!< Y
};
#if HID_BOOT_DEVICE > 0
/*! \brief HID mouse protocol data  */
static HID_MouseProtocolT g_HidProtocol;
#endif // HID_BOOT_DEVICE > 0

#if HID_IDLE_SUPP > 0
/*! \brief HID idle control data  */
static HID_IdleCtrlT g_HidIdle[HID_ID_NUMB+1];
#endif 
/*! \brief HID endpoint report delay  */
volatile static uint8_t g_HID_RepotrEpDly; 
/*! \brief HID relative data flag  */
volatile static uint8_t g_RelativeData0;   /* that flag is associated with relative data (X,Y) */

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void HID_USBTransferEndHandler (USB_EpIndexT EP);
static uint8_t HID_SendInReport (uint8_t Ctrl, uint8_t ID);

/*!
 ******************************************************************************
 ** \brief Init HID Mouse
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */ 
void HID_Init (void)
{
    g_HidCnfg = FALSE;
    HID_CnfgInit(NULL);
    USB_CoreInit();
}

/*!
 ******************************************************************************
 ** \brief HID configure
 **
 ** \param pDev Point to USB device control information
 **
 ** \return None
 **
 ******************************************************************************
 */ 
void HID_CnfgInit (pUSB_DevCtrlT pDev)
{
    uint32_t i;
    if (pDev != NULL && pDev->Configuration)
    {
        g_HidCnfg = TRUE;
        g_HID_RepotrEpDly = 0;
    #if HID_BOOT_DEVICE > 0
        g_HidProtocol = ReportProtocol;
    #endif // HID_BOOT_DEVICE > 0
        g_MouseReport.Buttons = 0;
        g_MouseReport.X = \
        g_MouseReport.Y = 0;
        g_RelativeData0 = FALSE;
    #if HID_IDLE_SUPP > 0
        for(i = (HID_ID_NUMB?1:0); i < HID_ID_NUMB+1; i++)
        {
          g_HidIdle[i].Dly  = \
          g_HidIdle[i].Cnt  = 0;
        }
    #endif // HID_IDLE_SUPP > 0
    }
    else
    {
        g_HidCnfg = FALSE;
    }
}

/*!
 ******************************************************************************
 ** \brief Implement GET USB Class HID descriptor
 **
 ** \param pSetup Point to USB setup packet 
 **
 ** \return USB Common Status
 **
 ******************************************************************************
 */ 
USB_CommStatusT HID_UsbClassHidDescriptor (pUSB_SetupPacketT pSetup)
{
    if (pSetup->wIndex.Word == HID_INTERFACE_0)
    {
        switch (pSetup->wValue.Hi)
        {
            case Hid:
                USB_DataTransfer(CTRL_ENP_IN,
                (uint8_t*)g_HidDescriptor,
                USB_CompareSize(SIZE_OF_HID_DESC,pSetup->wLength.Word),
                (void *)HID_USBTransferEndHandler);
            #ifdef DEBUG_MODE
                printf("GET_HID_DESC[STD]\n");
            #endif
                return(UsbPass);
            case HidReport:
                if (g_HidProtocol == ReportProtocol)
                {
                    USB_DataTransfer(CTRL_ENP_IN,
                    (uint8_t*)g_HidReportDescriptor,
                    USB_CompareSize(SIZE_OF_HID_MOUSE_DESC,pSetup->wLength.Word),
                    (void *)HID_USBTransferEndHandler);
                #ifdef DEBUG_MODE
                    printf("GET_HIDREPORT_DESC[STD]\n");
                #endif
                    return(UsbPass);
                }
        }
    }
    return(UsbNotSupport);
}

/*!
 ******************************************************************************
 ** \brief Implement GET USB Class HID Request
 **
 ** \param pSetup Point to USB setup packet 
 **
 ** \return USB Common Status
 **
 ******************************************************************************
 */ 
USB_CommStatusT HID_UsbClassHidRequest (pUSB_SetupPacketT pSetup)
{
    uint32_t i;
    switch (pSetup->bRequest)
    {
        case HID_GET_REPORT:
            if(pSetup->wIndex.Word == HID_INTERFACE_0)
            {
                if (pSetup->wValue.Hi == HID_INPUT)
                {
                    if(HID_SendInReport(TRUE,pSetup->wValue.Lo))
                    {
                        return(UsbPass);
                    }
                }
                else if (pSetup->wValue.Hi == HID_OUTPUT)
                {
                }
                else if (pSetup->wValue.Hi == HID_FEATURE )
                {
                }
            #ifdef DEBUG_MODE
                printf("GET_REPORT_REQUEST[Class]\n");
            #endif
            }
            break;
        case HID_SET_REPORT:
            if (pSetup->wIndex.Word == HID_INTERFACE_0)
            {
                if (pSetup->wValue.Hi == HID_INPUT)
                {
                }
                else if (pSetup->wValue.Hi == HID_OUTPUT)
                {
                }
                else if (pSetup->wValue.Hi == HID_FEATURE)
                {
                }
            #ifdef DEBUG_MODE
                printf("SET_REPORT_REQUEST[Class]\n");
            #endif
            }
            break;
    #if HID_IDLE_SUPP > 0
        case HID_GET_IDLE:
            if (pSetup->wIndex.Word == HID_INTERFACE_0)
            {
                if(pSetup->wValue.Lo <= HID_ID_NUMB)
                {
                    USB_DataTransfer(CTRL_ENP_IN,
                    (uint8_t*)&g_HidIdle[pSetup->wValue.Lo].Dly,
                    USB_CompareSize(1,pSetup->wLength.Word),
                    (void *)HID_USBTransferEndHandler);
                    return(UsbPass);
                }
            #ifdef DEBUG_MODE
                printf("GET_IDLE[Class]\n");
            #endif
            }
            break;
        case HID_SET_IDLE:
            if (pSetup->wIndex.Word == HID_INTERFACE_0)
            {
                if(pSetup->wValue.Lo <= HID_ID_NUMB)
                {
                    if(pSetup->wValue.Lo == 0)
                    {
                        for(i = 1; i < HID_ID_NUMB+1; i++)
                        {
                            g_HidIdle[i].Dly = pSetup->wValue.Hi;
                        }
                    }
                    g_HidIdle[pSetup->wValue.Lo].Dly = pSetup->wValue.Hi;
                    USB_StatusHandler(CTRL_ENP_OUT);
                #ifdef DEBUG_MODE
                    printf("SET_IDLE[Class]\n");
                #endif
                    return(UsbPass);
                }
            }
            break;
    #endif // HID_IDLE_SUPP > 0
    #if HID_BOOT_DEVICE > 0
        case HID_GET_PROTOCOL:
            if (pSetup->wIndex.Word == HID_INTERFACE_0)
            {
                USB_DataTransfer(CTRL_ENP_IN,
                (uint8_t*)&g_HidProtocol,
                USB_CompareSize(1,pSetup->wLength.Word),
                (void *)HID_USBTransferEndHandler);
            #ifdef DEBUG_MODE
                printf("GET_PROTOCOL[Class]\n");
            #endif
                return(UsbPass);
            }
            break;
        case HID_SET_PROTOCOL:
            if (pSetup->wIndex.Word == HID_INTERFACE_0)
            {
                g_HidProtocol = (HID_MouseProtocolT)pSetup->wValue.Word;
                USB_StatusHandler(CTRL_ENP_OUT);
            #ifdef DEBUG_MODE
                printf("SET_PROTOCOL[Class]\n");
            #endif
                return(UsbPass);
            }
            break;
    #endif // HID_BOOT_DEVICE > 0
    }
    return(UsbNotSupport);
}

/*!
 ******************************************************************************
 ** \brief USB HID report end
 **
 ** \param Ep Endpoint index 
 **
 ** \return None
 **
 ******************************************************************************
 */ 
void HID_USBTransferEndHandler (USB_EpIndexT Ep)
{
    if (Ep == CTRL_ENP_IN)
    {
        USB_StatusHandler(CTRL_ENP_IN);
    }
    else if (Ep == CTRL_ENP_OUT)
    {
        USB_StatusHandler(CTRL_ENP_OUT);
    }
    else if (Ep == ReportEpHid)
    {
        g_HID_RepotrEpDly = 0;
    }
    else
    {
        ASSERT(0);
    }

    if (g_RelativeData0)
    {
        g_RelativeData0 = FALSE;
        g_MouseReport.X = g_MouseReport.Y = 0;
    }
}

/*!
 ******************************************************************************
 ** \brief USB HID Mouse report send
 **
 ** \param X x axes data
 ** \param Y y axes data
 ** \param Buttons Buttons status
 ** \return None
 **
 ******************************************************************************
 */ 
void HID_MouseSendReport (int8_t X, int8_t Y, uint8_t Buttons)
{
    g_MouseReport.X = X;
    g_MouseReport.Y = Y;
    if((g_MouseReport.Buttons != Buttons) ||
        g_MouseReport.X ||
        g_MouseReport.Y)
    {
        g_MouseReport.Buttons = Buttons;
        HID_SendInReport(FALSE,HID_MOUSE_ID);
    }
}

/*!
 ******************************************************************************
 ** \brief USB HID send different report
 **
 ** \param Ctrl Control flag
 ** \param ID Report flag
 ** \return Report send status
 **
 ******************************************************************************
 */
static uint8_t HID_SendInReport (uint8_t Ctrl, uint8_t ID)
{

    ENTR_CRT_SECTION();

    if(!Ctrl)
    {
        g_HID_RepotrEpDly = ReportEpPollingPeriod;

    #if HID_IDLE_SUPP > 0
        if(g_HidIdle[ID].Dly)
        {
            if (g_HidIdle[ID].Cnt < g_HidIdle[ID].Dly)
            {
                EXT_CRT_SECTION();
                return(TRUE);
            }
        }
    #endif
    }

    switch(ID)
    {
        case HID_MOUSE_ID:
            g_RelativeData0 = TRUE;
            USB_DataTransfer((Ctrl?CTRL_ENP_IN:ReportEpHid),
                        #if HID_ID_NUMB > 0
                            (uint8_t*)(((uint8_t*)&g_MouseReport) + ((g_HidProtocol == ReportProtocol)?0:1)),     // first byte is ID
                        #else
                            (uint8_t*)&g_MouseReport,
                        #endif // HID_ID_NUMB > 0
                            (g_HidProtocol == ReportProtocol)?sizeof(HID_MouseReportT):BootReportMaxSize,
                            (void *)HID_USBTransferEndHandler);
            break;
        default:
            EXT_CRT_SECTION();
            return(FALSE);
    }
    EXT_CRT_SECTION();
    return(TRUE);
}

/*****************************************************************************/
/* END OF FILE */