/* - Progetti di prog
 *
 *  2.
 *
 **/

#include <stdio.h>
#include <stdlib.h>

#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            fputs((s), stderr);\
            exit(EXIT_FAILURE);\
        }\
    }while(0) 

int GCD_func(int, int);

int main(void)
{
    int n1,n2;
    
    fputs("Enter two integers: ",stdout);
    scanf("%d%d",&n1,&n2);

    fprintf(stdout,"Greatest common divisor: %d\n", GCD_func(n1, n2));

return 0;
}

int GCD_func(int m, int n){
    int r = 1;

    EXIT_IF(n<m, "Error! m must be greater than n\n");

    while(r != 0){
        r = m%n;
        m = n;
        n = r;
    }

    return m;
}
