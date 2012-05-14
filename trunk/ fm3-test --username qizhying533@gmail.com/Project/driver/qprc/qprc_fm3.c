/*!
 ******************************************************************************
 **
 ** \file driver\qprc\Qprc_fm3.c
 **
 ** \brief QPRC module driver file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-22 14:00
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
#include "qprc_fm3.h"


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FM3_QPRC_TypeDef* pFM3_QPRC_BASE[QPRC_CH_NUM] = 
{
    (FM3_QPRC_TypeDef*)(FM3_QPRC0_BASE),
    (FM3_QPRC_TypeDef*)(FM3_QPRC1_BASE)
};


/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/

static void qprc_IrqHandler(uint8_t Ch, uint8_t Irq);


/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*! \brief Pointer array of qprc irq callback function */
QPRC_CallbackT QPRC_IrqCallback[] = 
{ 
    NULL,
    NULL,
};


/*!
 ******************************************************************************
 ** \brief Set the count mode of the position counter
 **
 ** \param Ch Requested channel
 ** \param CntMode Count mode selection
 ** \arg QPRC_PC_MODE0
 ** \arg QPRC_PC_MODE1
 ** \arg QPRC_PC_MODE2
 ** \arg QPRC_PC_MODE3
 **
 ** \return none
 **
 ******************************************************************************
 */
void QRPC_SetPosMode(uint8_t Ch, uint8_t CntMode)
{
    pFM3_QPRC_BASE[Ch]->QCRL = (pFM3_QPRC_BASE[Ch]->QCRL & 0xFC) | CntMode;

    return;
}


/*!
 ******************************************************************************
 ** \brief Set the count mode of the revolution counter and the reset mode of the position
 **
 ** \param Ch Requested channel
 ** \param CntMode Count mode selection
 ** \arg QPRC_RC_MODE0
 ** \arg QPRC_RC_MODE1
 ** \arg QPRC_RC_MODE2
 ** \arg QPRC_RC_MODE3
 **
 ** \return none
 **
 ******************************************************************************
 */
void QRPC_SetRevMode(uint8_t Ch, uint8_t CntMode)
{
    pFM3_QPRC_BASE[Ch]->QCRL = (pFM3_QPRC_BASE[Ch]->QCRL & 0xF3) | (CntMode<<2);

    return;
}


/*!
 ******************************************************************************
 ** \brief Set the period (mask time) to ignore the events shown below after detecting a
 **  position counter overflow or underflow or detecting a ZIN active edge.
 **
 ** \param Ch Requested channel
 ** \param MskTime The time of position counter event ignored
 ** \arg QPRC_PCR_MASK_NONE
 ** \arg QPRC_PCR_MASK_2CNT
 ** \arg QPRC_PCR_MASK_4CNT
 ** \arg QPRC_PCR_MASK_8CNT
 **
 ** \return none
 **
 ******************************************************************************
 */
void QRPC_SetPCRRstMsk(uint8_t Ch, uint8_t MskTime)
{
    pFM3_QPRC_BASE[Ch]->QCRH = (pFM3_QPRC_BASE[Ch]->QCRH & 0xFC) | MskTime;

    return;
}


/*!
 ******************************************************************************
 ** \brief Read the current value of the position/revolution counter
 **
 ** \param Ch Requested channel
 ** \param RegType Register type selection
 ** \arg QPRC_CFG_POS
 ** \arg QPRC_CFG_REV
 **
 ** \return Current value of the position/revolution counter
 **
 ******************************************************************************
 */
uint16_t QPRC_CounterRead(uint8_t Ch, uint8_t RegType)
{
    if(RegType == QPRC_CFG_POS)
    {
        return pFM3_QPRC_BASE[Ch]->QPCR;
    }
    else
    {
        return pFM3_QPRC_BASE[Ch]->QRCR;
    }
}


/*!
 ******************************************************************************
 ** \brief Write the count value to position/revolution register
 **
 ** \param Ch Requested channel
 ** \param Val The count value be written to position/revolution register
 ** \param RegType Register type selection
 ** \arg QPRC_CFG_POS
 ** \arg QPRC_CFG_REV
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_CounterWrite(uint8_t Ch, uint16_t Val, uint8_t RegType)
{
    if(RegType == QPRC_CFG_POS)
    {
        pFM3_QPRC_BASE[Ch]->QPCR = Val;  
    }
    else
    {
        pFM3_QPRC_BASE[Ch]->QRCR = Val;  
    }

    return;
}


/*!
 ******************************************************************************
 ** \brief Specify the maximum value of the position counter
 **
 ** \param Ch Requested channel
 ** \param Val The count value be written to position/revolution register
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_MaxPositionWrite(uint8_t Ch, uint16_t Val)
{
    pFM3_QPRC_BASE[Ch]->QMPR = Val;

    return;
}


/*!
 ******************************************************************************
 ** \brief Set position counter compare register(QPCCR)
 **
 ** \param Ch Requested channel
 ** \param Val The count value be written to compare register
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_PosCompareWrite(uint8_t Ch, uint16_t Val)
{
    pFM3_QPRC_BASE[Ch]->QPCCR = Val;

    return;
}


/*!
 ******************************************************************************
 ** \brief Set position and revolution counter compare register(QPRCR)
 **
 ** \param Ch Requested channel
 ** \param Val The count value be written to compare register
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_PosRevCompareWrite(uint8_t Ch, uint16_t Val)
{
    pFM3_QPRC_BASE[Ch]->QPRCR = Val;

    return;
}


/*!
 ******************************************************************************
 ** \brief Enable position counter
 **
 ** \param Ch Requested channel
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_CountEnable(uint8_t Ch)
{
    pFM3_QPRC_BASE[Ch]->QCRL &= 0xEF;

    return;
}


/*!
 ******************************************************************************
 ** \brief Disable position counter and revolution counter
 **
 ** \param Ch Requested channel
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_CountDisable(uint8_t Ch)
{
    pFM3_QPRC_BASE[Ch]->QCRL |= 0x10;

    return;
}


/*!
 ******************************************************************************
 ** \brief Enable interrupt
 **
 ** \param Ch Requested channel
 ** \param IntType Interrupt type
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
void QPRC_IntEnable(uint8_t Ch, uint8_t IntType)
{
    switch(IntType)
    {
        case QPRC_INT_ENABLE_ORNG:
            pFM3_QPRC_BASE[Ch]->QECR |= 0x04;
            break;
        case QPRC_INT_ENABLE_OUZ:
            pFM3_QPRC_BASE[Ch]->QICRL |= 0x10;
            break;
        case QPRC_INT_ENABLE_PRCM:
            pFM3_QPRC_BASE[Ch]->QICRL |= 0x04;
            break;
        case QPRC_INT_ENABLE_PCM:
            pFM3_QPRC_BASE[Ch]->QICRL |= 0x01;
            break;
        case QPRC_INT_ENABLE_PCNRCM:
            pFM3_QPRC_BASE[Ch]->QICRH |= 0x10;
            break;
        case QPRC_INT_ENABLE_CDC:
            pFM3_QPRC_BASE[Ch]->QICRH |= 0x01;
            break;
        default:
            break;
    }

    return;
}


/*!
 ******************************************************************************
 ** \brief Disable interrupt
 **
 ** \param Ch Requested channel
 ** \param IntType Interrupt type
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
void QPRC_IntDisable(uint8_t Ch, uint8_t IntType)
{
    switch(IntType)
    {
        case QPRC_INT_ENABLE_ORNG:
            pFM3_QPRC_BASE[Ch]->QECR &= ~0x04;
            break;
        case QPRC_INT_ENABLE_OUZ:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~0x10;
            break;
        case QPRC_INT_ENABLE_PRCM:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~0x04;
            break;
        case QPRC_INT_ENABLE_PCM:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~0x01;
            break;
        case QPRC_INT_ENABLE_PCNRCM:
            pFM3_QPRC_BASE[Ch]->QICRH &= ~0x10;
            break;
        case QPRC_INT_ENABLE_CDC:
            pFM3_QPRC_BASE[Ch]->QICRH &= ~0x01;
            break;
        default:
            break;
    }

    return;
}


/*!
 ******************************************************************************
 ** \brief Get Interrupt request flag
 **
 ** \param Ch Requested channel
 ** \param IntType Interrupt type
 ** \arg QPRC_IRQ_OVRANGE
 ** \arg QPRC_IRQ_ZEROIDX
 ** \arg QPRC_IRQ_OVFLOW
 ** \arg QPRC_IRQ_UDFLOW
 ** \arg QPRC_IRQ_PRCM
 ** \arg QPRC_IRQ_PCM
 ** \arg QPRC_IRQ_PCNRCM
 ** \arg QPRC_IRQ_CDC
 **
 ** \return interrupt request flag
 ** \retval 0
 ** \retval 1
 **
 ******************************************************************************
 */
uint8_t QPRC_GetIntRequest(uint8_t Ch, uint8_t IntType)
{
    uint8_t ret;

    switch(IntType)
    {
        case QPRC_IRQ_OVRANGE:
            ret = (pFM3_QPRC_BASE[Ch]->QECR >> 1) & 0x01;
            break;
        case QPRC_IRQ_ZEROIDX:
            ret = (pFM3_QPRC_BASE[Ch]->QICRL >> 7) & 0x01;
            break;
        case QPRC_IRQ_OVFLOW:
            ret = (pFM3_QPRC_BASE[Ch]->QICRL >> 6) & 0x01;
            break;
        case QPRC_IRQ_UDFLOW:
            ret = (pFM3_QPRC_BASE[Ch]->QICRL >> 5) & 0x01;
            break;
        case QPRC_IRQ_PRCM:
            ret = (pFM3_QPRC_BASE[Ch]->QICRL >> 3) & 0x01;
            break;
        case QPRC_IRQ_PCM:
            ret = (pFM3_QPRC_BASE[Ch]->QICRL >> 1) & 0x01;
            break;
        case QPRC_IRQ_PCNRCM:
            ret = (pFM3_QPRC_BASE[Ch]->QICRH >> 5) & 0x01;
            break;
        case QPRC_IRQ_CDC:
            ret = (pFM3_QPRC_BASE[Ch]->QICRH >> 1) & 0x01;
            break;
        default:
            break;
    }

    return ret;
}


/*!
 ******************************************************************************
 ** \brief Clear Interrupt request flag
 **
 ** \param Ch Requested channel
 ** \param IntType Interrupt type
 ** \arg QPRC_IRQ_OVRANGE
 ** \arg QPRC_IRQ_ZEROIDX
 ** \arg QPRC_IRQ_OVFLOW
 ** \arg QPRC_IRQ_UDFLOW
 ** \arg QPRC_IRQ_PRCM
 ** \arg QPRC_IRQ_PCM
 ** \arg QPRC_IRQ_PCNRCM
 ** \arg QPRC_IRQ_CDC
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_ClrIntRequest(uint8_t Ch, uint16_t IntType)
{
    switch(IntType)
    {
        case QPRC_IRQ_OVRANGE:
            pFM3_QPRC_BASE[Ch]->QECR &= ~(0x01 << 1);
            break;
        case QPRC_IRQ_ZEROIDX:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~(0x01 << 7);
            break;
        case QPRC_IRQ_OVFLOW:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~(0x01 << 6);
            break;
        case QPRC_IRQ_UDFLOW:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~(0x01 << 5);
            break;
        case QPRC_IRQ_PRCM:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~(0x01 << 3);
            break;
        case QPRC_IRQ_PCM:
            pFM3_QPRC_BASE[Ch]->QICRL &= ~(0x01 << 1);
            break;
        case QPRC_IRQ_PCNRCM:
            pFM3_QPRC_BASE[Ch]->QICRH &= ~(0x01 << 5);
            break;
        case QPRC_IRQ_CDC:
            pFM3_QPRC_BASE[Ch]->QICRH &= ~(0x01 << 1);
            break;
        default:
            break;
    }
    
    return;
}


/*!
 ******************************************************************************
 ** \brief Set the detection edge
 **
 ** \param Ch Requested channel
 ** \param EdgeType The detection edge type
 ** \arg QPRC_AEDGE_DISABLE
 ** \arg QPRC_AEDGE_FALL
 ** \arg QPRC_AEDGE_RISE
 ** \arg QPRC_AEDGE_BOTH
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetAINEdge(uint8_t Ch, uint8_t EdgeType)
{
    pFM3_QPRC_BASE[Ch]->QCRH |= (EdgeType << 2);

    return;
}


/*!
 ******************************************************************************
 ** \brief Set the detection edge
 **
 ** \param Ch Requested channel
 ** \param EdgeType The detection edge type
 ** \arg QPRC_BEDGE_DISABLE
 ** \arg QPRC_BEDGE_FALL
 ** \arg QPRC_BEDGE_RISE
 ** \arg QPRC_BEDGE_BOTH
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetBINEdge(uint8_t Ch, uint8_t EdgeType)
{
    pFM3_QPRC_BASE[Ch]->QCRH |= (EdgeType << 4);

    return;
}


/*!
 ******************************************************************************
 ** \brief Set the detection edge
 **
 ** \param Ch Requested channel
 ** \param EdgeType The detection edge type
 ** \arg QPRC_ZEDGE_DISABLE
 ** \arg QPRC_ZEDGE_FALL
 ** \arg QPRC_ZEDGE_RISE
 ** \arg QPRC_ZEDGE_BOTH
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetZINEdge(uint8_t Ch, uint8_t EdgeType)
{
    pFM3_QPRC_BASE[Ch]->QCRH |= (EdgeType << 6);

    return;
}


/*!
 ******************************************************************************
 ** \brief Swap AIN and BIN inputs
 **
 ** \param Ch Requested channel
 ** \param Val Swap value
 ** \arg QPRC_SWAP_DIS
 ** \arg QPRC_SWAP_EN
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetSwap(uint8_t Ch, uint8_t Val)
{
    pFM3_QPRC_BASE[Ch]->QCRL = (pFM3_QPRC_BASE[Ch]->QCRL & 0x7F) | (Val << 7);
    
    return;
}


/*!
 ******************************************************************************
 ** \brief Set register QPRCR compared with position counter or revolution counter
 **
 ** \param Ch Requested channel
 ** \param Val Register QPRCR compared object
 ** \arg QPRC_RSEL_POS
 ** \arg QPRC_RSEL_REV
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetRegFunc(uint8_t Ch, uint8_t Val)
{
    pFM3_QPRC_BASE[Ch]->QCRL = (pFM3_QPRC_BASE[Ch]->QCRL & 0xBF) | (Val << 6);
    
    return;    
}


/*!
 ******************************************************************************
 ** \brief Set the function of the ZIN external pin
 **
 ** \param Ch Requested channel
 ** \param Val ZIN function
 ** \arg QPRC_ZIN_CLR
 ** \arg QPRC_ZIN_GATE
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetZINFunc(uint8_t Ch, uint8_t Val)
{
    pFM3_QPRC_BASE[Ch]->QCRL = (pFM3_QPRC_BASE[Ch]->QCRL & 0xDF) | (Val << 5);
    
    return;
}


/*!
 ******************************************************************************
 ** \brief Set the outrange mode of the revolution counter
 **
 ** \param Ch Requested channel
 ** \param Val Outrange mode
 ** \arg QPRC_OR_INT
 ** \arg QPRC_OR_8K
 **
 ** \return none
 **
 ******************************************************************************
 */
void QPRC_SetOrngMode(uint8_t Ch, uint8_t Val)
{
    pFM3_QPRC_BASE[Ch]->QECR = (pFM3_QPRC_BASE[Ch]->QECR & 0x01) | Val;
    
    return;
}


/*!
 ******************************************************************************
 ** \brief Read the direction of position counter
 **
 ** \param Ch Requested channel
 ** \param DirType The type of position counter direction
 ** \arg QPRC_DIROU
 ** \arg QPRC_DIRPC
 ** \return Position counter direction
 **
 ** \retval QPRC_PCINC
 ** \retval QPRC_PCDEC
 ******************************************************************************
 */
uint16_t QPRC_GetCountDirection(uint8_t Ch, uint8_t DirType)
{
    uint8_t ret;

    if(((pFM3_QPRC_BASE[Ch]->QICRH >> DirType) & 0x01) == 1)
    {
        ret = QPRC_PCDEC;
    }
    else
    {
        ret = QPRC_PCINC;
    }

    return ret;
}


/*!
 ******************************************************************************
 ** \brief Dual Timer / Quad Decoder interrupt handler
 **
 ** \return none
 **
 ******************************************************************************
 */
void DT_Handler(void)
{
    uint16_t irq;
    
    irq = (uint16_t)(FM3_INTREQ->IRQ06MON & 0x00003FFCU);

    if((irq & 0x00FC) != 0)
    {
        qprc_IrqHandler(0U, (uint8_t)(irq >> 2));
    }

    if((irq & 0x3F00) != 0)
    {
        qprc_IrqHandler(1U, (uint8_t)(irq >> 8));
    }

    return;
}


/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/ 
/*---------------------------------------------------------------------------*/
/* Interrupt handler                                                */
/*---------------------------------------------------------------------------*/
static void qprc_IrqHandler(uint8_t Ch, uint8_t Irq)
{
    /* Position Counter Matching Interrupt */
    if ((Irq & 0x01U) != 0)
    {  
        /* Clear Interrupt */
        pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_QPCMF;
        
        if(QPRC_IrqCallback[Ch] != NULL) {
            /* Call CallBackIrq */
            QPRC_IrqCallback[Ch](QPRC_IRQ_PCM);
        }
    }

    /* Position Counter & Revolution Counter Matching  Interrupt */
    if ((Irq & 0x02U) != 0) {  
        /* Clear Interrupt */
        pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_QPRCMF;
    
        if (QPRC_IrqCallback[Ch] != NULL) {
            /* Call CallBackIrq */
            QPRC_IrqCallback[Ch](QPRC_IRQ_PRCM);
        }
    }

    /* Over flow / Under flow / Zero index Interrupt */
    if ((Irq & 0x04U) != 0)
    {  
        if ((pFM3_QPRC_BASE[Ch]->QICR & QICR_ZIIF) != 0) {  /* Zero index */
            /* Clear Interrupt */
            pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_ZIIF;

            if (QPRC_IrqCallback[Ch] != NULL) {
                /* Call CallBackIrq */
                QPRC_IrqCallback[Ch](QPRC_IRQ_ZEROIDX);
            }
        }

        if ((pFM3_QPRC_BASE[Ch]->QICR & QICR_OFDF) != 0) {  /* Over flow */
            /* Clear Interrupt */
            pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_OFDF;

            if (QPRC_IrqCallback[Ch] != NULL) {
                /* Call CallBackIrq */
                QPRC_IrqCallback[Ch](QPRC_IRQ_OVFLOW);
            }
        }

        if ((pFM3_QPRC_BASE[Ch]->QICR & QICR_UFDF) != 0) {  /* Under flow */
            /* Clear Interrupt */
            pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_UFDF;

            if (QPRC_IrqCallback[Ch] != NULL) {
                /* Call CallBackIrq */
                QPRC_IrqCallback[Ch](QPRC_IRQ_UDFLOW);
            }
        }
    }

    /* Counter Direction Interrupt */
    if ((Irq & 0x08U) != 0) {  
        /* Clear Interrupt */
        pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_CDCF;

        if (QPRC_IrqCallback[Ch] != NULL) {
            /* Call CallBackIrq */
            QPRC_IrqCallback[Ch](QPRC_IRQ_CDC);
        }
    }

    /* Revolution Counter Over Range Interrupt */
    if ((Irq & 0x10U) != 0) {  
        /* Clear Interrupt */
        pFM3_QPRC_BASE[Ch]->QECR = (pFM3_QPRC_BASE[Ch]->QECR) & ~(QECR_ORNGF);

        if (QPRC_IrqCallback[Ch] != NULL) {
            /* Call CallBackIrq */
            QPRC_IrqCallback[Ch](QPRC_IRQ_OVRANGE);
        }
    }

    /* Position Counter Matching & Revolution Counter Matching Interrupt */
    if ((Irq & 0x20U) != 0) {  
        /* Clear Interrupt */
        pFM3_QPRC_BASE[Ch]->QICR = ((pFM3_QPRC_BASE[Ch]->QICR) | QICR_INTF) ^ QICR_QPCNRCMF;

        if (QPRC_IrqCallback[Ch] != NULL) {
            /* Call CallBackIrq */
            QPRC_IrqCallback[Ch](QPRC_IRQ_PCNRCM);
        }
    }
}


/*****************************************************************************/
/* END OF FILE */


