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
