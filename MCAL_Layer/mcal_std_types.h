/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    STD_TYPES              ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef MCAL_STD_TYPES_H
#define MCAL_STD_TYPES_H

/*section : includes*/
#include "std_libraries.h"
#include "compiler.h"

/*section : Macro Functions Declarations */


/*section : Data Types Declearations */
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;

typedef float f32;
typedef double f64;

typedef uint8 Std_ReturnType;

/*section : Macro Declarations */

#define STD_HIGH 0x01
#define STD_HIGH 0x01

#define STD_ON 0x01
#define STD_OFF 0x00

#define STD_ACTIVE 0x01
#define STD_IDLE 0x00

#define E_OK (Std_ReturnType)0x01
#define E_NOT_OK (Std_ReturnType)0x00

/*section : Functions Declarations*/

#endif /* MCAL_STD_TYPES_H */
