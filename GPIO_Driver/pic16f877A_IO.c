/* 
 * File:   pic16f877A_IO.c
 * Author: Abdelrhman Badr
 *
 * Created on August 27, 2020, 2:03 PM
 */

#include "MACROS.h"
#include "dataTypes.h"
#include "pic16f877A_IO.h"
#include "pic16f877A_config.h"

#define TRIS_INPUT   (0XFF)
#define TRIS_OUTPUT  (0X00)
#define PORT_HIGH    (0XFF)
#define PORT_LOW     (0X00)

void DIO_pinDirection(portName port, pinNumber pin , pinDirection direction)
{
    switch(port)
    {
        case A:  
            /*Disable ADC for this port except AN0*/
            setBit(ADCON1,PCFG3);
            setBit(ADCON1,PCFG2);
            setBit(ADCON1,PCFG1);
            clearBit(ADCON1,PCFG0);
            switch(direction)
            {
                case INPUT : setBit(TRISA,pin);break;
                case OUTPUT: clearBit(TRISA,pin);break; 
                default : /*error;*/ break;
            }
            break;
        case B:
            switch(direction)
            {
                case INPUT : setBit(TRISB,pin);break;
                case OUTPUT: clearBit(TRISB,pin);break; 
                default : /*error;*/ break;
            }
            break;
        case C:
            switch(direction)
            {
                case INPUT : setBit(TRISC,pin);break;
                case OUTPUT: clearBit(TRISC,pin);break; 
                default : /*error;*/ break;
            }
            break;
        case D:
            switch(direction)
            {
                case INPUT : setBit(TRISD,pin);break;
                case OUTPUT: clearBit(TRISD,pin);break; 
                default : /*error;*/ break;
            }
            break;
        case E:
            /*Disable ADC for this port*/
            setBit(ADCON1,PCFG3);
            setBit(ADCON1,PCFG2);
            clearBit(ADCON1,PCFG1);
            clearBit(ADCON1,PCFG0);
            switch(direction)
            {
                case INPUT : setBit(TRISE,pin);break;
                case OUTPUT: clearBit(TRISE,pin);break; 
                default : /*error;*/ break;
            }
            break;
        default: break;
    }
}

void DIO_pinWrite(portName port, pinNumber pin , digitalState state)
{
  switch(port)
  {
      case A:
          switch(state)
          {
              case LOW : clearBit(PORTA,pin);break;
              case HIGH: setBit(PORTA,pin);break;
          }
          break;
      case B:
          switch(state)
          {
              case LOW : clearBit(PORTB,pin);break;
              case HIGH: setBit(PORTB,pin);break;
          }
          break;
      case C:
          switch(state)
          {
              case LOW : clearBit(PORTC,pin);break;
              case HIGH: setBit(PORTC,pin);break;
          }
          break;    
      case D:
          switch(state)
          {
              case LOW : clearBit(PORTD,pin);break;
              case HIGH: setBit(PORTD,pin);break;
          }
          break;
      case E:
          switch(state)
          {
              case LOW : clearBit(PORTE,pin);break;
              case HIGH: setBit(PORTE,pin);break;
          }
          break;
      default: break;    
  }
}
digitalState DIO_pinRead(portName port , pinNumber pin)
{
  digitalState returnValue = LOW;
  switch(port)
  {
     case A: 
         returnValue = readBit(PORTA,pin);
         break;
     case B: 
         returnValue = readBit(PORTB,pin);
         break;
     case C: 
         returnValue = readBit(PORTC,pin);
         break;
     case D: 
         returnValue = readBit(PORTD,pin);
         break;
     case E: 
         returnValue = readBit(PORTE,pin);
         break;
     default: 
         /*error*/ 
         break;     
  }
  return returnValue;
}
void DIO_portDirection(portName port , pinDirection direction)
{
    switch(port)
    {
        case A: 
            switch(direction)
            {
                case INPUT : TRISA = TRIS_INPUT; break;  
                case OUTPUT: TRISA = TRIS_OUTPUT; break;     
            }
            break;
        case B: 
            switch(direction)
            {
                case INPUT : TRISB = TRIS_INPUT; break;  
                case OUTPUT: TRISB = TRIS_OUTPUT; break;     
            }
            break;
        case C: 
            switch(direction)
            {
                case INPUT : TRISC = TRIS_INPUT; break;  
                case OUTPUT: TRISC = TRIS_OUTPUT; break;     
            }
            break;
        case D: 
            switch(direction)
            {
                case INPUT : TRISD = TRIS_INPUT; break;  
                case OUTPUT: TRISD = TRIS_OUTPUT; break;     
            }
            break;
        case E: 
            switch(direction)
            {
                case INPUT : TRISE = TRIS_INPUT; break;  
                case OUTPUT: TRISE = TRIS_OUTPUT; break;     
            }
            break;
        default: /*error*/ break;    
            
    }
}
void DIO_portWrite (portName port , uint8 state)
{
    switch(port)
    {
        case A:
            PORTA = state;
            break;
        case B:
            PORTB = state;
            break;
        case C:
            PORTC = state;
            break;
        case D:
            PORTD = state;
            break;
        case E:
            PORTE = state;
            break;    
    }
}
uint8 DIO_portRead(portName port)
{
    uint8 returnValue;
    switch(port)
    {
        case A: returnValue = PORTA; break;
        case B: returnValue = PORTB; break;
        case C: returnValue = PORTC; break;
        case D: returnValue = PORTD; break;
        case E: returnValue = PORTE; break;
    }
    
    return returnValue;
}
void DIO_inputPullUpEnable(void)
{
    clearBit(OPTION_REG,7);
}
void DIO_inputPullUpDisable(void)
{
    setBit(OPTION_REG,7);
}