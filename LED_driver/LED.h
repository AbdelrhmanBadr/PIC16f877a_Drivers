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

typedef struct
{
    portName port;
    pinNumber pin;
    LED_connectionType connection;
}LED;

void LED_ledSetup(LED myLed);
void LED_ledState(LED myLed , LED_state myLedState);

#endif	/* LED_H_ */

