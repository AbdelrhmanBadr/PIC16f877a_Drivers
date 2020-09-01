/* 
 * File:   dataTypes file is file used to redefine the data types
 * Author: Abdelrhman Badr
 * Comments: This data types is taken from XC8 guid -->  https://www.mikrocontroller.net/attachment/211304/MPLAB_XC8_C_Compiler_User_s_Guide_1_2.pdf
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef dataTypes_H_
#define	dataTypes_H_

typedef unsigned char       uint8;
typedef signed char         int8;
typedef unsigned short      uint16;
typedef signed short        int16;
typedef unsigned long       uint32;
typedef signed long         int32;

typedef enum 
{
    false,
    true,        
}bool;


#endif	/* dataTypes_H_ */

