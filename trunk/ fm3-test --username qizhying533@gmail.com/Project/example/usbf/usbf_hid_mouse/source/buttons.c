/*!
 ******************************************************************************
 **
 ** \file Buttons.c
 **
 ** \brief Implement USB HID mouse function
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
#include "buttons.h"

/*!
 ******************************************************************************
 ** \brief Initialize buttons
 **
 ** \param None
 **
 ** \return None
 **
 ******************************************************************************
 */ 
void Buttons_Init (void)
{
	/*Select GPIO function for 
	PSW1 and PSW2*/
	B_CLICK_PFR &= ~B_CLICK_MASK;
	/*Make PSW1 and PSW2 pins inputs*/
	B_CLICK_DDR &= ~B_CLICK_MASK;
	/*Select CPIO function for 
	B_LEFT and B_RIGHT*/
	B_L_PFR &= ~B_L_MASK;
	B_R_PFR &= ~B_R_MASK;
	/*Make J_LEFT and J_RIGHT pins inputs*/
	B_L_DDR &= ~B_L_MASK;
	B_R_DDR &= ~B_R_MASK;
	/*Select CPIO function for 
	J_UP and J_DOWN*/
	B_U_PFR &= ~B_U_MASK;
	B_D_PFR &= ~B_D_MASK;
	/*Make J_UP and J_DOWN pins inputs*/
	B_U_DDR &= ~B_U_MASK;
	B_D_DDR &= ~B_D_MASK;
}

/*!
 ******************************************************************************
 ** \brief Get buttons status
 **
 ** \param None
 **
 ** \return Buttons status
 **
 ******************************************************************************
 */ 
ButtonsT Buttons_GetStatus (void)
{
	ButtonsT Buttons = {0};
	if(!(B_CLICK_PDIR & B1_CLICK))
	{
		//Buttons.B1 = 1;
	}
	if(!(B_CLICK_PDIR & B2_CLICK))
	{
		//Buttons.B2 = 1;
	}
	if(!(B_R_PDIR & B_RIGHT))
	{
		Buttons.BtRight = 1;
	}
	if(!(B_L_PDIR & B_LEFT))
	{
		Buttons.BtLeft = 1;
	}
	if(!(B_U_PDIR & B_UP))
	{
		Buttons.BtUp = 1;
	}
	if(!(B_D_PDIR & B_DOWN))
	{
		Buttons.BtDown = 1;
	}
	return(Buttons);
}
