/* - Progetti di programmazione -

	5. scrivete un programma che chieda all'utente di inserire un valore
       per x e poi visualizzi il valore del seguente polinomio:
        
       3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
       
       soluzione piu comune:
       result = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
*/

#include <stdio.h>

double pow(double, double);

int main(void)
{
	int x;
	int result = 0;
	
	printf("insert x: ");
	scanf("%d",&x);
	
	printf("3x%d^5 + 2x%d^4 - 5x%d^3 - %d^2 + 7*%d -6 \n",x,x,x,x,x);
	
	result = 3*pow(x,5) + 2*pow(x,4) - 5*pow(x,3) - pow(x,2) + 7*x - 6;  

	printf("result: %d",result);
return 0;	
}

double pow(double base, double esp){ /* base^esp */
	double done = 1;
	while(esp --> 0)
		done *= base;
	return done;
}
