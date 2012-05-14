/*!
 ******************************************************************************
 **
 ** \file int_fm3.c
 **
 ** \brief this file provides all interrupt drivers
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
#include "int_fm3.h"


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
 ** \brief interrupt Drq select setting
 **
 ** \param ch channel.
 **        This parameter can be one of the following values:
 ** \arg   0 channel 0
 ** \arg   1 channel 1
 ** \arg   ... ...
 ** \arg   31 channel 31

 ** \param sel selection setting.
 **        This parameter can be one of the following values:
 ** \arg   0 set interrupt signal to CPU
 **        1 set interrupt signal to DMA
 **
 ** \retval None
 **
 ******************************************************************************
 */
void Interupt_DrqSelSetting(uint8_t ch, uint8_t sel)
{
    uint32_t pos=1;
    
    /* Check the parameter */
    ASSERT(IS_DrqSel_CH_VALID(ch));
    
    pos=pos<<ch;
    if (sel == 1)
    {
      FM3_INTREQ->DRQSEL = FM3_INTREQ->DRQSEL | pos;//1: DRQ to DMA
    }
    else
    {
        pos=~pos;
        FM3_INTREQ->DRQSEL = FM3_INTREQ->DRQSEL & pos;//0: DRQ to CPU
    }
}


/*!
 ******************************************************************************
 ** \brief interrupt EXC02 read
 **
 ** \param none
 **
 ** \retval EXC02 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQEXC02Read(void)
{
    return (FM3_INTREQ->EXC02MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ00 read
 **
 ** \param none
 **
 ** \retval IRQ00 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ00MONRead(void)
{
    return (FM3_INTREQ->IRQ00MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ01 read
 **
 ** \param none
 **
 ** \retval IRQ01 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ01MONRead(void)
{
    return (FM3_INTREQ->IRQ01MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ02 read
 **
 ** \param none
 **
 ** \retval IRQ02 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ02MONRead(void)
{
    return (FM3_INTREQ->IRQ02MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ03 read
 **
 ** \param none
 **
 ** \retval IRQ03 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ03MONRead(void)
{
    return (FM3_INTREQ->IRQ03MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ04 read
 **
 ** \param none
 **
 ** \retval IRQ04 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ04MONRead(void)
{
    return (FM3_INTREQ->IRQ04MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ05 read
 **
 ** \param none
 **
 ** \retval IRQ05 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ05MONRead(void)
{
    return (FM3_INTREQ->IRQ05MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ06 read
 **
 ** \param none
 **
 ** \retval IRQ06 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ06MONRead(void)
{
    return (FM3_INTREQ->IRQ06MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ07 read
 **
 ** \param none
 **
 ** \retval IRQ07 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ07MONRead(void)
{
    return (FM3_INTREQ->IRQ07MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ08 read
 **
 ** \param none
 **
 ** \retval IRQ08 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ08MONRead(void)
{
    return (FM3_INTREQ->IRQ08MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ09 read
 **
 ** \param none
 **
 ** \retval IRQ09 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ09MONRead(void)
{
    return (FM3_INTREQ->IRQ09MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ10 read
 **
 ** \param none
 **
 ** \retval IRQ10 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ10MONRead(void)
{
    return (FM3_INTREQ->IRQ10MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ11 read
 **
 ** \param none
 **
 ** \retval IRQ11 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ11MONRead(void)
{
    return (FM3_INTREQ->IRQ11MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ12 read
 **
 ** \param none
 **
 ** \retval IRQ12 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ12MONRead(void)
{
    return (FM3_INTREQ->IRQ12MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ13 read
 **
 ** \param none
 **
 ** \retval IRQ13 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ13MONRead(void)
{
    return (FM3_INTREQ->IRQ13MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ14 read
 **
 ** \param none
 **
 ** \retval IRQ14 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ14MONRead(void)
{
    return (FM3_INTREQ->IRQ14MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ15 read
 **
 ** \param none
 **
 ** \retval IRQ15 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ15MONRead(void)
{
    return (FM3_INTREQ->IRQ15MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ16 read
 **
 ** \param none
 **
 ** \retval IRQ16 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ16MONRead(void)
{
    return (FM3_INTREQ->IRQ16MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ17 read
 **
 ** \param none
 **
 ** \retval IRQ17 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ17MONRead(void)
{
    return (FM3_INTREQ->IRQ17MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ18 read
 **
 ** \param none
 **
 ** \retval IRQ18 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ18MONRead(void)
{
    return (FM3_INTREQ->IRQ18MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ19 read
 **
 ** \param none
 **
 ** \retval IRQ19 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ19MONRead(void)
{
    return (FM3_INTREQ->IRQ19MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ20 read
 **
 ** \param none
 **
 ** \retval IRQ20 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ20MONRead(void)
{
    return (FM3_INTREQ->IRQ20MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ21 read
 **
 ** \param none
 **
 ** \retval IRQ21 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ21MONRead(void)
{
    return (FM3_INTREQ->IRQ21MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ22 read
 **
 ** \param none
 **
 ** \retval IRQ22 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ22MONRead(void)
{
    return (FM3_INTREQ->IRQ22MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ23 read
 **
 ** \param none
 **
 ** \retval IRQ23 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ23MONRead(void)
{
    return (FM3_INTREQ->IRQ23MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ24 read
 **
 ** \param none
 **
 ** \retval IRQ24 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ24MONRead(void)
{
    return (FM3_INTREQ->IRQ24MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ25 read
 **
 ** \param none
 **
 ** \retval IRQ25 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ25MONRead(void)
{
    return (FM3_INTREQ->IRQ25MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ26 read
 **
 ** \param none
 **
 ** \retval IRQ26 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ26MONRead(void)
{
    return (FM3_INTREQ->IRQ26MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ27 read
 **
 ** \param none
 **
 ** \retval IRQ27 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ27MONRead(void)
{
    return (FM3_INTREQ->IRQ27MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ28 read
 **
 ** \param none
 **
 ** \retval IRQ28 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ28MONRead(void)
{
    return (FM3_INTREQ->IRQ28MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ29 read
 **
 ** \param none
 **
 ** \retval IRQ29 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ29MONRead(void)
{
    return (FM3_INTREQ->IRQ29MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ30 read
 **
 ** \param none
 **
 ** \retval IRQ30 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ30MONRead(void)
{
    return (FM3_INTREQ->IRQ30MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ31 read
 **
 ** \param none
 **
 ** \retval IRQ31 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ31MONRead(void)
{
    return (FM3_INTREQ->IRQ31MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ32 read
 **
 ** \param none
 **
 ** \retval IRQ32 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ32MONRead(void)
{
    return (FM3_INTREQ->IRQ32MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ33 read
 **
 ** \param none
 **
 ** \retval IRQ33 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ33MONRead(void)
{
    return (FM3_INTREQ->IRQ33MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ34 read
 **
 ** \param none
 **
 ** \retval IRQ34 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ34MONRead(void)
{
    return (FM3_INTREQ->IRQ34MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ35 read
 **
 ** \param none
 **
 ** \retval IRQ35 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ35MONRead(void)
{
    return (FM3_INTREQ->IRQ35MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ36 read
 **
 ** \param none
 **
 ** \retval IRQ36 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ36MONRead(void)
{
    return (FM3_INTREQ->IRQ36MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ37 read
 **
 ** \param none
 **
 ** \retval IRQ37 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ37MONRead(void)
{
    return (FM3_INTREQ->IRQ37MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ38 read
 **
 ** \param none
 **
 ** \retval IRQ38 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ38MONRead(void)
{
    return (FM3_INTREQ->IRQ38MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ39 read
 **
 ** \param none
 **
 ** \retval IRQ39 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ39MONRead(void)
{
    return (FM3_INTREQ->IRQ39MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ40 read
 **
 ** \param none
 **
 ** \retval IRQ40 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ40MONRead(void)
{
    return (FM3_INTREQ->IRQ40MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ41 read
 **
 ** \param none
 **
 ** \retval IRQ41 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ41MONRead(void)
{
    return (FM3_INTREQ->IRQ41MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ42 read
 **
 ** \param none
 **
 ** \retval IRQ42 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ42MONRead(void)
{
    return (FM3_INTREQ->IRQ42MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ43 read
 **
 ** \param none
 **
 ** \retval IRQ43 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ43MONRead(void)
{
    return (FM3_INTREQ->IRQ43MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ44 read
 **
 ** \param none
 **
 ** \retval IRQ44 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ44MONRead(void)
{
    return (FM3_INTREQ->IRQ44MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ45 read
 **
 ** \param none
 **
 ** \retval IRQ45 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ45MONRead(void)
{
    return (FM3_INTREQ->IRQ45MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ46 read
 **
 ** \param none
 **
 ** \retval IRQ46 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ46MONRead(void)
{
    return (FM3_INTREQ->IRQ46MON);
}

/*!
 ******************************************************************************
 ** \brief interrupt IRQ47 read
 **
 ** \param none
 **
 ** \retval IRQ47 registor value
 **
 ******************************************************************************
 */
uint32_t INTERRUPT_IRQ47MONRead(void)
{
    return (FM3_INTREQ->IRQ47MON);
}

/*!
 ******************************************************************************
 ** \brief disable global interrupt
 **
 ** \param none
 **
 ** \retval none
 **
 ******************************************************************************
 */
void INTERRUPT_DisableGlobInt(void)
{
    __disable_irq();
}

/*!
 ******************************************************************************
 ** \brief enable global interrupt
 **
 ** \param none 

 ** \retval None
 **
 ******************************************************************************
 */
void INTERRUPT_EnableGlobInt(void)
{
    __enable_irq();
}

/*!
 ******************************************************************************
 ** \brief disable certain interrupt
 **
 ** \param ch IRQn number. 
 **        This parameter can be one of the following values:
 ** \arg      NMI_IRQn:           Non Maskable
 ** \arg      HardFault_IRQn:     Hard Fault
 ** \arg      MemManage_IRQn:     Memory Management
 ** \arg      BusFault_IRQn:      Bus Fault
 ** \arg      UsageFault_IRQn:    Usage Fault
 ** \arg      SVC_IRQn:           SV Call
 ** \arg      DebugMonitor_IRQn:  Debug Monitor
 ** \arg      PendSV_IRQn:        Pend SV
 ** \arg      SysTick_IRQn:       System Tick
 ** \arg      CSV_IRQn:           Clock Super Visor
 ** \arg      SWDT_IRQn:          Software Watchdog Timer
 ** \arg      LVD_IRQn:           Low Voltage Detector
 ** \arg      WFG_IRQn:           Wave Form Generator
 ** \arg      EXINT0_7_IRQn:      External Interrupt Request ch.0 to ch.7
 ** \arg      EXINT8_15_IRQn:     External Interrupt Request ch.8 to ch.15
 ** \arg      DTIM_QDU_IRQn:      Dual Timer / Quad Decoder
 ** \arg      MFS0RX_IRQn:        MultiFunction Serial Reception ch.0
 ** \arg      MFS0TX_IRQn:        MultiFunction Serial Transmission ch.0
 ** \arg      MFS1RX_IRQn:        MultiFunction Serial Reception ch.1
 ** \arg      MFS1TX_IRQn:        MultiFunction Serial Transmission ch.1
 ** \arg      MFS2RX_IRQn:        MultiFunction Serial Reception ch.2
 ** \arg      MFS2TX_IRQn:        MultiFunction Serial Transmission ch.2
 ** \arg      MFS3RX_IRQn:        MultiFunction Serial Reception ch.3
 ** \arg      MFS3TX_IRQn:        MultiFunction Serial Transmission ch.3
 ** \arg      MFS4RX_IRQn:        MultiFunction Serial Reception ch.4
 ** \arg      MFS4TX_IRQn:        MultiFunction Serial Transmission ch.4
 ** \arg      MFS5RX_IRQn:        MultiFunction Serial Reception ch.5
 ** \arg      MFS5TX_IRQn:        MultiFunction Serial Transmission ch.5
 ** \arg      MFS6RX_IRQn:        MultiFunction Serial Reception ch.6
 ** \arg      MFS6TX_IRQn:        MultiFunction Serial Transmission ch.6
 ** \arg      MFS7RX_IRQn:        MultiFunction Serial Reception ch.7
 ** \arg      MFS7TX_IRQn:        MultiFunction Serial Transmission ch.7
 ** \arg      PPG_IRQn:           PPG
 ** \arg      OSC_PLL_WC_IRQn:    OSC / PLL / Watch Counter
 ** \arg      ADC0_IRQn:          ADC0
 ** \arg      ADC1_IRQn:          ADC1
 ** \arg      ADC2_IRQn:          ADC2
 ** \arg      FRTIM_IRQn:         Free-run Timer
 ** \arg      INCAP_IRQn:         Input Capture
 ** \arg      OUTCOMP_IRQn:       Output Compare
 ** \arg      BTIM_IRQn:          Base Timer ch.0 to ch.7
 ** \arg      CAN0_IRQn:          CAN ch.0
 ** \arg      CAN1_IRQn:          CAN ch.1
 ** \arg      USBF_IRQn:          USB Function
 ** \arg      USBF_USBH_IRQn:     USB Function / USB HOST
 ** \arg      DMAC0_IRQn:         DMAC ch.0
 ** \arg      DMAC1_IRQn:         DMAC ch.1
 ** \arg      DMAC2_IRQn:         DMAC ch.2
 ** \arg      DMAC3_IRQn:         DMAC ch.3
 ** \arg      DMAC4_IRQn:         DMAC ch.4
 ** \arg      DMAC5_IRQn:         DMAC ch.5
 ** \arg      DMAC6_IRQn:         DMAC ch.6
 ** \arg      DMAC7_IRQn:         DMAC ch.7

 ** \retval None
 **
 ******************************************************************************
 */
void INTERRUPT_DisableInterrupt(IRQn_Type ch)
{
    NVIC_DisableIRQ(ch);
}

/*!
 ******************************************************************************
 ** \brief enable certain interrupt
 **
 ** \param ch IRQ channel
 **        This parameter can be one of the following values:
 ** \arg      NMI_IRQn:           Non Maskable
 ** \arg      HardFault_IRQn:     Hard Fault
 ** \arg      MemManage_IRQn:     Memory Management
 ** \arg      BusFault_IRQn:      Bus Fault
 ** \arg      UsageFault_IRQn:    Usage Fault
 ** \arg      SVC_IRQn:           SV Call
 ** \arg      DebugMonitor_IRQn:  Debug Monitor
 ** \arg      PendSV_IRQn:        Pend SV
 ** \arg      SysTick_IRQn:       System Tick
 ** \arg      CSV_IRQn:           Clock Super Visor
 ** \arg      SWDT_IRQn:          Software Watchdog Timer
 ** \arg      LVD_IRQn:           Low Voltage Detector
 ** \arg      WFG_IRQn:           Wave Form Generator
 ** \arg      EXINT0_7_IRQn:      External Interrupt Request ch.0 to ch.7
 ** \arg      EXINT8_15_IRQn:     External Interrupt Request ch.8 to ch.15
 ** \arg      DTIM_QDU_IRQn:      Dual Timer / Quad Decoder
 ** \arg      MFS0RX_IRQn:        MultiFunction Serial Reception ch.0
 ** \arg      MFS0TX_IRQn:        MultiFunction Serial Transmission ch.0
 ** \arg      MFS1RX_IRQn:        MultiFunction Serial Reception ch.1
 ** \arg      MFS1TX_IRQn:        MultiFunction Serial Transmission ch.1
 ** \arg      MFS2RX_IRQn:        MultiFunction Serial Reception ch.2
 ** \arg      MFS2TX_IRQn:        MultiFunction Serial Transmission ch.2
 ** \arg      MFS3RX_IRQn:        MultiFunction Serial Reception ch.3
 ** \arg      MFS3TX_IRQn:        MultiFunction Serial Transmission ch.3
 ** \arg      MFS4RX_IRQn:        MultiFunction Serial Reception ch.4
 ** \arg      MFS4TX_IRQn:        MultiFunction Serial Transmission ch.4
 ** \arg      MFS5RX_IRQn:        MultiFunction Serial Reception ch.5
 ** \arg      MFS5TX_IRQn:        MultiFunction Serial Transmission ch.5
 ** \arg      MFS6RX_IRQn:        MultiFunction Serial Reception ch.6
 ** \arg      MFS6TX_IRQn:        MultiFunction Serial Transmission ch.6
 ** \arg      MFS7RX_IRQn:        MultiFunction Serial Reception ch.7
 ** \arg      MFS7TX_IRQn:        MultiFunction Serial Transmission ch.7
 ** \arg      PPG_IRQn:           PPG
 ** \arg      OSC_PLL_WC_IRQn:    OSC / PLL / Watch Counter
 ** \arg      ADC0_IRQn:          ADC0
 ** \arg      ADC1_IRQn:          ADC1
 ** \arg      ADC2_IRQn:          ADC2
 ** \arg      FRTIM_IRQn:         Free-run Timer
 ** \arg      INCAP_IRQn:         Input Capture
 ** \arg      OUTCOMP_IRQn:       Output Compare
 ** \arg      BTIM_IRQn:          Base Timer ch.0 to ch.7
 ** \arg      CAN0_IRQn:          CAN ch.0
 ** \arg      CAN1_IRQn:          CAN ch.1
 ** \arg      USBF_IRQn:          USB Function
 ** \arg      USBF_USBH_IRQn:     USB Function / USB HOST
 ** \arg      DMAC0_IRQn:         DMAC ch.0
 ** \arg      DMAC1_IRQn:         DMAC ch.1
 ** \arg      DMAC2_IRQn:         DMAC ch.2
 ** \arg      DMAC3_IRQn:         DMAC ch.3
 ** \arg      DMAC4_IRQn:         DMAC ch.4
 ** \arg      DMAC5_IRQn:         DMAC ch.5
 ** \arg      DMAC6_IRQn:         DMAC ch.6
 ** \arg      DMAC7_IRQn:         DMAC ch.7

 ** \retval None
 **
 ******************************************************************************
 */
void INTERRUPT_EnableInterrupt(IRQn_Type ch)
{
    NVIC_EnableIRQ(ch);
}

/*!
 ******************************************************************************
 ** \brief set certain interrupt priority
 **
 ** \param ch IRQ channel.
 **        This parameter can be one of the following values:
 ** \arg      NMI_IRQn:           Non Maskable
 ** \arg      HardFault_IRQn:     Hard Fault
 ** \arg      MemManage_IRQn:     Memory Management
 ** \arg      BusFault_IRQn:      Bus Fault
 ** \arg      UsageFault_IRQn:    Usage Fault
 ** \arg      SVC_IRQn:           SV Call
 ** \arg      DebugMonitor_IRQn:  Debug Monitor
 ** \arg      PendSV_IRQn:        Pend SV
 ** \arg      SysTick_IRQn:       System Tick
 ** \arg      CSV_IRQn:           Clock Super Visor
 ** \arg      SWDT_IRQn:          Software Watchdog Timer
 ** \arg      LVD_IRQn:           Low Voltage Detector
 ** \arg      WFG_IRQn:           Wave Form Generator
 ** \arg      EXINT0_7_IRQn:      External Interrupt Request ch.0 to ch.7
 ** \arg      EXINT8_15_IRQn:     External Interrupt Request ch.8 to ch.15
 ** \arg      DTIM_QDU_IRQn:      Dual Timer / Quad Decoder
 ** \arg      MFS0RX_IRQn:        MultiFunction Serial Reception ch.0
 ** \arg      MFS0TX_IRQn:        MultiFunction Serial Transmission ch.0
 ** \arg      MFS1RX_IRQn:        MultiFunction Serial Reception ch.1
 ** \arg      MFS1TX_IRQn:        MultiFunction Serial Transmission ch.1
 ** \arg      MFS2RX_IRQn:        MultiFunction Serial Reception ch.2
 ** \arg      MFS2TX_IRQn:        MultiFunction Serial Transmission ch.2
 ** \arg      MFS3RX_IRQn:        MultiFunction Serial Reception ch.3
 ** \arg      MFS3TX_IRQn:        MultiFunction Serial Transmission ch.3
 ** \arg      MFS4RX_IRQn:        MultiFunction Serial Reception ch.4
 ** \arg      MFS4TX_IRQn:        MultiFunction Serial Transmission ch.4
 ** \arg      MFS5RX_IRQn:        MultiFunction Serial Reception ch.5
 ** \arg      MFS5TX_IRQn:        MultiFunction Serial Transmission ch.5
 ** \arg      MFS6RX_IRQn:        MultiFunction Serial Reception ch.6
 ** \arg      MFS6TX_IRQn:        MultiFunction Serial Transmission ch.6
 ** \arg      MFS7RX_IRQn:        MultiFunction Serial Reception ch.7
 ** \arg      MFS7TX_IRQn:        MultiFunction Serial Transmission ch.7
 ** \arg      PPG_IRQn:           PPG
 ** \arg      OSC_PLL_WC_IRQn:    OSC / PLL / Watch Counter
 ** \arg      ADC0_IRQn:          ADC0
 ** \arg      ADC1_IRQn:          ADC1
 ** \arg      ADC2_IRQn:          ADC2
 ** \arg      FRTIM_IRQn:         Free-run Timer
 ** \arg      INCAP_IRQn:         Input Capture
 ** \arg      OUTCOMP_IRQn:       Output Compare
 ** \arg      BTIM_IRQn:          Base Timer ch.0 to ch.7
 ** \arg      CAN0_IRQn:          CAN ch.0
 ** \arg      CAN1_IRQn:          CAN ch.1
 ** \arg      USBF_IRQn:          USB Function
 ** \arg      USBF_USBH_IRQn:     USB Function / USB HOST
 ** \arg      DMAC0_IRQn:         DMAC ch.0
 ** \arg      DMAC1_IRQn:         DMAC ch.1
 ** \arg      DMAC2_IRQn:         DMAC ch.2
 ** \arg      DMAC3_IRQn:         DMAC ch.3
 ** \arg      DMAC4_IRQn:         DMAC ch.4
 ** \arg      DMAC5_IRQn:         DMAC ch.5
 ** \arg      DMAC6_IRQn:         DMAC ch.6
 ** \arg      DMAC7_IRQn:         DMAC ch.7

 ** \param prio interrupt priority
 **        This parameter can be one of the following values:
 ** \arg   0: priority 0(high)
 ** \arg   1: priority 1
 ** \arg   ... ...
 ** \arg   16: priority 16(low)

 ** \retval None
 **
 ******************************************************************************
 */
void INTERRUPT_SetPrio(IRQn_Type ch, uint32_t prio)
{
    NVIC_SetPriority (ch, prio);
}