/* 
 * File:   PIR.h
 * Author: Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef PIR_H_
#define	PIR_H_

typedef enum
{
    PIR_motionNotDetected,
    PIR_motionDetected,        
}motion_state;

/***************************************************************************@dataType*********************************************************************************************/
/*
 * @name: PIR
 * @intilization: PIR var_name = {port_name,pin_number};
 * @note: port_name -- > {A,B,C,D,E}                pin_number --> {PIN0,PIN1,PIN2,.....,PIN7}
 * @example: connecting PIR sensor at B0
 * ----------------------> PIR mySensor = {B,PIN0};
 */
typedef struct
{
    portName port;
    pinNumber pin;
}PIR;
/*
 * @breif:PIR_PIRSetup() is a function used to setup the PIR sensor to micro controller
 * @para: variable from PIR dataType
 * @return: void
 * @note: variable from PIR dataType must be initialized
 */
void PIR_PIRSetup(PIR pir);
/*
 * @breif:PIR_motionState() is a function used to determine the motionState if there is motion or not
 * @para: variable from PIR dataType
 * @return: PIR_motionNotDetected       ( OR)         PIR_motionDetected
 * @note: variable from PIR dataType must be initialized
 */
motion_state PIR_motionState(PIR pir);

#endif	/* PIR_H_ */

