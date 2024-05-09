/* Prog di prog
 *
 * 11. Write a program that takes a first name 
 * and a last name entered by the user and displays 
 * the last name, a comma, and the first initial, 
 * followed by a period:
 *  
 *  Enter a first and last name: Lloyd Fosdick
 *  Fodsick, L.
 *
 * The user's input may contain extre spaces before 
 * the first name, between the first and last names, 
 * and after the last name.
 *
 **/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int i=0;
    char beg;
    bool space = false;

    fputs("Enter a first and last name: ",stdout);
    
    for(char ch; (ch = getchar()) != '\n'; ++i){
        if(i == 0) 
            beg = toupper(ch);
        
        if(ch == ' ')
            space = true;
    
        if(space == true && ch != ' ')
            putchar(ch);
    }
    printf(", %c.\n",beg);


return 0;
}
