/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \brief Implement USB HID mouse function on the FSSDC-9B506-EVB
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

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "includes.h"

/*! \brief Get EPxC register address */
#define DT0_TICK_PER_SEC      100
/*! \brief Mouse delta value */
#define MOUSE_DELTA           4

/*variable for clitical section entry control*/
uint32_t g_CriticalEnterCnt;

/*! \brief Dual timer enter flag */
uint32_t g_DTEnterFlag;

/*!
 ******************************************************************************
 ** \brief Dual timer interrupt handler
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */ 
void DT_QDU_IRQHandler(void)
{
    g_DTEnterFlag= TRUE;
    if(bFM3_DTIM_TIMER1RIS_TIMERXRIS)
    {
        FM3_DTIM->TIMER1INTCLR = 1; /* Clear Interrupt flag */
    }
}

/*!
 ******************************************************************************
 ** \brief Main function
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */ 
void main(void)
{
    ButtonsT buttCtrl;
    int8_t x = 0, y = 0;
    uint8_t buttons = 0, buttonsHold = 0;
    Buttons_Init();
    /*Set Timer 1 Load Value*/
    FM3_DTIM->TIMER1LOAD = __HCLK              /*Base Clock*/ 
                            /2                 /*APB Devider*/
                            /256               /*Timer devider*/
                            /DT0_TICK_PER_SEC; /*100 times per second*/
    /*Set Timer 1 Mode*/
    FM3_DTIM->TIMER1CONTROL = (0<<0) |     /*wrapping mode*/
                              (1<<1) |     /*1 = 32-bit counter*/
                              (2<<2) |     /*8 stages of prescale, clock is divided by 256*/
                              (1<<5) |     /*Interrupt Enable*/
                              (1<<6) |     /*Timer is in periodic mode*/
                              (1<<7) ;     /*Timer enabled*/  
    /*Enable Dual Timer Interrup*/
    NVIC_EnableIRQ(DTIM_QDU_IRQn);
    HID_Init();
    
    while(1)
    {
        if(g_DTEnterFlag)
        {
            g_DTEnterFlag = FALSE;
            if(USB_CoreReq(UsbCoreReqDevState) == UsbDevStatusConfigured)
            {
                buttCtrl = Buttons_GetStatus();

                // Buttons and Joystick processing
                if(buttCtrl.BtUp)
                {
                    y -= MOUSE_DELTA;
                }
                else if(buttCtrl.BtDown)
                {
                    y += MOUSE_DELTA;
                }

                if(buttCtrl.BtRight)
                {
                    x += MOUSE_DELTA;
                }
                else if(buttCtrl.BtLeft)
                {
                    x -= MOUSE_DELTA;
                }

                if(buttCtrl.Bt1Click)
                {
                    buttons |= 1;
                }
                else
                {
                    buttons &= ~1;
                }

                if(buttCtrl.Bt2Click)
                {
                    buttons |= 2;
                }
                else
                {
                    buttons &=~2;
                }

                if(y || x  || buttons || (buttonsHold ^ buttons))
                {
                    //USB_WakeUp();  // wake-up
                    // Send report
                    HID_MouseSendReport(x,y,buttons);
                    buttonsHold = buttons;
                    y = x = buttons = 0;
                }   
            }
        }
    }
    /*Main Loop*/
}

