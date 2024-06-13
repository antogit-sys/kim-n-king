#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define NEW_ARRAY(t,n)  ((t*)calloc(n,sizeof(t)))

#define N 26

void input(int *, bool);
bool isAnagrams(int *, size_t);

int main(void)
{
    int* words = NEW_ARRAY(int, N);

    fputs("Enter first word: ",stdout);
    input(words, true);

    fputs("Enter second word: ", stdout);
    input(words, false);

    if(isAnagrams(words, N)){
        puts("The words are anagrams.");
    }else{
        puts("The words are not anagrams.");
    }

return 0;
}

void input(int* a, bool flag){
    int ch;

    while((ch=getchar()) != '\n'){
        int pos = tolower(ch)-97;
        (flag == true)? a[pos]++: a[pos]--; //a[pos] += 1;
    }
    
}

bool isAnagrams(int *arr, size_t dim){
    bool done = true;

    while(dim --> 0){
        if(arr[dim] != 0){
            done = false;
            break;
        }
    }

    return done;
}
