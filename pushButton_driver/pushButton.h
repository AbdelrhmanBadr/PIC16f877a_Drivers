/* 
 * File:   pushButton.h
 * Author: Abdelrhman Badr 
 * Comments:
 * Revision history: 
 */

  
#ifndef pushButton_H_
#define	pushButton_H_

typedef enum
{
    pushButton_pullUp,
    pushButton_pullDown,        
}pushButton_connectionType;

typedef enum
{
    pushButtonReleased,
    pushButtonPressed,        
}pushButton_state;
/*******************************************@dataType****************************************************
 * @name:PUSHBUTTON 
 * @initialization: PUSHBUTTON var_name = {port_name , pin_number , connectionType}
 * @note: port_name = {A,B,C,D,E}           pin_number = {PIN0,PIN1,..}          connectionType = {pushButton_pullUp,pushButton_pullDown}
 * @example: to connect pull down push button at C5
 -----------------------------> PUSHBUTTON myButton = {C,PIN5,pushButton_pullDown};
 */
typedef struct
{
    portName port;
    pinNumber pin;
    pushButton_connectionType connectionType;
}PUSHBUTTON;
/*
 * @breif: pushButton_pushButtonSetup() is a function that used to setup the push button to microcontroller
 * @para:variable from PUSHBUTTON data type
 * @return: void
 * @note: variable from PUSHBUTTON data type must be initialized
 * @note: This function must be used with every push button in the project
 */
void pushButton_pushButtonSetup(PUSHBUTTON pb);
/*
 * @breif: pushButton_pushButtonState() is a function that used to determine the state of the push button
 * @para:variable from PUSHBUTTON data type
 * @return: PRESSED --> if the push button is pressed       RELEASED--> if the pushbutton is not pressed 
 * @note: variable from PUSHBUTTON data type must be initialized
 */
pushButton_state pushButton_pushButtonState(PUSHBUTTON pb);

#endif	/* pushButton_H_ */

