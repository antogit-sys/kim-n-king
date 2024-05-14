/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{ 
  long n = 1, tmp_n = n;

  for(size_t i = 0; n > 0; ++i){
      bool digit_seen[10] = {false};
      printf("Enter %zu° number: ",i);
      scanf("%ld", &n);
      
      tmp_n = n;
      while (tmp_n > 0){
          int digit = tmp_n % 10;
          if (digit_seen[digit])
            break;
          digit_seen[digit] = true;
          tmp_n /= 10;
      }
      
      if (tmp_n > 0)
          printf("Repeated digit\n");
      else
          printf("No repeated digit\n");
      
      putchar('\n');

  }

  return 0;
}

