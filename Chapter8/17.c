#include <stdio.h>
#include <stdlib.h>

#define EXIT_IF(c, s)\
    do{\
        if((c)){\
            puts((s));\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
  
#define FREE_MATRIX(m ,c)	free_matrix((void**)m, c)
    
void** matrix_alloc(size_t, size_t);
void free_matrix(void**, size_t);
void printim(int**, size_t, size_t);
void in_matrix(int**, size_t);

int main(void)
{
    // magic square
    int short n; 
    int** m;

    puts("This is program creates a magic square of a specified size.");
    puts("The size must be an odd number between 1 and 99.");
    fputs("Enter the size of magic square: ",stdout);
    fscanf(stdin, "%hd", &n);

    m = (int**) matrix_alloc(n, n);
    EXIT_IF(!m, "***failed matrix allocation***");

    in_matrix(m,n);
    printim(m,n,n);
    
    FREE_MATRIX(m,n);
}

void** matrix_alloc(size_t elementsize, size_t count)
{
    void** m = calloc(count,sizeof(void*));
    if(!m) return NULL;
    for(unsigned i=0; i<count; ++i){
        m[i]=calloc(elementsize,sizeof(void*));
        if(!m[i]) goto ONERR;
    }
    return m;

    ONERR:
    FREE_MATRIX(m, count);
	return NULL;
 }

void free_matrix(void** m, size_t count){
	for(unsigned i=0; i<count && m[i]; ++i)
        free(m[i]);
    free(m);
}

void printim(int** m, size_t r, size_t c){
    for(unsigned i=0; i<r; ++i){
        for(unsigned j=0; j<c; ++j){
            printf("%4d",m[i][j]);
        }
        putchar('\n');
    }
}

void in_matrix(int** magic_square, size_t n){
	int i = 0, j = n / 2;
	int newi, newj, num=1;
	
	//finisce quando num diventa n*n (n*n= numeti totali della matrice ,r * c)
	while(num <= n*n){
		magic_square[i][j]=num++;
		
		//applico l'algoritmo per generare un quadrato magico
		newi = (i - 1 + n) % n;
		newj = (j + 1) % n;
		
		//se la posizione è occupata allora
		if(magic_square[newi][newj] != 0){
			//mi sposto di una riga in basso
			i = (i + 1) % n;
		}else{
			//altrimenti salvo i nuovi valori dell'algoritmo nelle variabili effettive
			i = newi;
			j = newj;
		}
	}
	
}
