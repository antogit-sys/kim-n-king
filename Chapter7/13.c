/* Prog di prog
 *
 * 14. Write a program that calculates the 
 * average word length for a sentence:
 *
 *  Enter a sentence: It was deja vu all over again.
 *  Average word length: 3.4
 *
 * For simplicity, your program should consider 
 * a punctuation mark to be part of the word to 
 * which it is attached. Display the average word 
 * length to one decimal place.
 */

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
