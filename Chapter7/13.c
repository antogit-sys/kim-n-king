
#include <stdio.h>

int main(void)
{
    int cw = 1, cl = 0;

    fputs("Enter a sentence: ",stdout);

    for(int ch; (ch=getchar()) != '\n'; )
        (ch == ' ')?cw++:cl++;

    fprintf(stdout,"Average word length: %.1f\n",(float)cl/cw);


return 0;
}
