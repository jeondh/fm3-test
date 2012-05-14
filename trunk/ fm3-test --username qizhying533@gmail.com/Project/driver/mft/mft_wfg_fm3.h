/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_wfg_fm3.h
 **
 ** \brief Waveform Generator Unit drivers head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-12 14:15
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef DRV_MFT_WFG_H
#define DRV_MFT_WFG_H

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

/* WFG channel amount */
/*! \brief WFG channel amount */
#define MFT_WFG_CH_GROUP_AMOUNT 3

/* WFG channel pairs */
/*! \brief WFG CH10 */
#define WFG_CH10 0
/*! \brief WFG CH32 */
#define WFG_CH32 1
/*! \brief WFG CH54 */
#define WFG_CH54 2
/*! \brief WFG Channel none */
#define WFG_NONE -1

/* FRT channel */
/*! \brief FRT CH0 */
#define FRT_CH0 0
/*! \brief FRT CH1 */
#define FRT_CH1 1
/*! \brief FRT CH2 */
#define FRT_CH2 2
/*! \brief FRT Channel none */
#define FRT_NONE -1

/* WFG Division value */
/*! \brief WFG Division 0 */
#define WFG_DIV0 0
/*! \brief WFG Division 1 */
#define WFG_DIV1 1
/*! \brief WFG Division 2 */
#define WFG_DIV2 2
/*! \brief WFG Division 3 */
#define WFG_DIV3 3
/*! \brief WFG Division 4 */
#define WFG_DIV4 4
/*! \brief WFG Division 5 */
#define WFG_DIV5 5
/*! \brief WFG Division 6 */
#define WFG_DIV6 6

/* WFG Work mode */
/*! \brief WFG through work mode */
#define MODE_THROUGH 0
/*! \brief WFG RT-PPG work mode */
#define MODE_RT_PPG 1
/*! \brief WFG time-PPG work mode */
#define MODE_TIME_PPG 2
/*! \brief WFG RT-Dead-timer work mode */
#define MODE_RT_DEAD_TIMER 4
/*! \brief WFG PPG-Dead-timer work mode */
#define MODE_PPG_DEAD_TIMER 7

/* PPG timer unit */
/*! \brief PPG timer unit0 */
 #define PPG_TMR0 0
/*! \brief PPG timer unit1 */
 #define PPG_TMR2 1
/*! \brief PPG timer unit2 */
 #define PPG_TMR4 2
/*! \brief PPG timer disable */
 #define PPG_DIS  3

/* WFG output polarity */
/*! \brief WFG output low level */
#define LEVEL_LOW  0
/*! \brief WFG output high level */
#define LEVEL_HIGH 1

/* WFG timer currently state */
/*! \brief WFG timer stop */
#define WFG_STOP 0
/*! \brief WFG timer operating */
#define WFG_OPER 1

/* Noise-bear time for DTTI */
/*! \brief DTTI Noise-bear width 0 PCLK cycles */
#define DTTI_NOISE_TIME0 0
/*! \brief DTTI Noise-bear width 4 PCLK cycles */
#define DTTI_NOISE_TIME1 1
/*! \brief DTTI Noise-bear width 8 PCLK cycles */
#define DTTI_NOISE_TIME2 2
/*! \brief DTTI Noise-bear width 16 PCLK cycles */
#define DTTI_NOISE_TIME3 3
/*! \brief DTTI Noise-bear width 32 PCLK cycles */
#define DTTI_NOISE_TIME4 4
/*! \brief DTTI Noise-bear width disable */
#define DTTI_NOISE_DIS   5

/* Bit definition */
/*! \brief DCK bit set */
#define  WFG_WFSA_DCK           ((uint16_t)0xFFF8)
/*! \brief TMD bit set */
#define  WFG_WFSA_TMD           ((uint16_t)0xFFC7)
/*! \brief GTEN bit set */
#define  WFG_WFSA_GTEN          ((uint16_t)0xFF3F)
/*! \brief PSEL bit set */
#define  WFG_WFSA_PSEL          ((uint16_t)0xFCFF)
/*! \brief PGEN bit set */
#define  WFG_WFSA_PGEN          ((uint16_t)0xF3FF)
/*! \brief DMOD bit set */
#define  WFG_WFSA_DMOD          ((uint16_t)0xCFFF)

/*! \brief NWS bit set */
#define  WFG_NZCL_DTIE          ((uint16_t)0xFFFE)
/*! \brief NWS bit set */
#define  WFG_NZCL_NWS           ((uint16_t)0xFFF1)
/*! \brief SDTI bit set */
#define  WFG_NZCL_SDTI          ((uint16_t)0xFFEF)

/*! \brief DTIF bit set */
#define  WFG_WFIR_DTIF          ((uint16_t)0xFFFE)
/*! \brief DTIC bit set */
#define  WFG_WFIR_DTIC          ((uint16_t)0xFFFD)
/*! \brief TMIF10 bit set */
#define  WFG_WFIR_TMIF10        ((uint16_t)0xFFEF)
/*! \brief TMIC10 bit set */
#define  WFG_WFIR_TMIC10        ((uint16_t)0xFFDF)
/*! \brief TMIE10 bit set */
#define  WFG_WFIR_TMIE10        ((uint16_t)0xFFBF)
/*! \brief TMIS10 bit set */
#define  WFG_WFIR_TMIS10        ((uint16_t)0xFF7F)
/*! \brief TMIF32 bit set */
#define  WFG_WFIR_TMIF32        ((uint16_t)0xFEFF)
/*! \brief TMIC32 bit set */
#define  WFG_WFIR_TMIC32        ((uint16_t)0xFDFF)
/*! \brief TMIE32 bit set */
#define  WFG_WFIR_TMIE32        ((uint16_t)0xFBFF)
/*! \brief TMIS32 bit set */
#define  WFG_WFIR_TMIS32        ((uint16_t)0xF7FF)
/*! \brief TMIF54 bit set */
#define  WFG_WFIR_TMIF54        ((uint16_t)0xEFFF)
/*! \brief TMIC54 bit set */
#define  WFG_WFIR_TMIC54        ((uint16_t)0xDFFF)
/*! \brief TMIE54 bit set */
#define  WFG_WFIR_TMIE54        ((uint16_t)0xBFFF)
/*! \brief TMIS54 bit set */
#define  WFG_WFIR_TMIS54        ((uint16_t)0x7FFF)

/*! \brief WFG timer 10 interrupt bit set */
#define  WFG_INT_CH10     ((uint16_t)0x01)
/*! \brief WFG timer 32 interrupt bit set */
#define  WFG_INT_CH32     ((uint16_t)0x02)
/*! \brief WFG timer 54 interrupt bit set */
#define  WFG_INT_CH54     ((uint16_t)0x04)

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

/*! \brief Typedef of a Callback function pointer */
typedef void (*WFG_CallbackT) (uint8_t Type);

typedef void (*DTTI_CallbackT) ();

/*---------------------------------------------------------------------------*/
/* External variables                                                        */
/*---------------------------------------------------------------------------*/
extern WFG_CallbackT WFG_IntCallback[];

extern DTTI_CallbackT DTTI_IntCallback[];


/*---------------------------------------------------------------------------*/
/* declare functions                                                         */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Read division value for WFGxx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  Division value
 ** \retval  [WFG_DIV0, WFG_DIV8]
 *****************************************************************************
*/
uint8_t MFT_WfgDivRead(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Write division value for WFGxx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Div Division value
 ** \arg    [WFG_DIV0, WFG_DIV8]
 **
 ** \return  none
 *****************************************************************************
*/
uint8_t MFT_WfgDivWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx,
					           volatile uint8_t Div);

/*!
 ******************************************************************************
 ** \brief  Get work mode for WFGxx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  Mode value
 ** \retval  MODE_THROUGH,MODE_RT_PPG,MODE_TIME_PPG,MODE_RT_DEAD_TIMER,MODE_PPG_DEAD_TIMER
 *****************************************************************************
*/
uint8_t MFT_WfgGetWorkMode(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Set work mode for WFGxx
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Mode value
 ** \arg    MODE_THROUGH,MODE_RT_PPG,MODE_TIME_PPG,MODE_RT_DEAD_TIMER,MODE_PPG_DEAD_TIMER
 **
 ** \return  none
 *****************************************************************************
*/
uint8_t MFT_WfgSetWorkMode(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx, volatile uint8_t Mode);

/*!
 ******************************************************************************
 ** \brief  Check the CH_GATE signal generate or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \retval Gaten value. if value is 0, Does not generate the CH_GATE signal,
 ** 		or not, the signal was be generate
 *****************************************************************************
*/
uint8_t MFT_WfgGetChGateEnFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Check the CH_GATE signal generate or not
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Gaten value
 **
 ** \retval none
 **
 *****************************************************************************
*/
uint8_t MFT_WfgSetChGateEnFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx,
							volatile uint8_t Gaten);

/*!
 ******************************************************************************
 ** \brief  Get the PPG timer unit to be used at each channel of WFG.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  timer value
 ** \retval  PPG_TMR0,PPG_TMR2,PPG_TMR4,PPG_DIS
 *****************************************************************************
*/
uint8_t MFT_WfgGetPPGTimerUnit(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Set the PPG timer unit to be used at each channel of WFG.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  timer value
 ** \arg    PPG_TMR0,PPG_TMR2,PPG_TMR4,PPG_DIS
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetPPGTimerUnit(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx,
							volatile uint8_t timer);

/*!
 ******************************************************************************
 ** \brief  Read the CH_PPG signal that is input to each channel of WFG on WFG output
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return  state value 0 -  Does not reflect; others - reflect,
 ** 					 in combination with WFSA.TMD[2:0]
 *****************************************************************************
*/
uint8_t MFT_WfgGetChGateFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Set the CH_PPG signal that is input to each channel of WFG on WFG output
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  state
 ** \arg    0, others
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetChGateFlag(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx,
						  volatile uint8_t state);

/*!
 ******************************************************************************
 ** \brief  Read non-overlapped output signal polarity for WFGxx.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return polarity  Non-overlapped output signal polarity
 ** \retval    LEVEL_LOW, LEVEL_HIGH
 *****************************************************************************
*/
uint8_t MFT_WfgGetPolarity(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);
/*!
 ******************************************************************************
 ** \brief  Set non-overlapped output signal polarity for WFGxx.
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  polarity  Non-overlapped output signal polarity
 ** \arg    LEVEL_LOW, LEVEL_HIGH
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetPolarity(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx,
						volatile uint8_t Polarity);

/*!
 ******************************************************************************
 ** \brief  Read the initial value of the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \retval Val initial value of the WFG timer
 *****************************************************************************
*/
uint16_t MFT_WfgTimerValueRead(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Configure the initial value of the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  Val initial value of the WFG timer
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgTimerValueWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichWFGxx,
							volatile uint16_t Val);

/*!
 ******************************************************************************
 ** \brief  Read the state of DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return En
 ** \retval TRUE,FALSE
 *****************************************************************************
*/
uint8_t MFT_WfgGetDtifIntFnct(volatile uint8_t WhichMFT);

/*!
 ******************************************************************************
 ** \brief  Set the state of DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  En
 ** \arg    TRUE,FALSE
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetDtifIntFnct(volatile uint8_t WhichMFT,volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Read the state of DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return En
 ** \retval TRUE,FALSE
 *****************************************************************************
*/
uint8_t MFT_WfgGetDtifIntFlag(volatile uint8_t WhichMFT);

/*!
 ******************************************************************************
 ** \brief  Clean the DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgClrDtifIntFlag(volatile uint8_t WhichMFT);

/*!
 ******************************************************************************
 ** \brief  Get the flag of WFG timer interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return En
 ** \retval TRUE,FALSE
 *****************************************************************************
*/
uint8_t MFT_WfgGetTmrIntFlag(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Clear the flag of WFG timer interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgClrTmrIntFlag(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Read the state of WFG(starts or not)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return state
 ** \retval  WFG_STOP, WFG_OPER
 *****************************************************************************
*/
uint8_t MFT_WfgGetTmrState(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx);
/*!
 ******************************************************************************
 ** \brief  Start the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 ** \param  state
 ** \arg    WFG_STOP, WFG_OPER
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetTmrState(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx,
						volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Stop the WFG timer
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichWFGxx  Which WFGxx to configure
 ** \arg 	[WFG_CH10, WFG_CH54]
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgStopTmr(volatile uint8_t WhichMFT,volatile uint8_t WhichWFGxx);

/*!
 ******************************************************************************
 ** \brief  Read the noise-canceling width of the noise-canceler for the DTTIX pin input signal
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return width
 ** \retval [DTTI_NOISE_TIME0, DTTI_NOISE_TIME4]
 *****************************************************************************
*/
uint8_t MFT_WfgGetNoiseCancelWidth(volatile uint8_t WhichMFT);

/*!
 ******************************************************************************
 ** \brief   Sets the noise-canceling width of the noise-canceler for the DTTIX pin input signal
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  width
 ** \arg    [DTTI_NOISE_TIME0, DTTI_NOISE_TIME4]
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetNoiseCancelWidth(volatile uint8_t WhichMFT,volatile uint8_t width);

/*!
 ******************************************************************************
 ** \brief  Forcibly generates DTIF interrupt
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_WfgSetForceDtifIsr(volatile uint8_t WhichMFT);

/*!
 ******************************************************************************
 ** \brief WFG interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_Wfg_IRQHandler(void);

/*!
 ******************************************************************************
 ** \brief DTTI interrupt handler
 **
 ** \param None
 **
 ** \retval None
 **
 ******************************************************************************
 */
void MFT_DTTI_IRQHandler(void);


#endif /* DRV_MFT_WFG_H */

/*****************************************************************************/
/* END OF FILE */
