/* - Progetti di programmazione
 *
 *  1. Svrivete un programma che accetti la data dall'utente 
 *  nella forma mm/dd/yyyy e po stampatela nella forma:
 *  
 *  yyyymmdd
 *
 */

#include <stdio.h>
int main(void)
{
    int mm,dd,yyyy;
    
    fputs("Enter a date (mm/dd/yyyy): ",stdout);
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    fprintf(stdout,"You entered the date %.4d%.2d%.2d\n", yyyy, mm, dd);

return 0;
}
