/* - Progetti di prog
 *
 *  4. Scrivete un programma che chieda all'utente di inserire un numero
 *  telefonico nella forma (xxx) xxx-xxxx e successivamente stampi il
 *  numero nella forma xxx.xxx.xxxx
 *
 */

#include <stdio.h>
#include <string.h>
#define N 15

int main()
{
    char phone[N];

    fputs("Enter phone numbeer [ (xxx) xxx-xxxx ]: ",stdout);
    fgets(phone,sizeof(phone),stdin);
    
    phone[strlen(phone)]='\0';

    fprintf(stdout,"You entered %.3s.%.3s.%.4s\n",phone+1, phone+6, phone+10); 

return 0;
}


/*
    #include <stdio.h>

    int main(void) {
        int beg, mid, end;

        printf("Enter phone number [(xxx) xxx-xxxx]: ");
        scanf(" (%d ) %d- %d", &beg, &mid, &end);
        printf("You entered %.3d.%3d.%.4d\n", beg, mid, end);

        return 0;
    }
 
 */
