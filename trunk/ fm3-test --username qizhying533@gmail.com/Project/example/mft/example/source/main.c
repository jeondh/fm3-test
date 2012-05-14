/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\main.c
 **
 ** \author Calvin.Tan
 **
 ** \version V0.1
 **
 ** \date 2011-12-26
 **
 ** \brief This file provide testing the mft peripheral library.
 **
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "mb9bf50x_lib.h"
#include "EXMP_MFT_FRT.h"
#include "EXMP_MFT_OCU.h"
#include "EXMP_MFT_WFG.h"
#include "EXMP_MFT_ADCMP.h"

/**
 ******************************************************************************
 ** \brief  Main function of project for MB9B500 series.
 **
 ** \param  none
 ** \return uint32_t return value, if needed
 ******************************************************************************/

int32_t main(void)
{
    while(1)
    {
    	SystemInit();       /* Initialize system */
    	MFT_FRT_Initial();  /* Initialize FRT module */
    	MFT_OCU_Initial();  /* Initialize OCU module */
    	MFT_WFG_Initial();  /* Initialize WFG and DTTI module */
    	MFT_ADCMP_Initial();/* Initialize ADCMP module */
    }
}


