/* - Progetti di programmazione - 

	4. Scrivete un programma che chieda all'utente di inserire un 
	   importo in dollari e centesimi e successivamente lo stampi com
	   un addizionale del 5%

*/
#include <stdio.h>
int main(void)
{
	float amount = 0;
	 
	printf("Enter an amount: ");
	scanf("%f",&amount);
	
	printf("With tax added: %.2f",amount + (amount*5)/100); //5%

return 0;	
}
