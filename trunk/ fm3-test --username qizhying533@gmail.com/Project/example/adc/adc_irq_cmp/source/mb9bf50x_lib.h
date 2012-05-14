/*!
 ******************************************************************************
 **
 ** \file mb9bf50x_lib.h
 **
 ** \brief Driver head define
 **
 ** \author FSLA AE Team 
 **
 ** \version V0.10
 **
 ** \date 2001-01-19
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

#ifndef _MB9BF50X_LIB_H_
#define _MB9BF50X_LIB_H_

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fm3_common.h"

/* Driver head files include switch*/

#define ADC12
/* #define BT */
/* #define CLOCK */
/* #define CR */
/* #define CRC */
/* #define CSV */
/* #define DMAC */
/* #define DT */
/* #define EXTINT */
/* #define INT */
/* #define IO */
/* #define LPCM */
/* #define LVD */
/* #define MFS */
/* #define MFS_UART */
/* #define MFS_CSIO */
/* #define MFT_FRT */
/* #define MFT_OCU */
/* #define MFT_WFG */
/* #define MFT_ADCMP */
/* #define QPRC */
/* #define WC */
/* #define WD */

/* peripheral driver head files */
#ifdef ADC12
#include "adc\adc12_fm3.h"
#endif

#ifdef BT
#include "bt\basetimer_fm3.h"
#endif

#ifdef CLOCK
#include "clock\clock_fm3.h"
#endif

#ifdef CR
#include "cr\cr_fm3.h"
#endif

#ifdef CRC
#include "crc\crc_fm3.h"
#endif

#ifdef CSV
#include "cs\csv_fm3.h"
#endif

#ifdef DMAC
#include "dmac\dmac_fm3.h"
#endif

#ifdef DT
#include "dt\dt_fm3.h"
#endif

#ifdef EXTINT
#include "extint\extint_fm3.h"
#endif

#ifdef INT
#include "int\int_fm3.h"
#endif

#ifdef IO
#include "io\io_fm3.h"
#endif

#ifdef LPCM
#include "lpcm\lpcm_fm3.h"
#endif

#ifdef LVD
#include "lvd\lvd_fm3.h"
#endif

#ifdef MFS
#include "mfs\mfs_fm3.h"
#endif

#ifdef MFS_UART
#include "mfs\uart\uart_fm3.h"
#endif

#ifdef MFS_CSIO
#include "mfs\csio\csio_fm3.h"
#endif

#ifdef MFT_FRT
#include "mft\mft_frt_fm3.h"
#endif

#ifdef MFT_OCU
#include "mft\mft_ocu_fm3.h"
#endif

#ifdef MFT_WFG
#include "mft\mft_wfg_fm3.h"
#endif

#ifdef MFT_ADCMP
#include "mft\mft_adcmp_fm3.h"
#endif

#ifdef QPRC
#include "qprc\qprc_fm3.h"
#endif

#ifdef WC
#include "wc\wc_fm3.h"
#endif

#ifdef WD
#include "wd\wd_fm3.h"
#endif


#endif /* _MB9BF50X_LIB_H_ */

/*****************************************************************************/
/* END OF FILE */
