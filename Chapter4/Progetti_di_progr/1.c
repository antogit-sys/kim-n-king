/*  - Progetti di prog
 *  
 *  1. Scrivete un programma che chieda all'utente di immettere un numero a due
 *  cifre e successivamente stampi il numero con le cifre invertite. Una sessione del
 *  programma deve presentarsi come segue:
 *
 *  Enter a two-digit number: 28
 *  The reversal is: 82
 *
 *  Leggete il numero usando la specifica %d e poi suddividetelo in 2 cifre.
 *  ~ Suggerimento: Se n è un intero allora n%10 è l'ultima cifra di n, mentre
 *                  n/10 è n con ultima cifra rimossa
 * ___________________________________________________________________________________
 */


#include <stdio.h>
int main(void)
{
    int num;

    fputs("Enter a two-digit number: ",stdout);
    scanf("%d", &num);

    fprintf(stdout,"The reversal is : %d%d\n", num%10, num/10);

return 0;
}
