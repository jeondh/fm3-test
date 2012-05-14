/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_OCU.c
 **
 ** \brief Output Compare Unit all cell drivers testing source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 11:10
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
#include "TEST_MFT_OCU.h"

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief  OCU unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCURegisterTest(void)
{
	MFT_OCU_OCFS_Test();
	MFT_OCU_CST_Test();
	MFT_OCU_BDIS_Test();
	MFT_OCU_IOE_Test();
	MFT_OCU_IOP_Test();
	MFT_OCU_OTD_Test();
	MFT_OCU_CMOD_Test();
	MFT_OCU_BTS_Test();
	MFT_OCU_OCSC_Test();
	MFT_OCU_OCCP_Test();

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit OCFS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OCFS_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetFrtCh(MFT0,FRT_CH0,OC_CH0);
	temp = MFT_OcuGetFrtCh(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FRT_CH0,temp, "OCFS");

	MFT_OcuSetFrtCh(MFT0,FRT_CH2,OC_CH0);
	temp = MFT_OcuGetFrtCh(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FRT_CH2,temp, "OCFS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit CSF register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_CST_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetState(MFT0,OC_CH0,TRUE);
	temp = MFT_OcuGetState(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(TRUE,temp, "CST");

	MFT_OcuSetState(MFT0,OC_CH0,FALSE);
	temp = MFT_OcuGetState(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FALSE,temp, "CST");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit BDIS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_BDIS_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetOCCPBufFnct(MFT0,OC_CH0,TRUE);
	temp = MFT_OcuGetOCCPBufFnct(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(TRUE,temp, "BDIS");

	MFT_OcuSetOCCPBufFnct(MFT0,OC_CH0,FALSE);
	temp = MFT_OcuGetOCCPBufFnct(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FALSE,temp, "BDIS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit IOE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_IOE_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetIntFnct(MFT0,OC_CH0,TRUE);
	temp = MFT_OcuGetIntFnct(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(TRUE,temp, "IOE");

	MFT_OcuSetIntFnct(MFT0,OC_CH0,FALSE);
	temp = MFT_OcuGetIntFnct(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FALSE,temp, "IOE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit IOP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_IOP_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuClrIntFlag(MFT0,OC_CH0);
	temp = MFT_OcuGetIntFlag(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FALSE,temp, "IOP");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit OTD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OTD_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetOutputLevel(MFT0,OC_CH0,HIGH);
	temp = MFT_OcuGetOutputLevel(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(HIGH,temp, "OTD");

	MFT_OcuSetOutputLevel(MFT0,OC_CH0,LOW);
	temp = MFT_OcuGetOutputLevel(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(LOW,temp, "OTD");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit CMOD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_CMOD_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetCMODReg(MFT0,OC_CH0,TRUE);
	temp = MFT_OcuGetCMODReg(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(TRUE,temp, "CMOD");

	MFT_OcuSetCMODReg(MFT0,OC_CH0,FALSE);
	temp = MFT_OcuGetCMODReg(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(FALSE,temp, "CMOD");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit BTS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_BTS_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetTimeSendBuff(MFT0,OC_CH0,CNT_TOP);
	temp = MFT_OcuGetTimeSendBuff(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(CNT_TOP,temp, "BTS");

	MFT_OcuSetTimeSendBuff(MFT0,OC_CH0,CNT_BOTTOM);
	temp = MFT_OcuGetTimeSendBuff(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(CNT_BOTTOM,temp, "BTS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit OCSC register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OCSC_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuSetMODOperateReg(MFT0,OC_CH0,TRUE);
	temp = MFT_OcuGetMODOperateReg(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(TRUE,temp, "MOD");

	MFT_OcuSetMODOperateReg(MFT0,OC_CH0,TRUE);
	temp = MFT_OcuGetMODOperateReg(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(TRUE,temp, "MOD");

	return;
}

/*!
 ******************************************************************************
 ** \brief  OCU unit OCCP register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_OCCP_Test(void)
{
	uint32_t temp = 0;

	MFT_OcuOCCPValueWrite(MFT0,OC_CH0,0x55);
	temp = MFT_OcuOCCPValueRead(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(0x55,temp, "OCCP");

	MFT_OcuOCCPValueWrite(MFT0,OC_CH0,0xaa);
	temp = MFT_OcuOCCPValueRead(MFT0,OC_CH0);
	MFT_OCU_Printf_Note(0xaa,temp, "OCCP");

	return;
}

/*!
 ******************************************************************************
 ** \brief  Print the OCU test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_OCU_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str)
{
	if(SetValue == GetValue)
	{
		printf("The MFT OCU unit ") + printf(str) + printf(" register configure OK!\n");
	}
	else
	{
		printf("The MFT OCU unit ") + printf(str) + printf(" register configure FALSE!\n");
	}
}

/*****************************************************************************/
/* END OF FILE */
