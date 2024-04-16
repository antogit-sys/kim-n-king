#include <stdio.h>
#include <stdlib.h>

#define CONVERT_TO_12_HOUR(hours) ((hours == 0 || hours == 12) ? 12 : (hours % 12))

// Macro to determinate if the time is AM or PM
#define AM_PM(hours) (hours < 12 ? "AM" : "PM")

#define PRINT_TIME(__s, t)	(fprintf(stdout, "%s%.2u:%.2u %s\n",__s, CONVERT_TO_12_HOUR(t.hours), t.minutes, AM_PM(t.hours)))

#define CALC_MINUTE(t) (t.hours*60+t.minutes)

typedef struct{
    unsigned int hours;
    unsigned int minutes;
}Time;


Time input_t(const char*);
void print_t(const char*, Time);
void find_nearest_time(Time, Time);

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

    int size = sizeof(oarr)/sizeof(oarr[0]);

    t = input_t("Enter a 24-hour: ");
    int user_time = CALC_MINUTE(t);

    PRINT_TIME("Test: ",t);

    /* work in progress... */

return 0;
}

Time input_t(const char* __s){
    Time t;
    int result; 

    fprintf(stdout,"%s",__s);
   
    result = fscanf(stdin,"%u:%u",&t.hours, &t.minutes);
   
    if(t.hours>24 || t.minutes>59 || result == 0){
        fprintf(stderr,"%s","Error time! not valid\n");
        exit(1);
    }
           
   return t;
}


