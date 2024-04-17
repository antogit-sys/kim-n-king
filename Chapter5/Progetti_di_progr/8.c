/*  - Prog di Prog
 *
 *  8. The following table shows the daily flights from one city to another:
 *       
 *       Departure time     Arrival time
 *       8:00 a.m.          10:16 a.m.
 *       9:43 a.m.          11:52 a.m.
 *       11:19 a.m.         1:31 p.m.
 *       12:47 p.m.         3:00 p.m.
 *       2:00 p.m.          4:08 p.m.
 *       3:45 p.m.          5:55 p.m.
 *       7:00 p.m.          9:20 p.m.
 *       9:45 p.m.          11:58 p.m.
 *
 *     Write a program that asks the user to enter a time (expressed in 
 *     hours and minutes, using the 24-hour clock). The program then displays 
 *     the departure and arrival times for the flight whose departure time is 
 *     closest to that entered by the user:
 *
 *      Enter a 24-hour time: 13:15
 *      Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
 *
 *     Hint: Convert the input into a time expressed in minutes since midnight, 
 *     and compare it to the departure times, also expressed in minutes since midnight. 
 *     For example, 13:15 is 13 * 60 + 15 = 795 minutes since midnight, which is closer 
 *     to 12:47 p.m. (767 minutes since midnight) than to any of the other departure times.
 *
 */ 

#include <stdio.h>
#include <stdlib.h>

#define NOP 0
#define CONVERT_TO_12_HOUR(hours) ((hours == 0 || hours == 12) ? 12 : (hours % 12))

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

    t = input_t("Enter a 24-hour: ");

    size_t index = find_nearest_time(opart,length,t);
    printf("Closest deapture time is %s, arriving at %s\n",view_t(opart, index), view_t(oarr,index));
    
return EXIT_SUCCESS;
}

Time input_t(const char* __s){
    Time t;
    int result; 

    fprintf(stdout,"%s",__s);
   
    result = fscanf(stdin,"%u:%u",&t.hours, &t.minutes);
   
    if(t.hours>24 || t.minutes>59 || result == 0){
        fprintf(stderr,"%s","Error time! not valid\n");
        exit(EXIT_FAILURE);
    }
           
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
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    sprintf(buf,"%.2u:%.2u %s",CONVERT_TO_12_HOUR(t.hours), t.minutes, AM_PM(t.hours));
    
    return buf;
}
