
/* 
 * File: to configurate the IO module at pic  
 * Author: Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef pic16f877A_IO_H_
#define	pic16f877A_IO_H_

typedef enum
{
    OUTPUT,
    INPUT,        
}pinDirection;

typedef enum
{
    LOW,
    HIGH,        
}digitalState;

typedef enum
{
    PIN0,PIN1,PIN2,PIN3,
    PIN4,PIN5,PIN6,PIN7,        
}pinNumber;

typedef enum
{
    A,
    B,
    C,
    D,
    E,        
}portName;

/*
 * @breif:  DIO_pinDirection () is a function that used to determine the direction of the pin [INPUT - OUTPUT]
 * @para: Port name [A-B-C-D-E]
 * @para: pin number [PIN0,PIN1,PIN2,...,PIN7]
 * @para: direction of pin [OUTPUT - INPUT]
 * @return: void
 * @example: To set B0 as input pin --> DIO_pinDirection (B,PIN0,INPUT)
 */
void DIO_pinDirection(portName port, pinNumber pin , pinDirection direction);
/*
 * @breif: DIO_pinWrite () is a function that used to determine the output digital value [HIGH - LOW]
 * @para: Port name [A-B-C-D-E]
 * @para: pin number [PIN0,PIN1,PIN2,...,PIN7]
 * @para: The output digital value [HIGH-LOW]
 * @return: void
 * @example: To make the output of the C0 is high --> DIO_pinWrite(C, PIN0 , HIGH);
 */
void DIO_pinWrite(portName port, pinNumber pin , digitalState state);
/*
 * @breif:DIO_pinRead() is a function that used to read the input digital signal at input pin
 * @para: Port name [A-B-C-D-E]
 * @para: pin number [PIN0,PIN1,PIN2,...,PIN7]
 * @return: "HIGH" if the input to the pin is high signal and "LOW" if the input to the pin is low signal
 * @example: To assign the value of input signal at pin BO --> x = DIO_pinRead(B,0);
 */
digitalState DIO_pinRead(portName port , pinNumber pin);
/*
 * @breif: DIO_portDirection is a function that used to determine the direction of the port [INPUT - OUTPUT]
 * @para: Port name [A-B-C-D-E]
 * @para: direction of pin [OUTPUT - INPUT]
 * @return: void
 * @example: To set port B as input port --> DIO_portDirection (B,INPUT)
 */
void DIO_portDirection(portName port , pinDirection direction);
/*
 * @breif: DIO_portWrite () is a function that used to determine the output digital value [HIGH - LOW]
 * @para: Port name [A-B-C-D-E]
 * @para: The output digital value [HIGH-LOW]
 * @return: void
 * @example: To make the output of the port C is high --> DIO_portWrite(C, HIGH);
 */
void DIO_portWrite (portName port , digitalState state);
/*
 * @breif:DIO_portRead() is a function that used to read the input digital signal at input port
 * @para: Port name [A-B-C-D-E]
 * @return: The port value
 * @example: To assign the value of input signal at port B --> x = DIO_portRead(B);
 */
uint8 DIO_portRead(portName port);
/*
 * @breif:DIO_inputPullUpEnable() is a function that used to enable the input pull up at PORTB
 * @para: void
 * @return: void
 * @example: To enable input pull up at port(b) -->  DIO_inputPullUpEnable();
 * @note: The weak pull-up is automatically turned off when the port pin is configured as an output. 
 * @note: The pull-ups are disabled on a Power-on Reset.
 */
void DIO_inputPullUpEnable(void);
/*
 * @breif:DIO_inputPullUpDisable() is a function that used to disable the input pull up at PORTB
 * @para: void
 * @return: void
 * @example: To disable input pull up at port(b) -->  DIO_inputPullUpDisable();
 */
void DIO_inputPullUpDisable(void);

#endif	/* pic16f877A_IO */

