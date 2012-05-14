/*!
 ******************************************************************************
 **
 ** \file wd_fm3.h
 **
 ** \brief head file of watchdog timer driver
 **
 ** 
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-8
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
 
#ifndef _WD_FM3_H_
#define _WD_FM3_H_
 
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*! \brief Disable write protection mode of WD registers */
#define WD_UNLOCK             ((uint32_t)0x1acce551)

/*! \brief Disable write protection mode of HWD registers */
#define HWD_UNLOCK             ((uint32_t)0xe5331aae)


/*! \brief Clear software WD interrupt */
#define WD_CLR_SWINT            ((uint32_t)0x55555555)

/*! \brief Clear Hardware WD interrupt */
#define WD_CLR_HWINT            ((uint8_t)0x55)



/*!
 ******************************************************************************
 ** \brief Software Watchdog Interrupt callback function definition
 ******************************************************************************
 */
typedef void (WD_IntHandlerCallback_CB) (void);


/*!
 ******************************************************************************
 ** \brief Software configuration infomation structure
 ******************************************************************************
 */
typedef struct
{
    uint32_t  SWDVal;           //!< software cycle  value  
    WD_IntHandlerCallback_CB *pSWDIntHandlerCallback;//!< software watchdog interrupt callback 
}WD_SoftConfigInfoT;


/*!
 ******************************************************************************
 ** \brief Hardware configuration infomation structure
 ******************************************************************************
 */
typedef struct
{
    uint32_t  HWDVal;          //!< hardware cycle  value  
    WD_IntHandlerCallback_CB *pHWDIntHandlerCallback; //!< software watchdog interrupt callback */
}WD_HardConfigInfoT;






/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Software watchdog timer */
void WD_SoftRegLock(void);
void WD_SoftRegUnLock(void);
void WD_SoftSetInterval(uint32_t SWDCycle);
void WD_SoftResetEnable(void);
void WD_SoftResetDisable(void);
void WD_SoftIntEnable(void);
void WD_SoftIntDisable(void);
void WD_SoftClear(void);
IntStatusT WD_SoftGetIntFlag(void);
uint32_t WD_SoftReadInterval(void);
void WD_SoftConfig(WD_SoftConfigInfoT *pSWDconfigInfo);


/*! \brief Hardtware watchdog timer */
void WD_HardSetInterval(uint32_t HWDCycle);
void WD_HardResetEnable(void);
void WD_HardResetDisable(void);
void WD_HardIntEnable(void);
void WD_HardIntDisable(void);
void WD_HardClear(void);
IntStatusT WD_HardGetIntFlag(void);
uint32_t WD_HardReadInterval(void);
void WD_HardConfig(WD_HardConfigInfoT *pHWDconfigInfo);
void WD_HardRegUnLock(void);




#ifdef __cplusplus
}
#endif


#endif /* _CR_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */



