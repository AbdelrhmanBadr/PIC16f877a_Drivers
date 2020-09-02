/* 
 * File:   PIR.c
 * Author: Abdelrhman Badr
 *
 * Created on September 1, 2020, 11:25 PM
 */
#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"
#include "PIR.h"

void PIR_PIRSetup(PIR pir)
{
    /*set sensor pin as input pin*/
    DIO_pinDirection(pir.port,pir.pin,INPUT);
}

motion_state PIR_motionState(PIR pir)
{
    motion_state returnValue;
    if(DIO_pinRead(pir.port,pir.pin) == HIGH)
    {
        returnValue = PIR_motionDetected;
    }
    else if (DIO_pinRead(pir.port,pir.pin) == LOW)
    {
        returnValue = PIR_motionNotDetected;
    }
    else
    {
    }
    return returnValue;
}
