/* - Progetti di prog
 *
 *  6. modificate il programma addfrac.c della Sezione 3.2 in modo che l'utente
 *  immetta allo stesso tempo entrambe le frazioni separate da un segno più:
 *  
 *  Enter two fractions separated by a plus sign: 5/6+3/4
 *  The sum is 38/24
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
}fract;


int main()
{
    fract f1, f2;
    char op;
    int result_num, result_denom;
    
    printf("Enter two fractions separated by an operator sign: ");
    scanf("%d /%d %c %d /%d", &f1.num, &f1.den, &op, &f2.num, &f2.den);

    switch(op){
        case '+':
            result_num = f1.num * f2.den + f2.num * f2.den;
            break;
        case '-': 
            result_num = f1.num * f2.den - f1.num * f2.den;
            break;
        case '*':
            result_num = f1.num * f2.num;
            break;
        case '/':
            result_num = f1.num / f2.num;
            break;
        default:
            fprintf(stderr,"Operation (%c) not supported!\n",op);
            exit(EXIT_FAILURE);
            
    }

    result_denom = f1.den * f2.den;

    if(result_denom == result_num){
        printf("The (%c) is %d\n", op, result_num/result_denom);
        exit(EXIT_SUCCESS);
    }
        

    printf("The (%c) is %d/%d\n",op , result_num, result_denom);
    
return EXIT_SUCCESS;
}    

