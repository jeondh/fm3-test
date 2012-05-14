/*!
 ******************************************************************************
 **
 ** \file adc12_fm3.h
 **
 ** \brief adc drivers head file
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-29   
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

#ifndef _adc12_fm3_H_
#define _adc12_fm3_H_
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"
/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief define adc unit number
 ******************************************************************************
 */
typedef enum
{
    ADC_UNIT0 = 0,//!< ADC unit 0
    ADC_UNIT1 = 1,//!< ADC unit 1
    ADC_UNIT2 = 2,//!< ADC unit 2
}ADC12_UnitT;
/*!
 ******************************************************************************
 ** \brief  Check parameter Unit
 ******************************************************************************
 */

#define IS_ADC_UNIT_VALID(Unit) ((Unit == ADC_UNIT0)\
                                ||(Unit == ADC_UNIT1)\
                                ||(Unit == ADC_UNIT2))
/*!
 ******************************************************************************
 ** \brief define adc sampling time n 
 ******************************************************************************
 */
typedef enum
{
    ADC12_SAMPLE_TIME_N1 = 0<<5, //!< ADC sampling time 1 N
    ADC12_SAMPLE_TIME_N4 = 1<<5, //!< ADC sampling time 4 N
    ADC12_SAMPLE_TIME_N8 = 2<<5, //!< ADC sampling time 8 N
    ADC12_SAMPLE_TIME_N16 = 3<<5, //!< ADC sampling time 16 N
    ADC12_SAMPLE_TIME_N32 = 4<<5, //!< ADC sampling time 32 N
    ADC12_SAMPLE_TIME_N64 = 5<<5, //!< ADC sampling time 64 N
    ADC12_SAMPLE_TIME_N128 = 6<<5, //!< ADC sampling time 128 N
    ADC12_SAMPLE_TIME_N256 = 7<<5, //!< ADC sampling time 256 N
}ADC12_SamplingTimeNT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Unit
 ******************************************************************************
 */

#define IS_ADC_SAMPEL_TIME_VALID(SampleTime) ((SampleTime == ADC12_SAMPLE_TIME_N1)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N1)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N4)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N8)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N16)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N32)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N64)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N128)\
                                            ||(SampleTime == ADC12_SAMPLE_TIME_N256))
/*!
 ******************************************************************************
 ** \brief define adc channels 
 ******************************************************************************
 */
typedef enum
{
    ADC12_CH0=0,//!< ADC channel 0
    ADC12_CH1=1,//!< ADC channel 1
    ADC12_CH2=2,//!< ADC channel 2
    ADC12_CH3=3,//!< ADC channel 3
    ADC12_CH4=4,//!< ADC channel 4
    ADC12_CH5=5,//!< ADC channel 5
    ADC12_CH6=6,//!< ADC channel 6
    ADC12_CH7=7,//!< ADC channel 7
    ADC12_CH8=8,//!< ADC channel 8
    ADC12_CH9=9,//!< ADC channel 9
    ADC12_CH10=10,//!< ADC channel 10
    ADC12_CH11=11,//!< ADC channel 11
    ADC12_CH12=12,//!< ADC channel 12
    ADC12_CH13=13,//!< ADC channel 13
    ADC12_CH14=14,//!< ADC channel 14
    ADC12_CH15=15,//!< ADC channel 15
    ADC12_CH16=16,//!< ADC channel 16
    ADC12_CH17=17,//!< ADC channel 17
    ADC12_CH18=18,//!< ADC channel 18
    ADC12_CH19=19,//!< ADC channel 19
    ADC12_CH20=20,//!< ADC channel 20
    ADC12_CH21=21,//!< ADC channel 21
    ADC12_CH22=22,//!< ADC channel 22
    ADC12_CH23=23,//!< ADC channel 23
    ADC12_CH24=24,//!< ADC channel 24
    ADC12_CH25=25,//!< ADC channel 25
    ADC12_CH26=26,//!< ADC channel 26
    ADC12_CH27=27,//!< ADC channel 27
    ADC12_CH28=28,//!< ADC channel 28
    ADC12_CH29=29,//!< ADC channel 29
    ADC12_CH30=30,//!< ADC channel 30
    ADC12_CH31=31,//!< ADC channel 31
}ADC12_CHNUMT;


/*!
 ******************************************************************************
 ** \brief define adc channels 
 ******************************************************************************
 */
typedef enum
{
    AN00 = 1,  //!< ADC channel 0
    AN01 = 1<<1, //!< ADC channel 1
    AN02 = 1<<2, //!< ADC channel 2
    AN03 = 1<<3,  //!< ADC channel 3
    AN04 = 1<<4, //!< ADC channel 4
    AN05 = 1<<5, //!< ADC channel 5
    AN06 = 1<<6, //!< ADC channel 6
    AN07 = 1<<7, //!< ADC channel 7
    AN08 = 1<<8,  //!< ADC channel 8
    AN09 = 1<<9, //!< ADC channel 9
    AN10 = 1<<10, //!< ADC channel 10
    AN11 = 1<<11, //!< ADC channel 11
    AN12 = 1<<12, //!< ADC channel 12
    AN13 = 1<<13,  //!< ADC channel 13
    AN14 = 1<<14, //!< ADC channel 14
    AN15 = 1<<15,//!< ADC channel 15 
    AN16 = 1<<16,  //!< ADC channel 16
    AN17 = 1<<17, //!< ADC channel 17
    AN18 = 1<<18, //!< ADC channel 18
    AN19 = 1<<19,  //!< ADC channel 19
    AN20 = 1<<20, //!< ADC channel 20
    AN21 = 1<<21, //!< ADC channel 21
    AN22 = 1<<22, //!< ADC channel 22
    AN23 = 1<<23, //!< ADC channel 23
    AN24 = 1<<24, //!< ADC channel 24 
    AN25 = 1<<25, //!< ADC channel 25
    AN26 = 1<<26, //!< ADC channel 26
    AN27 = 1<<27, //!< ADC channel 27
    AN28 = 1<<28, //!< ADC channel 28
    AN29 = 1<<29, //!< ADC channel 29 
    AN30 = 1<<30, //!< ADC channel 30
    AN31 = 1<<31, //!< ADC channel 31
}ADC12_ChT;
/*!
 ******************************************************************************
 ** \brief  Check parameter Channel
 ******************************************************************************
 */

#define IS_ADC_CH_VALID(CH) ((CH == AN00)||(CH == AN01)||(CH == AN02)||(CH == AN03)\
                            ||(CH == AN04)||(CH == AN05)||(CH == AN06)||(CH == AN07)\
                            ||(CH == AN08)||(CH == AN09)||(CH == AN10)||(CH == AN11)\
                            |(CH == AN12)||(CH == AN13)||(CH == AN14)||(CH == AN15))
                                                        

/*!
 ******************************************************************************
 ** \brief define adc sampling time step region
 ******************************************************************************
 */
typedef enum
{
    ADC12_SAMPLE_TIME_STEP_REG0 = 0,  //!< ADC sampling time step region 0
    ADC12_SAMPLE_TIME_STEP_REG1 = 1,  //!< ADC sampling time step region 1
}ADC12_SampleTimeStepRegT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Step Register
 ******************************************************************************
 */

#define IS_ADC_SAMPEL_TIME_STEP_VALID(Step) ((Step == ADC12_SAMPLE_TIME_STEP_REG0)\
                                            ||(Step == ADC12_SAMPLE_TIME_STEP_REG0))

/*!
 ******************************************************************************
 ** \brief define adc sampling time select region
 ******************************************************************************
 */
typedef enum
{
    ADC12_SAMPLE_TIME_SEL_REG0 = 0,  //!< ADC sampling time select region 0
    ADC12_SAMPLE_TIME_SEL_REG1 = 1,  //!< ADC sampling time select region 1
}ADC12_SampleTimeSelRegT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Select Register
 ******************************************************************************
 */

#define IS_ADC_SAMPEL_TIME_SEL_VALID(Select) ((Select == ADC12_SAMPLE_TIME_SEL_REG0)\
                                            ||(Select == ADC12_SAMPLE_TIME_SEL_REG1))
/*!
 ******************************************************************************
 ** \brief define adc compare time division ratio
 ******************************************************************************
 */
typedef enum
{
    ADC12_CMP_TIME_DIV2 = 0, //!< ADC compare time division ratio 2
    ADC12_CMP_TIME_DIV3 = 1, //!< ADC compare time division ratio 3
    ADC12_CMP_TIME_DIV4 = 2, //!< ADC compare time division ratio 4
    ADC12_CMP_TIME_DIV5 = 3, //!< ADC compare time division ratio 5
    ADC12_CMP_TIME_DIV6 = 4, //!< ADC compare time division ratio 6
    ADC12_CMP_TIME_DIV7 = 5, //!< ADC compare time division ratio 7
    ADC12_CMP_TIME_DIV8 = 6, //!< ADC compare time division ratio 8
    ADC12_CMP_TIME_DIV9 = 7, //!< ADC compare time division ratio 9
}ADC12_CmpTimeDivT;

/*!
 ******************************************************************************
 ** \brief  Check parameter compare time division ratio
 ******************************************************************************
 */

#define IS_ADC_CMP_TIME_VALID(CmpTime) ((CmpTime == ADC12_CMP_TIME_DIV2)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV3)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV4)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV5)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV6)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV7)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV8)\
                                        ||(CmpTime <= ADC12_CMP_TIME_DIV9))

/*!
 ******************************************************************************
 ** \brief define adc scan conversion timer trigger selection
 ******************************************************************************
 */
typedef enum
{ 
    ADC12_TIMER_TRIGGER_NONE = 0,  	//!<No selected trigger (Input is fixed to "0".)
    ADC12_SCAN_TRIGGER_MFT = 1, 	//!<Starts scan conversion with the multifunction timer.
    ADC12_SCAN_TRIGGER_BT0 = 2, 	//!<Base timer ch.0
    ADC12_SCAN_TRIGGER_BT1 = 3, 	//!<Base timer ch.1
    ADC12_SCAN_TRIGGER_BT2 = 4, 	//!<Base timer ch.2
    ADC12_SCAN_TRIGGER_BT3 = 5, 	//!<Base timer ch.3
    ADC12_SCAN_TRIGGER_BT4 = 6, 	//!<Base timer ch.4
    ADC12_SCAN_TRIGGER_BT5 = 7, 	//!<Base timer ch.5
    ADC12_SCAN_TRIGGER_BT6 = 8, 	//!<Base timer ch.6
    ADC12_SCAN_TRIGGER_BT7 = 9, 	//!<Base timer ch.7
}ADC12_StartTimerTrigModeT;

/*!
 ******************************************************************************
 ** \brief  Check parameter conversion timer trigger selection
 ******************************************************************************
 */

#define IS_ADC_TRIGGER_MODE_VALID(Trigger) ((Trigger == ADC12_TIMER_TRIGGER_NONE)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_MFT)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT0)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT1)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT2)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT3)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT4)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT5)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT6)\
                                            ||(Trigger == ADC12_SCAN_TRIGGER_BT7))
/*!
 ******************************************************************************
 ** \brief define adc scan mode choose:single or repeat
 ******************************************************************************
 */
typedef enum
{
    ADC12_SCAN_MODE_SINGLE = 0,  //!< ADC conversion single mode
    ADC12_SCAN_MODE_CONTINUE = 1, //!< ADC conversion repeat mode
}ADC12_ScanModeT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Scan Mode
 ******************************************************************************
 */

#define IS_ADC_SCAN_MODE_VALID(ScanMode) ((ScanMode == ADC12_SCAN_MODE_SINGLE)\
                                        ||(ScanMode == ADC12_SCAN_MODE_CONTINUE))
/*!
 ******************************************************************************
 ** \brief define adc scan FIFO status
 ******************************************************************************
 */
typedef enum
{
    ADC12_SCAN_FIFO_EMPTY= 0x10000000,  		//!<Scan conversion FIFO empty bit
    ADC12_SCAN_FIF0_FULL = 0x01000000,		//!<Scan conversion FIFO full bit
    ADC12_SCAN_FIFO_OVERRUN = 0x00100000,	//!<Scan conversion overrun flag 
}ADC12_FIFOStatusT;



/*!
 ******************************************************************************
 ** \brief define adc conversion status
 ******************************************************************************
 */
typedef enum
{
    ADC12_SCAN_FINISH = 0x01,	//!<Scan conversion status flag
    ADC12_PRIORITY_FINISH = 0x02,//!<Priority conversion status flag
    ADC12_PRIORITY_PENDING = 0x04,//!<Priority conversion pending flag
    ADC12_CMP_COV_FLAG = 0x20,	//!<Conversion result comparison interrupt request bit
    ADC12_PRIORITY_COV_FLAG = 0x40,//!<Priority conversion interrupt request bit
    ADC12_SCAN_COV_FLAG = 0x80,	//!<Scan conversion interrupt request bit
}ADC12_ConversionStatusT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Conversion Status
 ******************************************************************************
 */

#define IS_ADC_COV_STATUS_VALID(CovSts) ((CovSts == ADC12_SCAN_FINISH)\
                                        ||(CovSts == ADC12_PRIORITY_FINISH)\
                                        ||(CovSts == ADC12_PRIORITY_PENDING)\
                                        ||(CovSts == ADC12_CMP_COV_FLAG)\
                                        ||(CovSts == ADC12_PRIORITY_COV_FLAG)\
                                        ||(CovSts == ADC12_SCAN_COV_FLAG))
/*!
 ******************************************************************************
 ** \brief define adc option mode
 ******************************************************************************
 */
typedef enum
{
    ADC12_OPTION_MODE = 0x01,   //!< ADC conversion ensable
    ADC12_STOP_MODE=0xfe,        //!< ADC conversion disable
}ADC12_OptionModeT;


/*!
 ******************************************************************************
 ** \brief define adc option enable or disable
 ******************************************************************************
 */
typedef enum 
{
    ADC12_DISABLE = 0, //!< ADC conversion disable
    ADC12_ENABLE = 1, //!< ADC conversion ensable
} ADC12_OptionT;
/*!
 ******************************************************************************
 ** \brief  Check parameter Option Mode
 ******************************************************************************
 */

#define IS_ADC_OPTION_MODE_VALID(Option) ((Option == ADC12_DISABLE)\
                                        ||(Option == ADC12_ENABLE))
/*!
 ******************************************************************************
 ** \brief define adc comparison enable or disable
 ******************************************************************************
 */
typedef enum 
{
    ADC12_CMP_DISABLE = 0, //!< ADC comparison disable
    ADC12_CMP_ENABLE = 1, //!< ADC comparison enable
} ADC12_CmpOptionT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Comparison Mode 
 ******************************************************************************
 */

#define IS_ADC_CMP_MODE_VALID(CmpMode) ((CmpMode == ADC12_CMP_DISABLE)\
                                        ||(CmpMode == ADC12_CMP_ENABLE))
/*!
 ******************************************************************************
 ** \brief define adc irq mode
 ******************************************************************************
 */
typedef enum
{
    ADC12_SCAN_CONVERSION = 0x08,	 //!<Scan conversion interrupt enable bit
    ADC12_PRIORITY_CONVERSION = 0x04,//!<Priority conversion interrupt enable bit
    ADC12_CMP_CONVERSION = 0x02,	//!<Conversion result comparison interrupt enable bit
    ADC12_FIFO_OVERRUN = 0x01,		//!<FIFO overrun interrupt enable bit
}ADC12_IrqT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Irq Mode 
 ******************************************************************************
 */

#define IS_ADC_IRQ_MODE_VALID(Irq) ((Irq == ADC12_SCAN_CONVERSION)\
                                    ||(Irq == ADC12_PRIORITY_CONVERSION)\
                                    ||(Irq == ADC12_CMP_CONVERSION)\
                                    ||(Irq == ADC12_FIFO_OVERRUN))
/*!
 ******************************************************************************
 ** \brief define adc FIFO stage counter
 ******************************************************************************
 */
typedef enum
{
    ADC12_FIFO_STAGE1=0,//!< ADC FIFO stage 1
    ADC12_FIFO_STAGE2=1,//!< ADC FIFO stage 2
    ADC12_FIFO_STAGE3=2,//!< ADC FIFO stage 3
    ADC12_FIFO_STAGE4=3,//!< ADC FIFO stage 4
    ADC12_FIFO_STAGE5=4,//!< ADC FIFO stage 5
    ADC12_FIFO_STAGE6=5,//!< ADC FIFO stage 6
    ADC12_FIFO_STAGE7=6,//!< ADC FIFO stage 7
    ADC12_FIFO_STAGE8=7,//!< ADC FIFO stage 8
    ADC12_FIFO_STAGE9=8,//!< ADC FIFO stage 9
    ADC12_FIFO_STAGE10=9,//!< ADC FIFO stage 10
    ADC12_FIFO_STAGE11=10,//!< ADC FIFO stage 11
    ADC12_FIFO_STAGE12=11,//!< ADC FIFO stage 12
    ADC12_FIFO_STAGE13=12,//!< ADC FIFO stage 13
    ADC12_FIFO_STAGE14=13,//!< ADC FIFO stage 14
    ADC12_FIFO_STAGE15=14,//!< ADC FIFO stage 15
    ADC12_FIFO_STAGE16=15,//!< ADC FIFO stage 16
}ADC12_FIFOStageT;

/*!
 ******************************************************************************
 ** \brief  Check parameter FIFO Stage
 ******************************************************************************
 */

#define IS_ADC_FIFO_STAGE_VALID(FIFOStage) ((FIFOStage == ADC12_FIFO_STAGE1)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE2)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE3)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE4)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE5)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE6)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE7)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE8)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE9)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE10)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE11)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE12)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE13)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE14)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE15)\
                                            ||(FIFOStage == ADC12_FIFO_STAGE16))
/*!
 ******************************************************************************
 ** \brief define adc data placement select
 ******************************************************************************
 */
typedef enum
{
    ADC12_DATA_SIDE_MSB = 0,   //!< ADC data placement from high bit
    ADC12_DATA_SIDE_LSB=1,     //!< ADC data placement from low bit
}ADC12_DataSideT;

/*!
 ******************************************************************************
 ** \brief  Check parameter Placement 
 ******************************************************************************
 */

#define IS_ADC_DATA_SIDE_VALID(DataSide) ((DataSide == ADC12_DATA_SIDE_MSB)\
                                        ||(DataSide == ADC12_DATA_SIDE_LSB))
/*!
 ******************************************************************************
 ** \brief define adc mode
 ******************************************************************************
 */
typedef enum
{
    ADC12_SCAN = 0,     //!< ADC scan mode
    ADC12_PRIORITY = 1,//!< ADC priority mode
}ADC12_ModeT;



 /*!
 ******************************************************************************
 ** \brief define Register Bit overrun interrupt enable
 ******************************************************************************
 */
#define ADCR_OVRIE           0x01U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  comparison interrupt enable
 ******************************************************************************
 */
#define ADCR_CMPIE           0x02U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority interrupt enable
 ******************************************************************************
 */
#define ADCR_PCIE            0x04U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan interrupt enable
 ******************************************************************************
 */
#define ADCR_SCIE            0x08U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  comparison interrupt  requset
 ******************************************************************************
 */
#define ADCR_CMPIF           0x20U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority interrupt  requset
 ******************************************************************************
 */
#define ADCR_PCIF            0x40U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan interrupt  requset
 ******************************************************************************
 */
#define ADCR_SCIF            0x80U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  all interrupt  requset
 ******************************************************************************
 */
#define ADCR_IFALL           (ADCR_CMPIF | ADCR_PCIF | ADCR_SCIF)
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion status
 ******************************************************************************
 */
#define ADSR_SCS             0x01U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion status
 ******************************************************************************
 */
#define ADSR_PCS             0x02U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion pending status
 ******************************************************************************
 */
#define ADSR_PCNS            0x04U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  FIFO data placement selection
 ******************************************************************************
 */
#define ADSR_FDAS            0x40U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  conversion forced stop
 ******************************************************************************
 */
#define ADSR_ADSTP           0x80U

 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion start
 ******************************************************************************
 */
#define SCCR_SSTR            0x01U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion timer start
 ******************************************************************************
 */
#define SCCR_SHEN            0x02U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion repeat
 ******************************************************************************
 */
#define SCCR_RPT             0x04U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion FIFO clear
 ******************************************************************************
 */
#define SCCR_SFCLR           0x10U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion overrun
 ******************************************************************************
 */
#define SCCR_SOVR            0x20U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion FIFO full
 ******************************************************************************
 */
#define SCCR_SFUL            0x40U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion FIFO empty
 ******************************************************************************
 */
#define SCCR_SEMP            0x80U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  scan conversion data valid
 ******************************************************************************
 */
#define SCFDL_INVL           0x1000U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion start
 ******************************************************************************
 */
#define PCCR_PSTR            0x01U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion timer start
 ******************************************************************************
 */
#define PCCR_PHEN            0x02U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion pending
 ******************************************************************************
 */
#define PCCR_PEEN            0x04U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority external trigger select
 ******************************************************************************
 */
#define PCCR_ESCE            0x08U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion FIFO clear
 ******************************************************************************
 */
#define PCCR_PFCLR           0x10U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion overrun
 ******************************************************************************
 */
#define PCCR_POVR            0x20U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion FIFO full
 ******************************************************************************
 */
#define PCCR_PFUL            0x40U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion FIFO empty
 ******************************************************************************
 */
#define PCCR_PEMP            0x80U
 /*!
 ******************************************************************************
 ** \brief define Register Bit  priority conversion data valid
 ******************************************************************************
 */
#define PCFDL_INVL           0x1000U
/*
#define CMPCR_CMD0           0x20U
#define CMPCR_CMD1           0x40U
#define CMPCR_CMPEN          0x80U*/
 /*!
 ******************************************************************************
 ** \brief define scan interrupt cause 
 ******************************************************************************
 */
#define Adc12_IRQSTATUS_SCAN     0x01U
 /*!
 ******************************************************************************
 ** \brief define priority interrupt cause 
 ******************************************************************************
 */
#define Adc12_IRQSTATUS_PRI      0x02U
 /*!
 ******************************************************************************
 ** \brief define comparison interrupt cause 
 ******************************************************************************
 */
#define Adc12_IRQSTATUS_COMP     0x04U
 /*!
 ******************************************************************************
 ** \brief define scan overrun interrupt cause 
 ******************************************************************************
 */
#define Adc12_IRQSTATUS_SOVR     0x08U
 /*!
 ******************************************************************************
 ** \brief define priority overrun interrupt cause 
 ******************************************************************************
 */
#define Adc12_IRQSTATUS_POVR     0x10U
/*!
 ******************************************************************************
 ** \brief structure for comparsion mode
 ******************************************************************************
 */
typedef struct 
{
    ADC12_CmpOptionT  ADC12_Cmpen; //!< comparsion mode enable or not
    ADC12_CmpOptionT ADC12_Cmd1;   //!< comparsion mode cmd 1 for setting condition
    ADC12_CmpOptionT ADC12_Cmd0;  //!< comparsion mode cmd 0 for setting channel
    uint16_t ADC12_CmpVal;        //!< comparsion value setup
}ADC12_ComparisonT;

/*!
 ******************************************************************************
 ** \brief structure for sampling time N times setting
 ******************************************************************************
 */
typedef struct
{

    ADC12_SamplingTimeNT ADC12_SampleTimeN0;//!< sampling time N times region 0
    ADC12_SamplingTimeNT ADC12_SampleTimeN1; //!< sampling time N times region 1

}ADC12_SampleTimeNT;

/*!
 ******************************************************************************
 ** \brief structure for sampling time setting
 ******************************************************************************
 */
typedef struct
{

    uint16_t ADC12_SampleTime0;//!< sampling time setting region 0
    uint16_t ADC12_SampleTime1; //!< sampling time setting region 1

}ADC12_SampleTimeT;

/*!
 ******************************************************************************
 ** \brief ADC interrupt callback function.
 **
 ** \param Status ADC interrupt cause 
 **
 ******************************************************************************
 */
typedef void  (*ADC12_CallBackIrqT)(int32_t Status);

/*!
 ******************************************************************************
 ** \brief structure for ADC configuration
 ******************************************************************************
 */
typedef struct
{
    ADC12_ChT          ADC12_Ch; //!< ADC channel
    ADC12_ModeT        ADC12_Mode;//!< ADC mode
    ADC12_CmpTimeDivT  ADC12_CmpDiv;//!< ADC compare divsion ratio
    ADC12_ScanModeT    ADC12_ScanMode;//!< ADC scan single or repeat
    ADC12_OptionT      ADC12_Option;//!< ADC enable or not
    ADC12_FIFOStageT   ADC12_FIFOStage;//!< ADC Fifo stage counter
    ADC12_DataSideT    ADC12_DataSide;//!< ADC data placement 
    ADC12_SampleTimeNT ADC12_SampleTimeN;//!< ADC sampling time N times setting
    ADC12_SampleTimeT  ADC12_SampleTime;//!< ADC sampling time setting
    ADC12_ComparisonT  ADC12_CmpOption;//!< ADC comparison option
    ADC12_SampleTimeSelRegT ADC12_SampleTimeSelReg;//!< ADC sampling time select region
    ADC12_StartTimerTrigModeT ADC12_StartTimerTrigMode;//!< ADC Timer trigger moDE
    ADC12_CallBackIrqT  ADC12_ConfigIrqCallback;//!< ADC callback function
}ADC12_Config;





/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
void ADC12_AdcInit(ADC12_UnitT ADC12_Unit, ADC12_Config *ADC12_InitT);
void ADC12_ChannelSelect(ADC12_UnitT ADC12_Unit,ADC12_Config *ADC12_InitT);
void ADC12_ClrScanFIFO(ADC12_UnitT ADC12_Unit);
void ADC12_IrqEnable(ADC12_UnitT ADC12_Unit, ADC12_IrqT ADC12_Irq);
void ADC12_IrqDisable(ADC12_UnitT ADC12_Unit, ADC12_IrqT ADC12_Irq);
void ADC12_Abort(ADC12_UnitT ADC12_Unit);
void ADC12_Stop(ADC12_UnitT ADC12_Unit);
void ADC12_ScanStart(ADC12_UnitT ADC12_Unit);
void ADC12_ScanTimerEnable(ADC12_UnitT ADC12_Unit);
void ADC12_ScanTimerDisable(ADC12_UnitT ADC12_Unit);
void ADC12_ScanOverrunFlagClr(ADC12_UnitT ADC12_Unit);
void ADC12_ScanIntReqClr(ADC12_UnitT ADC12_Unit);
void ADC12_CmpIntReqClr(ADC12_UnitT ADC12_Unit);
void ADC12_PriorityIntReqClr(ADC12_UnitT ADC12_Unit);
FlagStatusT ADC12_ScanFifoFullFlag(ADC12_UnitT ADC12_Unit);
FlagStatusT ADC12_ScanOverrunFlag(ADC12_UnitT ADC12_Unit);
FlagStatusT ADC12_ScanEmptyFlag(ADC12_UnitT ADC12_Unit);
FlagStatusT  ADC12_ConversionStatus(ADC12_UnitT ADC12_Unit, 
                                    ADC12_ConversionStatusT ADC12_ConversionStatus);
FlagStatusT  ADC12_ReadOptionStatus(ADC12_UnitT ADC12_Unit);
FlagStatusT ADC12_Read(ADC12_UnitT ADC12_Unit, uint16_t *ADC12_Info, 
                        uint16_t *ADC12_Data, uint16_t *ADC12_Stage);

#ifdef __cplusplus
}
#endif


#endif /* _Adc12_fm3_H_ */
