/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \brief Clock supervisor example code
 **
 ** Add here more detailed description if needed ...
 **
 ** \author FSLA AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-12-30
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
#include "mb9bf50x_lib.h"


/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void ExampleCSVSubReset(void); 
static void ExampleCSVMainReset(void);
static void ExampleFCSReset(void);
static void ExampleFCSIntQuery(void);
static void ExampleFCSInt(void);

static void HWWdtDisable(void);
static void CRTrimSet(void);

/*
 ******************************************************************************
 ** \brief Clock supervisor mode main function
 ******************************************************************************
 */
void main(void)
{        
	
    uint16_t ResetCause = 0;
    uint16_t CSVCause = 0; 
    
    HWWdtDisable();
    CRTrimSet();
    
    CSV_MainCSVDisable();    
    CSV_SubCSVDisable();   
    
    /* Read causes of resets, reading the register clears all bits */
    ResetCause = FM3_CRG->RST_STR;    
    CSVCause = CSV_GetCSVFailCause();
    
    /* Anomalous Frequency Detection(FCS) reset is generated */
    if ((ResetCause & 0x0080) == 0x0080)
    {
        #ifdef DEBUG_MODE 
        printf("Anomalous Frequency Detection(FCS) reset is generated.\n");
        printf("Frequency detection counter value: %d\n", CSV_GetFCSDetectCount());
        #endif
    }    
    /* Clock Failure Detection(CSV) reset is generated */    
    if ((ResetCause & 0x0040) == 0x0040)
    {
        /* Sub Clock Failure Detection(CSV) reset is generated.*/
        if ((CSVCause & CSV_SUB_FAIL) == CSV_SUB_FAIL) 
        { 
            #ifdef DEBUG_MODE 
            printf("Sub Clock Failure Detection(CSV) reset is generated.\n");
            #endif  
        }
        /* Main Clock Failure Detection(CSV) reset is generated */
        
        if ((CSVCause & CSV_MAIN_FAIL) == CSV_MAIN_FAIL)
        {  
            #ifdef DEBUG_MODE 
            printf("Main Clock Failure Detection(CSV) reset is generated.\n");
            #endif    
        }
        
        if (CSVCause == 0)
        {
            #ifdef DEBUG_MODE 
            ASSERT(0);
            #endif
        }
    } 
    
    /* FCS and CSV reset are not generated */
    if ((ResetCause & 0x00c0) == 0) 
    {  
        #ifdef DEBUG_MODE 
        printf("==================================================\n");
        printf("Clock supervisor example start\n");
        printf("==================================================\n");
        #endif  
        
        SystemInit();
        //ExampleCSVSubReset(); 
        //ExampleCSVMainReset();
        //ExampleFCSReset();
        //ExampleFCSIntQuery();
        ExampleFCSInt();
        

        while(1)
        {;}
    
    } 
    #ifdef DEBUG_MODE 
    printf("==================================================\n");
    printf("Clock supervisor example end\n");
    printf("==================================================\n");
    #endif  
    while(1){;}
    
}


/*
 ******************************************************************************
 ** \brief CSV Irq handler
 ******************************************************************************
 */
void CSV_Handler(void)
{
    CSV_ClrFCSIntRequest();
 
    // >>> user code
    #ifdef DEBUG_MODE 
    printf("Anomalous Frequency Detection(FCS) interrupt is generated.\n");
    printf("Frequency detection counter value: %d\n", CSV_GetFCSDetectCount());
    #endif  
}

/*!
 ******************************************************************************
 ** \brief Example code for sub reset function
 ******************************************************************************
 */
static void ExampleCSVSubReset(void) 
{
    CSV_SubCSVEnable();     
}

/*!
 ******************************************************************************
 ** \brief Example code for CSV main reset function
 ******************************************************************************
 */
static void ExampleCSVMainReset(void)
{
    CSV_MainCSVEnable();    
}

/*!
 ******************************************************************************
 ** \brief Example code for FCS reset function
 ******************************************************************************
 */
static void ExampleFCSReset(void)
{
    CSV_SetFCSCycle(FCS_CYCLE_1024); 
    
    /* normal setting */
    CSV_SetFCSDetectLower(926);    
    CSV_SetFCSDetectUpper(1131); 
    
    /* abnormal setting */
    //CSV_SetFCSDetectLower(1021);    
    //CSV_SetFCSDetectUpper(1022); 
    
    CSV_FCSEnable();   
    CSV_FCSResetEnable();        
     
}

/*!
 ******************************************************************************
 ** \brief Example code for FCS interrupt query function
 ******************************************************************************
 */
static void ExampleFCSIntQuery(void)
{
    CSV_SetFCSCycle(FCS_CYCLE_1024);  
    
    /* normal setting */
    //CSV_SetFCSDetectLower(926);    
    //CSV_SetFCSDetectUpper(1131); 
    
    /* abnormal setting */
    CSV_SetFCSDetectLower(1021);    
    CSV_SetFCSDetectUpper(1022);  
    
    CSV_FCSEnable(); 
    CSV_FCSResetDisable();
    CSV_FCSIntEnable();    
     
    while(1)
    {
        if (CSV_GetFCSIntRequest() == 1) 
        {
            CSV_ClrFCSIntRequest();
            #ifdef DEBUG_MODE 
            printf("Anomalous Frequency Detection(FCS) interrupt request is generated.\n");
            printf("Frequency detection counter value: %d\n", CSV_GetFCSDetectCount());
            #endif
        }
    }       
}


/*!
 ******************************************************************************
 ** \brief Example code for FCS interrupt function
 ******************************************************************************
 */
static void ExampleFCSInt(void)
{
    NVIC_EnableIRQ(CSV_IRQn);
    CSV_SetFCSCycle(FCS_CYCLE_1024); 
    
    /* normal setting */
    //CSV_SetFCSDetectLower(926);    
    //CSV_SetFCSDetectUpper(1131); 
    
    /* abnormal setting */
    CSV_SetFCSDetectLower(1021);    
    CSV_SetFCSDetectUpper(1022);  
    
    CSV_FCSEnable();       
    CSV_FCSResetDisable();
    CSV_FCSIntEnable();   
    
}


/*
 *  Stop HW Watchdog Timer
 */
static void HWWdtDisable(void)
{
    FM3_HWWDT->WDG_LCK = 0x1ACCE551;                 /* HW Watchdog Unlock */
    FM3_HWWDT->WDG_LCK = 0xE5331AAE;
    FM3_HWWDT->WDG_CTL = 0;                          /* HW Watchdog stop */
}

/*
/ *  Set CR Trimming Data
 */
static void CRTrimSet(void)
{

  if( 0x000003FF != (FM3_FLASH_IF->CRTRMM & 0x000003FF) )
  {
    /* UnLock (MCR_FTRM) */
    FM3_CRTRIM->MCR_RLR = 0x1ACCE554;
    /* Set MCR_FTRM */
    FM3_CRTRIM->MCR_FTRM = FM3_FLASH_IF->CRTRMM;
    /* Lock (MCR_FTRM) */
    FM3_CRTRIM->MCR_RLR = 0x00000000;
  }
}



/*****************************************************************************/
/* END OF FILE */


