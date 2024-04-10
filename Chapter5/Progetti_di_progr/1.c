/*
 * - Progetti di Prog
 *
 *  1. Write a program that calculates how many digits a number contains:
 *      
 *      Enter a number: 374
 *      The number 374 has 3 digits
 *     
 *     You many assume that the number has no more than four digits. Hint: Use 
 *     if statements to test the number. For example, if the number is 
 *     between 0 and 9, it has one digit. If the number is between 10 and 99,
 *     it has two digits.
 *
 *     XD
 */
#include <stdio.h>

size_t CALC_DIGITS(size_t n){
    size_t temp = n;
    size_t counter = 0;

    for(; temp != 0; ++counter){
        temp/=10;
    }
    return counter;

}

int main(void){
    int n,nd;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    nd = CALC_DIGITS(n);

    printf("The number %d has %d digits\n", n, nd);

    return 0;
}

