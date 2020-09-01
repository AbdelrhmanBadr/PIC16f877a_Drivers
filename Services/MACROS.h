
/* 
 * File:  common maros will use in all layers 
 * Author: Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MACROS_H_
#define	MACROS_H_

/*To put 0 at bit b at register a*/
#define clearBit(a,b)   ((a) &= ~(1<<(b)))      
/*To put 1 at bit b at register a*/
#define setBit(a,b)     ((a)|= (1<<(b)))
/*To toggle bit b at register a*/
#define toggleBit(a,b)  ((a) ^= (1<<(b)))
/*To read a bit b at register a*/
#define readBit(a,b)    (((a) & (1<<(b)))>>(b))

#endif	/* XC_HEADER_TEMPLATE_H */

