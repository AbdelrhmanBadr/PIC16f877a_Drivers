/* 
 * File:   sevenSegment.h 
 * Author:  Abdelrhman Badr
 * Comments:
 * Revision history: 
 */

#ifndef sevenSegment_H_
#define	sevenSegment_H_

typedef enum
{
    sevenSegment_commonAnode,
    sevenSegment_commonCathode,        
}_7SEG_type;

typedef enum
{
    ZERO,ONE,TWO,THREE,
    FOUR,FIVE,SIX,SEVEN,
    EIGHT,NINE,        
}_7SEG_num;

/****************************************************@dataType********************************************************** 
 * @name: SEVENSEGMENT
 * @initialization: SEVENSEGMENT var_name = {port_name , sevenSegment_type};
 * @notes: port_name --> {B-C-D}                    sevenSegment_type --> {sevenSegment_commonAnode,sevenSegment_commonCathode}
 * @note:This variable must be initialized
 * @example: connecting common cathode seven segment display at portB
 * -------------------------------> SEVENSEGMENT mySegment = {B,sevenSegment_commonCathode}
 */
typedef struct
{
    portName port;
    _7SEG_type type;
    
}SEVENSEGMENT;
/*
 * @breif: sevenSegment_7segSetup() function used to setup seven segment to the controller
 * @para: variable from SEVENSEGMENT data type
 * @return: void
 * @note: The variable from SEVENSEGMENT data type must be initialized
 * @note:This function must used with every seven segment in project
 */
void sevenSegment_7segSetup (SEVENSEGMENT seg);
/*
 * @breif: This function is used to display a number at the seven segment
 * @para: variable from SEVENSEGMENT data type
 * @para: The number that will be displayed {ZERO,ONE,TWO,..........,NINE}
 * @return: void
 * @note: The variable from SEVENSEGMENT data type must be initialized
 */
void sevenSegment_7segDisplay(SEVENSEGMENT seg , _7SEG_num num);
#endif	/* sevenSegment_H_ */

