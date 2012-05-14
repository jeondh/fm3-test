/*!
 ******************************************************************************
 **
 ** \file main.c
 **
 ** \brief Basetimer sample code.
 **
 ** \author FSLA AE Team 
 **
 ** \version V0.1
 **
 ** \date 2011-11-10
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
#include <stdint.h>

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/
extern void ExamplePwm(void);
extern void ExamplePwc(void);
extern void ExamplePpg(void);
extern void ExampleRt(void);



/*
 ******************************************************************************
 ** \brief Example main function
 ******************************************************************************
 */
void main(void)
{     
    //ExamplePwm();
    //ExamplePpg();
    ExampleRt();
    //ExamplePwc();    

    while(1);
}

/*
 ******************************************************************************
 ** \brief Delay requested secondes approximately
 **
 ** \param Sec Requested secondes
 ******************************************************************************
 */
void Delay(uint8_t Sec)
{
    int32_t i,j;
    
   
    if (SystemCoreClock == 80000000UL)
    {
        j = Sec*12500000UL;
    }
    else if (SystemCoreClock == 4000000UL)
    {
        j = Sec*625000UL;
    }
    else if(SystemCoreClock == 100000UL)
    {
        j = Sec*15600UL;
    }
    else if(SystemCoreClock == 32768UL)
    {    
        j = Sec*5120UL;
    }
  
   
    i = 0;
    while (1) 
    {
        i++;
        if (i > j) 
        {
            break;
        }
    }   
}

/*****************************************************************************/
/* END OF FILE */
