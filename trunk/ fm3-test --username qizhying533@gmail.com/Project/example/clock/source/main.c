/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \brief One sentence to describe the file.
 **
 ** Add here more detailed description if needed ...
 **
 ** \author FSLA AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-12-30
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
#include "mb9bf50x_lib.h"

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PwmTest(void);
static void Delay(uint8_t Sec);

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


void main(void)
{     
    /* Ouptput pwm waveform from P40 */
    PwmTest(); 
    CLOCK_MasterClockSwitch(CLOCK_HIGH_CR); //pwm cycle = 500us in 4M High-CR
    Delay(5);     
    CLOCK_MasterClockSwitch(CLOCK_LOW_CR);  //pwm cycle = 20ms in 100k Low-CR
    Delay(5);     
    CLOCK_MasterClockSwitch(CLOCK_MAIN_OSC);//pwm cycle = 500us in 4M Main OSC
    Delay(5);    
    CLOCK_MasterClockSwitch(CLOCK_SUB_OSC); //pwm cycle = 61ms in 32768 Sub OSC
    Delay(5);      
    CLOCK_MasterClockSwitch(CLOCK_PLL_OSC); //pwm cycle = 25us in 80M PLL OSC
    Delay(5); 

    while(1);
}


static void PwmTest(void)
{
    BT_PwmInitRegT reg;   
    uint8_t ch,iomode;
    
    /* Set Basetimer ch0 IO port */    
    FM3_GPIO->PFR4 |= 0x00000201;/* Use P40 and P49 */
    FM3_GPIO->EPFR04 |= 0x00000004;/* Use TIOB0_0 and TIOA0_0 */ 
     
    /* Set requested channel */ 
    ch = BT_CH_0;  
    
    /* Set requested I/O mode */
    iomode = BT_IO_MODE_0; 
    
    /* Enable Bastimner Interrupt */
    NVIC_EnableIRQ(BTIM_IRQn);
    
    /* Set initialization data */
    reg.Cycle = 999;   //Cycle = T*(m+1) = 25us
    reg.Duty = 199;     //Duty = T*(n+1) = 5us
    reg.Clock = BT_CLK_DIV_1;
    reg.Restart = BT_RESTART_ENABLE;
    reg.OutputMask = BT_MASK_DISABLE;
    reg.InputEdge = BT_TRG_DISABLE;
    reg.Polarity = BT_POLARITY_NORMAL;
    reg.Mode = BT_MODE_CONTINUOUS;
    
    /* Set IO Mode */
    BT_SetIOMode(ch,iomode);
    
    /* PWM register initialization */
    BT_PwmInit(ch,&reg); 
    
    /* Enable count operatoin */
    BT_CountEnable(ch);        

    
    /* Start triggered by software */
    BT_SoftTrgEnable(ch);    
  
}

static void Delay(uint8_t Sec)
{
    int32_t i,j;
    
   
    if (SystemCoreClock == 80000000UL)
    {
        j = Sec*12500000UL;
    }
    else if (SystemCoreClock == 4000000UL)
    {
        j = Sec*625000UL;
    }
    else if(SystemCoreClock == 100000UL)
    {
        j = Sec*15600UL;
    }
    else if(SystemCoreClock == 32768UL)
    {    
        j = Sec*5120UL;
    }
  
   
    i = 0;
    while (1) 
    {
        i++;
        if (i > j) 
        {
            break;
        }
    }   
}
/*****************************************************************************/
/* END OF FILE */
