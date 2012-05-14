/*!
 ******************************************************************************
 **
 ** \file template\source\mb9bf50x_int.c
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-11-21
 **
 ** \brief This file provides a template of all of the exception handlers and 
 **        interrupts.
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

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
/* global functions                                                          */
/*---------------------------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/*!
 ******************************************************************************
 ** \brief This function handles NMI exception.
 **
 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void NMI_Handler(void)
{
}

/*!
 ******************************************************************************
 ** \brief This function handles Hardware Fault exception.
 **
 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {}
}

/*!
 ******************************************************************************
 ** \brief This function handles Memory Manage exception.
 **
 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {}
}

/*!
 ******************************************************************************
 ** \brief This function handles Bus Fault exception.

 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {}
}

/*!
 ******************************************************************************
 ** \brief This function handles Usage Fault exception.

 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {}
}

/*!
 ******************************************************************************
 ** \brief This function handles Debug Monitor exception.

 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void DebugMon_Handler(void)
{
}

/*!
 ******************************************************************************
 ** \brief This function handles Service Call exception.

 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void SVC_Handler(void)
{
}

/*!
 ******************************************************************************
 ** \brief This function handles Pend Service exception.
 **
 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void PendSV_Handler(void)
{
}

/*!
 ******************************************************************************
 ** \brief This function handles SystemTick Handler.
 **
 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
void SysTick_Handler(void)
{
}


/******************************************************************************/
/*                 MB9BF50x Peripherals Interrupt Handlers                    */
/*  Add here the Interrupt Handler for the used peripheral(s) (xxx), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_mb9bf50x.s).                                                */
/******************************************************************************/

/*!
 ******************************************************************************
 ** \brief This function handles XXX Handler.
 **
 ** \param None        
 **
 ** \retval None
 **
 ******************************************************************************
 */
/*void XXX_IRQHandler(void)
{
}*/

/*****************************************************************************/
/* END OF FILE */
