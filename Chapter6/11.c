/* Prog di prog
 *
 * 11. The value of the mathematical constant e 
 * can be expressed as an infinite series:
 *
 *  e = 1 + 1/1! + 1/2! + 1/3! + ...
 *
 * Write a program that approximates e by 
 * computing the value of
 *  
 *  1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
 *
 * where n is an integer entered by the user.
 *
 */

#include <stdio.h>
#define QUAD(n) (n*n)
int main(void)
{
    float e;
    int n;

    fputs("n? ",stdout);
    scanf("%d",&n);

    for(int i = 1, den=1; i <= n; ++i){
        e += 1.0f / (den*=QUAD(i));
    }

    printf("e: %f\n", e);

}
