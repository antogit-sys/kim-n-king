/* - Progetti di programmazione

   3.I libri sono identificati da un Numero Standard Internazionale del Libro (ISBN).
   Gli ISBN assegnati dopo il 1° gennaio 2007 contengono 13 cifre, suddivise in cinque gruppi,
   come ad esempio 978-0-393-97950-3. (Gli ISBN più vecchi utilizzano 10 cifre.) Il primo gruppo
   (il prefisso GSI) è attualmente 978 o 979. Il gruppo identificatore specifica la lingua o il 
   paese d'origine (ad esempio, 0 e 1 sono utilizzati nei paesi di lingua inglese). Il codice 
   editore identifica l'editore (393 è il codice per W. W. Norton). Il numero dell'articolo è 
   assegnato dall'editore per identificare un libro specifico (97950 è il codice per questo libro).
   Un ISBN termina con una cifra di controllo che viene utilizzata per verificare l'accuratezza 
   delle cifre precedenti. Scrivi un programma che analizza un ISBN inserito dall'utente:

    Inserisci l'ISBN: 978-0-393-97950-3
    Prefisso GSI: 978
    Identificatore gruppo: 0
    Codice editore: 393
    Numero articolo: 97950
    Cifra di controllo: 3

    Nota: Il numero di cifre in ogni gruppo può variare: non puoi assumere che i gruppi abbiano 
    le lunghezze mostrate in questo esempio. Testa il tuo programma con valori ISBN effettivi 
    (generalmente trovati sul retro di un libro e sulla pagina dei diritti d'autore).
*/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 20

void analyze_ISBN(char*);

int main(void)
{
    char isbn[MAX_LENGTH];

    putchar('\n');
    fputs("Enter ISBN: ", stdout);
    fgets(isbn,MAX_LENGTH, stdin);

    //isbn[strcspn(isbn, "\n")] = '\0'; bug code execution

    isbn[strlen(isbn)-1] = '\0';

    analyze_ISBN(isbn);

    putchar('\n');

return 0;
}

void analyze_ISBN(char* isbn){
    char *name_group[]={
        "GS1 Prefix", "Group identifier",
        "Publisher Code", "Item number",
        "Check digit"
    };

    char* token = strtok(isbn,"-"); //(isbn, delimitatore)
    
    for(size_t gc=0; token!=NULL; gc++){ //group count
        fprintf(stdout,"%s: %s\n",name_group[gc], token);
        token = strtok(NULL, "-"); //point to next token
    }        
}
