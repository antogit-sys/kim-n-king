/* Prog di prog
 *
 * 10. Write a program that counts the number 
 * of vowels (a, e, i, o and u) in a sentence:
 *
 *  Enter a sentence: And that's the way it is.
 *  Your sentence contains 6 vowels.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IS_VOWELS(c)    (c=='A'|| c=='E' || c=='I' || c=='O' || c=='U') 

long vowels_count(const char*);

int main(void)
{
    int v;
    
    v = (int) vowels_count("Enter a sentence: ");
    
    fprintf(stdout,"Your sentence contains %d vowels.\n",v);

return 0;
}

long vowels_count(const char* s){
    long done = 0;
    char ch;

    fputs(s,stdout);
    fflush(stdout);

    while((ch = toupper(getchar())) != '\n') 
        IS_VOWELS(ch)? ++done:0;
    
    return done;
}
