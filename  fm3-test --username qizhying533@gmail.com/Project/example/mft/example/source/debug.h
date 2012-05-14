/*!
 ******************************************************************************
 **
 ** \file example\wc\wc_subclk\source\debug.h
 **
 ** \brief this file provides option of ouputting debug information for user
 **
 ** \author FSAL AE Team
 **
 ** \version V0.1
 **
 ** \date 2011-11-24
 **
 ** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU SEMICONDUCTOR
 **            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
 **            OMMISSIONS.
 **
 ** (C) Copyright 200x-201x by Fujitsu Semiconductor Ltd. Asia
 **
 ******************************************************************************
 */

#ifndef _DEBUG_H_
#define _DEBUG_H_

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include <stdio.h>
/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/* Uncomment the line below to expanse the "ASSERT" macro in the 
   Standard Peripheral Library drivers code */
#define DEBUG_MODE              TRUE
#define DEBUG_DRV_MFT_FRT       TRUE
//#define DEBUG_DRV_MFT_OCU       TRUE

#if(DEBUG_MODE)
    #define ASSERT(expr) \
            {do \
            { \
                if (!(expr)) \
                { \
                    printf("FILE: %s\n", __FILE__); \
                    printf("FUNC: %s\n", __FUNCTION__); \
                    printf("LINE: %u\n\n", __LINE__); \
                } \
            }while(0);}
#else
    #define ASSERT(expr)
#endif


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif /* _DEBUG_H_ */
/*****************************************************************************/
/* END OF FILE */ 
