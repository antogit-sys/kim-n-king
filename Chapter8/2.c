/* Prog di prog
 *
 * 2. Modify the repdigit.c program of Section 8.1 so 
 * that it prints a table showing how many times each 
 * digit appears in the number:
 *
 *  Enter a number: 41271092
 *  Digit:        0 1 2 3 4 5 6 7 8 9
 *  Occurrences:  1 2 2 0 1 0 0 1 0 1
 *
 **/

#include <stdio.h>

#define PUTINT(n)   fprintf(stdout,"%d ",n)

void print_occ(long);

int main(void)
{
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  puts("Digit:\t\t0 1 2 3 4 5 6 7 8 9");
  
  fputs("Occurences:\t",stdout);
  print_occ(n);

  putchar('\n');
  
  return 0;
}

void print_occ(long n){
    int occurrences[10] = {0};
    int digit;

    while (n > 0){
        digit = n % 10;
        occurrences[digit]++;
        n /= 10;
    }

    for(size_t i = 0; i<10; ++i){
        PUTINT(occurrences[i]);
    }

}
