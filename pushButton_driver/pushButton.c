/* 
 * File:   pushButton.c
 * Author: Abdelrhman Badr
 *
 * Created on September 1, 2020, 4:21 PM
 */

#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"
#include "pushButton.h"

void pushButton_pushButtonSetup(PUSHBUTTON pb)
{
    /*set pushButton pin as input pin*/
    DIO_pinDirection(pb.port,pb.pin,INPUT);
}
pushButton_state pushButton_pushButtonState(PUSHBUTTON pb)
{
    pushButton_state returnValue;
    switch(pb.connectionType)
    {
        case pushButton_pullUp: 
            if(DIO_pinRead(pb.port,pb.pin))
            {
                returnValue = RELEASED;
            }
            else
            {
                returnValue = PRESSED;
            }
            break;
        case pushButton_pullDown: 
            if(DIO_pinRead(pb.port,pb.pin))
            {
                returnValue = PRESSED;
            }
            else
            {
                returnValue = RELEASED;
            }
            break;    
    }
    return returnValue;
}