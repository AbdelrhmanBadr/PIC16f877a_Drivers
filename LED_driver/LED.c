/* 
 * File:   LED.c
 * Author: Abdelrhman Badr
 *
 * Created on September 1, 2020, 12:06 PM
 */

#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"
#include "LED.h"

void LED_ledSetup(LED myLed)
{
    /*Set led pin as output pin*/
    DIO_pinDirection(myLed.port , myLed.pin , OUTPUT);
    /*set initial state to make led off*/
    switch(myLed.connection)
    {
        case LED_forward: DIO_pinWrite(myLed.port , myLed.pin , LOW); break;
        case LED_reverse: DIO_pinWrite(myLed.port , myLed.pin , HIGH); break;   
    }
}
void LED_ledState(LED myLed , LED_state myLedState)
{
    switch(myLed.connection)
    {
        case LED_forward:
            switch(myLedState)
            {
                case LED_off :DIO_pinWrite(myLed.port,myLed.pin,LOW);  break;
                case LED_on  :DIO_pinWrite(myLed.port,myLed.pin,HIGH); break;
            }
            break;
        case LED_reverse:
            switch(myLedState)
            {
                case LED_off : DIO_pinWrite(myLed.port,myLed.pin,HIGH); break;
                case LED_on  : DIO_pinWrite(myLed.port,myLed.pin,LOW); break;
            }
            break;    
    }
}
