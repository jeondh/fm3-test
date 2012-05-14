/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_frt_fm3.h
 **
 ** \brief Free-run Timer Unit drivers head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-9 10:50
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef DRV_MFT_FRT_H
#define DRV_MFT_FRT_H

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

/*! \brief Chip has how many MFT units */
#define MFT_AMOUNT 2

/*! \brief MFT unit0 */
#define MFT0 0
/*! \brief MFT unit1 */
#define MFT1 1

/* FRT channel amount */
/*! \brief FRT channel amount */
#define MFT_FRT_CH_AMOUNT 3

/* FRT count mode */
/*! \brief FRT up count mode */
#define CNT_MODE_UP 0
/*! \brief FRT up and down count mode */
#define CNT_MODE_UPDOWN 1

/* FRT channel */
/*! \brief FRT CH0 */
#define FRT_CH0 0
/*! \brief FRT CH1 */
#define FRT_CH1 1
/*! \brief FRT CH2 */
#define FRT_CH2 2
/*! \brief FRT Channel none */
#define FRT_NONE -1

/* ADC unit */
/*! \brief ADC unit0 */
#define ADC_UNIT0 0
/*! \brief ADC unit1 */
#define ADC_UNIT1 1
/*! \brief ADC unit2 */
#define ADC_UNIT2 2
/*! \brief ADC unit none */
#define ADC_NONE -1

/* FRT Division value */
/*! \brief FRT Division 0 */
#define FRT_DIV0 0
/*! \brief FRT Division 1 */
#define FRT_DIV1 1
/*! \brief FRT Division 2 */
#define FRT_DIV2 2
/*! \brief FRT Division 3 */
#define FRT_DIV3 3
/*! \brief FRT Division 4 */
#define FRT_DIV4 4
/*! \brief FRT Division 5 */
#define FRT_DIV5 5
/*! \brief FRT Division 6 */
#define FRT_DIV6 6
/*! \brief FRT Division 7 */
#define FRT_DIV7 7
/*! \brief FRT Division 8 */
#define FRT_DIV8 8

/* FRT clock origin */
/*! \brief FRT clock internal origin */
#define InterClk 0
/*! \brief FRT clock external origin */
#define ExterClk 1

/* Bit definition */
/*! \brief FRT clock bit set */
#define  FRT_CLK        ((uint16_t)0xFFF0)
/*! \brief FRT SCLR bit set */
#define  FRT_SCLR       ((uint16_t)0xFFEF)
/*! \brief FRT MODE bit set */
#define  FRT_MODE       ((uint16_t)0xFFDF)
/*! \brief FRT STOP bit set */
#define  FRT_STOP       ((uint16_t)0xFFBF)
/*! \brief FRT BFE bit set */
#define  FRT_BFE        ((uint16_t)0xFF7F)
/*! \brief FRT ICRE bit set */
#define  FRT_ICRE       ((uint16_t)0xFEFF)
/*! \brief FRT ICLR bit set */
#define  FRT_ICLR       ((uint16_t)0xFDFF)
/*! \brief FRT IRQZE bit set */
#define  FRT_IRQZE      ((uint16_t)0xDFFF)
/*! \brief FRT IRQZF bit set */
#define  FRT_IRQZF      ((uint16_t)0xBFFF)
/*! \brief FRT ECKE bit set */
#define  FRT_ECKE      ((uint16_t)0x7FFF)

/*! \brief FRT AD0E bit set */
#define  FRT_AD0E      ((uint16_t)0xFFFE)
/*! \brief FRT AD1E bit set */
#define  FRT_AD1E      ((uint16_t)0xFFFD)
/*! \brief FRT AD2E bit set */
#define  FRT_AD2E      ((uint16_t)0xFFFB)

/*! \brief FRT channel 0 top interrupt bit set */
#define  FRT_INT_TOP_CH0    ((uint16_t)0x01)
/*! \brief FRT channel 1 top interrupt bit set */
#define  FRT_INT_TOP_CH1    ((uint16_t)0x02)
/*! \brief FRT channel 2 top interrupt bit set */
#define  FRT_INT_TOP_CH2    ((uint16_t)0x04)
/*! \brief FRT channel 0 zero interrupt bit set */
#define  FRT_INT_ZERO_CH0   ((uint16_t)0x08)
/*! \brief FRT channel 1 zero interrupt bit set */
#define  FRT_INT_ZERO_CH1   ((uint16_t)0x10)
/*! \brief FRT channel 2 zero interrupt bit set */
#define  FRT_INT_ZERO_CH2   ((uint16_t)0x20)

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

/*! \brief Typedef of a Callback function pointer */
typedef void (*FRT_CallbackT) (uint8_t Type);

/*---------------------------------------------------------------------------*/
/* External variables                                                        */
/*---------------------------------------------------------------------------*/
extern FRT_CallbackT FRT_IntCallback[];


/*---------------------------------------------------------------------------*/
/* declare functions                                                         */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Read division value for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return  FRT division value
 ** \retval  [FRT_DIV0, FRT_DIV8]
 *****************************************************************************
*/
uint8_t MFT_FrtDivRead(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Configure division value for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Div Division value
 ** \arg 	[FRT_DIV0, FRT_DIV8]
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtDivWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
					 volatile uint8_t Div);

/*!
 ******************************************************************************
 ** \brief  Initialize FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En  Enable or not
 ** \arg 	TRUE,FALSE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtInit(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
				 volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get count mode for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT count mode
 ** \retval CNT_MODE_UP
 ** \retval CNT_MODE_UPDOWN
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetCntMode(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set count mode for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Mode  Count mode.
 ** \arg    CNT_MODE_UP,CNT_MODE_UPDOWN
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetCntMode(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
					   volatile uint8_t Mode);

/*!
 ******************************************************************************
 ** \brief  Get FRT STOP register state
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT STOP register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetStopReg(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set FRT STOP register state
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetStopReg(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
					   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get TCCP buffer enable state for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set TCCP buffer enable state for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetTCCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get interrupt state for FRTx when TCCP matches FRT count value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTopIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set interrupt function for FRTx when TCCP matches FRT count value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetTopIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						  volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get FRT top-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTopIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Clear FRT top-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtClrTopIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Get interrupt state for FRTx when FRT count value reaches 0
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetZeroIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set interrupt function for FRTx when FRT count value reaches 0
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  En enable or not
 ** \arg    TRUE,FLASE
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetZeroIntFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						   volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Get FRT 0-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FLASE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetZeroIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Clear FRT 0-detect interrupt is occurred or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtClrZeroIntFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Get the FRT’s count clock origin
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return FRT TCCP buffer register state
 ** \retval InterClk
 ** \retval ExterClk
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetCLKOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set the FRT’s count clock origin
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Origin the clock signal origin
 ** \arg    InterClk,ExterClk
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetCLKOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						 volatile uint8_t Origin);

/*!
 ******************************************************************************
 ** \brief  Get state of output convert ADC start signal when 0-detected INT comes
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  WhichADC Start signal send to which ADC unit
 ** \arg    ADC_UNIT0, ADC_UNIT1, ADC_UNIT2
 **
 ** \return FRT TCCP buffer register state
 ** \retval TRUE
 ** \retval FALSE
 **
 *****************************************************************************
*/
uint8_t MFT_FrtGetTrigADCFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
							     volatile uint8_t WhichADC);

/*!
 ******************************************************************************
 ** \brief  Enable output convert ADC start signal when 0-detected INT comes.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  Origin the clock signal origin
 ** \arg    InterClk,ExterClk
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtSetTrigADCFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
				  volatile uint8_t WhichADC, volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Read FRTx count peak value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TCCP value
 **
 *****************************************************************************
*/
uint16_t MFT_FrtTCCPRead(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Write FRTx count peak value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  val
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtTCCPWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
					  volatile uint16_t val);

/*!
 ******************************************************************************
 ** \brief  Reads FRT’s current count value
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return TCDT value
 **
 *****************************************************************************
*/
uint16_t MFT_FrtTCDTRead(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Clean FRT’s current count value(set current count value as 0)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_FrtClrTCDT(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Start FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_FrtStart(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Stop FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_FrtStop(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh);

/*!
 ******************************************************************************
 ** \brief  Set count cycle for FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 ** \param  ms count cycle(ms)
 **
 ** \return none
 **
 *****************************************************************************
*/
void MFT_FrtSetCntCycle(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						volatile float ms);

/*!
 ******************************************************************************
 ** \brief FRT interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_Frt_IRQHandler(void);

#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
