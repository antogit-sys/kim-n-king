/* Prog di prog
 *
 * 12. Modify Programming Project 11 so that the program 
 * continues adding terms until the current term becomes 
 * less than epsilon, where epsilon is a small (floating-point) 
 * number entered by the user.
 *
 */

#include <stdio.h>

int fact(int n){
    int done = 1;
    for(int i = 1; i<=n; ++i){
        done*=i;
    }
    return done;
}

int main(void)
{
        
    float e=2.0f;
    float E,current;
    int i=1;

    printf("epsilon> ");
    scanf("%f",&E);

    do{
        current = 1.0f / fact(++i);
        e+=current;
    }while(current > E);
    
    printf("%f < %f\n",current,E);
    printf("e: %f\n",e);
    
return 0;
}
