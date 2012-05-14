/*!
 ******************************************************************************
 **
 ** \file example_pwm.c
 **
 ** \brief PWM timer sample code.
 **
 ** \author FSLA AE Team 
 **
 ** \version V0.1
 **
 ** \date 2011-11-10
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
#include <stdint.h>

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static uint32_t CntIntTrg,CntIntDuty,CntIntUnder;

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PwmIrqCallback(uint8_t Status);

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
extern void Delay(uint8_t Sec);


/*!
 ******************************************************************************
 ** \brief PWM timer example code
 **
 ** 1. Register initialization
 ** 2. Callback function initialization.
 ** 3. Enable interrupt.
 ** 4. Enable count operation.
 ** 5. Start soft trigger.
 ******************************************************************************
 */
void ExamplePwm(void)
{
  
    BT_PwmInitRegT reg;   
    uint8_t ch,interrupt,iomode;
    uint32_t t=0;
    
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("PWM Lib Example Program Start \n");
    printf("==================================================\n");
#endif
  
    /* Set Basetimer ch3 IO port */    
    FM3_GPIO->PFR4 |= 0x00001008;/* Use P43 and P4c */    
    FM3_GPIO->EPFR04 |= 0x04000000;/* Use TIOB3_0 and TIOA3_0 */
     
    /* Set requested channel */ 
    ch = BT_CH_3;  
    
    /* Set requested I/O mode */
    iomode = BT_IO_MODE_0;
    
    /* Set interrupt request */
    interrupt = BT_INT_ENABLE_UNDER|BT_INT_ENABLE_TRG|BT_INT_ENABLE_DUTY;  
    
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
    
    /* Set Irq callback function */
    reg.IrqCallback = PwmIrqCallback;
    
    /* Set IO Mode */
    BT_SetIOMode(ch,iomode);
    
    /* PWM register initialization */
    BT_PwmInit(ch,&reg); 
    
    /* Enable count operatoin */
    BT_CountEnable(ch);  
    
      
           
    /* Enable Interrupt */
    BT_PwmIntEnable(ch,interrupt);
    
    /* Start triggered by software */
    BT_SoftTrgEnable(ch);   

#ifdef DEBUG_MODE 
    printf("Cycle: %d\n", reg.Cycle);
    printf("Duty: %d\n", reg.Duty);       
#endif    
    

    
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("Enable Interrupt mode, waiting 5 seconds approximately\n");
#endif  
    
    
    /* Delay 5S approximately*/
    Delay(5); 
    
#ifdef DEBUG_MODE 
    printf("Interrupt times:\n"); 
    printf("BT_INT_TYP_TRG: %d\n", CntIntTrg);    
    printf("BT_INT_TYP_DUTY: %d\n", CntIntDuty);       
    printf("BT_INT_TYP_UNDER: %d\n", CntIntUnder);  
#endif
    

    
    BT_PwmIntDisable(ch,interrupt);
    

    
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("Disable Interrupt mode, waiting 5 seconds approximately\n");
#endif
    
    CntIntTrg = 0;
    CntIntDuty = 0;
    CntIntUnder = 0;   
    
    /* Delay 5S approximately*/
    Delay(5); 
    
#ifdef DEBUG_MODE 
    printf("Interrupt times:\n"); 
    printf("BT_INT_TYP_TRG: %d\n", CntIntTrg);    
    printf("BT_INT_TYP_DUTY: %d\n", CntIntDuty);       
    printf("BT_INT_TYP_UNDER: %d\n", CntIntUnder);  
#endif 
    
    /* Restart triggered by software */
    BT_SoftTrgEnable(ch); 
    
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("Enable query mode, waiting 5 seconds approximately\n");
#endif
 
    CntIntTrg = 0;
    CntIntDuty = 0;
    CntIntUnder = 0; 
    
    
    /* Interrupt query mode */
    do 
    {   
        if ((BT_GetIntRequest(ch)&BT_INT_TYP_TRG) == BT_INT_TYP_TRG)
        {
            BT_ClrIntRequest(ch,BT_INT_TYP_TRG);
            CntIntTrg++;
        }
        else if ((BT_GetIntRequest(ch)&BT_INT_TYP_DUTY) == BT_INT_TYP_DUTY)
        {
            BT_ClrIntRequest(ch,BT_INT_TYP_DUTY);
            CntIntDuty++;
        }
        else if ((BT_GetIntRequest(ch)&BT_INT_TYP_UNDER) == BT_INT_TYP_UNDER)
        {
            BT_ClrIntRequest(ch,BT_INT_TYP_UNDER);
            CntIntUnder++;
        }
        t++;
    } while(t <2500000UL);
    
#ifdef DEBUG_MODE
    printf("Interrupt request times:\n"); 
    printf("BT_INT_TYP_TRG: %d\n", CntIntTrg);    
    printf("BT_INT_TYP_DUTY: %d\n", CntIntDuty);       
    printf("BT_INT_TYP_UNDER: %d\n", CntIntUnder);  
#endif 
    
    BT_CountDisable(ch); 
    
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("PWM Lib Example Program End \n");
    printf("==================================================\n");
#endif
    
    
    while(1);
}
/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief User interrupt handler routine
 **
 ** \param Type Interrupt type
 **
 ** \note 1. User can use this call back function as interrupt handler.
 **       2. Set this function address to Irq callback function pointer array
 **          when initialization.
 **       3. Add user code in lines with '<<<'
 ******************************************************************************
 */
static void PwmIrqCallback(uint8_t Type)
{
 
    switch (Type) 
    {
        case BT_INT_TYP_TRG:
            //<<< user code here
            CntIntTrg++;
            break;
        case BT_INT_TYP_DUTY:
            //<<< user code here
            CntIntDuty++;
            break;
        case BT_INT_TYP_UNDER:
            //<<< user code here
            CntIntUnder++;
            break;
        default:
            //<<< user code here
            break;
    }    
}



/*****************************************************************************/
/* END OF FILE */
