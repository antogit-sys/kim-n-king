#include <stdio.h>
#include <ctype.h>

int scrabble_value(const char*);

int main(void)
{
    int sv = scrabble_value("Enter a worD: ");
    fprintf(stdout,"Scrabble value: %d\n",sv);

return 0;
}

int scrabble_value(const char* s){
    char ch;
    int done = 0;

    fputs(s, stdout);
    fflush(stdout);

    while((ch=getchar()) != '\n'){
        ch = (ch>='a' && ch<='z')? toupper(ch): ch;
        switch(ch){
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': 
            case 'R': case 'S': case 'T': case 'U': 
                done+=1;
                break;

            case 'D': case 'G':
                done+=2;
                break;

            case 'B': case 'C': case 'M': case 'P': 
                done+=3;
                break;
            
            case 'F': case 'H': case 'V': case 'W': case'Y': 
                done+=4; 
                break;
            
            case 'K': 
                done+=5;
                break;
            
            case 'J': case 'X':
                done+=8;
                break;
            
            case 'Q': case 'Z':
                done+=10;
                break;
        }
    }

    return done;
}
