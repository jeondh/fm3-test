/*!
 ******************************************************************************
 **
 ** \file wd_fm3.c
 **
 ** \brief watchdog timer driver
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-8
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
#include "Wd_fm3.h"
 


/*---------------------------------------------------------------------------*/
/* WD bit definition                                                      */
/*---------------------------------------------------------------------------*/


/*! \brief Software Watch dog Callback function */
static WD_IntHandlerCallback_CB *pSWD_IntCallback = NULL;  

/*! \brief Hardware Watch dog Callback function */
static WD_IntHandlerCallback_CB *pHWD_IntCallback = NULL;


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief Enable software watchdog timer register setting
 **
 ** \param None
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftRegUnLock(void)
{
    FM3_SWWDT->WDOGLOCK = WD_UNLOCK;
    return; 
}


/*!
 ******************************************************************************
 ** \brief Disable software watchdog timer register setting
 **
 ** \param None
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftRegLock(void)
{
    FM3_SWWDT->WDOGLOCK = 0;
    return; 
}

/*!
 ******************************************************************************
 ** \brief Enable hardware watchdog timer register setting other than control register
 **
 ** \param None
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardRegUnLock(void)
{
    FM3_HWWDT->WDG_LCK = WD_UNLOCK;
    return; 
}


/*!
 ******************************************************************************
 ** \brief Enable hardware watchdog timer control register setting
 **
 ** \param None
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardCtlRegUnLock(void)
{
    FM3_HWWDT->WDG_LCK = WD_UNLOCK;  //unlock
    FM3_HWWDT->WDG_LCK = HWD_UNLOCK; 
    return; 
}




/*!
 ******************************************************************************
 ** \brief Set the cycle of software watchdog timer 
 **
 ** \param SWDCycle Cycle of software watchdog timer
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftSetInterval(uint32_t SWDCycle)
{
    WD_SoftRegUnLock();
    FM3_SWWDT->WDOGLOAD = SWDCycle;
    WD_SoftRegLock();
    return;
}


/*!
 ******************************************************************************
 ** \brief Set the cycle of hardware watchdog timer 
 **
 ** \param HWDCycle Cycle of hardware watchdog timer
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardSetInterval(uint32_t HWDCycle)
{
    WD_HardRegUnLock();
    FM3_HWWDT->WDG_LDR = HWDCycle;
    return;
}


/*!
 ******************************************************************************
 ** \brief Enable software watchdog timer reset
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftResetEnable(void)
{
    WD_SoftIntEnable();
	WD_SoftRegUnLock();
    bFM3_SWWDT_WDOGCONTROL_RESEN = 1;
    WD_SoftRegLock();
    return;
}



/*!
 ******************************************************************************
 ** \brief Disable software watchdog timer reset
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftResetDisable(void)
{
    WD_SoftRegUnLock();
    bFM3_SWWDT_WDOGCONTROL_RESEN = 0;
    WD_SoftRegLock();
    return;
}

/*!
 ******************************************************************************
 ** \brief Enable hardware watchdog timer reset
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardResetEnable(void)
{
    WD_HardIntEnable();
    WD_HardCtlRegUnLock();
    bFM3_HWWDT_WDG_CTL_RESEN = 1;
    return;
}



/*!
 ******************************************************************************
 ** \brief Disable hardware watchdog timer reset
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardResetDisable(void)
{
    WD_HardCtlRegUnLock();
    bFM3_HWWDT_WDG_CTL_RESEN = 0;
    return;
}



/*!
 ******************************************************************************
 ** \brief Enable software watchdog timer Interrupt
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftIntEnable(void)
{
    WD_SoftRegUnLock();
    bFM3_SWWDT_WDOGCONTROL_INTEN = 1;
    WD_SoftRegLock();
    return;
}



/*!
 ******************************************************************************
 ** \brief Disable software watchdog timer Interrupt
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftIntDisable(void)
{
    WD_SoftRegUnLock();
    bFM3_SWWDT_WDOGCONTROL_INTEN = 0;
    WD_SoftRegLock();
    return;
}

/*!
 ******************************************************************************
 ** \brief Enable hardware watchdog timer Interrupt
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardIntEnable(void)
{
    WD_HardCtlRegUnLock();
    bFM3_HWWDT_WDG_CTL_INTEN = 1;
    return;
}



/*!
 ******************************************************************************
 ** \brief Disable hardware watchdog timer Interrupt
 **
 ** \param None	
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_HardIntDisable(void)
{
    WD_HardCtlRegUnLock();
    bFM3_HWWDT_WDG_CTL_INTEN = 0;
    return;
}



/*!
 ******************************************************************************
 ** \brief Clear software watchdog timer 
 **
 ** \param None
 ** 
 ** \return None
 **
 ******************************************************************************
 */ 
void WD_SoftClear(void)
{
    WD_SoftRegUnLock();
    FM3_SWWDT->WDOGINTCLR = WD_CLR_SWINT;
    WD_SoftRegLock();
    return;
}



/*!
 ******************************************************************************
 ** \brief Clear hardware watchdog timer 
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */
void WD_HardClear(void)
{
    WD_HardRegUnLock();
    FM3_HWWDT->WDG_ICL = WD_CLR_HWINT; 
    FM3_HWWDT->WDG_ICL = ~WD_CLR_HWINT;
    return;
}


/*!
 ******************************************************************************
 ** \brief Get software watchdog status 
 **
 ** \param None
 **
 ** \return Interrupt cause
 ** \retval RESET
 ** \retval SE
 **
 ******************************************************************************
 */
IntStatusT WD_SoftGetIntFlag()
{
    return (IntStatusT)bFM3_SWWDT_WDOGRIS_RIS;
}



/*!
 ******************************************************************************
 ** \brief Get hardware watchdog status 
 **
 ** \param None
 **
 ** \return Interrupt cause
 ** \retval RESET
 ** \retval SE
 **
 ******************************************************************************
 */
IntStatusT WD_HardGetIntFlag()
{
    WD_HardRegUnLock();
    return (IntStatusT)bFM3_HWWDT_WDG_RIS_RIS;
}



/*!
 ******************************************************************************
 ** \brief Read current value of software watchdog timer 
 **
 ** \param None
 **
 ** \return current counter value 
 **
 ******************************************************************************
 */
uint32_t WD_SoftReadInterval(void)
{
    return(FM3_SWWDT->WDOGVALUE);
}



/*!
 ******************************************************************************
 ** \brief Read current value of hardware watchdog timer
 **
 ** \param None
 **
 ** \return current counter value
 **
 ******************************************************************************
 */
uint32_t WD_HardReadInterval(void)
{
    return (FM3_HWWDT->WDG_VLR);
}






/*!
 ******************************************************************************
 ** \brief Software watchdog configuration
 **
 ** \param *pSWDconfigInfo point to SWD configuration structure
 **         
 ** \return None
 ** 
 **
 ******************************************************************************
 */
void WD_SoftConfig(WD_SoftConfigInfoT *pSWDconfigInfo)

{
    WD_SoftSetInterval(pSWDconfigInfo->SWDVal);
    pSWD_IntCallback = pSWDconfigInfo->pSWDIntHandlerCallback;
    return;
}



/*!
 ******************************************************************************
 ** \brief Hardware watchdog configuration
 **
 ** \param *pHWDconfigInfo point to HWD configuration structure
 **         
 ** \return None
 ** 
 **
 ******************************************************************************
 */
void WD_HardConfig(WD_HardConfigInfoT *pHWDconfigInfo)
{
    WD_HardSetInterval(pHWDconfigInfo->HWDVal);
    pHWD_IntCallback = pHWDconfigInfo->pHWDIntHandlerCallback;
    return;
}



/*!
 ******************************************************************************
 ** \brief Software watchdog interrupt handler
 **
 ** \param None
 **         
 ** \return None
 ** 
 ******************************************************************************
 */ 
void SWDT_Handler(void)
{
    if(WD_SoftGetIntFlag() == SET )
    {
        if(bFM3_SWWDT_WDOGCONTROL_RESEN == 0)
        {
            WD_SoftClear();
        }
        if(pSWD_IntCallback != NULL) 
        {
            pSWD_IntCallback();
        }
    }
}



/*!
 ******************************************************************************
 ** \brief Hardware watchdog interrupt handler
 **
 ** \param None
 **         
 ** \return None
 ** 
 ******************************************************************************
 */ 
void NMI_Handler(void)
{
    if(WD_HardGetIntFlag() == SET )
    {
        if(bFM3_HWWDT_WDG_CTL_RESEN == 0)
		{
		    WD_HardClear();
        }
        if(pHWD_IntCallback != NULL) 
        {
            pHWD_IntCallback();
        }
    }
}


/*****************************************************************************/

/* END OF FILE */
