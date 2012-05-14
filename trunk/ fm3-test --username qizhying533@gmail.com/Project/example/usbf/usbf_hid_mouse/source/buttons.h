/*!
 ******************************************************************************
 **
 ** \file buttons.h
 **
 ** \brief buttons head file
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-18
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
 
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "includes.h"

#ifndef  __BUTTONS_H
#define  __BUTTONS_H

/*!
 ******************************************************************************
 ** \brief Buttons
 ******************************************************************************
 */
/*! \brief Button 1 control bit */
#define B1_CLICK        (1<<0)
/*! \brief Button 2 control bit */
#define B2_CLICK        (1<<1)
/*! \brief Button Mask */
#define B_CLICK_MASK    (B1_CLICK | B2_CLICK)
/*! \brief PRF of button control IO */
#define B_CLICK_PFR      FM3_GPIO->PFR5
/*! \brief PDIR of button control IO */
#define B_CLICK_PDIR     FM3_GPIO->PDIR5
/*! \brief DDR of button control IO */
#define B_CLICK_DDR      FM3_GPIO->DDR5

/*!
 ******************************************************************************
 ** \brief Left
 ******************************************************************************
 */
/*! \brief Left button control bit */
#define B_LEFT        (1<<0)
/*! \brief Left button mask bit */
#define B_L_MASK      (B_LEFT)
/*! \brief PFR for button control IO */
#define B_L_PFR       FM3_GPIO->PFR4
/*! \brief PDIR for button control IO */
#define B_L_PDIR      FM3_GPIO->PDIR4
/*! \brief DDR for button control IO */
#define B_L_DDR       FM3_GPIO->DDR4

/*!
 ******************************************************************************
 ** \brief Right
 ******************************************************************************
 */
/*! \brief Right button control bit */
#define B_RIGHT       (1<<3)
/*! \brief Right button mask bit */
#define B_R_MASK      (B_RIGHT)
/*! \brief PFR for button control IO */
#define B_R_PFR       FM3_GPIO->PFR4
/*! \brief PDIR for button control IO */
#define B_R_PDIR      FM3_GPIO->PDIR4
/*! \brief DDR for button control IO */
#define B_R_DDR       FM3_GPIO->DDR4

/*!
 ******************************************************************************
 ** \brief Up
 ******************************************************************************
 */
/*! \brief Up button control bit */
#define B_UP          (1<<1)
/*! \brief Up button mask bit */
#define B_U_MASK      (B_UP)
/*! \brief PFR for button control IO */
#define B_U_PFR       FM3_GPIO->PFR4
/*! \brief PDIR for button control IO */
#define B_U_PDIR      FM3_GPIO->PDIR4
/*! \brief DDR for button control IO */
#define B_U_DDR       FM3_GPIO->DDR4

/*!
 ******************************************************************************
 ** \brief Down
 ******************************************************************************
 */
/*! \brief Down button control bit */
#define B_DOWN        (1<<2)
/*! \brief Down button mask bit */
#define B_D_MASK      (B_DOWN)

/*! \brief PFR for button control IO */
#define B_D_PFR       FM3_GPIO->PFR4
/*! \brief PDIR for button control IO */
#define B_D_PDIR      FM3_GPIO->PDIR4
/*! \brief DDR for button control IO */
#define B_D_DDR       FM3_GPIO->DDR4

/*!
 ******************************************************************************
 ** \brief Button status structure
 ******************************************************************************
 */
typedef union _ButtonsT
{
    uint32_t Data;
    struct
    {
        uint32_t BtUp        : 1;      //!< Up button   
        uint32_t BtDown      : 1;      //!< Down button  
        uint32_t BtRight     : 1;      //!< Right button  
        uint32_t BtLeft      : 1;      //!< Left button  
        uint32_t Bt1Click    : 1;      //!< Click Button 1  
        uint32_t Bt2Click    : 1;      //!< Click Button 2
        uint32_t             :26;      //!< Reserved  
    };
} ButtonsT, *pButtonsT;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
void Buttons_Init (void);
ButtonsT Buttons_GetStatus (void);

#ifdef __cplusplus
}
#endif

#endif  /* __BUTTONS_H */
