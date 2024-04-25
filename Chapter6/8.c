/* - Proge di prog
 *  
 *  8. Write a program that prints a one-month calendar. 
 *  The user specifies the number of days in the month and 
 *  the day of the week on which the month begins:
 *      
 *      Enter number of days in month: 31
 *      Enter starting day of the week (1=Sun, 7=Sat): 3
 *
 *            1  2  3  4  5
 *      6  7  8  9  10 11 12
 *      13 14 15 16 17 18 19
 *      20 21 22 23 24 25 26
 *      27 28 29 30 31
 *
 *  Hint: This program isn't as hard as it looks. The most 
 *  important part is a for statement that uses a variable i 
 *  to count from 1 to n, where n is the number of days in the 
 *  month, printing each value of i. Inside the loop, an if statement 
 *  tests whether i is the last day in a week; if so, it prints a 
 *  new-line character.
 */

#include <stdio.h>
#define SPACE() (fputs("   ",stdout)) 
#define PRINT_DAY(d) (fprintf(stdout,"%3d", d))

void print_calendar(int,int);

int main()
{
    int n, start;
    
    fputs("Enter number of days in month: " ,stdout);
    scanf("%d", &n);
    fputs("Enter starting day of the wek(1=Sun, 7=Sat): ",stdout);
    scanf("%d", &start);

    putchar('\n');
    print_calendar(n, start);
    putchar('\n');

    /*
    putchar('\n');
    puts(" Mo Tu We Th Fr Sa Su");
    for(int i = 1, day = 1; i <= n+start-1; ++i){
        (i<start)? SPACE(): PRINT_DAY(day++);
        
        if(i%7 == 0) putchar('\n');
    }
    putchar('\n');
    */
}

void print_calendar(int n_day, int start){
    puts(" Mo Tu We Th Fr Sa Su");
    for(int i = 1, day = 1; i <= n_day+start-1; ++i){
        (i<start)? SPACE(): PRINT_DAY(day++);

        if(i%7 == 0) putchar('\n');
    }
}
