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
 *  - * Solutions * - 
 * (a) 7
 * (b) 13
 * (c) 20
 * (d) 20
 * (e) 34
 * (f) 170
 * (g) 1754
 *
 **/

#include <stdio.h>

//typedef short Type;
//typedef int Type;
//typedef long Type;
//typedef long long Type;
//typedef float Type;
//typedef double Type;
typedef long double Type;

Type fact(Type);

int main(void)
{
    Type n;

    fputs("Enter a positive: ",stdout);
    scanf("%Lf",&n);

    fprintf(stdout,"Factorial of %Lf: %Lf\n",n,fact(n));


return 0;
}

Type fact(Type n){
    Type done = 1;
    
    for(Type i = 2; i<=n; ++i)
        done*=i;

    return done;
}
