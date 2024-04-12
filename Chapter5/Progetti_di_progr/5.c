/*
 *  - Progetti di  prog
 *  
 *  5.In one state, single residents are subject to the 
 *  following income tax:
 *
 *       Income          Amount of tax
 *       +-------------+----------------------------------------+    
 *       Not over $750 	1%      of income 	
 *       $750-$2,250 	$7.50 	plus 2% of amount over $750
 *       $2,250-$3,750 	$37.50 	plus 3% of amount over $2,250
 *       $3,750-$5,250 	$82.50 	plus 4% of amount over $3,750
 *       $5,250-$7,000 	$142.50 plus 5% of amount over $5,250
 *       Over $7,000 	$230.00	plus 6% of amount over $7,000
 *       +-------------+----------------------------------------+
 *    
 *   Write a program that asks the user to enter the amount 
 *   of taxable income, then displays the tax due.
*/

#include <stdio.h>

float putAmountOfTax(float);

int main(void)
{
   float income;

   fputs("Enter the your imponible income: ",stdout);
   scanf("%f",&income);
      
   fprintf(stdout,"amount of tax: %.2f\n",putAmountOfTax(income));

return 0;
}

float putAmountOfTax(float income){
    float done;

    if(income <= 750.00f)
        done = income * .01f;
    else if(income <= 2250.00f)
        done = 7.50f + (.02f * (income - 750.00f));
    else if(income <= 3750.00f)
        done = 37.50f + (.03f * (income - 2250.00f));
    else if(income <= 5250.00f)
        done = 82.50f + (.04f * (income - 3750.00f));
    else if(income <= 7000)
        done = 142.50f + (.05f * (income - 5250.00f));
    else
        done = 230.00f + (.06f * (income - 7000.00f));

    return done;
}
