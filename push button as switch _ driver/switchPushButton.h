/* 
 * File:   switchPushButton.h
 * Author: Abdlerhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef switchPushButton_H_
#define	switchPushButton_H_

/*
 * @const: bouncingTime_ms is indicating the bouncing time in milliseconds for the pushButton
 */
#define bouncingTime_ms (50)
typedef enum
{
    switchPushButtonNotPressed,
    switchPushButtonPressed,
}switch_pushButton_state;

typedef enum
{
    switchPushButton_pullUp,
    switchPushButton_pullDown,        
}switch_pushButton_connectionType;

/*
 * *********************************************************@dataType*********************************************************************
 * @name:SWITCHPUSHBUTTON
 * @initialization: SWITCHPUSHBUTTON variable_name = {port_name , pin_number , connection_type};
 * @Notes: port_name{A,B,C,D,E}           pin_number{PIN0,PIN1,PIN2,.......,PIN7}       connection_type{switchPushButton_pullUp,switchPushButton_pullDown}
 */
typedef struct
{
    portName port;
    pinNumber pin;
    switch_pushButton_connectionType connectionType;
}SWITCHPUSHBUTTON;

/*
 * @breif: switchpushButton_pushButtonSetup() is a function that used to setup the push button to microcontroller
 * @para:variable from SWITCHPUSHBUTTON data type
 * @return: void
 * @note: variable from SWITVHPUSHBUTTON data type must be initialized
 * @note: This function must be used with every push button in the project
 */
void switchPushButton_pushButtonSetup(SWITCHPUSHBUTTON pb);

/*
 * @breif: switchpushButton_pushButtonState() is a function that used to determine the state of the push button
 * @para:variable from PUSHBUTTON data type
 * @return: switchPushButtonNotPressed --> if push button is pressed                 switchPushButtonPressed --> if push button is not pressed  
 * @note: variable from SWITCHPUSHBUTTON data type must be initialized
 */
switch_pushButton_state switchPushButton_pushButtonState(SWITCHPUSHBUTTON pb);
#endif	/* switchPushButton_H_ */

