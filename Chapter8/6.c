#include <stdio.h>
#include <ctype.h>

#define PUTINT(n) fprintf(stdout,"%d",n)

int main(void)
{
    int ch;

    fputs("Enter a message: ",stdout);
    ch = toupper(getchar());

    fputs("In B1FF-speak: ",stdout);
    do{
        switch(ch){
            case 'A': PUTINT(4); break;
            case 'B': PUTINT(8); break;
            case 'E': PUTINT(3); break;
            case 'I': PUTINT(1); break;
            case 'O': PUTINT(0); break;
            case 'S': PUTINT(5); break;
            
            default: putchar(ch); break;
        }
    }while( (ch=toupper(getchar())) != '\n');
    fputs("!!!!!!!!!!",stdout);

    putchar('\n');


return 0;
}
