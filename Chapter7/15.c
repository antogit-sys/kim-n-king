/* - Prog di prog
 *
 * 15. Write a program that computes the factorial of a positive integer:
 *  
 *  Enter a positive integer: 6
 *  Factorial of 6: 720
 *
 * (a) Use a short variable to store the value of the factorial. What is the 
 * largest value of n for which the program correctly prints the factorial of n?
 * (b) Repeat part (a), using an int variable instead.
 * (c) Repeat part (a), using a long variable instead.
 * (d) Repeat part (a), using a long long variable instead (if your compiler 
 * supports the long long type.
 * (e) Repeat part (a), using a float variable instead.
 * (f) Repeat part (a), using a double variable instead.
 * (g) Repeat part (a), using a long double variable instead.
 *
 * In cases (e)-(g), the program will display a close approximation of the 
 * factorial, not necessarily the exact value.
 *
 *
 **/

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
