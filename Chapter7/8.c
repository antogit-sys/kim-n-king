/*  - Prog di Prog
 *
 *  8. Modify Programming Project 8 from Chapter 5 so that
 *  the user enters a time using the 12-hour clock. The input 
 *  will have the form hours:minutes followed by either A, P, 
 *  AM or PM (either lower-case or upper-case). White space is 
 *  allowed (but not required) between the numerical time and 
 *  the AM/PM indicator. Examples of valid input:
 *
 *      1:15P
 *      1:15PM
 *      1:15p
 *      1:15pm
 *      1:15 P
 *      1:15 PM
 *      1:15 p
 *      1:15 pm
 *
 *  You may assume that the input has one of these forms; there 
 *  is no need to test for errors.
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NOP 0
#define CONVERT_TO_12_HOUR(hours) ((hours == 0 || hours == 12) ? 12 : (hours % 12))
#define CONVERT_TO_24_HOUR(hours, am_pm) ((hours == 12 ? 0 : hours) + (toupper(am_pm) == 'P' ? 12 : 0))

// Macro to determinate if the time is AM or PM
#define AM_PM(hours) (hours < 12 ? "AM" : "PM")

//#define PRINT_TIME(__s, t)	(fprintf(stdout, "%s%.2u:%.2u %s\n",__s, CONVERT_TO_12_HOUR(t.hours), t.minutes, AM_PM(t.hours)))

#define CALC_MINUTE(t)          (t.hours*60+t.minutes)

typedef struct{
    unsigned int hours;
    unsigned int minutes;
}Time;


Time input_t(const char*);
size_t find_nearest_time(Time*, size_t, Time);
const char* view_t(Time*, size_t);

int main(void)
{
    Time t;

    Time opart[] = {
        {8, 0},
        {9, 43},
        {11, 19},
        {12, 47},
        {14, 0},
        {15, 45},
        {19, 0},
        {21, 45}
    };
    
    Time oarr[] = {
        {10, 16},
        {11, 52},
        {13, 31},
        {15, 0},
        {16, 8},
        {17, 55},
        {21, 20},
        {23, 58}
    };
    
    size_t length = sizeof(oarr)/sizeof(oarr[0]);

    t = input_t("Enter a 12-hour time (hours:minutes am/pm): ");

    size_t index = find_nearest_time(opart,length,t);
    printf("Closest deapture time is %s, arriving at %s\n",view_t(opart, index), view_t(oarr,index));
    
return EXIT_SUCCESS;
}

Time input_t(const char* __s){
    Time t;
    int result;
    char am_pm;

    fprintf(stdout,"%s",__s);
    fflush(stdout);

    result = fscanf(stdin,"%u : %u %c",&t.hours, &t.minutes, &am_pm);
   
    if(t.hours>24 || t.minutes>59 || result != 3){
        fprintf(stderr,"%s","Error time! not valid\n");
        exit(EXIT_FAILURE);
    }

    am_pm = toupper(am_pm); // Converti in maiuscolo per confronto case-insensitive

    if (am_pm != 'A' && am_pm != 'P') {
        fprintf(stderr, "%s", "Error: Invalid AM/PM indicator!\n");
        exit(EXIT_FAILURE);
    }

    t.hours = CONVERT_TO_24_HOUR(t.hours, am_pm);

           
   return t;
}

size_t find_nearest_time(Time* opart, size_t length, Time user_t){
    size_t user_time = CALC_MINUTE(user_t);
    size_t jpos = 0;

    for(size_t i=1; i<length; ++i)
        (user_time > CALC_MINUTE(opart[i]))? ++jpos : NOP;
    
    return jpos;
}

const char* view_t(Time* array_t, size_t index){
    Time t = array_t[index];
    char* buf = (char*)malloc(sizeof(char)*9);
    
    if(buf == NULL){
        fputs("Memory allocation failed\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    sprintf(buf,"%.2u:%.2u %s",CONVERT_TO_12_HOUR(t.hours), t.minutes, AM_PM(t.hours));
    
    return buf;
}
