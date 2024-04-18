#include <stdio.h>
#include <stdlib.h>

#define BETWEEN(a,n1,n2) (a>=n1 && a<=n2)

#define CALC_GRADE(n)\
    (BETWEEN(n,90,100)?"A":\
     (BETWEEN(n,80,89)?"B": \
      (BETWEEN(n,70,79)?"C": \
       (BETWEEN(n,60,69)?"D": \
        (BETWEEN(n,0,59)?"F":"**ERROR CALC GRADE***")))))

int main(void)
{
    int n=10;
    
    printf("%s",CALC_GRADE(n));
    

return EXIT_SUCCESS;
}
