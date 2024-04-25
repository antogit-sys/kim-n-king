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
