/*!
 ******************************************************************************
 **
 ** \file basetimer_fm3.c
 **
 ** \brief Base timer module driver.
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
#include "basetimer_fm3.h"
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
volatile static FM3_BT_PWM_TypeDef* pFM3_BT_BASE[] = 
{
    (FM3_BT_PWM_TypeDef*)(FM3_BT0_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT1_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT2_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT3_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT4_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT5_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT6_PWM),
    (FM3_BT_PWM_TypeDef*)(FM3_BT7_PWM),
};


/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void BTIrqHandler(uint8_t Ch);

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

 /*! \brief Pointer array of basetimer irq callback function */
static BT_CallbackT BT_IrqCallback[] = 
{ 
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief Set Base timer I/O Mode
 **
 ** \param Ch Requested channel
 ** \param IOMode requested I/O mode
 ******************************************************************************
 */
void BT_SetIOMode(uint8_t Ch, uint8_t IOMode)
{
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_IOMODE(IOMode));
    
    switch (Ch)
    {
        case BT_CH_0:
        case BT_CH_1:
            FM3_BTIOSEL03->BTSEL0123 = (FM3_BTIOSEL03->BTSEL0123&0xf0)|IOMode;
            break;
        case BT_CH_2:
        case BT_CH_3:
            FM3_BTIOSEL03->BTSEL0123 = (FM3_BTIOSEL03->BTSEL0123&0x0f)|(IOMode<<4);
            break;
        case BT_CH_4:
        case BT_CH_5:
            FM3_BTIOSEL47->BTSEL4567 = (FM3_BTIOSEL47->BTSEL4567&0xf0)|IOMode;
            break;
        case BT_CH_6:
        case BT_CH_7:
            FM3_BTIOSEL47->BTSEL4567 = (FM3_BTIOSEL47->BTSEL4567&0x0f)|(IOMode<<4);
            break;
        default:
            break;	            
	}
}

/*!
 ******************************************************************************
 ** \brief PWM timer initialization
 **
 ** \param Ch Requested channel
 ** \param pInit Initialization data pointor
 ******************************************************************************
 */
void BT_PwmInit (uint8_t Ch, BT_PwmInitRegT* pInit)
{
    uint16_t tmcr;
    
    volatile FM3_BT_PWM_TypeDef* pFM3_BT_PWM[] = 
    {
        (FM3_BT_PWM_TypeDef*)(FM3_BT0_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT1_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT2_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT3_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT4_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT5_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT6_PWM),
        (FM3_BT_PWM_TypeDef*)(FM3_BT7_PWM),
    };
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));    
    ASSERT(IS_BT_CLOCK(pInit->Clock));    
    ASSERT(IS_BT_RESTART(pInit->Restart));
    ASSERT(IS_BT_OUTPUT_MASK(pInit->OutputMask));
    ASSERT(IS_BT_TRG_EDGE(pInit->InputEdge));
    ASSERT(IS_BT_POLARITY(pInit->Polarity));
    ASSERT(IS_BT_MODE(pInit->Mode));             
    
    /* Reset Timer Function */
    pFM3_BT_PWM[Ch]->TMCR = 0;
    
    tmcr = ((pInit->Clock&0x07)<<12)|
            (pInit->Restart<<11)|
            (pInit->OutputMask<<10)|
            (pInit->InputEdge<<8)|
            (pInit->Polarity<<3)|
            (pInit->Mode<<2)|
             BT_PWM_MODE<<4;
    
    pFM3_BT_PWM[Ch]->TMCR = tmcr;                            
    pFM3_BT_PWM[Ch]->TMCR2 = (pInit->Clock&0x08)>>3;
    pFM3_BT_PWM[Ch]->PCSR = pInit->Cycle;
    pFM3_BT_PWM[Ch]->PDUT = pInit->Duty;
    BT_IrqCallback[Ch] = pInit->IrqCallback;
}

/*!
 ******************************************************************************
 ** \brief PPG timer initialization
 **
 ** \param Ch Requested channel  
 ** \param pInit Initialization data pointor
 ******************************************************************************
 */
void BT_PpgInit (uint8_t Ch, BT_PpgInitRegT* pInit)
{
    uint16_t tmcr;
    volatile FM3_BT_PPG_TypeDef* pFM3_BT_PPG[] = 
    {
        (FM3_BT_PPG_TypeDef*)(FM3_BT0_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT1_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT2_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT3_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT4_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT5_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT6_PPG),
        (FM3_BT_PPG_TypeDef*)(FM3_BT7_PPG),
    };   
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));    
    ASSERT(IS_BT_CLOCK(pInit->Clock));    
    ASSERT(IS_BT_RESTART(pInit->Restart));
    ASSERT(IS_BT_OUTPUT_MASK(pInit->OutputMask));
    ASSERT(IS_BT_TRG_EDGE(pInit->InputEdge));
    ASSERT(IS_BT_POLARITY(pInit->Polarity));
    ASSERT(IS_BT_MODE(pInit->Mode)); 
    
    /* Reset Timer Function */
    pFM3_BT_PPG[Ch]->TMCR = 0;
    
    tmcr = ((pInit->Clock&0x07)<<12)|
            (pInit->Restart<<11)|
            (pInit->OutputMask<<10)|
            (pInit->InputEdge<<8)|
            (pInit->Polarity<<3)|
            (pInit->Mode<<2)|
             BT_PPG_MODE<<4;
    
    pFM3_BT_PPG[Ch]->TMCR = tmcr;                            
    pFM3_BT_PPG[Ch]->TMCR2 = (pInit->Clock&0x08)>>3;
    pFM3_BT_PPG[Ch]->PRLL = pInit->LowWidth;
    pFM3_BT_PPG[Ch]->PRLH = pInit->HighWidth;
    BT_IrqCallback[Ch] = pInit->IrqCallback;
}

/*!
 ******************************************************************************
 ** \brief PWC timer initialization
 **
 ** \param Ch Requested channel
 ** \param pInit Initialization data pointor
 ******************************************************************************
 */
void BT_PwcInit (uint8_t Ch, BT_PwcInitRegT* pInit)
{
    uint16_t tmcr;
 
    volatile FM3_BT_PWC_TypeDef* pFM3_BT_PWC[] = 
    {
        (FM3_BT_PWC_TypeDef*)(FM3_BT0_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT1_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT2_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT3_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT4_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT5_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT6_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT7_PWC),
    };  
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));    
    ASSERT(IS_BT_CLOCK(pInit->Clock));
    ASSERT(IS_BT_PWC_EDGE(pInit->MeasureEdge));
    ASSERT(IS_BT_BIT_TIMER(pInit->TimerMode));
    ASSERT(IS_BT_MODE(pInit->Mode)); 
    
    if (pInit->TimerMode == BT_32BIT_TIMER)
    {
        ASSERT((Ch % 2) == 0); /* Even channel */
    }
    
    
    /* Reset Timer Function */
    pFM3_BT_PWC[Ch]->TMCR = 0; 
      
    tmcr = ((pInit->Clock&0x07)<<12)|
            (pInit->MeasureEdge<<8)|
            (pInit->TimerMode<<7)|
            (pInit->Mode<<2)|
             BT_PWC_MODE<<4;
    
    FM3_BT0_PWC->TMCR = tmcr;                            
    pFM3_BT_PWC[Ch]->TMCR2 = (pInit->Clock&0x08)>>3;
    BT_IrqCallback[Ch] = pInit->IrqCallback;
}

/*!
 ******************************************************************************
 ** \brief Reload timer initialization
 **
 ** \param Ch Requested channel
 ** \param pInit Initialization data pointor
 ******************************************************************************
 */
void BT_RtInit (uint8_t Ch, BT_RtInitRegT* pInit)
{
    uint16_t tmcr;
    
    volatile FM3_BT_RT_TypeDef* pFM3_BT_RT[] = 
    {
        (FM3_BT_RT_TypeDef*)(FM3_BT0_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT1_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT2_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT3_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT4_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT5_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT6_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT7_RT),
    };
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));    
    ASSERT(IS_BT_CLOCK(pInit->Clock)); 
    ASSERT(IS_BT_TRG_EDGE(pInit->InputEdge));
    ASSERT(IS_BT_BIT_TIMER(pInit->TimerMode));
    ASSERT(IS_BT_POLARITY(pInit->Polarity));
    ASSERT(IS_BT_MODE(pInit->Mode));    
    
    if (pInit->TimerMode == BT_32BIT_TIMER)
    {
        ASSERT((Ch % 2) == 0); /* Even channel */
    }
    
    /* Reset Timer Function */
    pFM3_BT_RT[Ch]->TMCR = 0;
    
    tmcr = ((pInit->Clock&0x07)<<12)|
            (pInit->InputEdge<<8)|
            (pInit->TimerMode<<7)|
            (pInit->Polarity<<3)|
            (pInit->Mode<<2)|
             BT_RT_MODE<<4;
    
    pFM3_BT_RT[Ch]->TMCR = tmcr;                            
    pFM3_BT_RT[Ch]->TMCR2 = (pInit->Clock&0x08)>>3;
    
    
    if (pInit->TimerMode == BT_16BIT_TIMER)
    {
        ASSERT((pInit->Cycle)<=0x0000ffff); //Only one register used for 16-bit timer
        pFM3_BT_RT[Ch]->PCSR = (uint16_t)pInit->Cycle;
    }
    else if (pInit->TimerMode == BT_32BIT_TIMER)
    {
        /* 
         * In 32-bit mode, for the reload timer, set the reload value of the 
         * upper 16 of 32 bits in the PWM Cycle Set Register of the odd channel. 
         * Then, set the reload value of the lower 16 bits in the PWM Cycle Set 
         * Register of the even channel.
         */
        pFM3_BT_RT[Ch+1]->PCSR = (uint16_t)(pInit->Cycle>>16);
        pFM3_BT_RT[Ch]->PCSR = (uint16_t)pInit->Cycle;
    }
    BT_IrqCallback[Ch] = pInit->IrqCallback;
}

/*!
 ******************************************************************************
 ** \brief Enable Pwm timer Interrupt 
 **
 ** \param Ch Requested channel 
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_DUTY
 ** \arg BT_INT_ENABLE_UNDER
 ******************************************************************************
 */
void BT_PwmIntEnable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_PWM_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC |= IntType<<4; 
    return;
}

/*!
 ******************************************************************************
 ** \brief Disable Pwm timer Interrupt 
 **
 ** \param Ch Requested channel
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_DUTY
 ** \arg BT_INT_ENABLE_UNDER
 ******************************************************************************
 */
void BT_PwmIntDisable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_PWM_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC &= (~(IntType<<4)); 
    return;
}

/*!
 ******************************************************************************
 ** \brief Enable Ppg timer Interrupt 
 **
 ** \param Ch Requested channel 
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_UNDER
 ******************************************************************************
 */
void BT_PpgIntEnable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_PPG_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC |= IntType<<4; 
    return;
}

/*!
 ******************************************************************************
 ** \brief Disable Ppg timer Interrupt 
 **
 ** \param Ch Requested channel
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_UNDER
 ******************************************************************************
 */
void BT_PpgIntDisable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_PPG_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC &= (~(IntType<<4)); 
    return;
}

/*!
 ******************************************************************************
 ** \brief Enable Pwc timer Interrupt 
 **
 ** \param Ch Requested channel 
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_MEASURE
 ** \arg BT_INT_ENABLE_OVERFLOW
 ******************************************************************************
 */
void BT_PwcIntEnable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_PWC_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC |= IntType<<4; 
    return;
}

/*!
 ******************************************************************************
 ** \brief Disable Pwc timer Interrupt 
 **
 ** \param Ch Requested channel
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_MEASURE
 ** \arg BT_INT_ENABLE_OVERFLOW
 ******************************************************************************
 */
void BT_PwcIntDisable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_PWC_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC &= (~(IntType<<4)); 
    return;
}

/*!
 ******************************************************************************
 ** \brief Enable Reload timer Interrupt 
 **
 ** \param Ch Requested channel 
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_UNDER
 ******************************************************************************
 */
void BT_RtIntEnable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_RT_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC |= IntType<<4; 
    return;
}

/*!
 ******************************************************************************
 ** \brief Disable Reload timer Interrupt 
 **
 ** \param Ch Requested channel
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_UNDER
 ******************************************************************************
 */
void BT_RtIntDisable(uint8_t Ch, uint16_t IntType)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    ASSERT(IS_BT_RT_INT(IntType));
    
    pFM3_BT_BASE[Ch]->STC &= (~(IntType<<4)); 
    return;
}






/*!
 ******************************************************************************
 ** \brief Enable count operation 
 **
 ** \param Ch Requested channel
 ******************************************************************************
 */
void BT_CountEnable(uint8_t Ch)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    pFM3_BT_BASE[Ch]->TMCR |= (1<<1);  
}

/*!
 ******************************************************************************
 ** \brief Stop count operation 
 **
 ** \param Ch Requested channel
 ******************************************************************************
 */
void BT_CountDisable(uint8_t Ch)
{    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    pFM3_BT_BASE[Ch]->TMCR &= (~(1<<1));  
}


/*!
 ******************************************************************************
 ** \brief Clear Interrupt request flag
 **
 ** \param Ch Requested channel
 ** \param IntType interrupt type
 ** \arg BT_INT_ENABLE_TRG
 ** \arg BT_INT_ENABLE_DUTY
 ** \arg BT_INT_ENABLE_UNDER
 ** \arg BT_INT_ENABLE_MEASURE
 ** \arg BT_INT_ENABLE_OVERFLOW
 ******************************************************************************
 */
void BT_ClrIntRequest(uint8_t Ch, uint16_t IntType)
{
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    pFM3_BT_BASE[Ch]->STC &= (~IntType);
}

/*!
 ******************************************************************************
 ** \brief Get Interrupt request flag
 **
 ** \param Ch Requested channel
 ** \return Interrupt request type 
 ** \retval BT_INT_TYP_TRG 
 ** \retval BT_INT_TYP_DUTY 
 ** \retval BT_INT_TYP_UNDER 
 ** \retval BT_INT_TYP_MEASURE 
 ** \retval BT_INT_TYP_OVERFLOW 
 ******************************************************************************
 */
uint8_t BT_GetIntRequest(uint8_t Ch)
{
     /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    return pFM3_BT_BASE[Ch]->STC&0x07;
}

/*!
 ******************************************************************************
 ** \brief Start triggered by software
 **
 ** \param Ch Requested channel
 ******************************************************************************
 */
void BT_SoftTrgEnable(uint8_t Ch)
{    
     /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    pFM3_BT_BASE[Ch]->TMCR |= 1;
}

/*!
 ******************************************************************************
 ** \brief Get PWC measurement error flag
 **
 ** \param Ch Requested channel
 ** \return Error flag 
 ** \retval 0 Normal status
 ** \retval 1 A measurement result not yet read was overwritten by the next 
 **           measurement result.
 ******************************************************************************
 */
uint8_t BT_GetMeasureError(uint8_t Ch)
{
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    return (pFM3_BT_BASE[Ch]->STC&0x80)>>7;
}

/*!
 ******************************************************************************
 ** \brief Get measured or count value of the PWC timer in 16-bit timer mode.
 **
 ** \param Ch Requested channel
 ** \return Measured or count value
 ******************************************************************************
 */
uint16_t BT_Get16bitMeasureData(uint8_t Ch)
{
    volatile FM3_BT_PWC_TypeDef* pFM3_BT_PWC[] = 
    {
        (FM3_BT_PWC_TypeDef*)(FM3_BT0_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT1_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT2_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT3_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT4_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT5_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT6_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT7_PWC),
    };
  
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    return (pFM3_BT_PWC[Ch]->DTBF);
}

/*!
 ******************************************************************************
 ** \brief Get measured or count value of the PWC timer in 32-bit timer mode.
 **
 ** \param Ch Requested channel
 ** \return Measured or count value
 ******************************************************************************
 */
uint32_t BT_Get32bitMeasureData(uint8_t Ch)
{
    volatile FM3_BT_PWC_TypeDef* pFM3_BT_PWC[] = 
    {
        (FM3_BT_PWC_TypeDef*)(FM3_BT0_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT1_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT2_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT3_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT4_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT5_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT6_PWC),
        (FM3_BT_PWC_TypeDef*)(FM3_BT7_PWC),
    };    
    uint32_t data; 
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));    
    ASSERT((Ch % 2) == 0); /* Even channel */
    
    /* Get lower 16bit data */
    data = (uint32_t)pFM3_BT_PWC[Ch]->DTBF;     
    /* Get upper 16bit data */
    data |= (uint32_t)(pFM3_BT_PWC[Ch+1]->DTBF)<<16;
    return data;
}

/*!
 ******************************************************************************
 ** \brief Get count value of the PWM,PPG and Reload timer in 16-bit timer mode.
 **
 ** \param Ch Requested channel
 ** \return Count value
 ******************************************************************************
 */
uint16_t BT_Get16bitCount(uint8_t Ch)
{
    volatile FM3_BT_RT_TypeDef* pFM3_BT_RT[] = 
    {
        (FM3_BT_RT_TypeDef*)(FM3_BT0_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT1_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT2_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT3_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT4_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT5_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT6_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT7_RT),
    };
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    return (pFM3_BT_RT[Ch]->TMR);
}

/*!
 ******************************************************************************
 ** \brief Get count value of Reload timer in 32-bit timer mode.
 **
 ** \param Ch Requested channel
 ** \return Count value
 ******************************************************************************
 */
uint32_t BT_Get32bitCount(uint8_t Ch)
{
    volatile FM3_BT_RT_TypeDef* pFM3_BT_RT[] = 
    {
        (FM3_BT_RT_TypeDef*)(FM3_BT0_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT1_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT2_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT3_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT4_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT5_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT6_RT),
        (FM3_BT_RT_TypeDef*)(FM3_BT7_RT),
    };
    uint32_t data; 
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));    
    ASSERT((Ch % 2) == 0); /* Even channel */

    /* 
     * When reading the TMR register in 32-bit mode, read the  
     * lower 16-bit data (even channel data) first, and then read the 
     * upper 16-bit data (odd channel data).
     */
    /* Get lower 16bit data */
    data = (uint32_t)pFM3_BT_RT[Ch]->TMR;     
    /* Get upper 16bit data */
    data |= (uint32_t)(pFM3_BT_RT[Ch+1]->TMR)<<16;
    return data;
}

/*!
 ******************************************************************************
 ** \brief Base timer Interrupt Handler
 ******************************************************************************
 */
void BT_IRQHandler(void)
{
    uint8_t Ch; 
    
    for(Ch = 0U; Ch < BT_CH_NUM; Ch++) 
    {
        /* Check IRQ source channel */
        if (((FM3_INTREQ->IRQ31MON>>(Ch*2))&0x0003U) != 0U) 
        {
            BTIrqHandler(Ch); 
        }
    }
}

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/ 

/*!
 ******************************************************************************
 ** \brief Base timer Interrupt Handler routine
 **
 ** \param Ch Requested channel
 ******************************************************************************
 */
static void BTIrqHandler(uint8_t Ch)
{
    
    uint8_t irq;
    uint16_t dummy;
    
    /* Check parameters */
    ASSERT(IS_BT_CH(Ch));
    
    /* Check Interrupt Request */
    irq = pFM3_BT_BASE[Ch]->STC; 
    
    /* 
     * Trigger Interrupt (PWM,PPG,Reload timer)
     * Measurement completion Interrupt (PWC)
     */
    if ((irq&(BT_INT_ENABLE_TRG<<4|BT_INT_TYP_TRG)) == (BT_INT_ENABLE_TRG<<4|BT_INT_TYP_TRG)) 
    {
        /* 
         * Clear Interrupt.   
         * For PWC timer, this bit should be cleared by reading the measurement 
         * result (DTBF) in user code.
         */ 
        pFM3_BT_BASE[Ch]->STC &= (~BT_INT_TYP_TRG); 

        if (BT_IrqCallback[Ch] != NULL) 
        {
            /* Call CallBackIrq */
            BT_IrqCallback[Ch](BT_INT_TYP_TRG);
        }
        else
        {
            /* Clear Interrupt (PWC) */
            dummy = BT_Get16bitMeasureData(Ch);            
        }
    }
    
    /* Duty Match Interrupt (PWM)*/   
    if ((irq&(BT_INT_ENABLE_DUTY<<4|BT_INT_TYP_DUTY)) == (BT_INT_ENABLE_DUTY<<4|BT_INT_TYP_DUTY)) 
    {
        /* Clear Interrupt */
        pFM3_BT_BASE[Ch]->STC &= (~BT_INT_TYP_DUTY);

        if (BT_IrqCallback[Ch] != NULL) 
        {
            /* Call CallBackIrq */
            BT_IrqCallback[Ch](BT_INT_TYP_DUTY);
        }
    }
    
    /* 
     * Underflow Interrupt (PWM,PPG,Reload timer)
     * Overflow Interrupt (PWC) 
     */
    if ((irq&(BT_INT_ENABLE_UNDER<<4|BT_INT_TYP_UNDER)) == (BT_INT_ENABLE_UNDER<<4|BT_INT_TYP_UNDER)) 
    {
        /* Clear Interrupt */
        pFM3_BT_BASE[Ch]->STC &= (~BT_INT_TYP_UNDER);

        if (BT_IrqCallback[Ch] != NULL) 
        {
            /* Call CallBackIrq */
            BT_IrqCallback[Ch](BT_INT_TYP_UNDER);
        }
    }   

}

/*****************************************************************************/
/* END OF FILE */
