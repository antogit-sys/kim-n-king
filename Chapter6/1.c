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
