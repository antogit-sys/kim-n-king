/*
 * - Progetti di prog
 *
 *   2. Write a program that asks the user for a 24-hour time, then displays the time in 12-hour form:
 *
 *          Enter a 24-hour time: 21:11
 *          Equivalent 12-hour time: 9:11 PM
 *      
 *      Be careful not to display 12:00 as 0:00.
 *
 *   ;)
 */

#include <stdio.h>

// Macro for converting time to 12-hour format
#define CONVERT_TO_12_HOUR(hours) ((hours == 0 || hours == 12) ? 12 : (hours % 12))

// Macro to determinate if the time is AM or PM
#define AM_PM(hours) (hours < 12 ? "AM" : "PM")

#define PRINTM_TIME(msg, hours,minutes)\
    (printf("%s%d:%.2d %s\n",msg,CONVERT_TO_12_HOUR(hours), minutes, AM_PM(hours)))

#define PRINT_TIME(hour, minutes)\
    (PRINTM_TIME("\r", hours, minutes))

int main(void)
{
    int hours, minutes;
    printf("Inserisci un'ora nel formato 24 ore: ");
    scanf("%d:%d", &hours, &minutes);
    
    /*
    printf("Tempo equivalente nel formato 12 ore: ");
    printf("%d:%.2d %s\n", CONVERT_TO_12_HOUR(hours), minutes, AM_PM(hours));
    */

    //print message and time
    PRINTM_TIME("Equivalent 12-hour time: ",hours,minutes);
    
    //print time
    PRINT_TIME(hours,minutes);

return 0;
}

