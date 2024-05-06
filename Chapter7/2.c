/* Prog di prog
 *
 * 2. 
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
