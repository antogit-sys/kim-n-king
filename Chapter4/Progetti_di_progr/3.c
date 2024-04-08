/*  - Progetti di prog
 *  
 *  3. Riscrivete il programma del Progetto di Programmazione 2 in modo che stampi
 *  la scrittura inversa di un numero a 3 cifree senza utilizzare calcoli aritmetici per
 *  dividere il numero in cifre.
 *  ~Suggerimento: Guardatre il programma upc.c della Sezione 4.1
 * ________________________________________________________________________________
 */


#include <stdio.h>
int main(void)
{
    int start, middle, end;

    fputs("Enter a three-digit number: ",stdout);
    fscanf(stdin,"%1d%1d%1d", &start, &middle, &end);

    fprintf(stdout,"The reaversal is: %d%d%d\n", end, middle, start);

return 0;
}
