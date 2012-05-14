/*!
 ******************************************************************************
 **
 ** \file crc_sw.c
 **
 ** \brief CRC table head file
 **
 ** \author FSLA AE Team
 **
 ** \version V0.10
 **
 ** \date 2011-11-24
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
#include "crc_sw.h"

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
/*! \brief CCITT CRC16 table  */
const uint16_t g_CRC16Table[256]={
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

/*! \brief CCITT CRC32 table  */
const uint32_t g_CRC32Table[256]={
    0x00000000L,  0x04c11db7L,  0x09823b6eL,  0x0d4326d9L,  
    0x130476dcL,  0x17c56b6bL,  0x1a864db2L,  0x1e475005L,  
    0x2608edb8L,  0x22c9f00fL,  0x2f8ad6d6L,  0x2b4bcb61L,  
    0x350c9b64L,  0x31cd86d3L,  0x3c8ea00aL,  0x384fbdbdL,  
    0x4c11db70L,  0x48d0c6c7L,  0x4593e01eL,  0x4152fda9L,  
    0x5f15adacL,  0x5bd4b01bL,  0x569796c2L,  0x52568b75L,
    0x6a1936c8L,  0x6ed82b7fL,  0x639b0da6L,  0x675a1011L,  
    0x791d4014L,  0x7ddc5da3L,  0x709f7b7aL,  0x745e66cdL,  
    0x9823b6e0L,  0x9ce2ab57L,  0x91a18d8eL,  0x95609039L,  
    0x8b27c03cL,  0x8fe6dd8bL,  0x82a5fb52L,  0x8664e6e5L,  
    0xbe2b5b58L,  0xbaea46efL,  0xb7a96036L,  0xb3687d81L,  
    0xad2f2d84L,  0xa9ee3033L,  0xa4ad16eaL,  0xa06c0b5dL,
    0xd4326d90L,  0xd0f37027L,  0xddb056feL,  0xd9714b49L,  
    0xc7361b4cL,  0xc3f706fbL,  0xceb42022L,  0xca753d95L,  
    0xf23a8028L,  0xf6fb9d9fL,  0xfbb8bb46L,  0xff79a6f1L,  
    0xe13ef6f4L,  0xe5ffeb43L,  0xe8bccd9aL,  0xec7dd02dL,  
    0x34867077L,  0x30476dc0L,  0x3d044b19L,  0x39c556aeL,  
    0x278206abL,  0x23431b1cL,  0x2e003dc5L,  0x2ac12072L,  
    0x128e9dcfL,  0x164f8078L,  0x1b0ca6a1L,  0x1fcdbb16L,  
    0x018aeb13L,  0x054bf6a4L,  0x0808d07dL,  0x0cc9cdcaL,  
    0x7897ab07L,  0x7c56b6b0L,  0x71159069L,  0x75d48ddeL,  
    0x6b93dddbL,  0x6f52c06cL,  0x6211e6b5L,  0x66d0fb02L,  
    0x5e9f46bfL,  0x5a5e5b08L,  0x571d7dd1L,  0x53dc6066L,
    0x4d9b3063L,  0x495a2dd4L,  0x44190b0dL,  0x40d816baL,  
    0xaca5c697L,  0xa864db20L,  0xa527fdf9L,  0xa1e6e04eL,  
    0xbfa1b04bL,  0xbb60adfcL,  0xb6238b25L,  0xb2e29692L,  
    0x8aad2b2fL,  0x8e6c3698L,  0x832f1041L,  0x87ee0df6L,  
    0x99a95df3L,  0x9d684044L,  0x902b669dL,  0x94ea7b2aL,  
    0xe0b41de7L,  0xe4750050L,  0xe9362689L,  0xedf73b3eL,
    0xf3b06b3bL,  0xf771768cL,  0xfa325055L,  0xfef34de2L,  
    0xc6bcf05fL,  0xc27dede8L,  0xcf3ecb31L,  0xcbffd686L,  
    0xd5b88683L,  0xd1799b34L,  0xdc3abdedL,  0xd8fba05aL,  
    0x690ce0eeL,  0x6dcdfd59L,  0x608edb80L,  0x644fc637L,  
    0x7a089632L,  0x7ec98b85L,  0x738aad5cL,  0x774bb0ebL,  
    0x4f040d56L,  0x4bc510e1L,  0x46863638L,  0x42472b8fL,  
    0x5c007b8aL,  0x58c1663dL,  0x558240e4L,  0x51435d53L,  
    0x251d3b9eL,  0x21dc2629L,  0x2c9f00f0L,  0x285e1d47L,  
    0x36194d42L,  0x32d850f5L,  0x3f9b762cL,  0x3b5a6b9bL,  
    0x0315d626L,  0x07d4cb91L,  0x0a97ed48L,  0x0e56f0ffL,  
    0x1011a0faL,  0x14d0bd4dL,  0x19939b94L,  0x1d528623L,
    0xf12f560eL,  0xf5ee4bb9L,  0xf8ad6d60L,  0xfc6c70d7L,  
    0xe22b20d2L,  0xe6ea3d65L,  0xeba91bbcL,  0xef68060bL,  
    0xd727bbb6L,  0xd3e6a601L,  0xdea580d8L,  0xda649d6fL,  
    0xc423cd6aL,  0xc0e2d0ddL,  0xcda1f604L,  0xc960ebb3L,  
    0xbd3e8d7eL,  0xb9ff90c9L,  0xb4bcb610L,  0xb07daba7L,  
    0xae3afba2L,  0xaafbe615L,  0xa7b8c0ccL,  0xa379dd7bL,
    0x9b3660c6L,  0x9ff77d71L,  0x92b45ba8L,  0x9675461fL,  
    0x8832161aL,  0x8cf30badL,  0x81b02d74L,  0x857130c3L,  
    0x5d8a9099L,  0x594b8d2eL,  0x5408abf7L,  0x50c9b640L,  
    0x4e8ee645L,  0x4a4ffbf2L,  0x470cdd2bL,  0x43cdc09cL,  
    0x7b827d21L,  0x7f436096L,  0x7200464fL,  0x76c15bf8L,  
    0x68860bfdL,  0x6c47164aL,  0x61043093L,  0x65c52d24L,  
    0x119b4be9L,  0x155a565eL,  0x18197087L,  0x1cd86d30L,  
    0x029f3d35L,  0x065e2082L,  0x0b1d065bL,  0x0fdc1becL,  
    0x3793a651L,  0x3352bbe6L,  0x3e119d3fL,  0x3ad08088L,  
    0x2497d08dL,  0x2056cd3aL,  0x2d15ebe3L,  0x29d4f654L,  
    0xc5a92679L,  0xc1683bceL,  0xcc2b1d17L,  0xc8ea00a0L,
    0xd6ad50a5L,  0xd26c4d12L,  0xdf2f6bcbL,  0xdbee767cL,
    0xe3a1cbc1L,  0xe760d676L,  0xea23f0afL,  0xeee2ed18L,
    0xf0a5bd1dL,  0xf464a0aaL,  0xf9278673L,  0xfde69bc4L,
    0x89b8fd09L,  0x8d79e0beL,  0x803ac667L,  0x84fbdbd0L,
    0x9abc8bd5L,  0x9e7d9662L,  0x933eb0bbL,  0x97ffad0cL,
    0xafb010b1L,  0xab710d06L,  0xa6322bdfL,  0xa2f33668L,
    0xbcb4666dL,  0xb8757bdaL,  0xb5365d03L,  0xb1f740b4L
};
/*!
 ******************************************************************************
 ** \brief Calculate CRC16 code by software arithmetic
 **        The CCITT CRC16 generator polynomial: 0x1021
 **
 ** \param pData  point to CRC data
 ** \param Size   point to CRC data size
 **
 ** \retval CRC16 code
 **
 ******************************************************************************
 */
uint16_t CRC_SwCalCRC16(uint8_t *pData, uint32_t Size)
{
    uint8_t temp;
    uint8_t *p_temp_data = pData;
    uint16_t crc = 0xFFFF; 
    /* Check parameter */
    ASSERT(pData != NULL);
    
    while(Size-- != 0)
    {
        temp = crc/256;
        crc <<=8;
        crc ^= g_CRC16Table[temp^*p_temp_data];
        p_temp_data++;
    }
    return crc;

}

/*!
 ******************************************************************************
 ** \brief Calculate CRC32 code by software arithmetic
 **        IEEE-802.3 CRC32 generator polynomial: 0x04C11DB7
 **
 ** \param pData  point to CRC data
 ** \param Size   point to CRC data size
 **
 ** \retval CRC32 code
 **
 ******************************************************************************
 */
uint32_t CRC_SwCalCRC32(uint8_t *pData, uint32_t Size)
{   
    uint8_t temp;
    uint8_t *p_temp_data = pData;
    uint32_t crc = 0xFFFFFFFF;
    /* Check parameter */
    ASSERT(pData != NULL);
    
    while(Size--)
    {
        temp=( crc >> 24 );
        crc = ( crc << 8 ) ^ g_CRC32Table[temp^*p_temp_data];
        p_temp_data++;
    }
    return ~crc;
}


/*****************************************************************************/
/* END OF FILE */    