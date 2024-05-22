/* Prog di prog
 *
 * 13. Modify Programming Project 11 from Chapter 7 so 
 * that the program labels its output:
 *
 *  Enter a first and last name: Lloyd Fosdick
 *  You entered the name: Fosdick, L.
 *
 * The program will need to store the last name 
 * (but not the first name) in an array of characters 
 * until it can be printed. You may assume that the last 
 * name is no more than 20 characters long.
 *
 **/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define OUT_CHAR_ARRAY(v,n)  for(size_t i=0; i<n; ++i) putchar(v[i])

int main(void)
{
    int i=0, j=0;
    char beg;
    char name[20];

    bool space = false;

    fputs("Enter a first and last name: ",stdout);
    
    for(char ch; (ch = getchar()) != '\n'; ++i){
        if(i == 0) 
            beg = toupper(ch);
        
        if(ch == ' ')
            space = true;
        
        if(space == true && ch != ' ')
            name[j++]=ch;
    }

    fputs("You entered the name: ",stdout);
    OUT_CHAR_ARRAY(name,j); //OUT_CHAR_ARRAY(name, strlen(name));
    printf(", %c.\n",beg);


return 0;
}
