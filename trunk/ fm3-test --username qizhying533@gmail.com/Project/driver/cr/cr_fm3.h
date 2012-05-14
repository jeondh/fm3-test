/*!
 ******************************************************************************
 **
 ** \file cr_fm3.h
 **
 ** \brief head file of CR trimming driver
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
 
#ifndef _CR_FM3_H_
#define _CR_FM3_H_
 
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*! \brief Frequency divsion ratio 1/4 */
#define CRC_FRQ_DIV_4                      0 
/*! \brief Frequency divsion ratio 1/8 */
#define CRC_FRQ_DIV_8                      1 // 1/8
/*! \brief Frequency divsion ratio 1/16 */
#define CRC_FRQ_DIV_16                     2 // 1/16
/*! \brief Frequency divsion ratio 1/32 */
#define CRC_FRQ_DIV_32                     3 // 1/32

/*! \brief Check parameter */
#define IS_CRC_FQR_DIV(val)                    ((val == CRC_FRQ_DIV_4) \
                                                ||(val == CRC_FRQ_DIV_8) \
                                                ||(val == CRC_FRQ_DIV_16) \
                                                ||(val == CRC_FRQ_DIV_32))
                                           


/*! \brief Disable write protection mode of MCR_FTRM  */
#define CR_UNLOCK							((uint32_t)0x1acce554)


/*! \brief flash address of CR trimming data  */
#define CR_TRIMMING_DATA             		*((volatile unsigned int*)(0x00101004UL))

                             
/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

void CR_RegUnLock(void);
void CR_RegLock(void);
void CR_SetTrimData(int16_t TrimData);
void CR_SetFreqConfig(uint8_t FrqDiv);
int16_t CR_DataCal(void);
int16_t CR_GetTrimData(void);
void CR_Init(void);


#ifdef __cplusplus
}
#endif


#endif /* _CR_FM3_H_ */
/*****************************************************************************/
/* END OF FILE */







