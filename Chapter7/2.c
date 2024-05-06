/* Prog di prog
 *
 * 2. Modify the square2.c program of Section 6.3 
 * so that it pauses after every 24 squares and 
 * displays the following message:
 *
 *  Press Enter to continue...
 *
 * After displaying the message, the program should use 
 * getchar to read a character. getchar won't allow the 
 * program to continue until the user pressed the Enter 
 * key.
 *
 **/

/* Prints a table of squares using a for statement */

#include <stdio.h>
#define flushin() for(int ch=getchar(); ch!=EOF && ch!='\n'; ch=getchar())
#define pressEnter() while(!getchar())

int main(void) {

    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    flushin();

    for(i = 1; i <= n; i++){
        printf("%20d%20d\n", i, i * i);
        if(i%24 == 0){
            fputs("Press Enter to continue...",stdout);
            pressEnter();
        }
    }
   
    putchar('\n');

    return 0;
}
