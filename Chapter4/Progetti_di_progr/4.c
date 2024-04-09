/*  - Progetti di prog
 *  
 *  3. Riscrivete il programma del Progetto di Programmazione 2 in modo che stampi
 *  la scrittura inversa di un numero 
 * ________________________________________________________________________________
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
