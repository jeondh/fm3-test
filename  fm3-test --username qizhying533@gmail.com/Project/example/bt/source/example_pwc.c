/*!
 ******************************************************************************
 **
 ** \file example_pwc.c
 **
 ** \brief PWC timer sample code.
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
#define MEASURE_CNT_MAX 10


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static uint32_t CntIntMeasure,CntIntOverflow,CntMeasureErr;
static uint32_t MeasureResult[MEASURE_CNT_MAX];
static uint8_t PwcChannel,PwcTimermode;

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PwcIrqCallback(uint8_t Status);

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
extern void Delay(uint8_t Sec);

/*!
 ******************************************************************************
 ** \brief PWC timer example code
 **
 ** 1. Register initialization
 ** 2. Callback function initialization.
 ** 3. Enable interrupt.
 ** 4. Enable count operation.
 ******************************************************************************
 */
void ExamplePwc(void)
{
  
    BT_PwcInitRegT reg;   
    uint8_t interrupt,iomode;
    uint32_t i;
    
    #ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("PWC Lib Example Program Start \n");
    printf("==================================================\n");
    #endif
  
    /* Set IO port */
    FM3_GPIO->PFR4 |= 0x00000201;/* Use P40 and P49 */
    FM3_GPIO->EPFR04 |= 0x00000004;/* Use TIOB0_0 and TIOA0_0 */ 
        
    /* Set requested channel,If 32-bit mode used, use CH 0,2,4,6 */
    PwcChannel = BT_CH_0;
    
    /* Set requested I/O mode */
    iomode = BT_IO_MODE_0;   
    
    /* Set interrupt request */
    interrupt = BT_INT_ENABLE_MEASURE|BT_INT_ENABLE_OVERFLOW;  
    
    PwcTimermode = BT_32BIT_TIMER;
    
    /* Enable Bastimner Interrupt */
    NVIC_EnableIRQ(BTIM_IRQn);
    
    /* Set initialization data */
    reg.Clock = BT_CLK_DIV_1;
    reg.MeasureEdge = BT_PWC_EDGE_LOW;
    reg.TimerMode = PwcTimermode;
    reg.Mode = BT_MODE_CONTINUOUS;   

    /* Set Irq callback function */
    reg.IrqCallback = PwcIrqCallback;
    
    /* Set IO Mode */
    BT_SetIOMode(PwcChannel,iomode);
    
    /* PWM register initialization */
    BT_PwcInit(PwcChannel,&reg);
    
    /* Enable Interrupt */
    BT_PwcIntEnable(PwcChannel,interrupt);
    
    /* Enable count operatoin */
    BT_CountEnable(PwcChannel);   

 
    

    
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("Enable Interrupt mode, Waiting for mesaurment compeleted \n");
#endif  
    
    
    /* Waiting for mesaurment compeleted*/
    while(CntIntMeasure < MEASURE_CNT_MAX);
    
    BT_PwcIntDisable(PwcChannel,interrupt);
    
#ifdef DEBUG_MODE 
    printf("Interrupt times:\n"); 
    printf("BT_INT_TYP_MEASURE: %d\n", CntIntMeasure);    
    printf("BT_INT_TYP_OVERFLOW: %d\n", CntIntOverflow);
    printf("Measure error: %d\n", CntMeasureErr); 
    printf("Measurement result 0: %d\n", MeasureResult[0]); 
    printf("Measurement result 1: %d\n", MeasureResult[1]); 
    printf("Measurement result end: %d\n", MeasureResult[MEASURE_CNT_MAX-1]);     
#endif     

    
 
#ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("Disable Interrupt, enable query mode, Waiting for mesaurment compeleted\n");
#endif
 
    CntIntMeasure = 0;
    CntIntOverflow = 0;
    CntMeasureErr = 0; 
    
    for(i = 0; i < MEASURE_CNT_MAX; i++)
    {
        MeasureResult[i] = 0;
    } 

    
    
    /* Interrupt query mode */
    do 
    {   
        if ((BT_GetIntRequest(PwcChannel)&BT_INT_TYP_MEASURE) == BT_INT_TYP_MEASURE)
        {
            
            BT_ClrIntRequest(PwcChannel,BT_INT_TYP_MEASURE);
            if (PwcTimermode == BT_16BIT_TIMER)
            {
                MeasureResult[CntIntMeasure] = BT_Get16bitMeasureData(PwcChannel) +
                    (CntIntOverflow * 0xffff);
            }
            else //BT_32IT_TIMER
            {
                //MeasureResult[CntIntMeasure] = BT_Get32bitMeasureData(PwcChannel);
            }
            CntIntOverflow = 0;
            CntIntMeasure++;
            
            
            if (BT_GetMeasureError(PwcChannel))
            {            
                CntMeasureErr++;
            }
        }
        else if ((BT_GetIntRequest(PwcChannel)&BT_INT_TYP_OVERFLOW) == BT_INT_TYP_OVERFLOW)
        {
            BT_ClrIntRequest(PwcChannel,BT_INT_TYP_OVERFLOW);
            CntIntOverflow++;
        }
        

    } while(CntIntMeasure < MEASURE_CNT_MAX);
    
#ifdef DEBUG_MODE
    printf("Interrupt request times:\n"); 
    printf("BT_INT_TYP_MEASURE: %d\n", CntIntMeasure);    
    printf("BT_INT_TYP_OVERFLOW: %d\n", CntIntOverflow); 
    printf("Measure error: %d\n", CntMeasureErr); 
    printf("Measurement result 0: %d\n", MeasureResult[0]); 
    printf("Measurement result 1: %d\n", MeasureResult[1]); 
    printf("Measurement result end: %d\n", MeasureResult[MEASURE_CNT_MAX-1]);     
#endif 
    
    BT_CountDisable(PwcChannel); 
    
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
 ** \brief PWC timer user interrupt handler routine
 **
 ** \param Type Interrupt type
 **
 ** \note 1. User can use this call back function as interrupt handler.
 **       2. Set this function address to Irq callback function pointer array
 **          when initialization.
 **       3. Add user code in lines with '<<<'
 **       4. For PWC timer, interrupt request bit should be cleared by reading                 
 **          the measurement result (DTBF) in user code.
 **       5. In 32-bit mode, the value of the lower 16 bits is read for the even  
 **          channel and that of the upper 16 bits for the odd channel. 
 ******************************************************************************
 */
static void PwcIrqCallback(uint8_t Type)
{
 
    switch (Type) 
    {
        case BT_INT_TYP_MEASURE:          
            //<<< user code here

            if (PwcTimermode == BT_16BIT_TIMER) 
            {
                MeasureResult[CntIntMeasure] = BT_Get16bitMeasureData(PwcChannel) +
                    (CntIntOverflow * 0xffff);
            }
            else //BT_32IT_TIMER
            {
                MeasureResult[CntIntMeasure] = BT_Get32bitMeasureData(PwcChannel);
            }
            if (CntIntMeasure <MEASURE_CNT_MAX)
            {                
                CntIntMeasure++;
            } 
            CntIntOverflow = 0;
            break;
        case BT_INT_TYP_OVERFLOW:
            //<<< user code here
            CntIntOverflow++;
            break;
        default:
            //<<< user code here
            break;
    }    
}



/*****************************************************************************/
/* END OF FILE */
