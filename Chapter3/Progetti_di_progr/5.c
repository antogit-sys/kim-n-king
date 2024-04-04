/* - Progetti di prog
 *
 *  5. traccia che inserirò dopo XD
 *  ...
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RANDINT(n_min, n_max) (rand() % ((n_max) - (n_min) + 1) + (n_min))

typedef unsigned long ulong;

ulong** create_matrix(ulong, ulong, bool);
ulong** fill_matrix(ulong, ulong, ulong, ulong);
bool checkDuplicate(ulong,ulong**,ulong,ulong);
void printMatrix(ulong**, ulong, ulong);
void freeMatrix(ulong**, ulong);
//void sumMatrix(bool,ulong**, ulong, ulong);

int main(void)
{
    int r=4,c=4;

    srand(time(NULL));
    ulong** m = (ulong**)create_matrix(r,c, true);
    printMatrix(m, r,c);
    //sum_matrix("Rows sums: ",m,r);

    freeMatrix(m,r);

return EXIT_SUCCESS;
}

ulong** create_matrix(ulong r, ulong c, bool f_fill){
    ulong **m = (ulong**) calloc(r, sizeof(ulong*));
    ulong size = r*c;

    if(m == NULL){
        fprintf(stderr,"Error of allocation the memory for rows\n");
        exit(1);	
    }
	
    for(size_t i=0; i<r; ++i){
        m[i] = (ulong*)calloc(c, sizeof(ulong));
        if(m[i] == NULL){
            fprintf(stderr,"Error of allocation the memory for columns\n");
            exit(1);
        }
    }
    
    (f_fill == true)? m = fill_matrix(1, size, r,c):0;

    return m;
}

ulong** fill_matrix(ulong n_min, ulong n_max, ulong r, ulong c){
    if(r*c != n_max-n_min+1){
        fprintf(stderr,"Error number maximum is less of max number element\n");
        exit(1);
    }
    
    ulong** mlocal = (ulong**)create_matrix(r,c,false);

    for(size_t i=0; i<r; ++i){
        for(size_t j=0; j<c; ++j){
            ulong num;
            do{
                num = RANDINT(n_min, n_max);
            }while(checkDuplicate(num, mlocal, r,c));
            mlocal[i][j] = num;
        }
    }
return mlocal;
}


bool checkDuplicate(ulong num, ulong** m, ulong rows, ulong columns){
    bool done = false;
    for(size_t i=0; i<rows; ++i){
        for(size_t j=0; j<columns; ++j){
            (m[i][j] == num)?done=true:0;
        }
    }
return done;
}

void printMatrix(ulong **m, ulong r, ulong c){
    for(size_t i=0; i<r; ++i){
        for(size_t j=0; j<c; ++j)
            printf("%2lu ",m[i][j]);
        putchar('\n');
    }
}

void freeMatrix(ulong** m, ulong r) {
    for (size_t i = 0; i < r; ++i) {
        free(m[i]);
    }
    free(m);
}

/*void sumMatrix(bool f_rows, ulong** m, ulong r, ulong c){
    ulong rorc; //rows or columns
    
    (f_rows == true)?rorc = r: rorc = c;
}*/
