/* - Progetti di programmazione -

	6. modificate il proggetto di programmazione 5 in modo che il
	   polinomio venga calcolato utilizzando la seguente formula:
	   
	    ((((3x + 2)x - 5)x - 1)x + 7)x - 6)
	   
	   Notate che il programma modificato esegue meno moltiplicazioni.
	   Questa tecnica per calcolare i polinomi è conosciuta cine la
	   regola di Horner
 
*/
#include <stdio.h>

int main(void)
{

    int x = 0;

    printf("inserisci x: ");
    scanf("%d", &x);
    printf("Risultato: %d\n",
           ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);

    return 0;
}
