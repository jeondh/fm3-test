/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_FRT.c
 **
 ** \brief Free-run Timer Unit all cell drivers testing source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 9:30
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
#include "TEST_MFT_FRT.h"


/*!
 ******************************************************************************
 ** \brief  FRT unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRTRegisterTest(void)
{
	MFT_FRT_CLK_Test();
	MFT_FRT_MODE_Test();
	MFT_FRT_STOP_Test();
	MFT_FRT_BFE_Test();
	MFT_FRT_ICRE_Test();
	MFT_FRT_ICLR_Test();
	MFT_FRT_IRQZE_Test();
	MFT_FRT_IRQZF_Test();
	MFT_FRT_ECKE_Test();
	MFT_FRT_ADxE_Test();
	MFT_FRT_TCCP_Test();
	MFT_FRT_TCDT_Test();

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit CLK register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_CLK_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtDivWrite(MFT0,FRT_CH0,FRT_DIV5);
	temp = MFT_FrtDivRead(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FRT_DIV5,temp, "CLK");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit MODE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_MODE_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetCntMode(MFT0,FRT_CH0,TRUE);
	temp = MFT_FrtGetCntMode(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "MODE");

	MFT_FrtSetCntMode(MFT0,FRT_CH0,FALSE);
	temp = MFT_FrtGetCntMode(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "MODE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit STOP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_STOP_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetStopReg(MFT0,FRT_CH0,TRUE);
	temp = MFT_FrtGetStopReg(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "STOP");

	MFT_FrtSetStopReg(MFT0,FRT_CH0,FALSE);
	temp = MFT_FrtGetStopReg(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "STOP");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit BFE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_BFE_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetTCCPBufFnct(MFT0,FRT_CH0,TRUE);
	temp = MFT_FrtGetTCCPBufFnct(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "BFE");

	MFT_FrtSetTCCPBufFnct(MFT0,FRT_CH0,FALSE);
	temp = MFT_FrtGetTCCPBufFnct(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "BFE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit ICRE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ICRE_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetTopIntFnct(MFT0,FRT_CH0,TRUE);
	temp = MFT_FrtGetTopIntFnct(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "ICRE");

	MFT_FrtSetTopIntFnct(MFT0,FRT_CH0,FALSE);
	temp = MFT_FrtGetTopIntFnct(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "ICRE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit ICLR register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ICLR_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtClrTopIntFlag(MFT0,FRT_CH0); //Clear this register bit
	temp = MFT_FrtGetTopIntFlag(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "ICLR");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit IRQZE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_IRQZE_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetZeroIntFnct(MFT0,FRT_CH0,TRUE);
	temp = MFT_FrtGetZeroIntFnct(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "IRQZE");

	MFT_FrtSetZeroIntFnct(MFT0,FRT_CH0,FALSE);
	temp = MFT_FrtGetZeroIntFnct(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "IRQZE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit IRQZF register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_IRQZF_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtClrZeroIntFlag(MFT0,FRT_CH0); //Clear this register bit
	temp = MFT_FrtGetZeroIntFlag(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "IRQZF");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit ECKE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ECKE_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetCLKOrigin(MFT0,FRT_CH0,TRUE);
	temp = MFT_FrtGetCLKOrigin(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "ECKE");

	MFT_FrtSetCLKOrigin(MFT0,FRT_CH0,FALSE);
	temp = MFT_FrtGetCLKOrigin(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "ECKE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit ADxE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_ADxE_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtSetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH0,TRUE);
	temp = MFT_FrtGetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH0);
	MFT_FRT_Printf_Note(TRUE,temp, "AD0E");

	MFT_FrtSetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH0,FALSE);
	temp = MFT_FrtGetTrigADCFnct(MFT0,ADCMP_CH0,ADCMP_CH0);
	MFT_FRT_Printf_Note(FALSE,temp, "AD0E");

	MFT_FrtSetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH1,TRUE);
	temp = MFT_FrtGetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH1);
	MFT_FRT_Printf_Note(TRUE,temp, "AD1E");

	MFT_FrtSetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH1,FALSE);
	temp = MFT_FrtGetTrigADCFnct(MFT0,ADCMP_CH1,ADCMP_CH1);
	MFT_FRT_Printf_Note(FALSE,temp, "AD1E");

	MFT_FrtSetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH2,TRUE);
	temp = MFT_FrtGetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH2);
	MFT_FRT_Printf_Note(TRUE,temp, "AD2E");

	MFT_FrtSetTrigADCFnct(MFT0,FRT_CH0,ADCMP_CH2,FALSE);
	temp = MFT_FrtGetTrigADCFnct(MFT0,ADCMP_CH2,ADCMP_CH2);
	MFT_FRT_Printf_Note(FALSE,temp, "AD2E");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit TCCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_TCCP_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtTCCPWrite(MFT0,FRT_CH0,0x55);
	temp = MFT_FrtTCCPRead(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(0x55,temp, "TCCP");

	MFT_FrtTCCPWrite(MFT0,FRT_CH0,0xAA);
	temp = MFT_FrtTCCPRead(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(0xAA,temp, "TCCP");

	return;
}

/*!
 ******************************************************************************
 ** \brief  FRT unit TCDT register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_TCDT_Test(void)
{
	uint32_t temp = 0;

	MFT_FrtClrTCDT(MFT0,FRT_CH0);
	temp = MFT_FrtTCDTRead(MFT0,FRT_CH0);
	MFT_FRT_Printf_Note(0,temp, "TCDT");

	return;
}

/*!
 ******************************************************************************
 ** \brief  Print the FRT test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_FRT_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str)
{
	if(SetValue == GetValue)
	{
		printf("The MFT FRT unit ") + printf(str) + printf(" register configure OK!\n");
	}
	else
	{
		printf("The MFT FRT unit ") + printf(str) + printf(" register configure FALSE!\n");
	}
}

/*****************************************************************************/
/* END OF FILE */
