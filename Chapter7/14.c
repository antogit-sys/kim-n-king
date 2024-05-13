#include <stdio.h>
#include <math.h>

#define AVERAGE(n1, n2) ((n1 + n2)/2.0)
#define TERM(y) (.00001*y)

int main(void)
{
    double x;
    double y = 1.0, newY;
   
    fputs("Enter a positive number: ",stdout);
    scanf("%lf",&x);

    do{
        y = AVERAGE(y, x/y); 
        newY = AVERAGE(y, x/y);
    }while(fabs(y - newY) >= TERM(y));

    fprintf(stdout,"Square root: %lf\n",y);

return 0;
}
