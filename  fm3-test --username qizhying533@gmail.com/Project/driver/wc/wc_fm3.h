/*!
 ******************************************************************************
 **
 ** \file wc_fm3.h
 **
 ** \brief Watch counter drivers head file
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-21
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
 
#ifndef _WC_FM3_H_
#define _WC_FM3_H_


/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/* Watch counter input clock type */
/*! \brief Sub Clock */
#define WCPRES_INPUT_CLOCK_SUB_CLOCK          ((uint16_t)0x0000)
/*! \brief Main Clock */
#define WCPRES_INPUT_CLOCK_MAIN_CLOCK         ((uint16_t)0x0001)
/*! \brief Check input clock parameter */
#define IS_WCPRES_INPUT_CLOCK_VALID(Clk)        ((Clk == WCPRES_INPUT_CLOCK_SUB_CLOCK) || \
                                                 (Clk == WCPRES_INPUT_CLOCK_MAIN_CLOCK))

/* brief Watch counter output clock array */
/*! \brief Clock Array 0 */
#define WCPRES_OUTPUT_CLOCK_ARRAY0            ((uint16_t)0x0000)  /*  WCCK3       WCCK2      WCCK1      WCCK0     */
                                                                  /*  2^15/Fcl    2^14/Fcl   2^13/Fcl   2^12/Fcl  */
/*! \brief Clock Array 1 */                                                                  
#define WCPRES_OUTPUT_CLOCK_ARRAY1            ((uint16_t)0x0100)  /*  WCCK3       WCCK2      WCCK1      WCCK0     */
                                                                  /*  2^25/Fcl    2^24/Fcl   2^23/Fcl   2^22/Fcl  */
/*! \brief Check clock array parameter */
#define IS_WCPRES_OUTPUT_CLOCK_ARRAY_VALID(ClkArray)    ((ClkArray == WCPRES_OUTPUT_CLOCK_ARRAY0) || \
                                                         (ClkArray == WCPRES_OUTPUT_CLOCK_ARRAY1))

/* Watch counter output clock type */                                            
/*! \brief WCCK0 */   
#define WC_OUTPUT_CLOCK_WCCK0             ((uint8_t)0x00)
/*! \brief WCCK1 */   
#define WC_OUTPUT_CLOCK_WCCK1             ((uint8_t)0x01)
/*! \brief WCCK2 */  
#define WC_OUTPUT_CLOCK_WCCK2             ((uint8_t)0x02)
/*! \brief WCCK3 */    
#define WC_OUTPUT_CLOCK_WCCK3             ((uint8_t)0x03)
/*! \brief Check watch counter output clock type */  
#define IS_WC_OUTPUT_CLOCK_VALID(Clk)       ((Clk == WC_OUTPUT_CLOCK_WCCK0) || \
                                             (Clk == WC_OUTPUT_CLOCK_WCCK1) || \
                                             (Clk == WC_OUTPUT_CLOCK_WCCK2) || \
                                             (Clk == WC_OUTPUT_CLOCK_WCCK3))

/*!
 ******************************************************************************
 ** \brief Watch counter Interrupt callback function definition
 ******************************************************************************
 */
typedef void (WC_IntHandlerCallback_CB) (void);

/*!
 ******************************************************************************
 ** \brief Watch counter configuration infomation structure
 ******************************************************************************
 */
typedef struct
{
    uint8_t  CntClkSel;        //!< counter clock selection 
    uint8_t  CntVal;           //!< count value                           
    uint8_t  CntIntEn;         //!< watch counter interrupt enable/diable
    WC_IntHandlerCallback_CB *pIntHandlerCallback; //!< watch counter interrupt callback 
}WC_ConfigInfoT;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
/* watch counter prescaler */
void WCPRES_ClkInSel(uint8_t InClock);
void WCPRES_ClkOutSel (uint32_t OutClock);
void WCPRES_ClkEn (FuncStateT ClkEn);
FlagStatusT WCPRES_GetClkStat (void);
/* watch counter */
void WC_Config(WC_ConfigInfoT *pConfigInfo);
void WC_Start(void);
void WC_Stop(void);
uint8_t WC_GetCntVal(void);
FlagStatusT WC_GetOpStat(void);
IntStatusT WC_GetIntFlag (void);
void WC_ClrIntFlag(void);

#ifdef __cplusplus
}
#endif


#endif /* _WC_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */
