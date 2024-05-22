/* -Prog di prog
 *
 * 5. In the SCRABBLE Crossword Game, players form words using small tiles, 
 * each containing a letter and a face value. The face value varies from one 
 * letter to another, based on the letter's rarity. (Here are the face values: 
 * 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ.) Write a program 
 * that computes the value of a word by summing the values of its letters:
 *
 *  Enter a word: pitfall
 *  Scrabble value: 12
 *
 * Your program should allow any mixture of lower-case and upper-case letters in 
 * the word. Hint: Use the toupper library function.
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
