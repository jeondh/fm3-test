/*!
 ******************************************************************************
 **
 ** \file example\mft\example\source\EXMP_MFT_OCU.c
 **
 ** \brief Output Compare Unit example source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-28 14:30
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
#include "EXMP_MFT_OCU.h"


/*!
 ******************************************************************************
 ** \brief  MFT module OCU unit initial
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_Initial(void)
{
    //SystemInit();       /* Initialize system */
    InitialOCU();    /* Initialize OCU module */
    //NVIC_EnableIRQ(OUTCOMP_IRQn);   /* Enable OCU interrupt */

    return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit parameter configure
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void InitialOCU(void)
{
    _stParaForOCCP stParaForOCCP;
    stParaForOCCP.WhichMFT = MFT0; /* Which MFT will be configured */
    stParaForOCCP.WhichFRTCh = FRT_CH0; /* OCCP compare with which FRT channel.
                                           Usually this value should agree with
                                           the value in ConfFRT()*/
    stParaForOCCP.OCSB_CMODE = FALSE; /* Configure OCU work mode */
    stParaForOCCP.OCSC_MOD = TRUE;
    stParaForOCCP.EnBuf = FALSE; /* Enable or disable OCCP buffer function */
    stParaForOCCP.EnINT = TRUE;  /* Enable or disable OCCP inerrupt function  */

    stParaForOCCP.WhichOCCPCh = OC_CH0; /* Configure OCU channel 0 */
    MFT_OCUInitConfig(&stParaForOCCP);
    stParaForOCCP.WhichOCCPCh = OC_CH1;/* Configure OCU channel 1 */
    MFT_OCUInitConfig(&stParaForOCCP);

    return;
}

/*!
 ******************************************************************************
 ** \brief    OCU unit register configure
 **
 ** \param    _stParaForOCCP OCU unit struct
 **
 ** \return   none
 *****************************************************************************
*/
void MFT_OCUInitConfig(volatile _stParaForOCCP *p)
{
    volatile int8_t WhichMFT, WhichOCCPCh, WhichFRTCh, OCSB_CMODE, OCSC_MOD, EnBuf, EnINT;

    WhichMFT = p->WhichMFT;
    WhichOCCPCh = p->WhichOCCPCh;
    WhichFRTCh = p->WhichFRTCh;
    OCSB_CMODE = p->OCSB_CMODE;
    OCSC_MOD = p->OCSC_MOD;
    EnBuf = p->EnBuf;
    EnINT = p->EnINT;


    MFT_OcuSetFrtCh(WhichMFT, WhichFRTCh, WhichOCCPCh); // connect OCCP channel to which FRT channel
    MFT_OcuSetWorkMode(WhichMFT, WhichOCCPCh, OCSB_CMODE, OCSC_MOD);
    MFT_OcuSetOCCPBufFnct(WhichMFT, WhichOCCPCh, EnBuf); // enable/disable OCCP buffer
    MFT_OcuSetIntFnct(WhichMFT, WhichOCCPCh, EnINT); // enable/disable OCCP match FRT interrupt
    MFT_OcuStart(WhichMFT, WhichOCCPCh); /* Start OCU */

    OCU_IntCallback[WhichMFT] = OCU_Callback;  /* Interrupt callback function */

    return;
}

/*!
 ******************************************************************************
 ** \brief Interrupt callback function
 **
 ** \param IntType IntType Interrupt type
 ** \arg OCU_INT_CH0
 ** \arg OCU_INT_CH1
 ** \arg OCU_INT_CH2
 ** \arg OCU_INT_CH3
 ** \arg OCU_INT_CH4
 ** \arg OCU_INT_CH5
 **
 ** \return none
 **
 ******************************************************************************
 */
static void OCU_Callback(uint8_t IntType)
{
    switch(IntType)
    {
        case OCU_INT_CH0:
                printf("OCU channel 0 interrupt \n");
                break;
        case OCU_INT_CH1:
                printf("OCU channel 1 interrupt \n");
                break;
        case OCU_INT_CH2:
                printf("OCU channel 2 interrupt \n");
                break;
        case OCU_INT_CH3:
                printf("OCU channel 3 interrupt \n");
                break;
        case OCU_INT_CH4:
                printf("OCU channel 4 interrupt \n");
                break;
        case OCU_INT_CH5:
                printf("OCU channel 5 interrupt \n");
                break;

        default:
                break;
    }

    return;
}

/*****************************************************************************/
/* END OF FILE */
