/* - Progetti di programmazione

	7. Scrivete un programma che chieda all'utente di inserire un 
	   importo in dollari e poi mostri come pagarlo utilizzando il
	   minor numero di biglietti da 20$, 10$, 5%, e 1$:
	   
	   Enter a dollar amount: 93
	   $20 bills: 4
	   $10 bills: 1
	   $5  bills: 0
	   $1  bills: 3
  
 */
#include <stdio.h>

int main(void)
{
	int amount = 0;
	int coins[] = {20, 10, 5, 1};
	int size = sizeof(coins) / sizeof(coins[0]);
	
	printf("Enter a dollar amount: ");
	scanf("%d",&amount);
	
	for(int i=0; i<size; ++i){
		int num = amount / coins[i]; //calcolo numero di biglietti per quei $
		amount%=coins[i]; //aggiorno l'ammontare (resto della divisione)
		printf("$%d bills: %d\n",coins[i],num);
	}
	
return 0;	
}
