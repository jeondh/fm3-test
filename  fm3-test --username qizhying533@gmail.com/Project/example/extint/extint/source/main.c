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
/* global data                                                               */
/*---------------------------------------------------------------------------*/
ExtInt_Config ExtInt_Init;
/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief  NMI function for user
 **
 ** \param  None
 **
 ** \retval None
 ******************************************************************************
 */
static void NMI_IntIrqCallback(void)
{
       /*NMI function for user */
   
       printf("NMI occess!!\n\r");
}
/*!
 ******************************************************************************
 ** \brief  external interrupt function for user
 **
 ** \param  CH switch with the external interrupt channel
 ** \arg   INT00
 ** \arg   INT01
 ** \arg   INT02
 ** \arg   INT03
 ** \arg   INT04
 ** \arg   INT05
 ** \arg   INT06
 ** \arg   INT07
 ** \arg   INT08
 ** \arg   INT09
 ** \arg   INT10
 ** \arg   INT11
 ** \arg   INT12
 ** \arg   INT13
 ** \arg   INT14
 ** \arg   INT15   
 ** \retval None
 ******************************************************************************
 */
static void EXTINT_IntIrqCallback(int16_t CH)
{
     //user code
#ifdef DEBUG_MODE
    //user code
    switch(CH)
    {
        /*interrupt function for user CH0*/
        case INT00:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH1*/
        case INT01:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;	  
        /*interrupt function for user CH2*/
        case INT02:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH3*/
        case INT03:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH4*/
        case INT04:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH5*/
        case INT05:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH6*/
        case INT06:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH7*/
        case INT07:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH8*/
        case INT08:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH9*/
        case INT09:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH10*/
        case INT10:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH11*/
        case INT11:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH12*/
        case INT12:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH13*/
        case INT13:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH14*/
        case INT14:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        /*interrupt function for user CH15*/
        case INT15:
            printf("CH:%d External Interrupt occess!!\n\r", CH);
            break;
        default:
            printf("Error!!\n\r");
    }
#endif
}


/**
 ******************************************************************************
 ** \brief  Main function of project for MB9B500 series.
 **
 ** \param  none
 *****************************************************************************
 */

int32_t main(void)
{

    /*Channel and Type Init*/

    ExtInt_Init.ExtInt_Ch = INT13;
    ExtInt_Init.ExtInt_Type = GPIO_LOW_LEVEL;
	
    /* I/O port setting for ext int*/
    EXTINT_GPIOInit(GPIO_P40_BASE, GPIO_PIN1);/*Pin33->P41,INT13_1,*/

    /* Set Irq callback function */
    ExtInt_Init.ExtInt_ConfigIrqCallback = EXTINT_IntIrqCallback; 

    /* Initialize EPFR06 for ext int */
    EXTINT_Init(INT13_1, &ExtInt_Init);

    /* INT interrupt disable */
    EXTINT_IntDisable(ExtInt_Init.ExtInt_Ch);

    /* INT13_1 low level edge */
    EXTINT_IntSetType(&ExtInt_Init);

    /* Enable INT13_1 */  
    EXTINT_IntEnable(ExtInt_Init.ExtInt_Ch);	

    /* Enable interrupt */
    NVIC_SetPriority( EXINT8_15_IRQn, 2 );
    NVIC_ClearPendingIRQ( EXINT8_15_IRQn );
  
    NVIC_EnableIRQ(EXINT8_15_IRQn);

    /*Channel and Type Init*/
    ExtInt_Init.ExtInt_Ch = INT05;
    ExtInt_Init.ExtInt_Type = GPIO_RISING_EDGE;

    /* I/O port setting for ext int*/
    EXTINT_GPIOInit(GPIO_P20_BASE, GPIO_PIN0);/*Pin89->P20,INT5_0,*/
   
    /* Initialize EPFR06 for ext int */
    EXTINT_Init(INT05_0, &ExtInt_Init);

    /* INT interrupt disable */
    EXTINT_IntDisable(ExtInt_Init.ExtInt_Ch);

    /* INT13_1 low level edge */
    EXTINT_IntSetType(&ExtInt_Init);

    /* enable INT05_0 */  
    EXTINT_IntEnable(ExtInt_Init.ExtInt_Ch);	

    /* Enable interrupt */
    NVIC_SetPriority( EXINT0_7_IRQn, 2 );
    NVIC_ClearPendingIRQ( EXINT0_7_IRQn );
  
    NVIC_EnableIRQ(EXINT0_7_IRQn);
    
    /* Set Irq callback function */
    ExtInt_Init.NMIInt_ConfigIrqCallback = NMI_IntIrqCallback;
    /* Initialize EPFR00 for NMI */
    NMI_IntInit(&ExtInt_Init);

   

	
    while(1);
}



