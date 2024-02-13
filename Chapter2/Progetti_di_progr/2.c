/* - Progetti di programmazione -

	2. Scrivete un programma che calcoli il volume di una sfera con un 
       raggio di 10 metri utilizzando la formula:
       v = 4/3PIr^3 --> PI Greco
       
       Scrivete la frazione 4/3 come 4.0f/3.0f (Provate a scriverlo 
       come 4/3 cosa succede?) Suggerimento: il C non possiede un 
       operatore esponenziale quindi per calcolare r^3 avete la
       necessità di moltiplicare r più volte per se stesso
 
*/
#include <stdio.h>
int main(void)
{
	int r = 10; //raggio
	float v = 4.0f/3.0f*3.14f*r*r*r; //volume
	printf("raggio: %d\n",r);
	printf("volume: %.2f\n",v);
	
return 0;	
}
