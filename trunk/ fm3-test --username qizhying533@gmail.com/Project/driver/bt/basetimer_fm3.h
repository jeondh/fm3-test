/*!
 ******************************************************************************
 **
 ** \file basetimer_fm3.h
 **
 ** \brief Base timer module driver
 ** 
 **
 ** \author 
 **
 ** \version V0.01
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
 
#ifndef _BASETIMER_FM3_H_
#define _BASETIMER_FM3_H_

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"
#include <stdint.h>
/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*! \brief Base timer total channel number */
#define BT_CH_NUM                       8

/*! \brief Basetimer channel 0 */
#define BT_CH_0                         0
/*! \brief Basetimer channel 1 */
#define BT_CH_1                         1
/*! \brief Basetimer channel 2 */
#define BT_CH_2                         2
/*! \brief Basetimer channel 3 */
#define BT_CH_3                         3
/*! \brief Basetimer channel 4 */
#define BT_CH_4                         4
/*! \brief Basetimer channel 5 */
#define BT_CH_5                         5
/*! \brief Basetimer channel 6 */
#define BT_CH_6                         6
/*! \brief Basetimer channel 7 */
#define BT_CH_7                         7

/*! \brief Basetimer channel check list */
#define IS_BT_CH(CH) (((CH) == BT_CH_0) || \
                      ((CH) == BT_CH_1) || \
                      ((CH) == BT_CH_2) || \
                      ((CH) == BT_CH_3) || \
                      ((CH) == BT_CH_4) || \
                      ((CH) == BT_CH_5) || \
                      ((CH) == BT_CH_6) || \
                      ((CH) == BT_CH_7))


/* Base timer IO mode selection*/
/*! \brief I/O mode 0 (Standard 16-bit timer mode) */
#define BT_IO_MODE_0                     0
/*! \brief I/O mode 1 (timer full mode) */
#define BT_IO_MODE_1                     1
/*! \brief I/O mode 2 (Shared external trigger mode) */
#define BT_IO_MODE_2                     2
/*! \brief I/O mode 3 (Shared channel signal trigger mode) */
#define BT_IO_MODE_3                     3
/*! \brief I/O mode 4 (Timer start/stop mode) */
#define BT_IO_MODE_4                     4
/*! \brief I/O mode 5 (Software-based simultaneous startup mode) */
#define BT_IO_MODE_5                     5
/*! \brief I/O mode 6 (Software-based startup and timer start/stop mode) */
#define BT_IO_MODE_6                     6
/*! \brief I/O mode 7 (Timer start mode) */
#define BT_IO_MODE_7                     7
/*! \brief I/O mode 8 (Shared channel signal trigger and timer start/stop mode) */
#define BT_IO_MODE_8                     8

/*! \brief Basetimer I/O mode check list */
#define IS_BT_IOMODE(IOMODE) (((IOMODE) == BT_IO_MODE_0) || \
                              ((IOMODE) == BT_IO_MODE_1) || \
                              ((IOMODE) == BT_IO_MODE_2) || \
                              ((IOMODE) == BT_IO_MODE_3) || \
                              ((IOMODE) == BT_IO_MODE_4) || \
                              ((IOMODE) == BT_IO_MODE_5) || \
                              ((IOMODE) == BT_IO_MODE_6) || \
                              ((IOMODE) == BT_IO_MODE_7) || \
                              ((IOMODE) == BT_IO_MODE_8))


/* Base timer function selection */
/*! \brief Base timer reset mode */
#define BT_RST_MODE                     0
/*! \brief Base timer PWM function */
#define BT_PWM_MODE                     1
/*! \brief Base timer PPG function */
#define BT_PPG_MODE                     2
/*! \brief Base timer reload timer function */
#define BT_RT_MODE                      3
/*! \brief Base timer PWC function */
#define BT_PWC_MODE                     4

/* Base timer count clock selection */
/*! \brief PCLK */
#define BT_CLK_DIV_1                    0
/*! \brief PCLK/4 */
#define BT_CLK_DIV_4                    1
/*! \brief PCLK/16 */
#define BT_CLK_DIV_16                   2
/*! \brief PCLK/128 */
#define BT_CLK_DIV_128                  3
/*! \brief PCLK/256 */
#define BT_CLK_DIV_256                  4
/*! \brief External clock (rising edge event) */
#define BT_CLK_RIS_EDGE                 5
/*! \brief External clock (falling edge event) */
#define BT_CLK_FALL_EDGE                6
/*! \brief External clock (both edge event) */
#define BT_CLK_BOTH_EDGE                7
/*! \brief PCLK/512 */
#define BT_CLK_DIV_512                  8
/*! \brief PCLK/1024 */
#define BT_CLK_DIV_1024                 9
/*! \brief PCLK/2048 */
#define BT_CLK_DIV_2048                 10

/*! \brief Basetimer Clock divider check list */
#define IS_BT_CLOCK(CLOCK) (((CLOCK) == BT_CLK_DIV_1) || \
                            ((CLOCK) == BT_CLK_DIV_4) || \
                            ((CLOCK) == BT_CLK_DIV_16) || \
                            ((CLOCK) == BT_CLK_DIV_128) || \
                            ((CLOCK) == BT_CLK_DIV_256) || \
                            ((CLOCK) == BT_CLK_RIS_EDGE) || \
                            ((CLOCK) == BT_CLK_FALL_EDGE) || \
                            ((CLOCK) == BT_CLK_BOTH_EDGE) || \
                            ((CLOCK) == BT_CLK_DIV_512) || \
                            ((CLOCK) == BT_CLK_DIV_1024) || \
                            ((CLOCK) == BT_CLK_DIV_2048))


/* Base timer restart enable */
/*! \brief Restart disabled */
#define BT_RESTART_DISABLE              0
/*! \brief Restart enabled */
#define BT_RESTART_ENABLE               1

/*! \brief Basetimer restart bit check list */
#define IS_BT_RESTART(RESTART)  (((RESTART) == BT_RESTART_DISABLE) || \
                                ((RESTART) == BT_RESTART_ENABLE))

/* Base timer output mask */
/*! \brief Normal output */
#define BT_MASK_DISABLE                 0
/*! \brief Fixed to LOW output */
#define BT_MASK_ENABLE                  1

/*! \brief Basetimer output maske bit check list */
#define IS_BT_OUTPUT_MASK(MASK) (((MASK) == BT_MASK_DISABLE) || \
                                 ((MASK) == BT_MASK_ENABLE))

/* Base timer Trigger input edge selection (PWM,PPG,Reload timer) */
/*! \brief Trigger input disabled */
#define BT_TRG_DISABLE                  0
/*! \brief Rising edge */
#define BT_TRG_EDGE_RIS                 1
/*! \brief Falling edge */
#define BT_TRG_EDGE_FALL                2
/*! \brief Both edges */
#define BT_TRG_EDGE_BOTH                3

/*! \brief Basetimer Trigger input edge check list */
#define IS_BT_TRG_EDGE(EDGE) (((EDGE) == BT_TRG_DISABLE) || \
                              ((EDGE) == BT_TRG_EDGE_RIS) || \
                              ((EDGE) == BT_TRG_EDGE_FALL) || \
                              ((EDGE) == BT_TRG_EDGE_BOTH))

/* Base timer PWC measurement edge selection (PWC)*/
/*! \brief HIGH pulse width measurement (¡ü to ¡ý) */
#define BT_PWC_EDGE_HIGH                0
/*! \brief Cycle measurement between rising edges (¡ü to ¡ü) */
#define BT_PWC_EDGE_RIS                 1
/*! \brief Cycle measurement between falling edges (¡ý to ¡ý) */
#define BT_PWC_EDGE_FALL                2
/*! \brief Pulse width measurement between all edges (¡ü or ¡ý to ¡ý or ¡ü) */
#define BT_PWC_EDGE_BOTH                3
/*! \brief LOW pulse width measurement (¡ý to ¡ü) */
#define BT_PWC_EDGE_LOW                 4

/*! \brief Basetimer PWC measurement edge check list */
#define IS_BT_PWC_EDGE(EDGE) (((EDGE) == BT_PWC_EDGE_HIGH) || \
                              ((EDGE) == BT_PWC_EDGE_RIS) || \
                              ((EDGE) == BT_PWC_EDGE_FALL) || \
                              ((EDGE) == BT_PWC_EDGE_BOTH) || \
                              ((EDGE) == BT_PWC_EDGE_LOW))

/* Base timer Output polarity specification */
/*! \brief Normal polarity */
#define BT_POLARITY_NORMAL              0
/*! \brief Inverted polarity */
#define BT_POLARITY_INVERTED            1

/*! \brief Basetimer Output polarity bit check list */
#define IS_BT_POLARITY(POLARITY) (((POLARITY) == BT_POLARITY_NORMAL) || \
                                  ((POLARITY) == BT_POLARITY_INVERTED))

/* Base timer mode selection */
/*! \brief Continuous operation */
#define BT_MODE_CONTINUOUS              0
/*! \brief One-shot operation */
#define BT_MODE_ONESHOT                 1

/*! \brief Basetimer mode check list */
#define IS_BT_MODE(MODE) (((MODE) == BT_MODE_CONTINUOUS) || \
                          ((MODE) == BT_MODE_ONESHOT))

/* 32-bit timer selection for RT/PWC */
/*! \brief 16-bit timer mode */
#define BT_16BIT_TIMER                  0
/*! \brief 32-bit timer mode */
#define BT_32BIT_TIMER                  1

/*! \brief Basetimer 32-bit timer selection bit check list */
#define IS_BT_BIT_TIMER(TIMER) (((TIMER) == BT_16BIT_TIMER) || \
                                ((TIMER) == BT_32BIT_TIMER))

/* BT interrupt enable */
/*! \brief Trigger interrupt request enable */
#define BT_INT_ENABLE_TRG               4
/*! \brief Duty match interrupt request enable */
#define BT_INT_ENABLE_DUTY              2
/*! \brief Underflow interrupt request enable */
#define BT_INT_ENABLE_UNDER             1

/* BT interrupt enable (PWC)*/
/*! \brief Measurement completion interrupt request enable */
#define BT_INT_ENABLE_MEASURE           4
/*! \brief Overflow interrupt request enable */
#define BT_INT_ENABLE_OVERFLOW          1
   
/*
 ******************************************************************************
 ** Interrupt Type for each timer function:
 ** PWM timer:      BT_INT_ENABLE_TRG, BT_INT_ENABLE_DUTY, BT_INT_ENABLE_UNDER  
 ** PPG timer:      BT_INT_ENABLE_TRG, BT_INT_ENABLE_UNDER
 ** Reload timer:   BT_INT_ENABLE_TRG, BT_INT_ENABLE_UNDER
 ** PWC timer:      BT_INT_ENABLE_MEASURE, BT_INT_ENABLE_OVERFLOW
 ******************************************************************************
 */
#define BT_PWM_INT_ALL  (BT_INT_ENABLE_TRG|BT_INT_ENABLE_DUTY|BT_INT_ENABLE_UNDER)
#define BT_PPG_INT_ALL  (BT_INT_ENABLE_TRG|BT_INT_ENABLE_UNDER)
#define BT_RT_INT_ALL   (BT_INT_ENABLE_TRG|BT_INT_ENABLE_UNDER)
#define BT_PWC_INT_ALL  (BT_INT_ENABLE_MEASURE|BT_INT_ENABLE_OVERFLOW)

/*! \brief Basetimer PWM interrupt type check list */
#define IS_BT_PWM_INT(INT)  (((INT)|BT_PWM_INT_ALL) == BT_PWM_INT_ALL)
/*! \brief Basetimer PPG interrupt type check list */
#define IS_BT_PPG_INT(INT)  (((INT)|BT_PPG_INT_ALL) == BT_PPG_INT_ALL)
/*! \brief Basetimer Reload interrupt type check list */
#define IS_BT_RT_INT(INT)   (((INT)|BT_RT_INT_ALL) == BT_RT_INT_ALL)
/*! \brief Basetimer PWC interrupt type check list */
#define IS_BT_PWC_INT(INT)  (((INT)|BT_PWC_INT_ALL) == BT_PWC_INT_ALL)

/* BT interrupt status */
/*! \brief Trigger interrupt request */
#define BT_INT_TYP_TRG                  4
/*! \brief Duty match interrupt request */
#define BT_INT_TYP_DUTY                 2
/*! \brief Underflow interrupt request */
#define BT_INT_TYP_UNDER                1

/* BT interrupt status (PWC) */
/*! \brief Measurement completion interrupt request */
#define BT_INT_TYP_MEASURE              4
/*! \brief Overflow interrupt request */
#define BT_INT_TYP_OVERFLOW             1

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief Typedef of a Callback function pointer 
 **
 ** \param Status Input parameter for a callback function
 **
 ******************************************************************************
 */
typedef void (*BT_CallbackT) (uint8_t Type);


/*!
 ******************************************************************************
 ** \brief PWM timer initialization data structure
 ******************************************************************************
 */
typedef struct 
{    
    uint16_t        Cycle;       //!< PWM Cycle Settng    
    uint16_t        Duty;        //!< PWM Duty Setting    
    uint16_t        Clock;       //!< Clock selection    
    uint16_t        Restart;     //!< Restart enable   
    uint16_t        OutputMask;  //!< Output level of PWM output waveforms    	
    uint16_t        InputEdge;   //!< Trigger input edge selection    
    uint16_t        Polarity;    //!< Output polarity specification    
    uint16_t        Mode;        //!< Selects continuous pulse output or one-shot pulse output  
    BT_CallbackT    IrqCallback; //!<Irq callback function pointer
} BT_PwmInitRegT;  


/*!
 ******************************************************************************
 ** \brief PPG timer initialization data structure
 ******************************************************************************
 */
typedef struct 
{  
    uint16_t        LowWidth;       //!< LOW width of PPG output waveforms */    
    uint16_t        HighWidth;      //!< HIGH width of PPG output waveforms */     
    uint16_t        Clock;          //!< Count clock selection */
    uint16_t        Restart;        //!< Restart enable */
    uint16_t        OutputMask;     //!< Output level of PWM output waveforms */ 
    uint16_t        InputEdge;      //!< Trigger input edge selection */ 
    uint16_t        Polarity;       //!< Output polarity specification */
    uint16_t        Mode;           //!< Selects continuous pulse output or one-shot pulse output */ 
    BT_CallbackT    IrqCallback;    //!<Irq callback function pointer
} BT_PpgInitRegT;  

/*!
 ******************************************************************************
 ** \brief PWC timer initialization data structure
 ******************************************************************************
 */
typedef struct
{
        
    uint16_t        Clock;          //!< Count clock selection */
    uint16_t        MeasureEdge;    //!< Measurement edge selection */
    uint16_t        TimerMode;      //!< 32-bit timer selection */ 
    uint16_t        Mode;           //!< Selects Continuous measurement mode or One-shot measurement mode */ 
    BT_CallbackT    IrqCallback;    //!<Irq callback function pointer
} BT_PwcInitRegT; 

/*!
 ******************************************************************************
 ** \brief Reload timer initialization data structure
 ******************************************************************************
 */
typedef struct
{    
    uint32_t        Cycle;          //!< PWM Cycle Settng    
    uint16_t        Clock;          //!< Clock selection    
    uint16_t        InputEdge;      //!< Trigger input edge selection  
    uint16_t        TimerMode;      //!< 32-bit timer selection */ 
    uint16_t        Polarity;       //!< Output polarity specification    
    uint16_t        Mode;           //!< Selects continuous pulse output or one-shot pulse output  
    BT_CallbackT    IrqCallback;    //!<Irq callback function pointer
} BT_RtInitRegT;  

/*---------------------------------------------------------------------------*/
/* External variables                                                        */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

/* Set Base timer I/O Mode */
void BT_SetIOMode(uint8_t Ch, uint8_t IOMode);

/* PWM timer initialization */
void BT_PwmInit (uint8_t Ch, BT_PwmInitRegT* pInit);

/* PPG timer initialization */
void BT_PpgInit (uint8_t Ch, BT_PpgInitRegT* pInit);

/* PWC timer initialization */
void BT_PwcInit (uint8_t Ch, BT_PwcInitRegT* pInit);

/* Reload timer initialization */
void BT_RtInit (uint8_t Ch, BT_RtInitRegT* pInit);

/* Enable count operation */
void BT_CountEnable(uint8_t Ch);

/* Stop count operation */
void BT_CountDisable(uint8_t Ch);

/* Enable Pwm timer Interrupt */
void BT_PwmIntEnable(uint8_t Ch, uint16_t IntType);

/* Disable Pwm timer Interrupt */
void BT_PwmIntDisable(uint8_t Ch, uint16_t IntType);

/* Enable Ppg timer Interrupt */
void BT_PpgIntEnable(uint8_t Ch, uint16_t IntType);

/* Disable Ppg timer Interrupt */
void BT_PpgIntDisable(uint8_t Ch, uint16_t IntType);

/* Enable Reload timer Interrupt */
void BT_RtIntEnable(uint8_t Ch, uint16_t IntType);

/* Disable Reload timer Interrupt */
void BT_RtIntDisable(uint8_t Ch, uint16_t IntType);

/* Enable Pwc timer Interrupt */
void BT_PwcIntEnable(uint8_t Ch, uint16_t IntType);

/* Disable Pwc timer Interrupt */
void BT_PwcIntDisable(uint8_t Ch, uint16_t IntType);

/* Clear Interrupt request flag */
void BT_ClrIntRequest(uint8_t Ch, uint16_t IntType);

/* Get Interrupt request flag */
uint8_t BT_GetIntRequest(uint8_t Ch);

/* Start triggered by software */
void BT_SoftTrgEnable(uint8_t Ch);

/* Get PWC measurement error flag */
uint8_t BT_GetMeasureError(uint8_t Ch);

/* Get measured or count value of the PWC timer in 16-bit timer mode. */
uint16_t BT_Get16bitMeasureData(uint8_t Ch);

/* Get measured or count value of the PWC timer in 32-bit timer mode. */
uint32_t BT_Get32bitMeasureData(uint8_t Ch);

/* Get count value of the PWM,PPG and Reload timer in 16-bit timer mode */
uint16_t BT_Get16bitCount(uint8_t Ch);

/* Get count value of Reload timer in 32-bit timer mode. */
uint32_t BT_Get32bitCount(uint8_t Ch);
#ifdef __cplusplus
}
#endif


#endif /* _BASETIMER_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */
