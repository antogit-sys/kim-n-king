/* Prog di prog
 *
 * 10. Programming Project 9 in Chapter 5 asked you 
 * to write a program that determines which of two 
 * dates comes earlier on the calendar. Generalize the 
 * program so that the user may enter any number of dates. 
 * The user will enter 0/0/0 to indicate that no more dates 
 * will be entered:
 *  
 *  Enter a date (mm/dd/yy): 3/6/08
 *  Enter a date (mm/dd/yy): 5/17/07
 *  Enter a date (mm/dd/yy): 6/3/07ù
 *  Enter a date (mm/dd/yy): 0/0/0
 *  5/17/07 is the earliest date
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIND_SMALLER_DATE(date1, date2) \
    ((date1.year != date2.year)? \
        ((date1.year < date2.year) ? date1 : date2) : \
        ((date1.month != date2.month) ? \
            ((date1.month < date2.month) ? date1 : date2) : \
            ((date1.day < date2.day) ? date1 : date2)))


#define dateIsZero(d)   (d.day == 0 && d.month == 0 && d.year == 0)

typedef struct{
    int year;
    int month;
    int day;
}Date;

Date inputDate(const char*);
const char* view_date(Date);

int main(void)
{
    Date d;
    Date min = inputDate("Enter a date (mm/dd/yy): ");
    while(!(dateIsZero(min) || dateIsZero(d))){
        d = inputDate("Enter a date (mm/dd/yy): ");
        min = dateIsZero(d)?min:FIND_SMALLER_DATE(d,min);
    }
    
    printf("%s is earlier date", view_date(min));


return EXIT_SUCCESS;
}

Date inputDate(const char* __s){
    Date d;
    int result;

    fprintf(stdout,"%s",__s);
    result = fscanf(stdin,"%d/ %d/ %d", &d.month, &d.day, &d.year);

    if(result == 0){
        fprintf(stderr,"Error! format date not valid, line %d\n",__LINE__);
        exit(EXIT_FAILURE);
    }

    return d;
}

const char* view_date(Date d){
    /* 00/00/00 = max charter = 8+1 */
    char* buf = (char*)malloc(sizeof(char)*9);
    
    if(buf == NULL){
        fprintf(stderr,"Error! Memory Allocation failed, line: %d\n",__LINE__);
        exit(EXIT_FAILURE);
    }

    sprintf(buf,"%.2d/%.2d/%.2d",d.month, d.day, d.year);
    
    if(strlen(buf) > 9){
        fprintf(stderr, "Error! string too long, max 9 charter, line: %d\n",__LINE__);
        exit(EXIT_FAILURE);
    }

    return buf;
}
