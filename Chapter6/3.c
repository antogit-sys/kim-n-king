/* - Progetti di prog
 *
 *  3.
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

typedef struct{
    int num;
    int den;
}fract;

int GCD_func(int, int);

int main(void)
{
    fract f;
   
    fputs("Enter a fraction: ",stdout);
    scanf("%d /%d",&f.num,&f.den);

    int mcd = GCD_func(f.num, f.den);

    fprintf(stdout,"In lowest terms: %d/%d\n", f.num/mcd, f.den/mcd);

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
