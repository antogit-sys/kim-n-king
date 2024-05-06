/* Sums a series of numbers (using double variables) */

#include <stdio.h>

int main(void) {

    long double n, sum = 0.0;

    printf("This program sums a series of floating-point numbers.\n");
    printf("Enter numbers (0 to terminate): ");

    scanf("%Lf", &n);
    while (n != 0.0) {
        sum += n;
        scanf("%Lf", &n);
    }
    printf("The sum is: %Lf\n", sum);

    return 0;
}
