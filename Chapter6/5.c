/*  - Progetti di prog
 *  
 *  5. Programming Project 1 in Chapter 4 asked you to write 
 *  a program that displays a two-digit number with its 
 *  digits reversed. Generalize the program so that the 
 *  number can have one, two, three, or more digits. 
 *
 *  Hint: Use a do loop that repeatedly divides the number 
 *  by 10, stopping when it reaches 0. 
 * _________________________________________________________
 */


#include <stdio.h>

#define OUT_NUM_REV(n)\
    do{\
        do{\
            fprintf(stdout,"%d",n%10);\
        }while((n/=10) != 0);\
        putchar('\n');\
    }while(0)

int main(void)
{
    int num;
    
    fputs("Enter an integer number: ",stdout);
    scanf("%d", &num);
    
    fprintf(stdout,"The reversal is: ");
    OUT_NUM_REV(num);
    
    /*
    do{
        printf("%d", num%10);
    }while((num/=10) != 0);
    putchar('\n');

    */
return 0;
}
