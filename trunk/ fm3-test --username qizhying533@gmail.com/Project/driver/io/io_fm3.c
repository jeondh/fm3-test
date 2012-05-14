/*!
 ******************************************************************************
 **
 ** \file io_fm3.c
 **
 ** \brief IO driver
 **
 ** 
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-18
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
#include "Io_fm3.h"

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global data                                                               */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* global functions                                                          */
/*---------------------------------------------------------------------------*/




/*!
 ******************************************************************************
 ** \brief Configure IO port  
 **
 ** \param ioport IO port number 
 ** \arg GPIO_PORT0
 ** \arg GPIO_PORT1
 ** \arg GPIO_PORT2
 ** \arg GPIO_PORT3
 ** \arg GPIO_PORT4
 ** \arg GPIO_PORT5
 ** \arg GPIO_PORT6
 ** \arg GPIO_PORT7
 ** \arg GPIO_PORT8
 **       
 ** \param iopin  IO pin number 
 ** \arg GPIO_ALL_PIN
 ** \arg GPIO_PIN_0
 ** \arg GPIO_PIN_1
 ** \arg GPIO_PIN_2
 ** \arg GPIO_PIN_3
 ** \arg GPIO_PIN_4
 ** \arg GPIO_PIN_5
 ** \arg GPIO_PIN_6
 ** \arg GPIO_PIN_7
 ** \arg GPIO_PIN_8
 ** \arg GPIO_PIN_9
 ** \arg GPIO_PIN_A
 ** \arg GPIO_PIN_B
 ** \arg GPIO_PIN_C
 ** \arg GPIO_PIN_D
 ** \arg GPIO_PIN_E
 ** \arg GPIO_PIN_F
 **
 ** \param  iomode IO mode 
 ** \arg IO_GPIO_MODE
 ** \arg IO_PERIPHERAL_MODE
 ** \retval None
 **
 ******************************************************************************
 */
void IO_ConfigPort(uint8_t ioport, uint32_t iopin, uint8_t iomode)
{
    /* Check the parameter */
    ASSERT (IS_IO_MODE(iomode));
    ASSERT (IS_GPIO_PORT(ioport));
    ASSERT (IS_GPIO_PIN(iopin));
	
    if(iomode == IO_PERIPHERAL_MODE)
    {
        switch(ioport)
    	{
    	    case GPIO_PORT0: 
    	        FM3_GPIO->PFR0 |= iopin;  
    	        break;
    	    case GPIO_PORT1:
    	        FM3_GPIO->PFR1 |= iopin; 
    	        FM3_GPIO->ADE &= ~iopin;
    	    	break;
    	    case GPIO_PORT2:
    	        FM3_GPIO->PFR2 |= iopin; 
    	        break;
    	    case GPIO_PORT3:
    	        FM3_GPIO->PFR3 |= iopin; 
    	        break;
    	    case GPIO_PORT4:
    	        FM3_GPIO->PFR4 |= iopin; 
    	        break;
    	    case GPIO_PORT5:
    	        FM3_GPIO->PFR5 |= iopin; 
    	        break;
    	    case GPIO_PORT6:
    	        FM3_GPIO->PFR6 |= iopin; 
    	        break;
    	    case GPIO_PORT7:
    	        FM3_GPIO->PFR7 |= iopin; 
    	        break;
    	    case GPIO_PORT8:
    	        FM3_GPIO->PFR8 |= iopin; 
    	        break;

    	    default: 
    	        break;
    	}

    }
    else
    {
    	switch(ioport)
    	{
    	    case GPIO_PORT0: 
    	        FM3_GPIO->PFR0 &= ~ iopin;  
    	        break;
    	    case GPIO_PORT1:
    	        FM3_GPIO->PFR1 &= ~ iopin; 
    	        FM3_GPIO->ADE &= ~iopin;
    	    	break;
    	    case GPIO_PORT2:
    	        FM3_GPIO->PFR2 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT3:
    	        FM3_GPIO->PFR3 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT4:
    	        FM3_GPIO->PFR4 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT5:
    	        FM3_GPIO->PFR5 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT6:
    	        FM3_GPIO->PFR6 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT7:
    	        FM3_GPIO->PFR7 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT8:
    	        FM3_GPIO->PFR8 &= ~ iopin; 
    	        break;

    	    default: 
    	        break;
    	}

    }
}



/*!
 ******************************************************************************
 ** \brief Set GPIO as input  
 **
 ** \param ioport IO port number 
 ** \arg GPIO_PORT0
 ** \arg GPIO_PORT1
 ** \arg GPIO_PORT2
 ** \arg GPIO_PORT3
 ** \arg GPIO_PORT4
 ** \arg GPIO_PORT5
 ** \arg GPIO_PORT6
 ** \arg GPIO_PORT7
 ** \arg GPIO_PORT8
 **       
 ** \param iopin  IO pin number 
 ** \arg GPIO_ALL_PIN
 ** \arg GPIO_PIN_0
 ** \arg GPIO_PIN_1
 ** \arg GPIO_PIN_2
 ** \arg GPIO_PIN_3
 ** \arg GPIO_PIN_4
 ** \arg GPIO_PIN_5
 ** \arg GPIO_PIN_6
 ** \arg GPIO_PIN_7
 ** \arg GPIO_PIN_8
 ** \arg GPIO_PIN_9
 ** \arg GPIO_PIN_A
 ** \arg GPIO_PIN_B
 ** \arg GPIO_PIN_C
 ** \arg GPIO_PIN_D
 ** \arg GPIO_PIN_E
 ** \arg GPIO_PIN_F
 **
 ** \retval None
 **
 ******************************************************************************
 */
void IO_GPIOSetInput(uint8_t ioport, uint32_t iopin)
{
    /* Check the parameter */
    ASSERT (IS_GPIO_PORT(ioport));
    ASSERT (IS_GPIO_PIN(iopin));
	
    IO_ConfigPort(ioport, iopin, IO_GPIO_MODE);
    switch(ioport)
    {
        case GPIO_PORT0: 
    	     FM3_GPIO->DDR0 &= ~ iopin;  
    	     break;
    	case GPIO_PORT1:
    	     FM3_GPIO->DDR1 &= ~ iopin; 
    	     break;
    	case GPIO_PORT2:
    	     FM3_GPIO->DDR2 &= ~ iopin; 
    	     break;
    	case GPIO_PORT3:
    	     FM3_GPIO->DDR3 &= ~ iopin; 
    	     break;
    	case GPIO_PORT4:
    	     FM3_GPIO->DDR4 &= ~ iopin; 
    	     break;
    	case GPIO_PORT5:
    	     FM3_GPIO->DDR5 &= ~ iopin; 
    	     break;
    	case GPIO_PORT6:
    	     FM3_GPIO->DDR6 &= ~ iopin; 
    	     break;
    	case GPIO_PORT7:
    	     FM3_GPIO->DDR7 &= ~ iopin; 
    	     break;
    	case GPIO_PORT8:
    	     FM3_GPIO->DDR8 &= ~ iopin; 
    	     break;

    	default: 
    	     break;
    	}
    return;	
	
}


/*!
 ******************************************************************************
 ** \brief Set GPIO as output 
 **
 ** \param ioport IO port number 
 ** \arg GPIO_PORT0
 ** \arg GPIO_PORT1
 ** \arg GPIO_PORT2
 ** \arg GPIO_PORT3
 ** \arg GPIO_PORT4
 ** \arg GPIO_PORT5
 ** \arg GPIO_PORT6
 ** \arg GPIO_PORT7
 ** \arg GPIO_PORT8
 **       
 ** \param iopin  IO pin number 
 ** \arg GPIO_ALL_PIN
 ** \arg GPIO_PIN_0
 ** \arg GPIO_PIN_1
 ** \arg GPIO_PIN_2
 ** \arg GPIO_PIN_3
 ** \arg GPIO_PIN_4
 ** \arg GPIO_PIN_5
 ** \arg GPIO_PIN_6
 ** \arg GPIO_PIN_7
 ** \arg GPIO_PIN_8
 ** \arg GPIO_PIN_9
 ** \arg GPIO_PIN_A
 ** \arg GPIO_PIN_B
 ** \arg GPIO_PIN_C
 ** \arg GPIO_PIN_D
 ** \arg GPIO_PIN_E
 ** \arg GPIO_PIN_F
 **
 ** \retval None
 **
 ******************************************************************************
 */
void IO_GPIOSetOutput(uint8_t ioport, uint32_t iopin)
{
    /* Check the parameter */
    ASSERT (IS_GPIO_PORT(ioport));
    ASSERT (IS_GPIO_PIN(iopin));
    
    IO_ConfigPort(ioport, iopin, IO_GPIO_MODE);
    switch(ioport)
    {
        case GPIO_PORT0: 
    	     FM3_GPIO->DDR0 |=  iopin;  
    	     break;
    	case GPIO_PORT1:
    	     FM3_GPIO->DDR1 |=  iopin; 
    	     break;
    	case GPIO_PORT2:
    	     FM3_GPIO->DDR2 |=  iopin; 
    	     break;
    	case GPIO_PORT3:
    	     FM3_GPIO->DDR3 |=  iopin; 
    	     break;
    	case GPIO_PORT4:
    	     FM3_GPIO->DDR4 |=  iopin; 
    	     break;
    	case GPIO_PORT5:
    	     FM3_GPIO->DDR5 |=  iopin; 
    	     break;
    	case GPIO_PORT6:
    	     FM3_GPIO->DDR6 |=  iopin; 
    	     break;
    	case GPIO_PORT7:
    	     FM3_GPIO->DDR7 |=  iopin; 
    	     break;
    	case GPIO_PORT8:
    	     FM3_GPIO->DDR8 |=  iopin; 
    	     break;

    	default: 
    	     break;
    	}
    return;	
}

 
 
/*!
 ******************************************************************************
 ** \brief Read data from GPIO 
 **
 ** \param ioport IO port number 
 ** \arg GPIO_PORT0
 ** \arg GPIO_PORT1
 ** \arg GPIO_PORT2
 ** \arg GPIO_PORT3
 ** \arg GPIO_PORT4
 ** \arg GPIO_PORT5
 ** \arg GPIO_PORT6
 ** \arg GPIO_PORT7
 ** \arg GPIO_PORT8
 **       
 ** \param iopin  IO pin number 
 ** \arg GPIO_ALL_PIN
 ** \arg GPIO_PIN_0
 ** \arg GPIO_PIN_1
 ** \arg GPIO_PIN_2
 ** \arg GPIO_PIN_3
 ** \arg GPIO_PIN_4
 ** \arg GPIO_PIN_5
 ** \arg GPIO_PIN_6
 ** \arg GPIO_PIN_7
 ** \arg GPIO_PIN_8
 ** \arg GPIO_PIN_9
 ** \arg GPIO_PIN_A
 ** \arg GPIO_PIN_B
 ** \arg GPIO_PIN_C
 ** \arg GPIO_PIN_D
 ** \arg GPIO_PIN_E
 ** \arg GPIO_PIN_F
 **
 ** \retval Data read from GPIO
 **
 ******************************************************************************
 */ 
uint32_t IO_GPIOReadData(uint8_t ioport, uint32_t iopin)
{
    uint32_t data=0; 

    /* Check the parameter */
    ASSERT (IS_GPIO_PORT(ioport));
    ASSERT (IS_GPIO_PIN(iopin));
	
    if(iopin == GPIO_ALL_PIN)
    {    
        switch(ioport)
        {
            case GPIO_PORT0: 
    	        data = FM3_GPIO->PDIR0;  
    	        break;
    	    case GPIO_PORT1:
    	        data = FM3_GPIO->PDIR1; 
    	        break;
    	    case GPIO_PORT2:
    	        data = FM3_GPIO->PDIR2; 
    	        break;
    	    case GPIO_PORT3:
    	        data = FM3_GPIO->PDIR3; 
    	        break;
    	    case GPIO_PORT4:
    	        data = FM3_GPIO->PDIR4; 
    	        break;
    	    case GPIO_PORT5:
    	        data = FM3_GPIO->PDIR5; 
    	        break;
    	    case GPIO_PORT6:
    	        data = FM3_GPIO->PDIR6; 
    	        break;
    	    case GPIO_PORT7:
    	        data = FM3_GPIO->PDIR7; 
    	        break;
    	    case GPIO_PORT8:
    	        data = FM3_GPIO->PDIR8; 
    	        break;

    	    default: 
    	        break;
        	}
    	}
    else
    {
    	switch(ioport)
        {
            case GPIO_PORT0: 
    	        data = FM3_GPIO->PDIR0 & iopin;  
    	        break;
    	    case GPIO_PORT1:
    	        data = FM3_GPIO->PDIR1 & iopin; 
    	        break;
    	    case GPIO_PORT2:
    	        data = FM3_GPIO->PDIR2 & iopin; 
    	        break;
    	    case GPIO_PORT3:
    	        data = FM3_GPIO->PDIR3 & iopin; 
    	        break;
    	    case GPIO_PORT4:
    	        data = FM3_GPIO->PDIR4 & iopin; 
    	        break;
    	    case GPIO_PORT5:
    	        data = FM3_GPIO->PDIR5 & iopin; 
    	        break;
    	    case GPIO_PORT6:
    	        data = FM3_GPIO->PDIR6 & iopin; 
    	        break;
    	    case GPIO_PORT7:
    	        data = FM3_GPIO->PDIR7 & iopin; 
    	        break;
    	    case GPIO_PORT8:
    	        data = FM3_GPIO->PDIR8 & iopin; 
    	        break;

    	    default: 
    	        break;	
    	}
    }
    return data;	
}


/*!
 ******************************************************************************
 ** \brief Write data to GPIO 
 **
 ** \param ioport IO port number 
 ** \arg GPIO_PORT0
 ** \arg GPIO_PORT1
 ** \arg GPIO_PORT2
 ** \arg GPIO_PORT3
 ** \arg GPIO_PORT4
 ** \arg GPIO_PORT5
 ** \arg GPIO_PORT6
 ** \arg GPIO_PORT7
 ** \arg GPIO_PORT8
 **       
 ** \param iopin  IO pin number 
 ** \arg GPIO_ALL_PIN
 ** \arg GPIO_PIN_0
 ** \arg GPIO_PIN_1
 ** \arg GPIO_PIN_2
 ** \arg GPIO_PIN_3
 ** \arg GPIO_PIN_4
 ** \arg GPIO_PIN_5
 ** \arg GPIO_PIN_6
 ** \arg GPIO_PIN_7
 ** \arg GPIO_PIN_8
 ** \arg GPIO_PIN_9
 ** \arg GPIO_PIN_A
 ** \arg GPIO_PIN_B
 ** \arg GPIO_PIN_C
 ** \arg GPIO_PIN_D
 ** \arg GPIO_PIN_E
 ** \arg GPIO_PIN_F
 **
 ** \param  iodata Data written
 **
 ** \retval None
 **
 ******************************************************************************
 */ 
void IO_GPIOWriteData(uint8_t ioport, uint32_t iopin, uint32_t iodata)
{
    /* Check the parameter */
    ASSERT (IS_GPIO_PORT(ioport));
    ASSERT (IS_GPIO_PIN(iopin));
	
	
    if(iopin == GPIO_ALL_PIN)
    {    
        switch(ioport)
        {
            case GPIO_PORT0: 
    	        FM3_GPIO->PDOR0 = iodata;  
    	        break;
    	    case GPIO_PORT1:
    	        FM3_GPIO->PDOR1 = iodata; 
    	        break;
    	    case GPIO_PORT2:
    	        FM3_GPIO->PDOR2 = iodata;; 
    	        break;
    	    case GPIO_PORT3:
    	        FM3_GPIO->PDOR3 = iodata; 
    	        break;
    	    case GPIO_PORT4:
    	        FM3_GPIO->PDOR4 = iodata; 
    	        break;
    	    case GPIO_PORT5:
    	        FM3_GPIO->PDOR5 = iodata; 
    	        break;
    	    case GPIO_PORT6:
    	        FM3_GPIO->PDOR6 = iodata; 
    	        break;
    	    case GPIO_PORT7:
    	        FM3_GPIO->PDOR7 = iodata; 
    	        break;
    	    case GPIO_PORT8:
    	        FM3_GPIO->PDOR8 = iodata; 
    	        break;

    	    default: 
    	        break;
        	}
    	}
    else
    {
    	switch(ioport)
        {
            case GPIO_PORT0: 
				if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR0 |= iopin;
                else
                    FM3_GPIO->PDOR0 &= ~iopin;
    	        break;
    	    case GPIO_PORT1:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR1 |= iopin;
                else
                    FM3_GPIO->PDOR1 &= ~iopin;
    	        break;
    	    case GPIO_PORT2:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR2 |= iopin;
                else
                    FM3_GPIO->PDOR2 &= ~iopin; 
    	        break;
    	    case GPIO_PORT3:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR3 |= iopin;
                else
                    FM3_GPIO->PDOR3 &= ~iopin; 
    	        break;
    	    case GPIO_PORT4:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR4 |= iopin;
                else
                    FM3_GPIO->PDOR4 &= ~iopin; 
    	        break;
    	    case GPIO_PORT5:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR5 |= iopin;
                else
                    FM3_GPIO->PDOR5 &= ~iopin; 
    	        break;
    	    case GPIO_PORT6:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR6 |= iopin;
                else
                    FM3_GPIO->PDOR6 &= ~iopin; 
    	        break;
    	    case GPIO_PORT7:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR7 |= iopin;
                else
                    FM3_GPIO->PDOR7 &= ~iopin; 
    	        break;
    	    case GPIO_PORT8:
    	        if((iopin & iodata) == iopin )
                    FM3_GPIO->PDOR8 |= iopin;
                else
                    FM3_GPIO->PDOR8 &= ~iopin; 
    	        break;

    	    default: 
    	        break;	
    	}
    }
    return;        	
} 
 



/*!
 ******************************************************************************
 ** \brief Set IO port pull-up 
 **
 ** \param ioport IO port number 
 ** \arg GPIO_PORT0
 ** \arg GPIO_PORT1
 ** \arg GPIO_PORT2
 ** \arg GPIO_PORT3
 ** \arg GPIO_PORT4
 ** \arg GPIO_PORT5
 ** \arg GPIO_PORT6
 ** \arg GPIO_PORT7
 ** \arg GPIO_PORT8
 **       
 ** \param iopin  IO pin number 
 ** \arg GPIO_ALL_PIN
 ** \arg GPIO_PIN_0
 ** \arg GPIO_PIN_1
 ** \arg GPIO_PIN_2
 ** \arg GPIO_PIN_3
 ** \arg GPIO_PIN_4
 ** \arg GPIO_PIN_5
 ** \arg GPIO_PIN_6
 ** \arg GPIO_PIN_7
 ** \arg GPIO_PIN_8
 ** \arg GPIO_PIN_9
 ** \arg GPIO_PIN_A
 ** \arg GPIO_PIN_B
 ** \arg GPIO_PIN_C
 ** \arg GPIO_PIN_D
 ** \arg GPIO_PIN_E
 ** \arg GPIO_PIN_F
 **
 ** \param pulltype pull-up type
 ** \arg IO_PULLUP_CONN
 ** \arg IO_PULLUP_DISCONN
 ** \retval None
 **
 ******************************************************************************
 */  
void IO_GPIOConfigPullup(uint8_t ioport, uint32_t iopin, uint8_t pulltype)
{
    /* Check the parameter */
    ASSERT (IS_IO_PULLUP(pulltype));
    ASSERT (IS_GPIO_PORT(ioport));
    ASSERT (IS_GPIO_PIN(iopin));
	
    if(pulltype == IO_PULLUP_CONN)
    {    
        switch(ioport)
        {
            case GPIO_PORT0: 
    	        FM3_GPIO->PCR0 |= iopin ;  
    	        break;
    	    case GPIO_PORT1:
    	        FM3_GPIO->PCR1 |= iopin; 
    	        break;
    	    case GPIO_PORT2:
    	        FM3_GPIO->PCR2 |= iopin; 
    	        break;
    	    case GPIO_PORT3:
    	        FM3_GPIO->PCR3 |= iopin; 
    	        break;
    	    case GPIO_PORT4:
    	        FM3_GPIO->PCR4 |= iopin; 
    	        break;
    	    case GPIO_PORT5:
    	        FM3_GPIO->PCR5 |= iopin; 
    	        break;
    	    case GPIO_PORT6:
    	        FM3_GPIO->PCR6 |= iopin; 
    	        break;
    	    case GPIO_PORT7:
    	        FM3_GPIO->PCR7 |= iopin; 
    	        break;

    	    default: 
    	        break;
    	}
    }
    else
    {
    	switch(ioport)
        {
            case GPIO_PORT0: 
    	        FM3_GPIO->PCR0 &= ~ iopin;  
    	        break;
    	    case GPIO_PORT1:
    	        FM3_GPIO->PCR1 &= ~ iopin; 
    	    	break;
    	    case GPIO_PORT2:
    	        FM3_GPIO->PCR2 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT3:
    	        FM3_GPIO->PCR3 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT4:
    	        FM3_GPIO->PCR4 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT5:
    	        FM3_GPIO->PCR5 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT6:
    	        FM3_GPIO->PCR6 &= ~ iopin; 
    	        break;
    	    case GPIO_PORT7:
    	        FM3_GPIO->PCR7 &= ~ iopin; 
    	        break;

    	    default: 
    	        break;
    	}
    }
    return;	
	
}


 
 
 /*****************************************************************************/
/* END OF FILE */
 
 