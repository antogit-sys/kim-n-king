/* Progetti di prog
 *
 *  7. Rearrange the square3.c program so that the 
 *  for loop initializes i, tests i, and increments i. 
 *  Don't rewrite the program; in particular, don't use 
 *  any multiplications.
 *
 **/

/* Prints a table of squares using an odd method */

#include <stdio.h>

int main(void) {

    int n, odd;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    
    for (int i = 1, square = 1,odd=3; i <= n; odd += 2, ++i) {
        printf("%10d%10d\n", i, square);
        square += odd;
    }
    
    return 0;
}
