/* Prog di prog
 *
 * 4. Write a program that translates an alphabetic 
 * phone number into numeric form:
 *
 *  Enter phone number: CALLATT
 *  2255288
 *
 * (In case you don't have a telephone nearby, here 
 * are the letters on the keys: 2=ABC, 3=DEF, 4=GHI, 
 * 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the original 
 * phone number contains nonalphabetic characters (digits 
 * or punctuation, for example), leave them unchanged:
 *
 *  Enter phone number: 1-800-COL-LECT
 *  1-800-265-5328
 *
 * You may assums that any letteres entered by the user 
 * are upper case.
 *
 **/
#include <stdio.h>
#include <ctype.h>
void print_num(const char*);

int main(void)
{
    print_num("Enter a phone number: ");
    putchar('\n');

return 0;
}

void print_num(const char *s){
    int ch;

    fputs(s, stdout);
    fflush(stdout);
    
    while((ch=getchar()) != '\n'){
        ch = (ch>='a' && ch<='z')? toupper(ch): ch;
        switch(ch){
            case 'A': case 'B': case 'C': putchar('2');
                                          break;
            case 'D': case 'E': case 'F': putchar('3');
                                          break;
            case 'G': case 'H': case 'I': putchar('4');
                                          break;
            case 'J': case 'K': case 'L': putchar('5');
                                          break;
            case 'M': case 'N': case 'O': putchar('6');
                                          break;
            case 'P': case 'R': case 'S': putchar('7');
                                          break;
            case 'T': case 'U': case 'V': putchar('8');
                                          break;
            case 'W': case 'X': case 'Y': putchar('9');
                                          break;
            default:
                putchar(ch);
                break;
            }
    }

}
