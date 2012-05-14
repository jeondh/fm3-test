/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_ICU.c
 **
 ** \brief Input Capture Unit all cell drivers testing source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2012-01-09 11:10
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
#include "TEST_MFT_ICU.h"

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief  ICU unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCURegisterTest(void)
{
	MFT_ICU_ICFS_Test();
	MFT_ICU_EG_Test();
	MFT_ICU_ICEx_Test();
	MFT_ICU_ICPx_Test();
	MFT_ICU_IEIx_Test();
	MFT_ICU_ICCP_Test();

	return;
}

/*!
 ******************************************************************************
 ** \brief  ICU unit ICFS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICFS_Test(void)
{
	uint32_t temp = 0;

	MFT_IcuSetFrtCh(MFT0,FRT_CH0,ICU_CH0);
	temp = MFT_IcuGetFrtCh(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(FRT_CH0,temp, "ICFS");

	MFT_IcuSetFrtCh(MFT0,FRT_CH2,ICU_CH0);
	temp = MFT_IcuGetFrtCh(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(FRT_CH2,temp, "ICFS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ICU unit EG register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_EG_Test(void)
{
	uint32_t temp = 0;

	MFT_IcuSetState(MFT0,ICU_CH0,ICU_RISE);
	temp = MFT_IcuGetState(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(ICU_RISE,temp, "EG");

	MFT_IcuSetState(MFT0,ICU_CH0,ICU_DIS);
	temp = MFT_IcuGetState(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(ICU_DIS,temp, "EG");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ICU unit ICEx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICEx_Test(void)
{
	uint32_t temp = 0;

	MFT_IcuSetIntFnct(MFT0,ICU_CH0,TRUE);
	temp = MFT_IcuGetIntFnct(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(TRUE,temp, "ICEx");

	MFT_IcuSetIntFnct(MFT0,ICU_CH0,FALSE);
	temp = MFT_IcuGetIntFnct(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(FALSE,temp, "ICEx");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ICU unit ICPx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICPx_Test(void)
{
	uint32_t temp = 0;

	MFT_IcuClrIntFlag(MFT0,ICU_CH0);
	temp = MFT_IcuGetIntFlag(MFT0,ICU_CH0);
	MFT_OCU_Printf_Note(FALSE,temp, "ICPx");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ICU unit IEIx register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_IEIx_Test(void)
{
	uint32_t temp = 0;

	temp = MFT_IcuGetLastEdge(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(RISE,temp, "IEIx");

	temp = MFT_IcuGetLastEdge(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(FALL,temp, "IEIx");

	return;
}

/*!
 ******************************************************************************
 ** \brief  ICU unit ICCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_ICCP_Test(void)
{
	uint32_t temp = 0;

	MFT_IcuICCPValueWrite(MFT0,ICU_CH0,0x55);
	temp = MFT_IcuICCPValueRead(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(0x55,temp, "ICCP");

	MFT_IcuICCPValueWrite(MFT0,ICU_CH0,0xaa);
	temp = MFT_IcuICCPValueRead(MFT0,ICU_CH0);
	MFT_ICU_Printf_Note(0xaa,temp, "ICCP");

	return;
}

/*!
 ******************************************************************************
 ** \brief  Print the ICU test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_ICU_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str)
{
	if(SetValue == GetValue)
	{
		printf("The MFT ICU unit ") + printf(str) + printf(" register configure OK!\n");
	}
	else
	{
		printf("The MFT ICU unit ") + printf(str) + printf(" register configure FALSE!\n");
	}
}

/*****************************************************************************/
/* END OF FILE */
