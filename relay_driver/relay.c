/* 
 * File:   relay.c
 * Author: Abdelrhman Badr
 *
 * Created on September 2, 2020, 2:08 PM
 */

#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"
#include "relay.h"

void relay_relaySetup(RELAY r)
{
    /*set pin as o/p pin*/
    DIO_pinDirection(r.port,r.pin,OUTPUT);
    /*set initial state to disable the relay*/
    switch(r.type)
    {
        case activeLow: DIO_pinWrite(r.port,r.pin,HIGH); break;
        case activeHigh:DIO_pinWrite(r.port,r.pin,LOW);break;
    }
}
void relay_relayState(RELAY r ,relay_state state)
{
    switch(r.type)
    {
        case activeLow:
            switch(state)
            {
                case relay_off :
                    DIO_pinWrite(r.port,r.pin,HIGH);
                    break;
                case relay_on:
                    DIO_pinWrite(r.port,r.pin,LOW);
                    break;
            }
            break;
        case activeHigh:
            switch(state)
            {
                case relay_off :
                    DIO_pinWrite(r.port,r.pin,LOW);
                    break;
                case relay_on:
                    DIO_pinWrite(r.port,r.pin,HIGH);
                    break; 
            }
            break;
    }
}