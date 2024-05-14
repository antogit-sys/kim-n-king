/* Prog di prog 8
 *
 * 4. Modify the reverse.c program of Section 8.1 to use 
 * the expression (int) (sizeof(a) / sizeof(a[0])) 
 * (or a macro with this value for the array length.
 *
 */

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* Reverses a series of numbers */

#include <stdio.h>

#define SIZE(v, type) ((type)sizeof(v)/sizeof(v[0]))

int main(void)
{
  int a[10], i, n;
  
  n = SIZE(a,int);

  printf("Enter %d numbers: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("In reverse order:");
  for (i = n - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}

