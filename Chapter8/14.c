/* Prog di prog 8
 *
 * Write a program that reverses the words in a sentence:
 *  Enter a sentence: you can cage a swallow can't you?
 *  Reversal of sentence: you can't swallow a cage can you?
 *
 * Hint: Use a loop to read the characters one by one and store them in a one-dimensional char array. Have the loop
 * stop at a period, question mark, or exclamation point (the "terminating character"), which is saved in a separate char variable. 
 * Then use a second loop to search backward through the array for the beginning of the last word. Print the last word, then search backward for the next-to-last word. 
 * Repeat until the beginning of the array is reached. Finally, print the terminating character.
 *
 *
 **/
#include <stdio.h>
#include <stdlib.h>

#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            puts((s));\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define IN(a,op,v1,v2,v3) (a op v1 && a op v2 && a op v3)
#define NEW_ARRAY(t,n)  ((t*)calloc(n,sizeof(t)))

#define N 100

size_t input_stdi(char*, char*);
void out_reversal_sentence(char*, int, char);

int main(void)
{
    char* words = NEW_ARRAY(char, N);
    char c_term;
    int size = 0;

    fputs("Enter a sentence: ",stdout);
    size = input_stdi(words,&c_term);

    EXIT_IF(IN(c_term, != ,'.','?','!'), "Error invalid final charter!");

    fputs("Reversal of sentence: ",stdout);
    out_reversal_sentence(words, size, c_term);
    putchar('\n');

    return 0;
}

size_t input_stdi(char* v, char* term){
    int i = 0;
    for(int ch; (ch=getchar()) != '\n'; ){
        v[i++]=ch;
        *term = ch;
    }
    v[i] = '\0';
    return i;
}

void out_reversal_sentence(char *string, int str_len, char c_term){
    int i = str_len - 1;

    EXIT_IF(N<i, "***Error size max size 100!***");

    while(i-->= 0){
        if(string[i - 1] == ' ' || i == 0){
            int j = i;
            while(string[j] != ' ' && j < str_len-1)
                putchar(string[j++]);
            if(i > 0)
                putchar(' ');
        }
    }
    putchar(c_term);
}
