/*!
 ******************************************************************************
 **
 ** \file clock_fm3.h
 **
 ** \brief clock module driver
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
 
#ifndef _CLOCK_FM3_H_
#define _CLOCK_FM3_H_


/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"
#include <stdint.h>

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/**
 ******************************************************************************
 ** System Clock Mode Control Register value definition
 **        <i>(USER SETTING)</i>
 ** 
 ** SCM_CTL
 **
 ** Bit#7-5 : RCS[2:0]
 ** - 0 = Internal high-speed CR oscillation (default)
 ** - 1 = Main oscillation clock
 ** - 2 = PLL oscillation clock
 ** - 3 = (not allowed)
 ** - 4 = Internal low-speed CR oscillation
 ** - 5 = Sub clock oscillation
 ** - 6 = (not allowed)
 ** - 7 = (not allowed)
 **
 ** Bit#4 : PLLE
 ** - 0 = Disable PLL (default)
 ** - 1 = Enable PLL
 **
 ** Bit#3 : SOSCE
 ** - 0 = Disable sub oscillation (default)
 ** - 1 = Enable sub oscillation
 **
 ** Bit#2 : (reserved)
 **
 ** Bit#1 : MOSCE
 ** - 0 = Disable main oscillation (default)
 ** - 1 = Enable main oscillation  
 **
 ** Bit#0 : (reserved)  
 ******************************************************************************/ 

/*! \brief Internal high-speed CR oscillation. */
#define CLOCK_HIGH_CR        0x00000000
/*! \brief Main oscillation clock. */
#define CLOCK_MAIN_OSC       0x00000022
/*! \brief PLL oscillation clock. */
#define CLOCK_PLL_OSC        0x00000052
/*! \brief Internal low-speed CR oscillation. */
#define CLOCK_LOW_CR         0x00000080
/*! \brief Sub clock oscillation. */
#define CLOCK_SUB_OSC        0x000000A8

#define IS_SRC_CLOCK(CLOCK) (((CLOCK) == CLOCK_HIGH_CR) || \
                             ((CLOCK) == CLOCK_MAIN_OSC) || \
                             ((CLOCK) == CLOCK_PLL_OSC) || \
                             ((CLOCK) == CLOCK_LOW_CR) || \
                             ((CLOCK) == CLOCK_SUB_OSC)) 
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

/* Switch master clock */
void CLOCK_MasterClockSwitch(uint32_t ClockType); 



#ifdef __cplusplus
}
#endif


#endif /* _CLOCK_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */
