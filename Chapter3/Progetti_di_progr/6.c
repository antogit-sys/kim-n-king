/* - Progetti di prog
 *
 *  6. modificate il programma addfrac.c della Sezione 3.2 in modo che l'utente
 *  immetta allo stesso tempo entrambe le frazioni separate da un segno più:
 *  
 *  Enter two fractions separated by a plus sign: 5/6+3/4
 *  The sum is 38/24
 *
 */

#include <stdio.h>

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

