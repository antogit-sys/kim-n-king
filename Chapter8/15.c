#include <stdio.h>
#include <stdlib.h>

#define OCA(v,n)  for(size_t i=0; i<n; ++i) putchar(v[i])
#define NEW_ARRAY(t,n)  ((t*)calloc(n,sizeof(t)))
#define ARRCPY(dest, src, size) for(size_t i=0; i<size; ++i) dest[i]=src[i]
#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            puts((s));\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define N 80
#define FLUSHIN()   for(int ch; (ch=getchar()) != EOF  && ch !='\n';)
#define ISMAUSIC(ch) (ch>=65 && ch<=90)
#define CC_ENCODER(ch, key, c) (((ch-c)+key)%26+c)

size_t input_char_arr(const char*, char*);
char* caesar_encoder(char*, size_t, int);

int main(void)
{
    int key;
    char* v = NEW_ARRAY(char,N);
    int dim = input_char_arr("eneter message to be encrypted: ",v);

    fputs("Enter shift amount(1-25): ",stdout);
    fscanf(stdin, "%d", &key);
    FLUSHIN();
    
    v = caesar_encoder(v,dim, key);

    fputs("Encrypted message: ",stdout);
    OCA(v,dim);

return 0;
}

size_t input_char_arr(const char* s, char* arr){
    int i = 0;

    fputs(s,stdout);
    fflush(stdout);

    for(int ch; (ch=getchar()) != '\n'; ){
        EXIT_IF(i>=N, "*** Error max size: 80! ***");
        arr[i++]=ch;
    }
    arr[i] = '\0';

    return i;
}

char* caesar_encoder(char* v, size_t str_len, int key){
    int ch;
    char* arr = NEW_ARRAY(char, str_len);
    
    ARRCPY(arr, v, str_len);

    for(size_t i = 0; i<str_len; i++){
        ch = arr[i];
        switch(ch){
            case ' ': 
            case ',':
            case '?':
            case '!':
            case '.':
            case '#':
            case '$':
            case '"':
            case '-':
            case ';':
                break;
            default: 
                ch = ISMAUSIC(ch)? CC_ENCODER(ch,key,'A'): CC_ENCODER(ch, key, 'a');        
                break;
        }
        arr[i]=ch;
    }

return arr;
}
