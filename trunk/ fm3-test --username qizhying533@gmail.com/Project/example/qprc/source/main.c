/*!
 ******************************************************************************
 **
 ** \file example\qprc\source\main.c
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-12-23
 **
 ** \brief This file provides an example to use the qprc peripheral library.
 **
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
#include "mb9bf50x_lib.h"


/*---------------------------------------------------------------------------*/
/* global functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void qprc_callback(uint8_t IntType);


/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
void QPRC_Init(void);


/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/
static volatile int8_t int_flag;
uint16_t uint_pos, uint_rev;
int32_t int_delay;


/*!
 ******************************************************************************
 ** \brief  Main function of project for MB9B506 series.
 **
 ** \param  none
 **
 ** \retval uint32_t return value, if needed
 ******************************************************************************
 */
int32_t main(void)
{
    SystemInit();    /* Initialize system */
    
    QPRC_Init();     /* Initialize QPRC module */
    
    NVIC_EnableIRQ(DTIM_QDU_IRQn);        /* Enable dual timer interrupt */

    QPRC_CountEnable(QPRC_CH0);           /* Start counter */
    
    while(1)
    {
        int_delay ++;
        if(int_delay >= 200)
        {
            int_delay = 0;
            uint_pos = QPRC_CounterRead(QPRC_CH0, QPRC_CFG_POS);    /* Get position */
            uint_rev = QPRC_CounterRead(QPRC_CH0, QPRC_CFG_REV);    /* Get revolution */
        }

        if(int_flag >= 0x20)
        {
            QPRC_CountDisable(QPRC_CH0);         /* stop counter */
        }
    }
}


/*!
 ******************************************************************************
 ** \brief  Initialize QPRC module(QPRC0)
 **
 ** \param  none
 **
 ** \retval none
 ******************************************************************************
 */
void QPRC_Init(void)
{
    /* Set I/O Port (Quad Counter Ch0) */
    /* AIN/BIN/ZIN : P49/P4A/P4B */
    FM3_GPIO->PCR4   = (FM3_GPIO->PCR4 | 0x00000E00);       /* pull-up on */
    FM3_GPIO->DDR4   = (FM3_GPIO->DDR4 & ~(0x00000E00));    /* input */
    FM3_GPIO->PFR4   = (FM3_GPIO->PFR4 | 0x00000E00);        /* uses a pin as peripheral functions */
    FM3_GPIO->EPFR09 = (FM3_GPIO->EPFR09 | 0x0000002A);    /* select multi function pin */

    /* Set QPRC0 parameter */
    QPRC_MaxPositionWrite(QPRC_CH0, 4095);
    QPRC_PosCompareWrite(QPRC_CH0, 2048);
    QPRC_PosRevCompareWrite(QPRC_CH0, 4);
    QPRC_SetRegFunc(QPRC_CH0, QPRC_RSEL_REV);
    QRPC_SetPosMode(QPRC_CH0, QPRC_PC_MODE2);
    QRPC_SetRevMode(QPRC_CH0, QPRC_RC_MODE2);
    QPRC_SetAINEdge(QPRC_CH0, QPRC_AEDGE_BOTH);
    QPRC_SetBINEdge(QPRC_CH0, QPRC_BEDGE_BOTH);
    QPRC_IrqCallback[QPRC_CH0] = qprc_callback;

    /* Enable all interrupt */
    QPRC_IntEnable(QPRC_CH0, QPRC_INT_ENABLE_ORNG);        
    QPRC_IntEnable(QPRC_CH0, QPRC_INT_ENABLE_OUZ);
    QPRC_IntEnable(QPRC_CH0, QPRC_INT_ENABLE_PRCM);
    QPRC_IntEnable(QPRC_CH0, QPRC_INT_ENABLE_PCM);
    QPRC_IntEnable(QPRC_CH0, QPRC_INT_ENABLE_PCNRCM);

    return;
}


/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg QPRC_INT_ENABLE_ORNG
 ** \arg QPRC_INT_ENABLE_OUZ
 ** \arg QPRC_INT_ENABLE_PRCM
 ** \arg QPRC_INT_ENABLE_PCM
 ** \arg QPRC_INT_ENABLE_PCNRCM
 ** \arg QPRC_INT_ENABLE_CDC
 **
 ** \return none
 **
 ******************************************************************************
 */
static void qprc_callback(uint8_t IntType)
{
    int_flag++;

    switch(IntType)
    {
        case QPRC_IRQ_OVRANGE:
            printf(" Outrange interrupt \n");
            break;
        case QPRC_IRQ_ZEROIDX:
            printf(" Zero index interrupt \n");
            break;
        case QPRC_IRQ_OVFLOW:
            printf(" Overflow interrupt \n");
            break;
        case QPRC_IRQ_UDFLOW:
            printf(" Underflow interrupt \n");
            break;
        case QPRC_IRQ_PRCM:
            printf(" Position counter & revolution counter interrupt \n");
            break;
        case QPRC_IRQ_PCM:
            printf(" PC match interrupt \n");
            break;
        case QPRC_IRQ_PCNRCM:
            printf(" PC match and RC match interrupt \n");
            break;
        case QPRC_IRQ_CDC:
            printf(" Count inversion interrupt \n");
            break;
            
        default:
            break;
    }
}


/*****************************************************************************/
/* END OF FILE */

