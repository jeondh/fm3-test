/*!
 ******************************************************************************
 **
 ** \file driver\mft\mft_adcmp_fm3.h
 **
 ** \brief  ADC Start Compare Unit drivers head file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.2.0
 **
 ** \date 2012-1-10 13:50
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef DRV_MFT_ADCMP_H
#define DRV_MFT_ADCMP_H

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

/* ADC compare channel */
/*! \brief ADCMP CH0 */
#define ADCMP_CH0 0
/*! \brief ADCMP CH1 */
#define ADCMP_CH1 1
/*! \brief ADCMP CH2 */
#define ADCMP_CH2 2
/*! \brief ADCMP Channel none */
#define ADCMP_NONE -1

/* ADC start mode */
/*! \brief ADC start when FRT in Up-count/Peak/Down-count state and it matches
 *   the setting value of ACCP mode */
#define ACCP_UPPEAKDOWN          0
/*! \brief ADC start when FRT in Up-countstate and it matches
 *   the setting value of ACCP mode */
#define ACCP_UP                  1
/*! \brief ADC start when FRT in Peak/Down-count state and it matches
 *   the setting value of ACCP mode */
#define ACCP_PEAKDOWN            2
/*! \brief ADC start when FRT in Up-count state and it matches the setting value of ACCP mode
 *  or when FRT in Peak/Down-count state and it matches the setting value of ACCPDN mode */
#define ACCP_UP_ACCPDN_PEAKDOWN  3

/* When send buffer to ACCP or ACCPDN */
/*! \brief send buffer to ACCP or ACCPDN at FRT count zero */
#define ADCMP_ZERO     0
/*! \brief send buffer to ACCP or ACCPDN at FRT count peak */
#define ADCMP_PEAK    1

/* ADC trigger origin */
/*! \brief ADCMP trigger ADC */
#define TRI_ADCMP   0
/*! \brief FRT trigger ADC */
#define TRI_FRT     1

/* Bit definition */
/*! \brief CE0 bit set */
#define  ADCMP_ACSA_CE0           ((uint16_t)0xFFFC)
/*! \brief CE1 bit set */
#define  ADCMP_ACSA_CE1           ((uint16_t)0xFFF3)
/*! \brief CE2 bit set */
#define  ADCMP_ACSA_CE2           ((uint16_t)0xFFCF)
/*! \brief SEL0 bit set */
#define  ADCMP_ACSA_SEL0          ((uint16_t)0xFCFF)
/*! \brief SEL1 bit set */
#define  ADCMP_ACSA_SEL1          ((uint16_t)0xF3FF)
/*! \brief SEL2 bit set */
#define  ADCMP_ACSA_SEL2          ((uint16_t)0xCFFF)

/*! \brief BDIS0 bit set */
#define  ADCMP_ACSB_BDIS0         ((uint8_t)0xFE)
/*! \brief BDIS1 bit set */
#define  ADCMP_ACSB_BDIS1         ((uint8_t)0xFD)
/*! \brief BDIS2 bit set */
#define  ADCMP_ACSB_BDIS2         ((uint8_t)0xFB)
/*! \brief BTS0 bit set */
#define  ADCMP_ACSB_BTS0          ((uint8_t)0xEF)
/*! \brief BTS1 bit set */
#define  ADCMP_ACSB_BTS1          ((uint8_t)0xDF)
/*! \brief BTS2 bit set */
#define  ADCMP_ACSB_BTS2          ((uint8_t)0xBF)

/*! \brief AD0S bit set */
#define  ADCMP_ATSA_AD0S          ((uint16_t)0xFFFC)
/*! \brief AD1S bit set */
#define  ADCMP_ATSA_AD1S          ((uint16_t)0xFFF3)
/*! \brief AD2S bit set */
#define  ADCMP_ATSA_AD2S          ((uint16_t)0xFFCF)
/*! \brief AD0P bit set */
#define  ADCMP_ATSA_AD0P          ((uint16_t)0xFCFF)
/*! \brief AD1P bit set */
#define  ADCMP_ATSA_AD1P          ((uint16_t)0xF3FF)
/*! \brief AD2P bit set */
#define  ADCMP_ATSA_AD2P          ((uint16_t)0xCFFF)


/*---------------------------------------------------------------------------*/
/* declare functions                                                         */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  Read register value that ADC channel connect to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return Which FRT channel to configure
 ** \retval  FTR_CH0, FTR_CH1, FTR_CH2
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetFRTCh(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Set ADCMP channel connects to which FRT channel
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  WhichFRTCh  Which FRT channel to configure
 ** \arg 	FRT_CH0,FRT_CH1,FRT_CH2
 **
 ** \return none
 **
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetFRTCh(volatile uint8_t WhichMFT, volatile uint8_t WhichFRTCh,
						   	   volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Read which count state FRT should be in to instruct AD conversion
 **  		to be started at each channel of ADCMP
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return Mode
 ** \retval ACCP_UPPEAKDOWN,ACCP_UP,ACCP_PEAKDOWN,ACCP_UP_ACCPDN_PEAKDOWN
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetStartMode(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Set which count state FRT should be in to instruct AD conversion
 **  		to be started at each channel of ADCMP
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  Mode
 ** \arg    ACCP_UPPEAKDOWN,ACCP_UP,ACCP_PEAKDOWN,ACCP_UP_ACCPDN_PEAKDOWN
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetStartMode(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
						   volatile uint8_t Mode);

/*!
 ******************************************************************************
 ** \brief  Read state of the buffer function of the ACCP0 and ACCPDN0 registers
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return En enable or not
 ** \retval TRUE, FALSE
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetACCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Read state of the buffer function of the ACCP0 and ACCPDN0 registers
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  En
 ** \arg    TRUE, FALSE
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetACCPBufFnct(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
							 volatile uint8_t En);

/*!
 ******************************************************************************
 ** \brief  Read the timing  of transferring data from the buffer register to
 **         the ACCP0 and ACCPDN0 registers when the buffer function is enabled
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \return When
 ** \retval ADCMP_ZERO, ADCMP_PEAK
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Set the timing  of transferring data from the buffer register to
 **         the ACCP0 and ACCPDN0 registers when the buffer function is enabled
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  When
 ** \arg    ADCMP_ZERO, ADCMP_PEAK
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetTimeSendBuff(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
							  volatile uint8_t When);

/*!
 ******************************************************************************
 ** \brief  Read the timing of starting AD conversion(ACCP)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \retval ACCPValue
 *****************************************************************************
*/
uint16_t MFT_AdcmpAccpRead(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Configure the timing of starting AD conversion(ACCP)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \retval none
 *****************************************************************************
*/
uint8_t MFT_AdcmpAccpWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
						volatile uint16_t value);

/*!
 ******************************************************************************
 ** \brief  Read the timing of starting AD conversion(ACCPDN)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 **
 ** \retval ACCPValue
 *****************************************************************************
*/
uint16_t MFT_AdcmpAccpdnRead(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Configure the timing of starting AD conversion(ACCPDN)
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \retval none
 *****************************************************************************
*/
uint8_t MFT_AdcmpAccpdnWrite(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
						  volatile uint16_t value);

/*!
 ******************************************************************************
 ** \brief  Get the start signal to be used to start the scan conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \return Origin
 ** \retval TRI_ADCMP,TRI_FRT
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetTriggerOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Set the start signal to be used to start the scan conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 ** \param  Origin
 ** \arg    TRI_ADCMP,TRI_FRT
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetTriggerOrigin(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
							   volatile uint8_t Origin);

/*!
 ******************************************************************************
 ** \brief  Get the start signal to be used to start priority conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 **
 ** \return Origin
 ** \retval TRI_ADCMP,TRI_FRT
 *****************************************************************************
*/
uint8_t MFT_AdcmpGetPriority(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP);

/*!
 ******************************************************************************
 ** \brief  Set the start signal to be used to start priority conversion of ADC
 **
 ** \param  WhichMFT Which MFT will be configured
 ** \arg 	MFT0,MFT1
 ** \param  WhichADCMP  Which ADCMP channel to be configured
 ** \arg 	ADCMP_CH0, ADCMP_CH1, ADCMP_CH2
 ** \param  ACCP Value
 ** \param  Origin
 ** \arg    TRI_ADCMP,TRI_FRT
 **
 ** \return none
 *****************************************************************************
*/
uint8_t MFT_AdcmpSetPriority(volatile uint8_t WhichMFT, volatile uint8_t WhichADCMP,
						  volatile uint8_t Type);

#endif /* DRV_MFT_FRT_H */

/*****************************************************************************/
/* END OF FILE */
