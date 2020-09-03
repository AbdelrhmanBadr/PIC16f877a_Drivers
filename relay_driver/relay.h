/* 
 * File:   relay.h
 * Author: Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef relay_H_
#define	relay_H_

typedef enum
{
    activeLow,
    activeHigh,        
}relay_type;

typedef enum
{
    relay_off,
    relay_on,        
}relay_state;
/********************************************************@dataType*******************************************************************************/
/*
 * @name: RELAY
 * @initialization: RELAY var_name = {port_name,pin_number,relay_type};
 * @note: port_name --> {A,B,C,D,E}         pin_number-->{PIN0,PIN1,...,PIN7}           relay_type-->{relay_off, relay_on}
 */
  
typedef struct
{
    portName port;
    pinNumber pin;
    relay_type type;
}RELAY;
/*
 * @breif:this function used to setup relay to the microcontroller and must be used with every relay used 
 * @para:variable fromRELAY data type
 * @return: void
 * @note: variable from RELAY datatype must be initialized 
 */
void relay_relaySetup(RELAY r);

/*
 * @breif: relay_realyState() function used to enable or disable the relay used
 * @para: variable from RELAY data type
 * @para: state if you want to turn it on --> {relay_on} if you ant to turn it off  --> {relay_off}  
 * @return: void
 * @note: variable fromRELAY data type must be initialized 
 */
void relay_relayState(RELAY r ,relay_state state);

#endif	/* relay_H_ */

