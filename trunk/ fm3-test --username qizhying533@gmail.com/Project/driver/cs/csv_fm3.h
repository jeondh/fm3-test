/*!
 ******************************************************************************
 **
 ** \file csv_fm3.h
 **
 ** \brief Clock supervisor module driver
 ** 
 **
 ** \author 
 **
 ** \version V0.01
 **
 ** \date 2011-12-30
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
 
#ifndef _CSV_FM3_H_
#define _CSV_FM3_H_


/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"
#include <stdint.h>

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/*! \brief 1/256 frequency of high-speed CR oscillation */
#define FCS_CYCLE_256        5
/*! \brief 1/512 frequency of high-speed CR oscillation */
#define FCS_CYCLE_512        6
/*! \brief 1/1024 frequency of high-speed CR oscillation [Initial value] */
#define FCS_CYCLE_1024       7

/*! \brief FCS count cycle check list */
#define IS_FCS_CYCLE(CYCLE) (((CYCLE) == FCS_CYCLE_256) || \
                             ((CYCLE) == FCS_CYCLE_512) || \
                             ((CYCLE) == FCS_CYCLE_1024))


/*! \brief A sub clock failure has been detected. */
#define CSV_SUB_FAIL        2
/*! \brief A main clock failure has been detected. */
#define CSV_MAIN_FAIL       1

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
/* External variables                                                        */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif


/*!
 ******************************************************************************
 ** \brief The main CSV function is enabled
 ******************************************************************************
 */
void CSV_MainCSVEnable(void);

/*!
 ******************************************************************************
 ** \brief The main CSV function is disabled
 ******************************************************************************
 */
void CSV_MainCSVDisable(void);

/*!
 ******************************************************************************
 ** \brief The sub CSV function is enabled.
 ******************************************************************************
 */
void CSV_SubCSVEnable(void);

/*!
 ******************************************************************************
 ** \brief The sub CSV function is disabled¡£
 ******************************************************************************
 */
void CSV_SubCSVDisable(void);


/*!
 ******************************************************************************
 ** \brief The FCS function is enabled.
 ******************************************************************************
 */
void CSV_FCSEnable(void);

/*!
 ******************************************************************************
 ** \brief The FCS function is disabled
 ******************************************************************************
 */
void CSV_FCSDisable(void);

/*!
 ******************************************************************************
 ** \brief The FCS reset is enabled.
 ******************************************************************************
 */
void CSV_FCSResetEnable(void);


/*!
 ******************************************************************************
 ** \brief The FCS reset is disabled.
 ******************************************************************************
 */
void CSV_FCSResetDisable(void);
/*!
 ******************************************************************************
 ** \brief Enables FCS interrupts
 ******************************************************************************
 */
void CSV_FCSIntEnable(void);

/*!
 ******************************************************************************
 ** \brief Disables FCS interrupts
 ******************************************************************************
 */
void CSV_FCSIntDisable(void);

/*!
 ******************************************************************************
 ** \brief Clears the FCS interrupt cause.
 ******************************************************************************
 */
void CSV_ClrFCSIntRequest(void);

/*!
 ******************************************************************************
 ** \brief Get Anomalous frequency detection interrupt status
 **
 ** \return interrupt status
 ** \retval 0 No FCS interrupt has been asserted.
 ** \retval 1 An FCS interrupt has been asserted.
 ******************************************************************************
 */
uint8_t CSV_GetFCSIntRequest(void);

/*!
 ******************************************************************************
 ** \brief FCS count cycle setting
 **
 ** \param Cycle 
 ** \arg FCS_CYCLE_256      1/256 frequency of high-speed CR oscillation   
 ** \arg FCS_CYCLE_512      1/512 frequency of high-speed CR oscillation
 ** \arg FCS_CYCLE_1024     1/1024 frequency of high-speed CR oscillation
 ******************************************************************************
 */
void CSV_SetFCSCycle(uint16_t Cycle);



/*!
 ******************************************************************************
 ** \brief Get CSV status
 **
 ** \return Status of Sub CSV function
 ** \retval CSV_SUB_FAIL A sub clock failure has been detected.
 ** \retval CSV_MAIN_FAIL A main clock failure has been detected.
 ******************************************************************************
 */
uint8_t CSV_GetCSVFailCause(void);



/*!
 ******************************************************************************
 ** \brief Frequency lower detection window setting
 **
 ** \param Limit limit value
 ******************************************************************************
 */
void CSV_SetFCSDetectLower(uint16_t Limit);

/*!
 ******************************************************************************
 ** \brief Frequency upper detection window setting
 **
 ** \param Limit Limit value
 ******************************************************************************
 */
void CSV_SetFCSDetectUpper(uint16_t Limit);

/*!
 ******************************************************************************
 ** \brief Get the counter value of frequency detection using the main clock.
 **
 ** \return Frequency detection counter value
 ******************************************************************************
 */
uint16_t CSV_GetFCSDetectCount(void);

#ifdef __cplusplus
}
#endif


#endif /* _CLOCK_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */
