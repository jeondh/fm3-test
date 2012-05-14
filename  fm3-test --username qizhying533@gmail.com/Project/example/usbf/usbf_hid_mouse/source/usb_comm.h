/*!
 ******************************************************************************
 **
 ** \file usb_comm.h
 **
 ** \brief USB common definition
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-12-22
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
#ifndef __ARM_COMM_DEF_H
#define __ARM_COMM_DEF_H

/*! \brief FALSE difinition  */
#ifndef FALSE
#define FALSE (1 == 0)
#endif

/*! \brief TRUE difinition  */
#ifndef TRUE
#define TRUE  (1 == 1)
#endif

/*! \brief NULL difinition  */
#ifndef NULL
#define NULL ((void*)0)
#endif

/*! \brief Get Max data  */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
/*! \brief Get Min data  */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
/*! \brief Split data into 2 bytes, (low, high) */
#define _2BL(a)   (uint8_t)(a),(uint8_t)(a>>8)
/*! \brief Split data into 2 bytes, (high, low) */
#define _2BB(a)   (uint8_t)(a>>8),(uint8_t)(a)

/*! \brief Critical enter count external declare  */
extern uint32_t g_CriticalEnterCnt;

/*! \brief Enter critical section function  */
#define EntrCritSection() \
{\
	if(g_CriticalEnterCnt == 0)\
	{\
		asm("CPSID i");\
	}\
	++g_CriticalEnterCnt;\
}

/*! \brief Exit critical section function  */
#define ExtCritSection(void) \
{\
	if(--g_CriticalEnterCnt == 0) \
	{\
		asm("CPSIE i");\
	}\
}

/*! \brief Exit critical section definition  */
#define ENTR_CRT_SECTION() EntrCritSection()
/*! \brief Exit critical section definition  */
#define EXT_CRT_SECTION()  ExtCritSection()

#endif // __ARM_COMM_DEF_H
