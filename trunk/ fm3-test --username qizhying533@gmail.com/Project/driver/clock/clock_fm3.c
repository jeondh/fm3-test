/*!
 ******************************************************************************
 **
 ** \file clock_fm3.c
 **
 ** \brief Clock module driver.
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
 ** \note History: \n
 ** V0.1 2011-12-30 original version \n
 **
 ******************************************************************************
 */
 

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "clock_fm3.h"
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
 ** \brief Switch master clock
 **
 ** \param ClockType Requested source clock
 **
 ** \note 1. This functuon can not be used as clock initialization.
 **       2. This function can not disable Main or Sub oscillator, even when  
 **          switch master clock to internal CR clock.
 **       3. Oscillation stabilization wait time are defined in system_mb9bf50x.h. 
 **       4. Current master clock is saved in variable SystemCoreClock.
 ******************************************************************************
 */
void CLOCK_MasterClockSwitch (uint32_t ClockType) {

    static uint32_t u32IoRegisterRead;     
    
    /* Check parameters */
    ASSERT(IS_SRC_CLOCK(ClockType));
    
    FM3_CRG->SCM_CTL &= ~0xE0;                      /* Switch master clock to High-CR firstly */
           
    FM3_CRG->CSW_TMR = CSW_TMR_Val;                 /* set oscillation stabilization wait time */
    
    if (ClockType&(1UL<<1))                         /* Main clock oscillator enabled ? */
    {               
        FM3_CRG->SCM_CTL |= (1UL<<1);               /* enable main oscillator */ 
        while (!(FM3_CRG->SCM_STR&(1UL<<1)));       /* wait for Main clock oscillation stable */
    }
    
    if (ClockType&(1UL<<3))                         /* Sub clock oscillator enabled ? */
    {               
        FM3_CRG->SCM_CTL |= (1UL<<3);               /* enable sub oscillator */ 
        while (!(FM3_CRG->SCM_STR&(1UL<<3)));       /* wait for Sub clock oscillation stable */
    }
    
    FM3_CRG->PSW_TMR   = PSW_TMR_Val;                /* set PLL stabilization wait time */   
    
    if (ClockType&(1UL<<4))                         /* PLL enabled ? */
    {                  
        FM3_CRG->SCM_CTL |= (1UL<<4);              /* enable PLL */ 
        while (!(FM3_CRG->SCM_STR&(1UL<<4)));       /* wait for PLL stable */
    }
    
    FM3_CRG->SCM_CTL  |= (ClockType&0xE0);          /* Set Master Clock switch */ 
    
    do                                              
    {                                               
        u32IoRegisterRead = (FM3_CRG->SCM_CTL&0xE0); 
    }while ((FM3_CRG->SCM_STR&0xE0) != u32IoRegisterRead);
    
    SystemCoreClockUpdate();
}





/*****************************************************************************/
/* END OF FILE */
