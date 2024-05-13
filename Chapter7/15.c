
#include <stdio.h>

typedef short Type;
//typedef int Type;

Type fact(Type);

int main(void)
{
    Type n;

    fputs("Enter a positive: ",stdout);
    scanf("%hd",&n);

    fprintf(stdout,"Factorial of %hd: %hd\n",n,fact(n));


return 0;
}

Type fact(Type n){
    Type done = 1;
    
    for(Type i = 2; i<=n; ++i)
        done*=i;

    return done;
}
