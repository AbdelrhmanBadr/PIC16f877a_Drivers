/* 
 * File:   sevenSegment.c
 * Author: Abdelrhman Badr
 *
 * Created on September 1, 2020, 5:59 PM
 */
#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"
#include "sevenSegment.h"

#define _7seg_ZERO  (0x7E)
#define _7seg_ONE   (0x30)
#define _7seg_TWO   (0x6D)
#define _7seg_THREE (0x79)
#define _7seg_FOUR  (0x33)
#define _7seg_FIVE  (0x5B)
#define _7seg_SIX   (0x5F)
#define _7seg_SEVEN (0x70)
#define _7seg_EIGHT (0x7F)
#define _7seg_NINE  (0x73)

#define disable_7seg_commonCathode  (0x00)
#define disable_7seg_commonAnode    (0x7F)

void sevenSegment_7segSetup (SEVENSEGMENT seg)
{
    /*Set seven segment port as output port*/
    DIO_portDirection(seg.port,OUTPUT);
    /*Set initial digital state as LOW*/
    switch(seg.type)
    {
        case sevenSegment_commonAnode : DIO_portWrite(seg.port,disable_7seg_commonAnode);break;
        case sevenSegment_commonCathode: DIO_portWrite(seg.port,disable_7seg_commonCathode);break;
    }
    
}
void sevenSegment_7segDisplay(SEVENSEGMENT seg , _7SEG_num num)
{
    switch(seg.type)
    {
        case sevenSegment_commonCathode:
            switch(num)
            {
                case ZERO : DIO_portWrite(seg.port,_7seg_ZERO);  break;
                case ONE  : DIO_portWrite(seg.port,_7seg_ONE);   break;
                case TWO  : DIO_portWrite(seg.port,_7seg_TWO);   break;
                case THREE :DIO_portWrite(seg.port,_7seg_THREE); break;
                case FOUR : DIO_portWrite(seg.port,_7seg_FOUR);  break;
                case FIVE : DIO_portWrite(seg.port,_7seg_FIVE);  break;
                case SIX :  DIO_portWrite(seg.port,_7seg_SIX);   break;
                case SEVEN :DIO_portWrite(seg.port,_7seg_SEVEN); break;
                case EIGHT :DIO_portWrite(seg.port,_7seg_EIGHT); break;
                case NINE  :DIO_portWrite(seg.port, _7seg_NINE); break;
            }
            break;
        case sevenSegment_commonAnode:
            switch(num)
            {
                case ZERO : DIO_portWrite(seg.port,~_7seg_ZERO);    break;
                case ONE  : DIO_portWrite(seg.port,~_7seg_ONE);     break;
                case TWO  : DIO_portWrite(seg.port,~_7seg_TWO);     break;
                case THREE :DIO_portWrite(seg.port,~_7seg_THREE);   break;
                case FOUR : DIO_portWrite(seg.port,~_7seg_FOUR);    break;
                case FIVE : DIO_portWrite(seg.port,~_7seg_FIVE);    break;
                case SIX :  DIO_portWrite(seg.port,~_7seg_SIX);     break;
                case SEVEN :DIO_portWrite(seg.port,~_7seg_SEVEN);   break;
                case EIGHT :DIO_portWrite(seg.port,~_7seg_EIGHT);   break;
                case NINE  :DIO_portWrite(seg.port,~_7seg_NINE) ;   break;
            }
            break;
    }
}