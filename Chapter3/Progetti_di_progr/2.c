/* - Progetti di programmazione
 *
 *  2. Scrivete un programma che formatti le informazioni 
 *  inserite dall'utente. Una sessione del programma deve
 *  presentarsi in questo modo:
 *
 *  Enter item number: 583
 *  Enter unit price: 13.5
 *  Enter purchase date (mm/dd/yyyy): 10/24/2010
 *
 *  Item            Unit            Purchase
 *                  Price           Date
 *  583             $13.50          10/24/2010  
 *  
 *  il numero indicante l'articolo e la data di acquisto
 *  devono essere allineati a sinistra mentre il prezzo
 *  unitario deve essere allineato a destra. Ammettete
 *  somme in dollari fino a 9999,99$.
 *
 *  Suggerimento: utilizzate le tabulazioni per allineare le colonne
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int year;
    int month;
    int day;
}Date;

Date inputDate(const char*);
char* viewDate(Date);

int main(void)
{
    int item_num;       //numero articolo
    float unit_price;   //prezzo unitario
    Date d;

    fputs("Enter item number: ",stdout);
    scanf("%d",&item_num);

    putchar('\n');
    fputs("Enter unit price: ", stdout);
    scanf("%f", &unit_price);

    //fputs(stdout, "Enter purchase date (mm/dd/yyyy): ");
    //scanf("%.2d / %.2d / %.4d", &d.month, &d.day, &d.year);

    d = inputDate("Enter purchase date (mm/dd/yyyy): ");
    
    putchar('\n');   
    fputs("Item\tUnit\tPurcharse\n",stdout);
    fputs("\tPrice\tDate\n",stdout);
    fprintf(stdout,"%d\t$%.2f\t%s\n",item_num, unit_price, viewDate(d));

return 0;
}

Date inputDate(const char* msg){
    Date d;

    fputs(msg, stdout);
    scanf("%d / %d / %d", &d.month, &d.day, &d.year);
    
    return d;
}

char* viewDate(Date d){
    /* mm/dd/yyyy = 10 char max + '\0' */
    char* buf = (char*)malloc(sizeof(char)*11); 
    
    if(buf == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    sprintf(buf,"%.2d/%.2d/%.4d", d.month, d.day, d.year);
    
    if(strlen(buf)>=11){
        fprintf(stderr, "format not valid\n");
        exit(EXIT_FAILURE);
    }

    return buf;
}
