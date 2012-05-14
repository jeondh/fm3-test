/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\main.c
 **
 ** \author FSAL AE Team
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
#include "TEST_MFT_FRT.h"
#include "TEST_MFT_OCU.h"
#include "TEST_MFT_WFG.h"
#include "TEST_MFT_ADCMP.h"

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
      MFT_FRTRegisterTest();
      MFT_OCURegisterTest();
      MFT_WFGRegisterTest();
      MFT_ADCMPRegisterTest();
    }
}


