/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_ADCMP.c
 **
 ** \brief ADC Start Compare Unit drivers testing source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 15:50
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
#include "TEST_MFT_ADCMP.h"

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief  ADCMP unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMPRegisterTest(void)
{
	MFT_ADCMP_CEx_Test();
	MFT_ADCMP_SELx_Test();
	MFT_ADCMP_BDIS_Test();
	MFT_ADCMP_BTS_Test();
	MFT_ADCMP_ACCP_Test();
	MFT_ADCMP_ACCPDN_Test();
	MFT_ADCMP_ADxS_Test();
	MFT_ADCMP_ADxP_Test();

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit CEx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_CEx_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpSetFRTCh(MFT0,FRT_CH0,ADCMP_CH0);
	temp = MFT_AdcmpGetFRTCh(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(FRT_CH0,temp, "CE0");

	MFT_AdcmpSetFRTCh(MFT0,FRT_CH2,ADCMP_CH0);
	temp = MFT_AdcmpGetFRTCh(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(FRT_CH2,temp, "CE0");

	MFT_AdcmpSetFRTCh(MFT0,FRT_CH0,ADCMP_CH1);
	temp = MFT_AdcmpGetFRTCh(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(FRT_CH0,temp, "CE1");

	MFT_AdcmpSetFRTCh(MFT0,FRT_CH2,ADCMP_CH1);
	temp = MFT_AdcmpGetFRTCh(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(FRT_CH2,temp, "CE1");

	MFT_AdcmpSetFRTCh(MFT0,FRT_CH0,ADCMP_CH2);
	temp = MFT_AdcmpGetFRTCh(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(FRT_CH0,temp, "CE2");

	MFT_AdcmpSetFRTCh(MFT0,FRT_CH2,ADCMP_CH2);
	temp = MFT_AdcmpGetFRTCh(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(FRT_CH2,temp, "CE2");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit SELx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_SELx_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpSetStartMode(MFT0,ADCMP_CH0,ACCP_PEAKDOWN);
	temp = MFT_AdcmpGetStartMode(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(ACCP_PEAKDOWN,temp, "SEL0");

	MFT_AdcmpSetStartMode(MFT0,ADCMP_CH0,ACCP_UPPEAKDOWN);
	temp = MFT_AdcmpGetStartMode(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(ACCP_UPPEAKDOWN,temp, "SEL0");

	MFT_AdcmpSetStartMode(MFT0,ADCMP_CH1,ACCP_PEAKDOWN);
	temp = MFT_AdcmpGetStartMode(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(ACCP_PEAKDOWN,temp, "SEL1");

	MFT_AdcmpSetStartMode(MFT0,ADCMP_CH1,ACCP_UPPEAKDOWN);
	temp = MFT_AdcmpGetStartMode(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(ACCP_UPPEAKDOWN,temp, "SEL1");

	MFT_AdcmpSetStartMode(MFT0,ADCMP_CH2,ACCP_PEAKDOWN);
	temp = MFT_AdcmpGetStartMode(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(ACCP_PEAKDOWN,temp, "SEL2");

	MFT_AdcmpSetStartMode(MFT0,ADCMP_CH2,ACCP_UPPEAKDOWN);
	temp = MFT_AdcmpGetStartMode(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(ACCP_UPPEAKDOWN,temp, "SEL2");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit BDIS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_BDIS_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpSetACCPBufFnct(MFT0,ADCMP_CH0,TRUE);
	temp = MFT_AdcmpGetACCPBufFnct(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(TRUE,temp, "BDIS");

	MFT_AdcmpSetACCPBufFnct(MFT0,ADCMP_CH0,FALSE);
	temp = MFT_AdcmpGetACCPBufFnct(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(FALSE,temp, "BDIS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit BTS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_BTS_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpSetTimeSendBuff(MFT0,ADCMP_CH0,ADCMP_PEAK);
	temp = MFT_AdcmpGetTimeSendBuff(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(ADCMP_PEAK,temp, "BTS");

	MFT_AdcmpSetTimeSendBuff(MFT0,ADCMP_CH0,ADCMP_ZERO);
	temp = MFT_AdcmpGetTimeSendBuff(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(ADCMP_ZERO,temp, "BTS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ACCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ACCP_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpAccpWrite(MFT0,ADCMP_CH0,0x55);
	temp = MFT_AdcmpAccpRead(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(0x55,temp, "ACCP");

	MFT_AdcmpAccpWrite(MFT0,ADCMP_CH0,0xaa);
	temp = MFT_AdcmpAccpRead(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(0xaa,temp, "ACCP");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ACCPDN register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ACCPDN_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpAccpdnWrite(MFT0,ADCMP_CH0,0x55);
	temp = MFT_AdcmpAccpdnRead(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(0x55,temp, "ACCPDN");

	MFT_AdcmpAccpdnWrite(MFT0,ADCMP_CH0,0xaa);
	temp = MFT_AdcmpAccpdnRead(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(0xaa,temp, "ACCPDN");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ADxS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ADxS_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpSetTriggerOrigin(MFT0,ADCMP_CH0,TRI_FRT);
	temp = MFT_AdcmpGetTriggerOrigin(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(TRI_FRT,temp, "AD0S");

	MFT_AdcmpSetTriggerOrigin(MFT0,ADCMP_CH0,TRI_ADCMP);
	temp = MFT_AdcmpGetTriggerOrigin(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(TRI_ADCMP,temp, "AD0S");

	MFT_AdcmpSetTriggerOrigin(MFT0,ADCMP_CH1,TRI_FRT);
	temp = MFT_AdcmpGetTriggerOrigin(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(TRI_FRT,temp, "AD1S");

	MFT_AdcmpSetTriggerOrigin(MFT0,ADCMP_CH1,TRI_ADCMP);
	temp = MFT_AdcmpGetTriggerOrigin(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(TRI_ADCMP,temp, "AD1S");

	MFT_AdcmpSetTriggerOrigin(MFT0,ADCMP_CH2,TRI_FRT);
	temp = MFT_AdcmpGetTriggerOrigin(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(TRI_FRT,temp, "AD2S");

	MFT_AdcmpSetTriggerOrigin(MFT0,ADCMP_CH2,TRI_ADCMP);
	temp = MFT_AdcmpGetTriggerOrigin(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(TRI_ADCMP,temp, "AD2S");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ADCMP unit ADxP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_ADxP_Test(void)
{
	uint32_t temp = 0;

	MFT_AdcmpSetPriority(MFT0,ADCMP_CH0,TRI_FRT);
	temp = MFT_AdcmpGetPriority(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(TRI_FRT,temp, "AD0P");

	MFT_AdcmpSetPriority(MFT0,ADCMP_CH0,TRI_ADCMP);
	temp = MFT_AdcmpGetPriority(MFT0,ADCMP_CH0);
	MFT_ADCMP_Printf_Note(TRI_ADCMP,temp, "AD0P");

	MFT_AdcmpSetPriority(MFT0,ADCMP_CH1,TRI_FRT);
	temp = MFT_AdcmpGetPriority(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(TRI_FRT,temp, "AD1P");

	MFT_AdcmpSetPriority(MFT0,ADCMP_CH1,TRI_ADCMP);
	temp = MFT_AdcmpGetPriority(MFT0,ADCMP_CH1);
	MFT_ADCMP_Printf_Note(TRI_ADCMP,temp, "AD1P");

	MFT_AdcmpSetPriority(MFT0,ADCMP_CH2,TRI_FRT);
	temp = MFT_AdcmpGetPriority(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(TRI_FRT,temp, "AD2P");

	MFT_AdcmpSetPriority(MFT0,ADCMP_CH2,TRI_ADCMP);
	temp = MFT_AdcmpGetPriority(MFT0,ADCMP_CH2);
	MFT_ADCMP_Printf_Note(TRI_ADCMP,temp, "AD2P");

	return;
}

/*!
 ******************************************************************************
 ** \brief  Print the ADCMP test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ADCMP_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str)
{
	if(SetValue == GetValue)
	{
		printf("The MFT ADCMP unit ") + printf(str) + printf(" register configure OK!\n");
	}
	else
	{
		printf("The MFT ADCMP unit ") + printf(str) + printf(" register configure FALSE!\n");
	}
}

/*****************************************************************************/
/* END OF FILE */
