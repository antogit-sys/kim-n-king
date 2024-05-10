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
