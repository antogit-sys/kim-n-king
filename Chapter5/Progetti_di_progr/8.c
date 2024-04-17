#include <stdio.h>
#include <stdlib.h>

#define CONVERT_TO_12_HOUR(hours) ((hours == 0 || hours == 12) ? 12 : (hours % 12))

// Macro to determinate if the time is AM or PM
#define AM_PM(hours) (hours < 12 ? "AM" : "PM")

#define PRINT_TIME(__s, t)	(fprintf(stdout, "%s%.2u:%.2u %s\n",__s, CONVERT_TO_12_HOUR(t.hours), t.minutes, AM_PM(t.hours)))

#define CALC_MINUTE(t)          (t.hours*60+t.minutes)

typedef struct{
    unsigned int hours;
    unsigned int minutes;
}Time;


Time input_t(const char*);
const char* view_t(Time);
size_t find_nearest_time(Time*, size_t, Time);
const char* s
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

    //printf("%ld\n",find_nearest_time(opart,length,t));
    //printf("Closest deapture time is %s, arriving at %s",view_t(t), view_arriving_t(oarr));

return EXIT_SUCCESS;
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
const char* view_t(Time t){
    //00:00·[AM/PM] charter max = 8+1;
    char* __s = malloc(sizeof(char)*9);
    
    if(__s == NULL){
        fprintf(stderr,"%s","Error! dynamic allocation failed\n");
        exit(EXIT_FAILURE);
    }

    sprintf(__s, "%.2u:%.2u %s", CONVERT_TO_12_HOUR(t.hours), t.minutes, AM_PM(t.hours));
    return __s;
}

size_t find_nearest_time(Time* opart, size_t length, Time user_t){
    size_t user_time = CALC_MINUTE(user_t);
    size_t opart_min_time = CALC_MINUTE(opart[0]);
    
    size_t jpos = 0;

    for(size_t i=1; i<length; ++i){
        size_t cmtd = CALC_MINUTE(opart[i]); //departure
        if(user_time > cmtd){
            opart_min_time = cmtd;
            ++jpos;
        }
    }
    return jpos;
}

