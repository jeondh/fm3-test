/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-12
 **
 ** \brief This file provides an example to detect the external interrupt 
 **        
 **       
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
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
#define ADC12_MaxValue   4096
#define ADC12_Volt   3300
#define ADC12_CmpData 0x800
#define ADC12_SamplingTime 8
#define BUFFER_SIZE 128
/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
ADC12_UnitT ADC_Unit;
uint16_t ADC12_ScanData[128];
uint16_t ADC12_ScanInfo[128];
uint16_t ADC12_ScanStage;
uint8_t ADC12_DataCnt;
uint8_t ADC12_DataSize;
uint8_t Read_Finished = 0;
uint16_t ADC12_Value;
ADC12_Config ADC12_Init;
/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

static void ADC12_Callback(int32_t Status)
{
   

    switch (Status) 
    {
        case Adc12_IRQSTATUS_SCAN:

            break;
        
        case Adc12_IRQSTATUS_PRI:
		
            break;
		
        case Adc12_IRQSTATUS_COMP:
	   
            if (ADC12_DataCnt >= 128) 
            {                         
                ADC12_DataCnt = 0;
                ADC12_Stop(ADC_Unit); 
                return;
            }
            /*Set FIFO Size*/
            ADC12_ScanStage = ADC12_FIFO_STAGE1 + 1;

            /*Read FIFO */
            ADC12_Read(ADC_Unit, &ADC12_ScanInfo[ADC12_DataCnt], 
                        &ADC12_ScanData[ADC12_DataCnt], &ADC12_ScanStage);
  
            /*Add Size */		
            ADC12_DataCnt +=ADC12_ScanStage;       
            
            /*Clear FIFO*/			
            ADC12_ClrScanFIFO(ADC_Unit); 
            Read_Finished = 1;
            //NVIC_ClearPendingIRQ(ADC0_IRQn);
	   
            break;
		
        case Adc12_IRQSTATUS_SOVR:
            //Clear fifo
            break;
	   
        case Adc12_IRQSTATUS_POVR:
            //Clear fifo
            break;
		
        default:
            ;
    }
    
}

static void ADC12_PrintResult(void)
{
    if(Read_Finished)
    {         
        /*Read FIFO according to placement select */
        if(ADC12_Init.ADC12_DataSide == ADC12_DATA_SIDE_MSB)
        {
            ADC12_Value = ADC12_ScanData[ADC12_DataSize]>>4;     
        }
        if(ADC12_Init.ADC12_DataSide == ADC12_DATA_SIDE_LSB)
        {
            ADC12_Value = ADC12_ScanData[ADC12_DataSize];     
        }	
        /*Conversion Voltage */	  
        ADC12_Value = (ADC12_Value*ADC12_Volt) / ADC12_MaxValue;

        /*Check CH and Print Result */	
#ifdef DEBUG_MODE           
        if((ADC12_ScanInfo[ADC12_DataSize] & 0x1F) == ADC12_CH7)
        {
            printf( "AN07:%d mv\n\r",ADC12_Value);
        }
#endif	        
           
        ADC12_DataSize += 1;
        if(ADC12_DataSize >= BUFFER_SIZE)
        Read_Finished = 0;     
    }
  
}
/**
 ******************************************************************************
 ** \brief  Main function of project for MB9B500 series.
 **
 ** \param  none
 ** \return uint32_t return value, if needed
 *****************************************************************************
 */

int32_t main(void)
{
    /*Unit Select*/
    ADC_Unit = ADC_UNIT0;
    /*AN07 Pin17 */
    ADC12_Init.ADC12_Ch = AN07;
    /* MSB Bit31~Bit20 */
    ADC12_Init.ADC12_DataSide = ADC12_DATA_SIDE_MSB; 
    /* Continue mode */
    ADC12_Init.ADC12_ScanMode = ADC12_SCAN_MODE_CONTINUE;
    /*Comparison time = Compare clock cycle by 14 */
    ADC12_Init.ADC12_CmpDiv = ADC12_CMP_TIME_DIV9; 
    /* Option enable */
    ADC12_Init.ADC12_Option = ADC12_ENABLE; 
    /*Sample Time Select Register 0*/
    ADC12_Init.ADC12_SampleTimeSelReg = ADC12_SAMPLE_TIME_SEL_REG0;
    /*sampling time= ( 1 / HCLK ) * [ ( 8 + 1 ) * 4 +1 ]*/
    ADC12_Init.ADC12_SampleTimeN.ADC12_SampleTimeN0 = ADC12_SAMPLE_TIME_N4;
    ADC12_Init.ADC12_SampleTime.ADC12_SampleTime0 = ADC12_SamplingTime;
    /*Software Mode*/
    ADC12_Init.ADC12_StartTimerTrigMode = ADC12_TIMER_TRIGGER_NONE; 
    /*FIFO Size 1*/
    ADC12_Init.ADC12_FIFOStage = ADC12_FIFO_STAGE1;
    /*Comparison function init */
    ADC12_Init.ADC12_CmpOption.ADC12_Cmpen = ADC12_CMP_ENABLE;
    ADC12_Init.ADC12_CmpOption.ADC12_Cmd1 = ADC12_CMP_ENABLE;
    ADC12_Init.ADC12_CmpOption.ADC12_Cmd0 = ADC12_CMP_DISABLE;	
    ADC12_Init.ADC12_CmpOption.ADC12_CmpVal = ADC12_CmpData<<4;
	
    /* Set Irq callback function */
    ADC12_Init.ADC12_ConfigIrqCallback = ADC12_Callback;
    /* Set I/O port */
    FM3_GPIO->ADE |= 0x00000080;  /* Analog input */
    FM3_GPIO->PFR1= 0x00000080;  /* Use P17  AN07*/ 
    /*Disable Comparison interrrupt*/	
    ADC12_IrqDisable(ADC_Unit, ADC12_CMP_CONVERSION);

    /* Clear FIFO for ADC */	
    ADC12_ClrScanFIFO(ADC_Unit);
   
    /* Init for ADC */
    ADC12_AdcInit(ADC_Unit, &ADC12_Init);
   
    /*ANx Channel Select*/
    ADC12_ChannelSelect(ADC_Unit, &ADC12_Init);
   
    /*wait for conversion enable valid */
    while(!ADC12_ReadOptionStatus(ADC_Unit));
   
    /*Interrupt Enable*/
    if(ADC_Unit == ADC_UNIT0)
    {
        NVIC_SetPriority(ADC0_IRQn, 0x1); 
        NVIC_EnableIRQ(ADC0_IRQn);
    }
    if(ADC_Unit == ADC_UNIT1)
    {
        NVIC_SetPriority(ADC1_IRQn, 0x1); 
        NVIC_EnableIRQ(ADC1_IRQn);
    }
    if(ADC_Unit == ADC_UNIT2)
    {
        NVIC_SetPriority(ADC2_IRQn, 0x1); 
        NVIC_EnableIRQ(ADC2_IRQn);
    }
    /*Enable Comparison interrrupt*/	
    ADC12_IrqEnable(ADC_Unit, ADC12_CMP_CONVERSION);

    /*Ensable Start Conversion*/	
    ADC12_ScanStart(ADC_Unit);

    while(1)
    {
        ADC12_PrintResult();	      
    }
}



