/*!
 ******************************************************************************
 **
 ** \file mb9bf50x_lib.h
 **
 ** \brief This file includes all Peripheral Library head files.
 **
 ** \author FSLA AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-11-21
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
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
#define MFT_FRT    TRUE
#define MFT_OCU    TRUE
#define MFT_WFG    TRUE
#define MFT_ADCMP  TRUE
/*#define QPRC       TRUE*/

/* peripheral driver head files */
#if MFT_FRT
#include "mft\mft_frt_fm3.h"
#endif
#if MFT_OCU
#include "mft\mft_ocu_fm3.h"
#endif
#if MFT_WFG
#include "mft\mft_wfg_fm3.h"
#endif
#if MFT_ADCMP
#include "mft\mft_adcmp_fm3.h"
#endif
#if QPRC
#include "qprc\qprc_fm3.h"
#endif

#endif /* _MB9BF50X_LIB_H_ */

/*****************************************************************************/
/* END OF FILE */
