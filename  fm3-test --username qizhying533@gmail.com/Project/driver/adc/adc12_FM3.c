/*!
 ******************************************************************************
 **
 ** \file adc12_fm3.c
 **
 ** \brief this file provides adc 12-bit drivers.
 **
 ** \author FSLA AE Team 
 **
 ** \version V0.10   
 **
 ** \date 2011-12-14
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
 
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "adc12_FM3.h"
/*---------------------------------------------------------------------------*/
/* Bit definition                                                            */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief define FIFO Info buffer
 ******************************************************************************
 */
typedef struct
{
    uint16_t *ADC12_FIFOData;//!< ADC save data from FIFO 
    uint16_t *ADC12_FIFODataInfo;//!< ADC save FIFO status from FIFO
    uint16_t *ADC12_FIFOStage;//!< ADC read FIFO number
}ADC12_FIFOInfoT;
/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FM3_ADC_TypeDef* ADC12_Reg[] = 
{
    (FM3_ADC_TypeDef*)(FM3_ADC0),
    (FM3_ADC_TypeDef*)(FM3_ADC1),
    (FM3_ADC_TypeDef*)(FM3_ADC2),
};

 /*!
 ******************************************************************************
 ** \brief save adc conversion results
 ******************************************************************************
 */
static ADC12_FIFOInfoT ADC12_FIFOInfo[] =
{
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
};
 /*!
 ******************************************************************************
 ** \brief save adc conversion results
 ******************************************************************************
 */

static ADC12_CallBackIrqT ADC12_IrqCallback[] = 
{ 
    NULL,
    NULL,
    NULL,
};

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void ADC12_IrqHandler(ADC12_UnitT ADC12_Unit, uint8_t Irq);
/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief Initialize  for ADC 12 bit scan mode
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2
 ** \param ADC12_InitT config scan mode
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_AdcInit(ADC12_UnitT ADC12_Unit, ADC12_Config *ADC12_InitT)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    ASSERT(IS_ADC_SAMPEL_TIME_VALID(ADC12_InitT->ADC12_SampleTimeN.
        ADC12_SampleTimeN0));
    ASSERT(IS_ADC_SAMPEL_TIME_VALID(ADC12_InitT->ADC12_SampleTimeN.
        ADC12_SampleTimeN1));       
    ASSERT(IS_ADC_SAMPEL_TIME_SEL_VALID(ADC12_InitT->ADC12_SampleTimeSelReg));
    ASSERT(IS_ADC_CMP_TIME_VALID(ADC12_InitT->ADC12_CmpDiv));
    ASSERT(IS_ADC_TRIGGER_MODE_VALID(ADC12_InitT->ADC12_StartTimerTrigMode));
    ASSERT(IS_ADC_SCAN_MODE_VALID(ADC12_InitT->ADC12_ScanMode));

    ASSERT(IS_ADC_OPTION_MODE_VALID(ADC12_InitT->ADC12_Option));
    ASSERT(IS_ADC_FIFO_STAGE_VALID(ADC12_InitT->ADC12_FIFOStage));
    ASSERT(IS_ADC_DATA_SIDE_VALID(ADC12_InitT->ADC12_DataSide));
		
    ASSERT(IS_ADC_CMP_MODE_VALID(ADC12_InitT->ADC12_CmpOption.ADC12_Cmd0));
    ASSERT(IS_ADC_CMP_MODE_VALID(ADC12_InitT->ADC12_CmpOption.ADC12_Cmd1));
    ASSERT(IS_ADC_CMP_MODE_VALID(ADC12_InitT->ADC12_CmpOption.ADC12_Cmpen));		
    /* Set Scan Function */
    ADC12_Reg[ADC12_Unit]->SCCR = ((ADC12_InitT->ADC12_ScanMode << 2) | SCCR_SFCLR); 
    //Clear FIFO Status, set scan mode, scan timer or sw select

    /* Set Scan Start Trigger */   
    ADC12_Reg[ADC12_Unit]->SCTSL = ADC12_InitT->ADC12_StartTimerTrigMode;


    /*Comparison time */
    ADC12_Reg[ADC12_Unit]->ADCT = ADC12_InitT->ADC12_CmpDiv;

    /*Set Scan FIFO Size  */	
    ADC12_Reg[ADC12_Unit]->SFNS = ADC12_InitT->ADC12_FIFOStage;

    /*Set Scan Placement way  */	
    ADC12_Reg[ADC12_Unit]->ADSR |= (ADC12_InitT->ADC12_DataSide<<6);

	
    /* Set Sampling Time */

    ADC12_Reg[ADC12_Unit]->ADST0 = ((ADC12_InitT->ADC12_SampleTimeN.ADC12_SampleTimeN0) | 
	   	ADC12_InitT->ADC12_SampleTime.ADC12_SampleTime0);

    ADC12_Reg[ADC12_Unit]->ADST1 = ((ADC12_InitT->ADC12_SampleTimeN.ADC12_SampleTimeN1 ) |
	   	ADC12_InitT->ADC12_SampleTime.ADC12_SampleTime1);


    /* Set Compare Function */
    if(ADC12_InitT->ADC12_CmpOption.ADC12_Cmpen == ADC12_CMP_ENABLE)
    {
        ADC12_Reg[ADC12_Unit]->CMPCR = ((ADC12_InitT->ADC12_CmpOption.ADC12_Cmpen << 7) |
            (ADC12_InitT->ADC12_CmpOption.ADC12_Cmd1  << 6) | 
            (ADC12_InitT->ADC12_CmpOption.ADC12_Cmd0 << 5));	
        ADC12_Reg[ADC12_Unit]->CMPD = ADC12_InitT->ADC12_CmpOption.ADC12_CmpVal;
    }
    else
    {
        ADC12_Reg[ADC12_Unit]->CMPCR = 0x0000;
    }
    /*Set Scan Conversion Enable */
    if(ADC12_InitT->ADC12_Option == ADC12_ENABLE)
    {
        ADC12_Reg[ADC12_Unit]->ADCEN |= ADC12_OPTION_MODE;   // enable
    }
    else
    {
        ADC12_Reg[ADC12_Unit]->ADCEN &=ADC12_STOP_MODE;   // disable
    }

    ADC12_IrqCallback[ADC12_Unit] =  ADC12_InitT->ADC12_ConfigIrqCallback;
    return;
}
/*!
 ******************************************************************************
 ** \brief Channel select for ADC 
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2
 ** \param ADC12_InitT config scan mode
 ** \arg   
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ChannelSelect(ADC12_UnitT ADC12_Unit,ADC12_Config *ADC12_InitT)
{
    uint16_t i;
    uint16_t ch;

    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    ASSERT(IS_ADC_CH_VALID(ADC12_InitT->ADC12_Ch));
    ASSERT(IS_ADC_SAMPEL_TIME_SEL_VALID(ADC12_InitT->ADC12_SampleTimeSelReg));

    ASSERT(IS_ADC_CMP_MODE_VALID(ADC12_InitT->ADC12_CmpOption.ADC12_Cmpen));
		
    ch = ADC12_InitT->ADC12_Ch;
    for(i=0; i< 31; i++)
    {
        if((ch >> i) == 1)
        break ;
    }
    /* Set Input Channel to SCAN */
    if(ADC12_InitT->ADC12_Ch < AN08)
    {
        ADC12_Reg[ADC12_Unit]->SCIS0 |= (uint8_t)(ADC12_InitT->ADC12_Ch & 
            0x000000FF);
    }
    else if(ADC12_InitT->ADC12_Ch < AN16)
    {
        ADC12_Reg[ADC12_Unit]->SCIS1 |= (uint8_t)((ADC12_InitT->ADC12_Ch >> 8) &
            0x000000FF);
    }
    else if(ADC12_InitT->ADC12_Ch < AN24)
    {
        ADC12_Reg[ADC12_Unit]->SCIS2 |= (uint8_t)((ADC12_InitT->ADC12_Ch >> 16) &
             0x000000FF);
    }
    else if(ADC12_InitT->ADC12_Ch <= AN31)
    {
        ADC12_Reg[ADC12_Unit]->SCIS3 |= (uint8_t)((ADC12_InitT->ADC12_Ch >> 24) &
            0x000000FF);
    }
    /* Set Input Channel to Comparison  */
    if(ADC12_InitT->ADC12_CmpOption.ADC12_Cmpen == ADC12_CMP_ENABLE)
    {
        ADC12_Reg[ADC12_Unit]->CMPCR |= i;
    }

    /* Set Input Channel to Sampling Time Selection  */
    if(ADC12_InitT->ADC12_Ch < AN16)
    {

        if(ADC12_InitT->ADC12_SampleTimeSelReg == ADC12_SAMPLE_TIME_SEL_REG0)
        {
            ADC12_Reg[ADC12_Unit]->ADSS01 &= (~ADC12_InitT->ADC12_Ch);
        }
        else
        {
            ADC12_Reg[ADC12_Unit]->ADSS01 |= ADC12_InitT->ADC12_Ch;
        }
    }
    else if(ADC12_InitT->ADC12_Ch >= AN16)
    {

        if(ADC12_InitT->ADC12_SampleTimeSelReg == ADC12_SAMPLE_TIME_SEL_REG0)
        {
	        ADC12_Reg[ADC12_Unit]->ADSS23 &= (~(ADC12_InitT->ADC12_Ch>>16));
        }
        else
        {
            ADC12_Reg[ADC12_Unit]->ADSS23 |= (ADC12_InitT->ADC12_Ch>>16);
        }
    }

    return;
}

/*!
 ******************************************************************************
 ** \brief start scan adc
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2  
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ScanStart(ADC12_UnitT ADC12_Unit)

{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /* Check ScanTrgTim */
    ADC12_Reg[ADC12_Unit]->SCCR |= SCCR_SSTR;	

    return;
}

/*!
 ******************************************************************************
 ** \brief Scan conversion timer start enable
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ScanTimerEnable(ADC12_UnitT ADC12_Unit)

{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));;
    /* Check ScanTrgTim */
    ADC12_Reg[ADC12_Unit]->SCCR |= SCCR_SHEN;

    return;
}

/*!
 ******************************************************************************
 ** \brief Scan conversion timer start disable
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2 
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ScanTimerDisable(ADC12_UnitT ADC12_Unit)

{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));

    /* Check ScanTrgTim */
    ADC12_Reg[ADC12_Unit]->SCCR &= ~SCCR_SHEN;

    return;
}
/*!
 ******************************************************************************
 ** \brief clear fifo for scan mode
 ** \param ADC12_Unit config scan mode
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ClrScanFIFO(ADC12_UnitT ADC12_Unit)

{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Clear Data in FIFO*/
    ADC12_Reg[ADC12_Unit]->SCCR |= SCCR_SFCLR;		
    return;
}

/*!
 ******************************************************************************
 ** \brief interrupt enable for  ADC 12 bit 
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2
 ** \param ADC12_Irq ADC interrupt enable type
 ** \arg   ADC12_SCAN_CONVERSION 		
 ** \arg 	ADC12_PRIORITY_CONVERSION 
 ** \arg 	ADC12_CMP_CONVERSION              
 ** \arg 	ADC12_FIFO_OVERRUN 
 **
 ** \retval None
 **
 ******************************************************************************
 */

void ADC12_IrqEnable(ADC12_UnitT ADC12_Unit, ADC12_IrqT ADC12_Irq)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    ASSERT(IS_ADC_IRQ_MODE_VALID(ADC12_Irq));
	 
    /*Interrupt enable*/
    ADC12_Reg[ADC12_Unit]->ADCR|= ADC12_Irq;	
    return;	
}


/*!
 ******************************************************************************
 ** \brief interrupt disable for  ADC 12 bit scan mode
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2
 ** \param ADC12_Irq config scan mode
 ** \arg   ADC12_SCAN_CONVERSION
 ** \arg   ADC12_PRIORITY_CONVERSION
 ** \arg   ADC12_CMP_CONVERSION
 ** \arg   ADC12_FIFO_OVERRUN
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_IrqDisable(ADC12_UnitT ADC12_Unit, ADC12_IrqT ADC12_Irq)
{

    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    ASSERT(IS_ADC_IRQ_MODE_VALID(ADC12_Irq));
    /*Interrupt disable*/
    ADC12_Reg[ADC12_Unit]->ADCR &= ~ADC12_Irq;
    return;
}

/*!
 ******************************************************************************
 ** \brief forbid stop ADC
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2 
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_Abort(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*forbid conversion*/
    ADC12_Reg[ADC12_Unit] ->ADSR |= ADSR_ADSTP;
    return;
}

/*!
 ******************************************************************************
 ** \brief  stop ADC
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_Stop(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Stop conversion in repeat mode*/
    ADC12_Reg[ADC12_Unit] ->SCCR &= ~(SCCR_RPT);
    return;
}

/*!
 ******************************************************************************
 ** \brief  Read Scan conversion FIFO empty bit
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval SET FIFO is empty.
 ** \retval RESET Data remains in FIFO
 **
 ******************************************************************************
 */
FlagStatusT ADC12_ScanEmptyFlag(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    if((ADC12_Reg[ADC12_Unit] ->SCCR & SCCR_SEMP)== SCCR_SEMP)
    {
        return SET;
    }
    else
    {
        return RESET;      
    }
}

/*!
 ******************************************************************************
 ** \brief  Read Scan conversion FIFO full bit
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval SET FIFO is full.
 ** \retval RESET Data can be input to FIFO.
 **
 ******************************************************************************
 */
FlagStatusT ADC12_ScanFifoFullFlag(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    if((ADC12_Reg[ADC12_Unit] ->SCCR & SCCR_SFUL)== SCCR_SFUL)
    {
        return SET;
    }
    else
    {
        return RESET;      
    }
}

/*!
 ******************************************************************************
 ** \brief  Clear Scan Overrun flag
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ScanOverrunFlagClr(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    ADC12_Reg[ADC12_Unit] ->SCCR &= ~SCCR_SOVR;
    return;
 
}

/*!
 ******************************************************************************
 ** \brief  Clear Scan conversion interrupt request
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_ScanIntReqClr(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    ADC12_Reg[ADC12_Unit] ->ADCR &= ~ADCR_SCIF;
    return;
 
}
/*!
 ******************************************************************************
 ** \brief  Clear Priority conversion interrupt request
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_PriorityIntReqClr(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    ADC12_Reg[ADC12_Unit] ->ADCR &= ~ADCR_PCIF;
    return;
 
}
/*!
 ******************************************************************************
 ** \brief  Clear Conversion result comparison interrupt request
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC12_CmpIntReqClr(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    ADC12_Reg[ADC12_Unit] ->ADCR &= ~ADCR_CMPIF;
    return;
 
}
/*!
 ******************************************************************************
 ** \brief  Read Scan conversion overrun flag
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2   
 **
 ** \retval SET Overrun has occurred.
 ** \retval RESET No overrun has occurred.
 **
 ******************************************************************************
 */
FlagStatusT ADC12_ScanOverrunFlag(ADC12_UnitT ADC12_Unit)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    /*Read Scan conversion FIFO empty bit*/
    if((ADC12_Reg[ADC12_Unit] ->SCCR & SCCR_SOVR)== SCCR_SOVR)
    {
        return SET;
    }
    else
    {
        return RESET;      
    }
}
/*!
 ******************************************************************************
 ** \brief  read A/D data from register
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2  
 ** \param ADC12_Info save ADC FIFO info
 ** \param ADC12_Data save ADC FIFO data 
 ** \param ADC12_Stage stage of FIFO data 
 ** \retval SET: read OK
 **
 ******************************************************************************
 */
FlagStatusT ADC12_Read(ADC12_UnitT ADC12_Unit, uint16_t *ADC12_Info, 
                        uint16_t *ADC12_Data, uint16_t *ADC12_Stage)
{
      
    uint16_t ADC12_Cont;
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));

    ADC12_FIFOInfo[ADC12_Unit].ADC12_FIFOData = ADC12_Data;
    ADC12_FIFOInfo[ADC12_Unit].ADC12_FIFODataInfo = ADC12_Info;
    ADC12_FIFOInfo[ADC12_Unit].ADC12_FIFOStage = ADC12_Stage;
        
    /*Read FIFO Data*/
    for(ADC12_Cont = 0; ADC12_Cont<ADC12_FIFOInfo[ADC12_Unit].ADC12_FIFOStage[0]; 
        ADC12_Cont++)
    {
        if((ADC12_Reg[ADC12_Unit]->SCFDL & SCFDL_INVL) == 0)
        {        
            ADC12_FIFOInfo[ADC12_Unit].ADC12_FIFODataInfo[ADC12_Cont] = ADC12_Reg[ADC12_Unit]->SCFDL;
            ADC12_FIFOInfo[ADC12_Unit].ADC12_FIFOData[ADC12_Cont] = ADC12_Reg[ADC12_Unit]->SCFDH;
        }
        else 
        {
            return RESET;  
        }

    }
    
    return SET;
}

/*!
 ******************************************************************************
 ** \brief  read status busy or not
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2  
 **
 ** \retval SET conversion enable success
 ** \retval RESET conversion enable fail
 **
 ******************************************************************************
 */
FlagStatusT  ADC12_ReadOptionStatus(ADC12_UnitT ADC12_Unit)
{

    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    if((( ADC12_Reg[ADC12_Unit]->ADCEN)& 0x0002) == 0x0002)
    {
        return SET;
    }
    else
    {
        return RESET;
    }

}


/*!
 ******************************************************************************
 ** \brief  conversion status 
 **
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2  
 ** \param ADC12_CovStatus ADC conversion status
 ** \arg  ADC12_SCAN_FINISH 
 ** \arg   ADC12_PRIORITY_FINISH 
 ** \arg   ADC12_PRIORITY_PENDING 
 ** \arg    ADC12_CMP_COV_FLAG 
 ** \arg   ADC12_PRIORITY_COV_FLAG 
 ** \arg   ADC12_SCAN_COV_FLAG 
 ** \retval SET conversion in progress
 ** \retval RESET conversion stop
 **
 ******************************************************************************
 */
FlagStatusT  ADC12_ConversionStatus(ADC12_UnitT ADC12_Unit, 
                                    ADC12_ConversionStatusT ADC12_CovStatus)
{
    /* Check the parameter */
    ASSERT(IS_ADC_UNIT_VALID(ADC12_Unit));
    ASSERT(IS_ADC_COV_STATUS_VALID(ADC12_CovStatus));
    if(ADC12_CovStatus > 0x0f)
    {
        if((( ADC12_Reg[ADC12_Unit]->ADCR)& ADC12_CovStatus)!= 
            ADC12_CovStatus)
        {
            return RESET;
        }
        else
        {
            return SET;
        }
    
    }
    else
    {
        if((( ADC12_Reg[ADC12_Unit]->ADSR& ADC12_CovStatus)!= 
            ADC12_CovStatus))
        {
            return RESET;
        }
        else
        {
            return SET;
        }

    }

}

/*!
 ******************************************************************************
 ** \brief ADC 0 interrupt handler 
 ** 
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC0_IRQHandler(void)
{
    uint8_t irq;
    
    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint8_t)(FM3_INTREQ->IRQ25MON & 0x0000000FU);
    
    ADC12_IrqHandler(ADC_UNIT0, irq);
}

/*!
 ******************************************************************************
 ** \brief ADC 1 interrupt handler 
 ** 
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC1_IRQHandler(void)
{
    uint8_t irq;
    
    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint8_t)(FM3_INTREQ->IRQ26MON & 0x0000000FU);
    
    ADC12_IrqHandler(ADC_UNIT1, irq);
}

/*!
 ******************************************************************************
 ** \brief ADC 2 interrupt handler 
 ** 
 **
 ** \retval None
 **
 ******************************************************************************
 */
void ADC2_IRQHandler(void)
{
    uint8_t irq;
    
    /* deviation from MISRA-C:2004 Rule 11.3 */
    irq = (uint8_t)(FM3_INTREQ->IRQ27MON & 0x0000000FU);
    
    ADC12_IrqHandler(ADC_UNIT2, irq);
}

/*!
 ******************************************************************************
 ** \brief ADC interrupt handler 
 ** 
 ** \param ADC12_Unit set ADC unit
 ** \arg   ADC_UNIT0
 ** \arg   ADC_UNIT1
 ** \arg   ADC_UNIT2  
 ** \param Irq interrupt request
 **        This parameter can be one of the following values:
 ** \arg   
 ** \retval None
 **
 ******************************************************************************
 */
static void ADC12_IrqHandler(ADC12_UnitT ADC12_Unit, uint8_t Irq)
{

	
    /* SCAN Converter Interrupt */
    if((Irq & 0x02U) != 0)
    {
        if(ADC12_IrqCallback[ADC12_Unit]  != NULL)
        {
            /* Clear Interrupt */
            ADC12_Reg[ADC12_Unit]->ADCR &= ~(ADCR_SCIF);
            /* Call CallBackIrq */
            ADC12_IrqCallback[ADC12_Unit] (Adc12_IRQSTATUS_SCAN);

        }

    }
	
    /* PRI Converter Interrupt */
    if((Irq & 0x01U) != 0) 
    {  
        if(ADC12_IrqCallback[ADC12_Unit] != NULL) 
        {
            /* Call CallBackIrq */
            ADC12_IrqCallback[ADC12_Unit](Adc12_IRQSTATUS_PRI);
        }
        /* Clear Interrupt */
        ADC12_Reg[ADC12_Unit]->ADCR  &= ~(ADCR_PCIF);
    }

    /* Over run Interrupt */
    if((Irq & 0x04U) != 0) 
    {  
        /* Check interrupt */
        if((ADC12_Reg[ADC12_Unit]->SCCR & SCCR_SOVR) != 0)
        {
            /* Clear Interrupt */
            ADC12_Reg[ADC12_Unit]->SCCR = (ADC12_Reg[ADC12_Unit]->SCCR &
                                        ~(SCCR_SOVR));
            
            if(ADC12_IrqCallback[ADC12_Unit]  != NULL) 
	        {
                /* Call CallBackIrq */
                ADC12_IrqCallback[ADC12_Unit] (Adc12_IRQSTATUS_SOVR);
            }
        }
        
        if((ADC12_Reg[ADC12_Unit]->PCCR & PCCR_POVR) != 0)
        {
            /* Clear Interrupt */
            ADC12_Reg[ADC12_Unit]->PCCR = (ADC12_Reg[ADC12_Unit]->PCCR &
                                        ~(PCCR_POVR));
            
            if (ADC12_IrqCallback[ADC12_Unit]  != NULL) 
            {
                /* Call CallBackIrq */
                ADC12_IrqCallback[ADC12_Unit] (Adc12_IRQSTATUS_POVR);
            }
        }
    }
	
    /* Compare Interrupt */
    if ((Irq & 0x08U) != 0) 
    { 
        /* Clear Interrupt */
        ADC12_Reg[ADC12_Unit]->ADCR &= ~(ADCR_CMPIF);
        
        if (ADC12_IrqCallback[ADC12_Unit]  != NULL) 
	    {
            /* Call CallBackIrq */
            ADC12_IrqCallback[ADC12_Unit] (Adc12_IRQSTATUS_COMP);
        }
    }
}
/*****************************************************************************/

/* END OF FILE */

