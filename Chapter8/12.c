/* -Prog di prog
 *
 * 12. Modify Programming Project 5 from Chapter 7 
 * so that the SCRABBLE values of the letters are 
 * stored in an array. The array wil have 26 elements, 
 * corresponding to the 26 letters of the alphabet. For 
 * example, element 0 of the array will store 1 (because 
 * the SCRABBLE value of the letter B is 3), and so forth. 
 * As each character of the input word is read, the program 
 * will use the array to determine the SCRABBLE value of that 
 * character. Use an array initializer to set up the array.
 *
 **/
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

    int scrabble[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 4, 8, 4, 10
    };

    fputs(s, stdout);
    fflush(stdout);

    while((ch=getchar()) != '\n'){
        done += scrabble[toupper(ch)-'A'];
    }

    return done;
}
