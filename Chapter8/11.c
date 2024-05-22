/* Prog di prog 8
 *
 * 11. Modify Programming Project 4 from Chapter 7 so that 
 * the program labels its output:
 *  
 *  Enter phone number: 1-800-COL-LECT
 *  In numeric form: 1-800-265-5328
 *
 * The program will need to store the phone number (either 
 * in its original form or in its numeric form) in an array 
 * of character until it can be printed. You may assume that 
 * the phone number is no more than 15 characters long.
 *
 **/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OUT_CHAR_ARRAY(v,n)  for(size_t i=0; i<n; ++i) putchar(v[i])
#define NEW_ARRAY(t,n)  ((t*)malloc(sizeof(t)*n))

#define N 15

char* input_phone_num(const char*);

int main(void)
{
    char *v = NEW_ARRAY(char, N);
    
    v = input_phone_num("Enter a phone number: ");
    fputs("In numeric form: ",stdout);
    OUT_CHAR_ARRAY(v,N);
    putchar('\n');


return 0;
}

char* input_phone_num(const char *s){
    char ch;
    char* nform = NEW_ARRAY(char, N);

    fputs(s, stdout);
    fflush(stdout);
    
    for(int i = 0; (ch=getchar()) != '\n' && i < N; ++i){
        ch = (ch>='a' && ch<='z')? toupper(ch): ch;
        switch(ch){
            case 'A': case 'B': case 'C': nform[i]='2';
                                          break;
            case 'D': case 'E': case 'F': nform[i]='3';
                                          break;
            case 'G': case 'H': case 'I': nform[i]='4';
                                          break;
            case 'J': case 'K': case 'L': nform[i]='5';
                                          break;
            case 'M': case 'N': case 'O': nform[i]='6';
                                          break;
            case 'P': case 'R': case 'S': nform[i]='7';
                                          break;
            case 'T': case 'U': case 'V': nform[i]='8';
                                          break;
            case 'W': case 'X': case 'Y': nform[i]='2';
                                          break;
            default:
                nform[i]=ch;
                break;
            }
    }
return nform;
}
