/* - Progetti di programmazione
 
    9. Programming Project 8 in Chapter 2 asked you to write a program that 
    calculates the remaining balance on a loan after the first, second, and 
    third monthly payments. Modify the program so that it also asks the user 
    to enter the number of payments and then displays the balance remaining 
    after each of these payments.
*/

#include <stdio.h>
#define CALC_RATE(amount, rate)	(amount*rate/100)
	

float calc_balance_remaining(float*, float, float);

int main(void)
{
    float amount=20000.00f, rate=6.0f, monthly_payment=386.66f;
    int num_of_payments;
    
    printf("Enter amount of loan: ");
    //scanf("%f",&amount);
    
    printf("Enter interest rate: ");
    //scanf("%f",&rate);
	
    printf("Enter monthly payment: ");
    //scanf("%f",&monthly_payment);
    
    printf("Enter number of payments: ");
    scanf("%d", &num_of_payments);

    putchar('\n');

    for(size_t i=0; i<num_of_payments; ++i){
        amount -= monthly_payment;
        printf("Balance remaning after %d° payment: %.2f\n",
                i, calc_balance_remaining(&amount, rate, monthly_payment));
    }
	
return 0;	
}
float calc_balance_remaining(float* amount, float rate, float monthly_payment){
	
    float rate_monthly_interest = CALC_RATE(*amount, rate)/12;
    *amount = *amount-monthly_payment;
    *amount=*amount+rate_monthly_interest;
	
return *amount;
}
