/* - Prog di prog 8
 *
 * 7. Write a program that reads a 5 x 5 array of integers 
 * and then prints the row sums and the column sums:
 *  
 *  Enter row 1: 8 3 9 0 10
 *  Enter row 2: 3 5 17 1 1
 *  Enter row 3: 2 8 6 23 1
 *  Enter row 4: 15 7 3 2 9
 *  Enter row 5: 6 14 2 6 0
 *
 * Row totals: 30 27 40 36 28
 * Column totals: 34 37 37 32 21
 *
 **/

#include <stdio.h>
#define N 5

int main(void)
{
    int m[N][N] = {0};

    /* input */
    for(int i = 0; i<N ; ++i){
        printf("Enter row %d: ",i+1);
        for(int j=0; j<N; ++j){
            scanf("%d",&m[i][j]);
        }
    }

    putchar('\n');

    /* sum for row */
    fputs("Row totals: ",stdout);
    for(int i=0; i<N; ++i){
        int sumR = 0;
        for(int j=0; j<N; ++j){
            sumR+=m[i][j];
        }
        printf("%d ",sumR);
    }
    putchar('\n');

    /* sum for columns */
    fputs("Columns totals: ", stdout);
    for(int i=0; i<N; ++i){
        int sumC = 0;
        for(int j = 0; j < N; ++j){
            sumC+=m[j][i];
        }
        printf("%d ",sumC);
    }
    putchar('\n');


return 0;
}
