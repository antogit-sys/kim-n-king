/* Prog di prog
 *
 * 9. Write a program that prompts the user to enter two dates and then indicates which date comes earlier on the calandar:
 *  
 *  Enter first date (mm/dd/yyyy): 3/6/08
 *  Enter second date (mm/dd/yyyy): 5/17/07
 *
 *  5/17/07 is earlier than 3/6/08
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


typedef struct{
    int year;
    int month;
    int day;
}Date;

Date inputDate(const char*);
const char* view_date(Date);

int main(void)
{
    Date d1 = inputDate("Enter first date (mm/dd/yy): ");
    Date d2 = inputDate("Enter second date (mm/dd/yy): ");

    Date pd = FIND_SMALLER_DATE(d1, d2);
    printf("%s is earlier than %s\n", view_date(pd), view_date(pd == d1 ? d2 : d1));


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
