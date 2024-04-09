/*  - Progetti di prog
 *  
 *  4. Scrivete un programma che legga un numero intero inserito dall'utente 
 *  e lo visualizzi in ottale (base 8):
 *
 *      Enter a number between 0 and 32767
 *      In octal, the your number is: 03641
 *
 *  L'output dovrebbe essere visualizzato utilizzando cinque cifre anche se 
 *  sono sufficienti meno cifre. Suggerimento: per convertire il numero in ottale, 
 *  dividerlo prima per 8; il resto è l'ultima cifra del numero ottale (1, in questo caso).
 *  Quindi dividi il numero originale per 8 e ripeti il processo per arrivare alla 
 *  penultima cifra. (printf è in grado di visualizzare numeri in base 8, come vedremo 
 *  nel Capitolo 7, quindi esiste in realtà un modo più semplice per scrivere questo programma.)  
 * _____________________________________________________________________________________________
 */


#include <stdio.h>
int oct(int);

int main(void)
{
    int n;

    fputs("Enter a number between 0 and 32767: ",stdout);
    fscanf(stdin,"%d", &n);

    fprintf(stdout,"In octal, your number is: %.5o\n", n); //XD
    fprintf(stdout,"In octal, your number is (function): %.5d\n",oct(n)); //min 5 chars
    
return 0;
}

int oct(int num){
    int i = 1;
    int octNum=0;
       
    while(num!=0){
        octNum+=(num%8)*i;
        num/=8;
        i*=10;
    }

    return octNum;
}
