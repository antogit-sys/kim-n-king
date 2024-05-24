#include <stdio.h>
#include <stdlib.h>

#define OCA(v,n)  for(size_t i=0; i<n; ++i) putchar(v[i])
#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            puts((s));\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define IN(a,op,v1,v2,v3) (a op v1 && a op v2 && a op v3)

#define N 100

size_t input_stdi(char*, char*);
void reversal_sentence(char*, size_t n, char*);
int main(void) {

    char c, c_term, words[N] = {0};

    fputs("Enter a sentence: ",stdout);
    i = input_stdi(words,&c_term);

    EXIT_IF(IN(c_term, != ,'.','?','!'), "Error invalid final charter!");

    fputs("Reversal of sentence: ",stdout);


    return 0;
}

size_t input_stdi(char* v, char* term){
    int i = 0;
    for(int ch; (ch=getchar()) != '\n'; ){
        v[i++]=ch;
        *term = ch;
    }
    return i;
}

void reversal_sentence(char* v, size_t n, char* term){



}
