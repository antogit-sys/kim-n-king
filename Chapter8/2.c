/* Prog di prog
 *
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
    int occ = 0, digit = 0;
    long num = n;

    for(int i = 0; i < 10; ++i){
        occ = 0;
        n = num;
        while(n > 0){
            digit = n % 10;
            if(digit == i){
                occ++;
            }
            n /= 10;
        }
        PUTINT(occ);
    }

}
