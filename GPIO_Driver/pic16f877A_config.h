
/* 
 * File:   
 * Author: Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef pic16f877A_config_H_
#define	pic16f877A_config_H_
#define _XTAL_FREQ 16000000 

/*PortA register*/
#define PORTA   (*(volatile uint8 *)(0x05))
#define PORTA5  5
#define PORTA4  4   
#define PORTA3  3
#define PORTA2  2   
#define PORTA1  1
#define PORTA0  0

/*portB register*/
#define PORTB   (*(volatile uint8 *)(0x06))
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4   
#define PORTB3  3
#define PORTB2  2   
#define PORTB1  1
#define PORTB0  0

/*PortC register*/
#define PORTC   (*(volatile uint8 *)(0x07))
#define PORTC7  7
#define PORTC6  6
#define PORTC5  5
#define PORTC4  4   
#define PORTC3  3
#define PORTC2  2   
#define PORTC1  1
#define PORTC0  0

/*PortD register*/
#define PORTD   (*(volatile uint8 *)(0x08))
#define PORTD7  7
#define PORTD6  6
#define PORTD5  5
#define PORTD4  4   
#define PORTD3  3
#define PORTD2  2   
#define PORTD1  1
#define PORTD0  0

/*PortE register*/
#define PORTE   (*(volatile uint8 *)(0x09))
#define PORTE2  2   
#define PORTE1  1
#define PORTE0  0   

/*TrisA register*/
#define TRISA   (*(volatile uint8 *)(0x85))
#define TRISA5  5
#define TRISA4  4
#define TRISA3  3
#define TRISA2  2
#define TRISA1  1
#define TRISA0  0

/*TrisB register*/
#define TRISB   (*(volatile uint8 *)(0x86))
#define TRISB7  7
#define TRISB6  6
#define TRISB5  5
#define TRISB4  4
#define TRISB3  3
#define TRISB2  2
#define TRISB1  1
#define TRISB0  0

/*TrisC register*/
#define TRISC   (*(volatile uint8 *)(0x87))
#define TRISC7  7
#define TRISC6  6
#define TRISC5  5
#define TRISC4  4
#define TRISC3  3
#define TRISC2  2
#define TRISC1  1
#define TRISC0  0

/*TrisD register*/
#define TRISD   (*(volatile uint8 *)(0x88))
#define TRISD7  7 
#define TRISD6  6
#define TRISD5  5
#define TRISD4  4
#define TRISD3  3 
#define TRISD2  2 
#define TRISD1  1
#define TRISD0  0

/*TrisE register*/
#define TRISE   (*(volatile uint8 *)(0x89))
#define IBF     7
#define OBF     6
#define IBOV    5
#define PSPMODE 4
#define TRISE2  2
#define TRISE1  1
#define TRISE0  0

/*OPTION_REG register*/
#define OPTION_REG   (*(volatile uint8 *)(0x81))
#define RBPU    7
#define INTEDGE 6
#define T0CS    5
#define T0SE    4
#define PSA     3
#define PS2     2
#define PS1     1
#define PS0     0
/*ADCON1 REGISTER*/
#define ADCON1  (*(volatile uint8 *)(0X9F))
#define ADFM    7
#define ADCS2   6
#define PCFG3   3
#define PCFG2   2
#define PCFG1   1
#define PCFG0   0



/***********************************delay function*********************************************/
/*Delay*/
#pragma intrinsic(_delay)
extern __nonreentrant void _delay(unsigned long);
#pragma intrinsic(_delaywdt)
extern __nonreentrant void _delaywdt(unsigned long);
#if defined(_PIC14E) || defined(_PIC14EX)
#pragma intrinsic(_delay3)
extern __nonreentrant void _delay3(unsigned char);
#endif
// NOTE: To use the macros below, YOU must have previously defined _XTAL_FREQ
#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
#endif	/* XC_HEADER_TEMPLATE_H */

