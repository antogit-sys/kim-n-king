/*  - Progetti di prog
 *  
 *  2. Estendete il programma del progetto 1 per gestire i numeri a
 *  tre cifre
 * _________________________________________________________________
 */


#include <stdio.h>
int main(void)
{
    int num;

    fputs("Enter a three-digit number: ",stdout);
    scanf("%d", &num);

    fprintf(stdout,"The reversal is: %d%d%d\n", num%10, num/10 % 10, num/100);

return 0;
}
