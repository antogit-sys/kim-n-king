/* - Progetti di prog
 *
 *   1. prompt the user to enter numbers one by one, 
 *   When the user enters 0 or a negative number, the 
 *   program must display the largest nonnegative number 
 *   entered:
 *      
 *      Enter a number: 60
 *      Enter a number: 38.3
 *      Enter a number: 4.89
 *      Enter a number: 100.62
 *      Enter a number: 75.2295
 *      Enter a number: 0
 *
 *   The largest number entered was 100.62
 *   Notice that the numbers aren't necessarily integers.
*/

#include <stdio.h>

#define NUM_MAX_POSITIVE(n, max) if(n > 0) max = max>n?max:n

int main(void)
{
    float n,max;
    do{
        fputs("Enter a number: ",stdout);
        scanf("%f",&n);

        //if(n > 0) max = max>n?max:n;
        NUM_MAX_POSITIVE(n, max);

    }while(n>0 || n<0);

    fprintf(stdout,"The largest number entered was %.2f\n",max); 

return 0;
}
