/* - Progetti di prog
 *
 *  4. Scrivete un programma che chieda all'utente di inserire un numero
 *  telefonico nella forma (xxx) xxx-xxxx e successivamente stampi il
 *  numero nella forma xxx.xxx.xxxx
 *
 */

#include <stdio.h>
#include <string.h>
#define N 15

typedef struct{
    int num;
    int den;
}fract;


int main()
{
    fract f1, f2;
    int result_num, result_denom;
    
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d /%d +%d /%d", &f1.num, &f1.den, &f2.num, &f2.den);

    result_num = f1.num * f2.den + f2.num * f1.den;
    result_denom = f1.den * f2.den;
    printf("The sum is %d/%d\n", result_num, result_denom);
    
return 0;
}    

