/*!
 ******************************************************************************
 **
 ** \file driver\qprc\Qprc_fm3.h
 **
 ** \brief QPRC module driver head file
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

#ifndef _QPRC_FM3_H_
#define _QPRC_FM3_H_

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/*! \brief QPRC channel number */
#define QPRC_CH_NUM           2
#define QPRC_CH0              0
#define QPRC_CH1              1


/* QPRC register type selection */
/*! \brief Configure position counter register */
#define QPRC_CFG_POS            0
/*! \brief Configure revolution counter register */
#define QPRC_CFG_REV            1


/* QPRC select the count mode of the position counter */
/*! \brief Position counter mode0 */
#define QPRC_PC_MODE0            0
/*! \brief Position counter mode1 */
#define QPRC_PC_MODE1            1
/*! \brief Position counter mode2 */
#define QPRC_PC_MODE2            2
/*! \brief Position counter mode3 */
#define QPRC_PC_MODE3            3


/* QPRC select the count mode of the revolution counter and the reset mode of the position */
/*! \brief Revolution counter mode0 */
#define QPRC_RC_MODE0            0
/*! \brief Revolution counter mode1 */
#define QPRC_RC_MODE1            1
/*! \brief Revolution counter mode2 */
#define QPRC_RC_MODE2            2
/*! \brief Revolution counter mode3 */
#define QPRC_RC_MODE3            3


/* QPRC position counter reset mask */
/*! \brief Position counter reset mask mode0 */
#define QPRC_PCR_MASK_NONE       0
/*! \brief Position counter reset mask mode1 */
#define QPRC_PCR_MASK_2CNT       1
/*! \brief Position counter reset mask mode2 */
#define QPRC_PCR_MASK_4CNT       2
/*! \brief Position counter reset mask mode3 */
#define QPRC_PCR_MASK_8CNT       3


/* QPRC interrupt type */
/*! \brief Outrange interrupt enable */
#define QPRC_INT_ENABLE_ORNG       0
/*! \brief Overflow, underflow, or zero index interrupt enable */
#define QPRC_INT_ENABLE_OUZ        1
/*! \brief PC and RC match interrupt enable */
#define QPRC_INT_ENABLE_PRCM       2
/*! \brief PC match interrupt enable */
#define QPRC_INT_ENABLE_PCM        3
/*! \brief PC match and RC match interrupt enable */
#define QPRC_INT_ENABLE_PCNRCM     4
/*! \brief Count inversion interrupt enable */
#define QPRC_INT_ENABLE_CDC        5


/* QPRC interrupt request flag */
/*! \brief Outrange interrupt request flag */
#define QPRC_IRQ_OVRANGE           0
/*! \brief Zero index interrupt request flag */
#define QPRC_IRQ_ZEROIDX           1
/*! \brief Overflow interrupt request flag */
#define QPRC_IRQ_OVFLOW            2
/*! \brief Underflow interrupt request flag */
#define QPRC_IRQ_UDFLOW            3
/*! \brief PC and RC match interrupt request flag */
#define QPRC_IRQ_PRCM              4
/*! \brief PC match interrupt request flag */
#define QPRC_IRQ_PCM               5
/*! \brief PC match and RC match interrupt request flag */
#define QPRC_IRQ_PCNRCM            6
/*! \brief Count inversion interrupt request flag */
#define QPRC_IRQ_CDC               7


/* QPRC AIN edge type*/
/*! \brief Disables edge detection */
#define QPRC_AEDGE_DISABLE         0
/*! \brief Falling edge */
#define QPRC_AEDGE_FALL            1
/*! \brief Rising edge */
#define QPRC_AEDGE_RISE            2
/*! \brief Both edges */
#define QPRC_AEDGE_BOTH            3


/* QPRC BIN edge type*/
/*! \brief Disables edge detection */
#define QPRC_BEDGE_DISABLE          0
/*! \brief Falling edge */
#define QPRC_BEDGE_FALL             1
/*! \brief Rising edge */
#define QPRC_BEDGE_RISE             2
/*! \brief Both edges */
#define QPRC_BEDGE_BOTH             3


/* QPRC ZIN edge type*/
/*! \brief Disables edge detection */
#define QPRC_ZEDGE_DISABLE          0
/*! \brief Falling edge */
#define QPRC_ZEDGE_FALL             1
/*! \brief Rising edge */
#define QPRC_ZEDGE_RISE             2
/*! \brief Both edges */
#define QPRC_ZEDGE_BOTH             3


/* QPRC position counter direction type */
/*! \brief The last position counter overflow or underflow */
#define QPRC_DIROU                    3
/*! \brief The last position counter direction changed */
#define QPRC_DIRPC                    2


/* QPRC position counter direction return value */
/*! \brief The position counter was incremented */
#define QPRC_PCINC                  0
/*! \brief The position counter was decremented */
#define QPRC_PCDEC                  1


/* QPRC swap the connections of the AIN input and BIN input to the position counter */
/*! \brief No swap */
#define QPRC_SWAP_DIS              0
/*! \brief Swaps AIN and BIN inputs */
#define QPRC_SWAP_EN               1


/* QPRC register function selection */
/*! \brief Register QPRCR compared to position counter */
#define QPRC_RSEL_POS            0
/*! \brief Register QPRCR compared to revolution counter */
#define QPRC_RSEL_REV            1


/* QPRC set the function of the ZIN external pin */
/*! \brief Counter clear function */
#define QPRC_ZIN_CLR              0
/*! \brief Gate function */
#define QPRC_ZIN_GATE             1


/* QPRC set the outrange mode of the revolution counter */
/*! \brief Select a positive number */
#define QPRC_OR_INT              0
/*! \brief Select the 8K value */
#define QPRC_OR_8K               1


/* Register bit definition, not open to user */
#define QECR_ORNGIE          0x0004U
#define QECR_ORNGF           0x0002U
#define QECR_INTF            0x0002U

#define QICR_ZIIF            0x0080U
#define QICR_OFDF            0x0040U
#define QICR_UFDF            0x0020U
#define QICR_QPRCMF          0x0008U
#define QICR_QPCMF           0x0002U
#define QICR_QPCNRCMF        0x2000U
#define QICR_CDCF            0x0200U
#define QICR_INTF            0x22EAU    /* (QICR_ZIIF | QICR_OFDF | QICR_UFDF | QICR_QPRCMF | QICR_QPCMF | QICR_QPCNRCMF | QICR_CDCF) */


/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

/*! \brief Typedef of a Callback function pointer */
typedef void (*QPRC_CallbackT) (uint8_t IntType);


/*---------------------------------------------------------------------------*/
/* External variables                                                        */
/*---------------------------------------------------------------------------*/
extern QPRC_CallbackT QPRC_IrqCallback[];
 
/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif


uint16_t QPRC_CounterRead(uint8_t Ch, uint8_t RegType);

void QPRC_CounterWrite(uint8_t Ch, uint16_t Val, uint8_t RegType);

void QPRC_MaxPositionWrite(uint8_t Ch, uint16_t Val);

void QPRC_PosCompareWrite(uint8_t Ch, uint16_t Val);

void QPRC_PosRevCompareWrite(uint8_t Ch, uint16_t Val);

void QRPC_SetPosMode(uint8_t Ch, uint8_t CntMode);

void QRPC_SetRevMode(uint8_t Ch, uint8_t CntMode);

void QRPC_SetPCRRstMsk(uint8_t Ch, uint8_t MskTime);

void QRPC_SetCompareMode(uint8_t Ch, uint8_t CmpMode);

void QPRC_CountEnable(uint8_t Ch);

void QPRC_CountDisable(uint8_t Ch);

void QPRC_IntEnable(uint8_t Ch, uint8_t IntType);

void QPRC_IntDisable(uint8_t Ch, uint8_t IntType);

uint8_t QPRC_GetIntRequest(uint8_t Ch, uint8_t IntType);

uint16_t QPRC_GetCountDirection(uint8_t Ch, uint8_t DirType);

void QPRC_ClrIntRequest(uint8_t Ch, uint16_t IntType);

void QPRC_SetAINEdge(uint8_t Ch, uint8_t EdgeType);

void QPRC_SetBINEdge(uint8_t Ch, uint8_t EdgeType);

void QPRC_SetZINEdge(uint8_t Ch, uint8_t EdgeType);

void QPRC_SetSwap(uint8_t Ch, uint8_t Val);

void QPRC_SetRegFunc(uint8_t Ch, uint8_t Val);

void QPRC_SetZINFunc(uint8_t Ch, uint8_t Val);

void QPRC_SetOrngMode(uint8_t Ch, uint8_t Val);

void DT_Handler(void);


#ifdef __cplusplus
}
#endif

#endif   /* _QPRC_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */

