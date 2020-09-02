/* 
 * File:  LED.h file 
 * Author: Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef LED_H_
#define	LED_H_

typedef enum
{
    LED_forward,
    LED_reverse,        
}LED_connectionType;

typedef enum
{
    LED_off,
    LED_on,
}LED_state;

/*
 * *********************************************************@dataType*********************************************************************
 * @name: LED
 * @initialization: LED variable_name = {port_name , pin_number , connection_type};
 * @Notes: port_name{A,B,C,D,E}             pin_number{PIN0,PIN1,PIN2,.......,PIN7}         connection_type{LED_forward,LED_reverse}
 * @example : if we have led at pin B0 and reverse connection 
 *  --------------------------> LED myLed = {B,PIN0,LED_reverse}; 
 */
typedef struct
{
    portName port;
    pinNumber pin;
    LED_connectionType connection;
}LED;

/*
 * @breif:  LED_ledSetup must be used to all led used in project its allow to set the configuration of led to make it work correctly
 * @para: variable from LED dataType
 * @return:  void
 * @preConditions: variable from LED data type must be initialized
 */
void LED_ledSetup(LED myLed);
/*
 * @breif: LED_ledState () is a function that used to determine the state of led (LED_on , LED_off) 
 * @para: variable from LED data type  
 * @para: the state of the led (LED_on -  LED_off)
 * @return: void
 * @preConditions: variable from LED data type must be initialized
 */
void LED_ledState(LED myLed , LED_state myLedState);

#endif	/* LED_H_ */

