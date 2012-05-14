/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_ocu_fm3.h
 **
 ** \brief Output Compare Unit drivers head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-11 10:15
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */
#ifndef DRV_MFT_OCU_H
#define DRV_MFT_OCU_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef  __cplusplus
}
#endif

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/* OCCP channel amount */
/*! \brief OCCP channel amount */
#define OC_SUM 6

/*---------------------------------------------------------------------------*/
/* Channel number for output compare unit                                    */
/*---------------------------------------------------------------------------*/
/*! \brief Chip has how many MFT units */
#define MFT_AMOUNT 2

/*! \brief MFT unit0 */
#define MFT0 0
/*! \brief MFT unit1 */
#define MFT1 1

/* OCCP channel */
/*! \brief OCCP CH0 */
#define OC_CH0 0
/*! \brief OCCP CH1 */
#define OC_CH1 1
/*! \brief OCCP CH2 */
#define OC_CH2 2
/*! \brief OCCP CH3 */
#define OC_CH3 3
/*! \brief OCCP CH4 */
#define OC_CH4 4
/*! \brief OCCP CH5 */
#define OC_CH5 5
/*! \brief OCCP Channel none */
#define OC_NONE -1


/* FRT channel for OCU unit0 */
/*! \brief FRT CH0 for OCU unit0 */
#define  FRTCH0_OCU0    0x00
/*! \brief FRT CH1 for OCU unit0 */
#define  FRTCH1_OCU0    0x01
/*! \brief FRT CH2 for OCU unit0 */
#define  FRTCH2_OCU0    0x02
/*! \brief External MFT FRT unit for OCU unit0 */
#define  FRT2OCU0_ExMFT 0x03
/*! \brief None FRT for OCU unit0 */
#define  FRT2OCU0_NONE  0x04

/* FRT channel for OCU unit1 */
/*! \brief FRT CH0 for OCU unit1 */
#define  FRTCH0_OCU1    0x00
/*! \brief FRT CH1 for OCU unit1 */
#define  FRTCH1_OCU1    0x10
/*! \brief FRT CH2 for OCU unit1 */
#define  FRTCH2_OCU1    0x20
/*! \brief External MFT FRT unit for OCU unit1 */
#define  FRT2OCU1_ExMFT 0x30
/*! \brief None FRT for OCU unit1 */
#define  FRT2OCU1_NONE  0x40

/* Send OCCP buffer timing */
/*! \brief Send OCCP buffer when FRT count at zero */
#define CNT_BOTTOM 0
/*! \brief Send OCCP buffer when FRT count at top */
#define CNT_TOP 1

/* Initial output level */
/*! \brief Initial output high level */
#define HIGH  1
/*! \brief Initial output low level  */
#define LOW   0


/* OCCP unit */
/*! \brief OCCP0 */
#define OC_RT0 0
/*! \brief OCCP1 */
#define OC_RT1 1
/*! \brief OCCP2 */
#define OC_RT2 2
/*! \brief OCCP3 */
#define OC_RT3 3
/*! \brief OCCP4 */
#define OC_RT4 4
/*! \brief OCCP5 */
#define OC_RT5 5

/* Bit definition */
/*! \brief OCU OCSA FSO0 bit set */
#define  OCU_OCFS_FSO0      ((uint8_t)0xF0)
/*! \brief OCU OCSA FSO1 bit set */
#define  OCU_OCFS_FSO1      ((uint8_t)0x0F)

/*! \brief OCU  OCSA CST0 bit set */
#define  OCU_OCSA_CST0      ((uint8_t)0xFE)
/*! \brief OCU  OCSA CST1 bit set */
#define  OCU_OCSA_CST1      ((uint8_t)0xFD)
/*! \brief OCU  OCSA BDIS0 bit set */
#define  OCU_OCSA_BDIS0     ((uint8_t)0xFB)
/*! \brief OCU  OCSA BDIS0 bit set */
#define  OCU_OCSA_BDIS1     ((uint8_t)0xF7)
/*! \brief OCU  OCSA IOE0 bit set */
#define  OCU_OCSA_IOE0     ((uint8_t)0xEF)
/*! \brief OCU  OCSA IOE1 bit set */
#define  OCU_OCSA_IOE1     ((uint8_t)0xDF)
/*! \brief OCU  OCSA IOP0 bit set */
#define  OCU_OCSA_IOP0     ((uint8_t)0xBF)
/*! \brief OCU  OCSA IOP1 bit set */
#define  OCU_OCSA_IOP1     ((uint8_t)0x7F)

/*! \brief OCU  OCSB OTD0 bit set */
#define  OCU_OCSB_OTD0     ((uint8_t)0xFE)
/*! \brief OCU  OCSB OTD1 bit set */
#define  OCU_OCSB_OTD1     ((uint8_t)0xFD)
/*! \brief OCU  OCSB CMOD bit set */
#define  OCU_OCSB_CMOD     ((uint8_t)0xEF)
/*! \brief OCU  OCSB BTS0 bit set */
#define  OCU_OCSB_BTS0     ((uint8_t)0xDF)
/*! \brief OCU  OCSB BTS1 bit set */
#define  OCU_OCSB_BTS1     ((uint8_t)0xBF)

/*! \brief OCU channel 0 interrupt bit set */
#define  OCU_INT_CH0     ((uint16_t)0x01)
/*! \brief OCU channel 1 interrupt bit set */
#define  OCU_INT_CH1     ((uint16_t)0x02)
/*! \brief OCU channel 2 interrupt bit set */
#define  OCU_INT_CH2     ((uint16_t)0x04)
/*! \brief OCU channel 3 interrupt bit set */
#define  OCU_INT_CH3     ((uint16_t)0x08)
/*! \brief OCU channel 4 interrupt bit set */
#define  OCU_INT_CH4     ((uint16_t)0x10)
/*! \brief OCU channel 5 interrupt bit set */
#define  OCU_INT_CH5     ((uint16_t)0x20)

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

/*! \brief Typedef of a Callback function pointer */
typedef void (*OCU_CallbackT) (uint8_t Type);

/*---------------------------------------------------------------------------*/
/* External variables                                                        */
/*---------------------------------------------------------------------------*/
extern OCU_CallbackT OCU_IntCallback[];

/*---------------------------------------------------------------------------*/
/* declare functions                                                         */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief  Read register value that OCU channel connect to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Which FRT channel to configure
 ** \retval  FTR_CH0, FTR_CH1, FTR_CH2
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetFrtCh(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set register value that OCU channel connect to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetFrtCh(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
					 volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Get state of OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetState(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);
/*!
 ******************************************************************************
 ** \brief  Set state of OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetState(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
					 volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Start OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_OcuStart(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Stop OCU channel to operate
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_OcuStop(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Get OCCP buffer enable state for OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetOCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set OCCP buffer enable state for OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetOCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
						   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get interrupt is enabled or disabled for each OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set enable or disable interrupt for each OCU channel when OCCP matches FRT count
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
					   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get interrupt flag for each OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Enable or not
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Clear interrupt flag for each OCU channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuClrIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Get the initial output level for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return Level initial output level
 ** \retval HIGH_LEVEL, LOW_LEVEL
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetOutputLevel(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set the initial output level for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  Level initial output level
 ** \arg    HIGH_LEVEL, LOW_LEVEL
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetOutputLevel(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
						   volatile uint8_t Level);

/*!
 ******************************************************************************
 ** \brief  Get the CMOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return register value
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetCMODReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set the CMOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetCMODReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
					   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get the timing when data in OCCP buffer send to OCCP for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return When Timing of send buffer
 ** \retval CNT_TOP, CNT_BOTTOM
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);


/*!
 ******************************************************************************
 ** \brief  Set the timing when data in OCCP buffer send to OCCP for RTx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  When Timing of send buffer
 ** \arg CNT_TOP, CNT_BOTTOM
 **
 ** \return none
 **
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
							volatile uint8_t When);

/*!
 ******************************************************************************
 ** \brief  Get the MOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \return When Timing of send buffer
 ** \retval TRUE, FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_OcuGetMODOperateReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set the MOD mode register value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuSetMODOperateReg(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
						   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Set work mode for RTx.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  COMD
 ** \arg    TRUE, FALSE
 ** \param  MOD
 ** \arg    TRUE, FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_OcuSetWorkMode(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
				volatile uint8_t CMODE, volatile uint8_t MOD);

/*!
 ******************************************************************************
 ** \brief  Get OCCP value for RTx corresponding to OC channelx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 **
 ** \retval RegVal Register value
 **
 *****************************************************************************
*/
uint16_t MFT_OcuOCCPValueRead(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh);

/*!
 ******************************************************************************
 ** \brief  Set OCCP value for RTx corresponding to OC channelx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichOCCh  Which OC channel to configure
 ** \arg    [OC_CH0, OC_CH5]
 ** \param  RegVal
 **
 ** \retval none
 **
 *****************************************************************************
*/
uint8_t MFT_OcuOCCPValueWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichOCCh,
						   volatile uint16_t RegVal);

/*!
 ******************************************************************************
 ** \brief OCU interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_Ocu_IRQHandler(void);

#endif /* DRV_MFT_OCU_H */

/*****************************************************************************/
/* END OF FILE */
