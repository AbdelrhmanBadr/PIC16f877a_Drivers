/* 
 * File:   switchPushButton.c
 * Author: Abdelrhman Badr
 *
 * Created on September 3, 2020, 1:24 PM
 */

#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"
#include "switchPushButton.h"

#define HIGH 1
#define LOW  0
static uint8 previous_state;
static uint8 initial_state;

void switchPushButton_pushButtonSetup(SWITCHPUSHBUTTON pb)
{
    /*set pushButton pin as input pin*/
    DIO_pinDirection(pb.port,pb.pin,INPUT);
    initial_state = DIO_pinRead(pb.port,pb.pin);
    previous_state = DIO_pinRead(pb.port,pb.pin);
}
switch_pushButton_state switchPushButton_pushButtonState(SWITCHPUSHBUTTON pb)
{
    switch_pushButton_state returnValue;
    switch(pb.connectionType)
    {
        case switchPushButton_pullDown: 
            __delay_ms(bouncingTime_ms);
            if((DIO_pinRead(pb.port,pb.pin) == LOW) && (previous_state == LOW))
            {
                returnValue = switchPushButtonNotPressed;
                previous_state = LOW; 
            }
            else if((DIO_pinRead(pb.port,pb.pin) == LOW) && (previous_state == HIGH))
            {
                /********************************************/
                returnValue = switchPushButtonNotPressed;
                previous_state = LOW; 
            }
            else if((DIO_pinRead(pb.port,pb.pin) == HIGH) && (previous_state == LOW))
            {
                returnValue = switchPushButtonPressed;
                previous_state = HIGH; 
            }
            else if((DIO_pinRead(pb.port,pb.pin) == HIGH) && (previous_state == HIGH))
            {
                returnValue = switchPushButtonNotPressed;
                previous_state = HIGH;
            }
            else
            {
                
            }
               
            break;
            case switchPushButton_pullUp: 
            __delay_ms(bouncingTime_ms);
            if((DIO_pinRead(pb.port,pb.pin) == LOW) && (previous_state == LOW))
            {
                returnValue = switchPushButtonNotPressed;
                previous_state = LOW; 
            }
            else if((DIO_pinRead(pb.port,pb.pin) == LOW) && (previous_state == HIGH))
            {
                /********************************************/
                returnValue = switchPushButtonPressed;
                previous_state = LOW; 
            }
            else if((DIO_pinRead(pb.port,pb.pin) == HIGH) && (previous_state == LOW))
            {
                returnValue = switchPushButtonNotPressed;
                previous_state = HIGH; 
            }
            else if((DIO_pinRead(pb.port,pb.pin) == HIGH) && (previous_state == HIGH))
            {
                returnValue = switchPushButtonNotPressed;
                previous_state = HIGH;
            }
            else
            {
                
            }
               
            break;
    }
    return returnValue;
   
}