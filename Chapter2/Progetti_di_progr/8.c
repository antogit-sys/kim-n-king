/* - Progetti di programmazione
 
	8. Scrivete un programma che calcoli il saldo rimanente di un
	   prestito dopo il primo, il secondo e il terzo pagamento
	   mensile.
        
	   Enter amount of loan: 20000.00
	   Enter interest rate: 6.0
	   Enter monthly payment: 386.66
	   
	   Balance remaning after first payment: $19713.34
	   Balance remaning after second payment: $19425.25
	   Balance remaning after third payment: $19135.71
	   
	   
	   Visualizzate ogni saldo con due cifre decimali
	 
	   Suggerimento: ogni mese il saldo viene decrementato 
	   dell'ammontare del pagamento, ma viene incrementato del valore
	   del saldo moltiplicato per la rata di interesse. Per trovare la
	   rata mensile di interesse convertire il tasso d'interesse immesso
	   dall'utente in un numero percentuale e dividetelo per 12 (12 mesi)
*/

#include <stdio.h>
#define CALC_RATE(amount, rate)	(amount*rate/100)
	

float calc_balance_remaining(float*, float, float);

int main(void)
{
	float amount=20000.00f, rate=6.0f, monthly_payment=386.66f;
	const char* s[]={"first", "second", "thrid"};
	
	printf("Enter amount of loan: ");
	//scanf("%f",&amount);
	
	printf("Enter interest rate: ");
	//scanf("%f",&rate);
	
	printf("Enter monthly payment: ");
	//scanf("%f",&monthly_payment);
	
	putchar('\n');
	
	for(size_t i=0; i<3; ++i){
		printf("Balance remaning after %s payment: %.2f\n",
			s[i],calc_balance_remaining(&amount, rate, monthly_payment));
	}
	
return 0;	
}
float calc_balance_remaining(float* amount, float rate, float monthly_payment){
	
	float rate_monthly_interest = CALC_RATE(*amount, rate)/12;
	*amount = *amount-monthly_payment;
	*amount=*amount+rate_monthly_interest;
	
return *amount;
}
