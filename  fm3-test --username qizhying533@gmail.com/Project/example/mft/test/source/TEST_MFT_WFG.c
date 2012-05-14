/*!
 ******************************************************************************
 **
 ** \file example\mft\Test\Source\TEST_MFT_WFG.c
 **
 ** \brief Waveform Generator Unit all cell drivers testing source code file
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1.0
 **
 ** \date 2011-12-26 18:50
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
#include "TEST_MFT_WFG.h"

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/


/*!
 ******************************************************************************
 ** \brief  WFG unit register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFGRegisterTest(void)
{
	MFT_WFG_DCK_Test();
	MFT_WFG_TMD_Test();
	MFT_WFG_GATE_Test();
	MFT_WFG_PSEL_Test();
	MFT_WFG_PGEN_Test();
	MFT_WFG_DMOD_Test();
	MFT_WFG_WFTM_Test();
	MFT_WFG_DTIE_Test();
	MFT_WFG_DTIFandDTIC_Test();
	MFT_WFG_TMIFandTMIC_Test();
	MFT_WFG_TMIE_Test();
	MFT_WFG_NWS_Test();

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit DCK register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DCK_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgDivWrite(MFT0,WFG_CH10,WFG_DIV1);
	temp = MFT_WfgDivRead(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(WFG_DIV1,temp, "DCK");

	MFT_WfgDivWrite(MFT0,WFG_CH10,WFG_DIV5);
	temp = MFT_WfgDivRead(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(WFG_DIV5,temp, "DCK");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit TMD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_TMD_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetWorkMode(MFT0,WFG_CH10,MODE_RT_DEAD_TIMER);
	temp = MFT_WfgGetWorkMode(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(MODE_RT_DEAD_TIMER,temp, "TMD");

	MFT_WfgSetWorkMode(MFT0,WFG_CH10,MODE_THROUGH);
	temp = MFT_WfgGetWorkMode(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(MODE_THROUGH,temp, "TMD");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit GATE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_GATE_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetChGateEnFlag(MFT0,WFG_CH10,1);
	temp = MFT_WfgGetChGateEnFlag(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(1,temp, "GATE");

	MFT_WfgSetChGateEnFlag(MFT0,WFG_CH10,0);
	temp = MFT_WfgGetChGateEnFlag(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(0,temp, "GATE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit PSEL register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_PSEL_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetPPGTimerUnit(MFT0,WFG_CH10,PPG_TMR4);
	temp = MFT_WfgGetPPGTimerUnit(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(PPG_TMR4,temp, "PSEL");

	MFT_WfgSetPPGTimerUnit(MFT0,WFG_CH10,PPG_TMR0);
	temp = MFT_WfgGetPPGTimerUnit(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(PPG_TMR0,temp, "PSEL");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit PGEN register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_PGEN_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetChGateFlag(MFT0,WFG_CH10,1);
	temp = MFT_WfgGetChGateFlag(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(1,temp, "PGEN");

	MFT_WfgSetChGateFlag(MFT0,WFG_CH10,0);
	temp = MFT_WfgGetChGateFlag(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(0,temp, "PGEN");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit DMOD register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DMOD_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetPolarity(MFT0,WFG_CH10,LEVEL_HIGH);
	temp = MFT_WfgGetPolarity(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(LEVEL_HIGH,temp, "DMOD");

	MFT_WfgSetPolarity(MFT0,WFG_CH10,LEVEL_LOW);
	temp = MFT_WfgGetPolarity(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(LEVEL_LOW,temp, "DMOD");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit WFTM register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_WFTM_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgTimerValueWrite(MFT0,WFG_CH10,0x55);
	temp = MFT_WfgTimerValueRead(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(0x55,temp, "WFTM");

	MFT_WfgTimerValueWrite(MFT0,WFG_CH10,0xaa);
	temp = MFT_WfgTimerValueRead(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(0xaa,temp, "WFTM");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit DTIE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DTIE_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetDtifIntFnct(MFT0,TRUE);
	temp = MFT_WfgGetDtifIntFnct(MFT0);
	MFT_WFG_Printf_Note(TRUE,temp, "DTIE");

	MFT_WfgSetDtifIntFnct(MFT0,FALSE);
	temp = MFT_WfgGetDtifIntFnct(MFT0);
	MFT_WFG_Printf_Note(FALSE,temp, "DTIE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit DTIFandDTIC register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_DTIFandDTIC_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgClrDtifIntFlag(MFT0);
	temp = MFT_WfgGetDtifIntFlag(MFT0);
	MFT_WFG_Printf_Note(0,temp, "DTIFandDTIC");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit TMIFandTMIC register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_TMIFandTMIC_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgClrTmrIntFlag(MFT0,WFG_CH10);
	temp = MFT_WfgGetTmrIntFlag(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(0,temp, "TMIFandTMIC");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit TMIE register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_TMIE_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetTmrState(MFT0,WFG_CH10,WFG_OPER);
	temp = MFT_WfgGetTmrState(MFT0,WFG_CH10);
	MFT_WFG_Printf_Note(WFG_OPER,temp, "TMIE");

	return;
}

/*!
 ******************************************************************************
 ** \brief  WFG unit NWS register test function
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_NWS_Test(void)
{
	uint32_t temp = 0;

	MFT_WfgSetNoiseCancelWidth(MFT0,DTTI_NOISE_TIME4);
	temp = MFT_WfgGetNoiseCancelWidth(MFT0);
	MFT_WFG_Printf_Note(DTTI_NOISE_TIME4,temp, "NWS");

	MFT_WfgSetNoiseCancelWidth(MFT0,DTTI_NOISE_TIME0);
	temp = MFT_WfgGetNoiseCancelWidth(MFT0);
	MFT_WFG_Printf_Note(DTTI_NOISE_TIME0,temp, "NWS");

	return;
}

/*!
 ******************************************************************************
 ** \brief  Print the WFG test result on IAR Terminal I/O window
 **
 ** \param none
 **
 ** \return none
 *****************************************************************************
*/
void MFT_WFG_Printf_Note(uint32_t SetValue, uint32_t GetValue, char *str)
{
	if(SetValue == GetValue)
	{
		printf("The MFT WFG unit ") + printf(str) + printf(" register configure OK!\n");
	}
	else
	{
		printf("The MFT WFG unit ") + printf(str) + printf(" register configure FALSE!\n");
	}
}

/*****************************************************************************/
/* END OF FILE */
