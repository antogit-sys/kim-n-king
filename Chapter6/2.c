/* - Progetti di prog
 *
 *  2. Write a program that asks the user to enter 
 *  two integers, then caluclates and displays 
 *  their greatest common divison (GCD):
 *
 *      Enter two integers: 12 28
 *      Greatest common divisor: 4
 *
 *  Hint: The classic algorithm for computing the GCD, 
 *  known as Euclid's algorithm, goes as follows: Let m 
 *  and n be variables containing the two numbers. If n 
 *  is 0, then stop: m contains the GCD. Otherwise, compute 
 *  the remainder when m is divided by n. Copy n into m and 
 *  copy the remainder into n. Then repeat the process, starting 
 *  with testing whether n is 0.
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
