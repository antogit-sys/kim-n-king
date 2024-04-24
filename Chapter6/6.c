/*  - Progetti di prog
 *  
 *  5. Write a program that prompts the user to enter a 
 *  number n, then prints all even squares between 1 
 *  and n. For example, if the user enters 100, the 
 *  program should print the following:
 *
 *      4
 *      16
 *      36
 *      64
 *      100
 * ________________________________________________________
 */


#include <stdio.h>
#include <stdlib.h>

#define QUAD(n) (n*n)

void print_q(int long);

int main(void)
{
    int num;
    
    fputs("Enter an integer number: ",stdout);
    scanf("%d", &num);

    print_q(num);
   

return EXIT_SUCCESS;
}

void print_q(int long n){
    if(n <= 0){
        fputs("Error! print_q: negative number or zero\n",stderr);
        exit(EXIT_FAILURE);
    }

    for(int i = 2; n >= QUAD(i); i+=2)
        printf("%d\n",QUAD(i));

}
