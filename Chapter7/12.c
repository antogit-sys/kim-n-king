/* Prog di prog
 *
 * 12. Write a program that evaluates an expression:
 *  
 *  Enter an expression: 1+2.5*3
 *  Value of expression: 10.5
 *
 * The operands in the expression are floating-point 
 * numbers; the operators are +, -, * and /. The expression 
 * is evalued from left to right (no operator taes precedence 
 * over any other operator).
 **/

#include <stdio.h>

int main(void)
{
    int ch;
    float tot=0.0f, num=0.0f;

    fputs("Enter an expression: ",stdout);
    scanf("%f",&tot);

    while((ch = getchar()) != '\n'){

        switch(ch){
            case '+':
                scanf("%f",&num);
                tot+=num;
                break;

            case '-':
                scanf("%f",&num);
                tot-=num;
                break;

            case '*':
                scanf("%f",&num);
                tot*=num;
                break;

            case '/':
                scanf("%f",&num);
                tot/=num;
                break;

            default:
                break;
        }

    }

    fprintf(stdout,"Value of expression: %.1f\n",tot);

return 0;
}
