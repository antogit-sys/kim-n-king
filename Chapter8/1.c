/* Prog di prog 8
 *
 * 1. Modify the repdigit.c program of Section 8.1 
 * so that it shows which digits (if any) were 
 * repeated:
 *
 *  Enter a number: 939577
 *  Repeated digit(s): 7 9
 *
 **/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
  bool digit_seen[10] = {false};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  fputs("Repeated digit(s): ",stdout);
  while (n > 0) {
    digit = n % 10; 
	if (digit_seen[digit]){
        printf("%d ",digit);
    }
    digit_seen[digit] = true;
    n /= 10; 
  }
  putchar('\n');

  return 0;
}

