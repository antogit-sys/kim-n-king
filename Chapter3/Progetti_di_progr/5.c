/* - Project 3.05
 *
 *  5. Write a program that asks the user to enter the numbers from 1 to 16 (in any order) 
 *  and then displays the numbers in a 4 by 4 arrangement, followed by the sums of the rows, 
 *  columns, and diagonals:
 *
 *  Enter the numbers from 1 to 16 in any order:
 *  16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
 *   
 *  16  3  2 13
 *   5 10 11  8
 *   9  6  7 12
 *   4 15 14  1
 *
 *  Row sums: 34 34 34 34
 *  Column sums: 34 34 34 34
 *  Diagonal sums: 34 34
 *
 *  If the row, column, and diagonal sums are all the same (as they are in this example), the 
 *  numbers are said to form a magic square. The magic square shown here appears in a 1514 engraving 
 *  by artist and mathematician Albrecht Dürer. (Note that the middle numbers in the last row give the 
 *  date of engraving.)
 *  
 *  ============
 *  
 *  MY IMPLEMENT
 *      ||          (I'm only 20, don't expect much)
 *      ||          (Yes is truly an arrows XD)
 *      \/
 *       
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RANDINT(n_min, n_max)           (rand() % ((n_max) - (n_min) + 1) + (n_min))
#define isSquareMatrix(rows, cols)      ((rows == cols) && (rows>1 && cols >1) )//?true:false)

void swapint(int*,int*);

int** create_matrix(int, int, bool);
int** fill_matrix(int, int, int, int);
bool checkDuplicate(int,int**,int,int);
void printMatrix(int**, int, int);
void freeMatrix(int**, int);
int* sumMatrixRC(bool, int**, int, int);
void sum2Diagonals(int**, int, int, int*, int*);

int main(void)
{
    int r=4,c=4;
    int d1, d2;

    srand(time(NULL));
    int** m = create_matrix(r,c, true);
    printMatrix(m, r,c);
    putchar('\n');

    int* column_sums = sumMatrixRC(false, m, r, c);
    printf("Column sums:\n");
    for(int i=0; i<c; ++i){
        printf("colonna %d: %d\n", i+1, column_sums[i]);
    }
    putchar('\n');

    int* row_sums = sumMatrixRC(true, m, r, c);
    printf("Row sums:\n");
    for (int i=0; i<r; ++i){
        printf("Riga %d: %d\n", i+1, row_sums[i]);
    }
    putchar('\n');

    sum2Diagonals(m,r,c, &d1,&d2); 
    printf("sum diagonal 1: %d\n",d1);
    printf("sum diagonal 2: %d\n0",d2);

	freeMatrix(m,r);
return EXIT_SUCCESS;
}

void swapint(int* n1, int* n2){
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
}

/* -- Matrix --  */
int** create_matrix(int r, int c, bool f_fill){
    int **m = (int**) calloc(r, sizeof(int*));
    int size = r*c;

    if(m == NULL){
        fprintf(stderr,"Error of allocation the memory for rows\n");
        exit(1);	
    }
	
    for(size_t i=0; i<r; ++i){
        m[i] = (int*)calloc(c, sizeof(int));
        if(m[i] == NULL){
            fprintf(stderr,"Error of allocation the memory for columns\n");
            exit(1);
        }
    }
    
    (f_fill == true)? m = fill_matrix(1, size, r,c):0;

    return m;
}

int** fill_matrix(int n_min, int n_max, int r, int c){
    if(r*c != n_max-n_min+1){
        fprintf(stderr,"Error number maximum is less of max number element\n");
        exit(1);
    }
    
    int** mlocal = create_matrix(r,c,false);

    for(size_t i=0; i<r; ++i){
        for(size_t j=0; j<c; ++j){
            int num;
            do{
                num = RANDINT(n_min, n_max);
            }while(checkDuplicate(num, mlocal, r,c));
            mlocal[i][j] = num;
        }
    }
return mlocal;
}

bool checkDuplicate(int num, int** m, int rows, int columns){
    bool done = false;
    for(size_t i=0; i<rows; ++i){
        for(size_t j=0; j<columns; ++j){
            if(m[i][j] == num){
                done=true;
                break;
            }
        }
    }
return done;
}

void printMatrix(int **m, int r, int c){
    for(size_t i=0; i<r; ++i){
        for(size_t j=0; j<c; ++j)
            printf("%2d ",m[i][j]);
        putchar('\n');
    }
}

void freeMatrix(int** m, int r){
    for(size_t i=0; i<r; ++i){
        free(m[i]);
    }
    free(m);
}

int* sumMatrixRC(bool f_rows, int** m, int r, int c){
    //possible row/columns
    int pr = r;
    int pc = c;
    
    (!f_rows)?swapint(&pr,&pc):0;
    
    //create array --> sum rows or columns
    int* sums_rorc = (int*)calloc(pr,sizeof(int)); //r or c
    if(sums_rorc == NULL){
        fprintf(stderr,"Error of allocation the memory for sums");
    }

    for(size_t i=0; i<pr; ++i){
        for(size_t j=0; j<pc; ++j){
            size_t n = m[f_rows?i:j][f_rows?j:i];
            sums_rorc[i]+=n;
        } 
    }
return sums_rorc;
}


void sum2Diagonals(int** m, int r, int c, int *diag1, int *diag2){
    if(!isSquareMatrix(r, c)){
        fprintf(stderr, "Errore: la matrice non è quadrata o ha dimensioni non valide!\n");
        exit(1);
    }

    *diag1 = 0;
    *diag2 = 0;

    for(size_t i=0; i<r; ++i){
        *diag1 += m[i][i];
        *diag2 += m[i][c - 1 - i];
    }
}

