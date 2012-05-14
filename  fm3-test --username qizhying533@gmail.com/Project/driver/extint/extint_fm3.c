/*!
 ******************************************************************************
 **
 ** \file extint_fm3.c
 **
 ** \brief this file provides external interrupt drivers.
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-18
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
#include "extint_fm3.h"
/*---------------------------------------------------------------------------*/
/* Bit definition                                                            */
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
static void EXTINT07_IrqHandler(int16_t CH);
static void EXTINT815_IrqHandler(int16_t CH);
static void NMI_IrqHandler(void);
/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

static EXTINT_CallbackT EXTINT_IrqCallback[] = 
{ 
    NULL,/*for channel 0~7*/
    NULL,/*for channel 8~15*/
};

static NMI_CallbackT NMI_IrqCallback[] = 
{ 
    NULL,

};
/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief Initialize I/O for external interrupt
 **
 ** \param IOPort set the external interrupt port
 ** \arg  GPIO_P00_BASE
 ** \arg  GPIO_P10_BASE
 ** \arg  GPIO_P20_BASE
 ** \arg  GPIO_P30_BASE
 ** \arg  GPIO_P40_BASE
 ** \arg  GPIO_P50_BASE
 ** \arg  GPIO_P60_BASE
 ** \arg  GPIO_P70_BASE
 ** \arg  GPIO_P80_BASE
 ** \param IOPin set the external interrupt pin
 ** \arg   GPIO_PIN0
 ** \arg   GPIO_PIN1
 ** \arg   GPIO_PIN2
 ** \arg   GPIO_PIN3
 ** \arg   GPIO_PIN4
 ** \arg   GPIO_PIN5
 ** \arg   GPIO_PIN6
 ** \arg   GPIO_PIN7
 ** \arg   GPIO_PIN8
 ** \arg   GPIO_PINA
 ** \arg   GPIO_PINB
 ** \arg   GPIO_PINC
 ** \arg   GPIO_PIND
 ** \arg   GPIO_PINE
 ** \arg   GPIO_PINF
 ** \retval None
 **
 ******************************************************************************
 */
void EXTINT_GPIOInit(int32_t IOPort, int32_t IOPin)
{

    /* Check the parameter */
    ASSERT(IS_IO_PIN_VALID(IOPin));
    ASSERT(IS_IO_PORT_VALID(IOPort));
    /* Port Function Setting */
    switch(IOPort)
    {
        case GPIO_P00_BASE:
            FM3_GPIO->PFR0 |= IOPin;
            break;
        case GPIO_P10_BASE:
            FM3_GPIO->ADE  &= ~IOPin;    /* Analog Input Setting For Port 1 */
            FM3_GPIO->PFR1 |= IOPin;
            break;
        case GPIO_P20_BASE:
          FM3_GPIO->PFR2 |= IOPin;
          break;
        case GPIO_P30_BASE:
            FM3_GPIO->PFR3 |= IOPin;
            break;
        case GPIO_P40_BASE:
            FM3_GPIO->PFR4 |= IOPin;
            break;
        case GPIO_P50_BASE:
            FM3_GPIO->PFR5 |= IOPin;
            break;
        case GPIO_P60_BASE:
            FM3_GPIO->PFR6 |= IOPin;
            break;
        case GPIO_P70_BASE:
            FM3_GPIO->PFR7 |= IOPin;
            break;
        case GPIO_P80_BASE:
            FM3_GPIO->PFR8 |= IOPin;
            break; 
        default:
            break;
    }
      
    return;
}


/*!
 ******************************************************************************
 ** \brief Initialize EPFR06 for external interrupt
 **
 ** \param Ext_Init set the external interrupt pin and callback function
  ** \arg  
 ** \param IntPin set the external interrupt pin
 **        This parameter can be one of the following values:
 ** \arg   INT00_0
 ** \arg   INT00_1
 ** \arg   INT00_2
 ** \arg   INT01_0
 ** \arg   INT01_1
 ** \arg   INT01_2
 ** \arg   INT02_0
 ** \arg   INT02_1
 ** \arg   INT02_2
 ** \arg   INT03_0
 ** \arg   INT03_1
 ** \arg   INT03_2
 ** \arg   INT04_0
 ** \arg   INT04_1
 ** \arg   INT04_2
 ** \arg   INT05_0
 ** \arg   INT05_1
 ** \arg   INT05_2
 ** \arg   INT06_1
 ** \arg   INT06_2
 ** \arg   INT07_2
 ** \arg   INT08_1
 ** \arg   INT08_2
 ** \arg   INT09_1
 ** \arg   INT09_2
 ** \arg   INT10_1
 ** \arg   INT10_2
 ** \arg   INT11_1
 ** \arg   INT11_2
 ** \arg   INT12_1
 ** \arg   INT12_2
 ** \arg   INT13_1
 ** \arg   INT13_2
 ** \arg   INT14_1
 ** \arg   INT14_2
 ** \arg   INT15_1
 ** \arg   INT15_2
 ** \retval None
 **
 ******************************************************************************
 */
void EXTINT_Init(uint32_t IntPin, ExtInt_Config *Ext_Init)
{

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(Ext_Init->ExtInt_Ch));
    ASSERT(IS_EPFR06_INT_VALID0(IntPin));
    
    /* assigns functions to external interrupt pins */
    FM3_GPIO->EPFR06 |= IntPin;  
    
    /*clear the external interrupt request */
    FM3_EXTI->EICL  = INT_INIT; 


    if(Ext_Init->ExtInt_Ch <= INT07)
    {
        EXTINT_IrqCallback[0] = Ext_Init->ExtInt_ConfigIrqCallback;
    }
    else if(Ext_Init->ExtInt_Ch > INT07 && Ext_Init->ExtInt_Ch <= INT15)
    {
        EXTINT_IrqCallback[1] = Ext_Init->ExtInt_ConfigIrqCallback;
    }
    return;
}


/*!
 ******************************************************************************
 ** \brief enable for external interrupt
 **
 ** \param CH set the external interrupt channel
 **        This parameter can be one of the following values:
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
 **
 ******************************************************************************
 */
void EXTINT_IntEnable(int16_t CH)
{

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(CH));
	
    /* interrupt enable */
    FM3_EXTI->ENIR  |= (1<<CH); 		
      
    return;
}



/*!
 ******************************************************************************
 ** \brief disable for external interrupt
 **
 ** \param CH set the external interrupt channel
 **        This parameter can be one of the following values:
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
 **
 ** \retval None
 **
 ******************************************************************************
 */
void EXTINT_IntDisable(int16_t CH)
{

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(CH));
	
    /* interrupt disable */
    FM3_EXTI->ENIR  &= (~(1<<CH));		
      
    return;
}

/*!
 ******************************************************************************
 ** \brief clear the held external interrupt cause
 **
 ** \param CH set the external interrupt channel
 **        This parameter can be one of the following values:
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
 **
 ******************************************************************************
 */
void EXTINT_IntClr(uint16_t CH)
{

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(CH));
	
    /* interrupt clear */
    FM3_EXTI->EICL &= (~(1<<CH));		
      
    return;
}


/*!
 ******************************************************************************
 ** \brief select the level or edge of the signal external interrupt
 **
 ** \param Ext_Init set the external interrupt channel and detect type for external interrupt
 ** \arg  
 ** \retval None
 **
 ******************************************************************************
 */
void EXTINT_IntSetType(ExtInt_Config *Ext_Init)
{

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(Ext_Init->ExtInt_Ch));
    ASSERT(IS_INT_TYPE_VALID(Ext_Init->ExtInt_Type)); 
	  
    /* set interrupt cause type */
    FM3_EXTI->ELVR  |= ((Ext_Init->ExtInt_Type)<<((Ext_Init->ExtInt_Ch)<<1));		

    return;
}


/*!
 ******************************************************************************
 ** \brief detect an external interrupt or not
 **
 ** \param CH set the external interrupt channel
 **        This parameter can be one of the following values:
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
 **
 ** \retval SET: Detect an external interrupt request
 **            RESET: Detect no external interrupt request
 ******************************************************************************
 */
FlagStatusT EXTINT_IntStatus(int16_t CH)
{
    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(CH));
	
     /* interrupt status */
    if(((FM3_EXTI->EIRR)&(1<< CH))!= RESET)
    {
        return SET;
    }
    else
    {
        return RESET;
    }			
      
}

/*!
 ******************************************************************************
 ** \brief interrupt handle
 ** 
 **
 ** \retval None
 **
 ******************************************************************************
 */
void INT0_7_Handler(void)
{
    uint8_t Ch;
       
    for(Ch = 0U; Ch < EXTINT_CH_NUM; Ch++) 
    {
        /* Check IRQ source channel */
        if(((FM3_INTREQ->IRQ04MON >> Ch) & INT_BIT0) != RESET) 
        {
            EXTINT07_IrqHandler(Ch); 
        }
    }

}


/*!
 ******************************************************************************
 ** \brief interrupt handle
 ** 
 **
 ** \retval None
 **
 ******************************************************************************
 */
void INT8_15_Handler(void)
{
    uint8_t Ch;
    
    for(Ch = 0U; Ch < EXTINT_CH_NUM; Ch++)
    {
        /* Check IRQ source channel */
        if(((FM3_INTREQ->IRQ05MON >> Ch) & INT_BIT0) != RESET) 
        {
            EXTINT815_IrqHandler(Ch); 
        }
    }

}

/*!
 ******************************************************************************
 ** \brief Initialize EPFR00 for NMI
 **
 ** \param  Ext_Init ConfigIrqCallback function
 ** \arg   
 ** \retval None
 **
 ******************************************************************************
 */
void NMI_IntInit(ExtInt_Config *Ext_Init)
{

    FM3_GPIO->EPFR00 |= INT_NMI_EPFR;  /* assigns functions to NMI */	

    FM3_GPIO->PFR0  |= INT_NMI_Port;   /* set port to NMI */	

    FM3_EXTI->NMICL = INT_INIT;    /*clear the NMI request */

    NMI_IrqCallback[0] = Ext_Init->NMIInt_ConfigIrqCallback;
    
    return;
}

/*!
 ******************************************************************************
 ** \brief clear the held NMI  cause
 **
 **       
 ** \retval None
 **
 ******************************************************************************
 */
void NMI_IntClr(void)

{
	/* clear interrupt flag */
	FM3_EXTI->NMICL = INT_INIT;						
    return;
}

/*!
 ******************************************************************************
 ** \brief read NMI  status
 **
 **       
 ** \retval SET for interrupt cause, RESET for nointerrupt
 **
 ******************************************************************************
 */


FlagStatusT NMI_IntStatus(void)
{
	
    if(((FM3_EXTI->NMIRR)& INT_BIT0)!= RESET)
  	{
        return SET;
  	}
  	else
  	{
        return RESET;
  	}
 
}

/*!
 ******************************************************************************
 ** \brief NMI  Handler
 **    
 ** \retval None
 **
 ******************************************************************************
 */
void NMI_Handler(void)
{
    /* Check IRQ source channel */
    if(((FM3_INTREQ->EXC02MON) & INT_BIT0) != RESET) 
    {
        NMI_IrqHandler(); 
    }     
    return;
}
/*---------------------------------------------------------------------------*/
/* local functions                                                          */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief interrupt handle for external interrupt 0-7
 ** 
 ** \param CH set the external interrupt channel
 **        This parameter can be one of the following values:
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
 ** 
 **
 ******************************************************************************
 */
static void EXTINT07_IrqHandler(int16_t CH)
{
    int16_t CH_07;

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(CH));

    CH_07 = CH;	
    if(EXTINT_IntStatus(CH_07)==SET)
    {
       
        EXTINT_IntClr(CH_07);

	    if(EXTINT_IrqCallback[0] != NULL)
	    {
            /* Call CallBackIrq */
            EXTINT_IrqCallback[0](CH_07);
        }
	
    }
}

/*!
 ******************************************************************************
 ** \brief interrupt handle for external interrupt 8-15
 ** 
  ** \param CH set the external interrupt channel
 **        This parameter can be one of the following values:
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
 ** 
 **
 ******************************************************************************
 */
static void EXTINT815_IrqHandler(int16_t CH)
{
    int16_t CH_815;

    /* Check the parameter */
    ASSERT(IS_INT_CH_VALID(CH));
	
    CH_815 = CH + EXTINT_CH_NUM;
    if(EXTINT_IntStatus(CH_815)==SET)
    {
        EXTINT_IntClr(CH_815);

	    if (EXTINT_IrqCallback[1] != NULL) 
        {
            /* Call CallBackIrq */
            EXTINT_IrqCallback[1](CH_815);
        }
	
    }
}


/*!
 ******************************************************************************
 ** \brief interrupt handle for NMI
 ** 
 **
 ******************************************************************************
 */
static void NMI_IrqHandler(void)
{

    if(NMI_IntStatus()==SET)
    {
	    NMI_IntClr();

	    if(NMI_IrqCallback[0] != NULL) 
        {
            /* Call CallBackIrq */
            NMI_IrqCallback[0]();
        }
	
    }
}
/*****************************************************************************/

/* END OF FILE */
