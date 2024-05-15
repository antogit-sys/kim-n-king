/* - Prog di prog 8
 *
 * 6. The prototypical Internet newbie is a fellow named BIFF, 
 * who has a unique way of writing messages. Here's a typical 
 * BIFF communiqué:
 *
 * H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
 *
 * Write a "BIFF filter" that reads a message entered by the 
 * user and translates it into BIFF-speak:
 *
 *  Enter message: Hey dude, C is rilly cool
 *  In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
 *
 * Your program should convert the message to upper-case letters, 
 * substitute digits for certain letters (A→4, B→8, E→3, I→1, O→0, S→5), 
 * and then append 10 or so exclamation marks.
 *
 * Hint: Store the original message in an array of characters, then go back 
 * through the array, translating and printing characters one by one.
 *
 **/

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
