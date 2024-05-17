/* - Prog di prog 8
 *
 * 8. Modify Programming Project 7 so that it prompts 
 * for five quiz grades for each of five students, then 
 * computes the total score and average score for each 
 * student, and the average score, high score, and low 
 * score for each quiz.
 *
 **/

#include <stdio.h>
#define N 5

int main(void)
{
    int m[N][N] = {0};

    /* input */
    for(int i = 0; i<N ; ++i){
        printf("Enter quiz grades for student %d: ",i+1);
        for(int j=0; j<N; ++j){
            scanf("%d",&m[i][j]);
        }
    }

    putchar('\n');

    /* Total and average */
    for(int i=0; i<N; ++i){
        int acc = 0; // accumulate variable
        printf("Total and average score for student %d: ",i+1);
        for(int j=0; j<N; ++j){
            acc+=m[i][j];
        }
        printf("%d %.1f\n",acc, (double)acc/N);
    }

    putchar('\n');

    /* Score hight and low */
    for(int i=0; i<N; ++i){
        int min=m[i][0], max=m[i][0], acc = m[i][0];
        printf("Score hight,low and average value for student %d: ",i+1);
        for(int j = 1; j < N; ++j){
            min = (min>m[i][j])?m[j][i]:min;
            max = (max<m[i][j])?m[i][j]:max;
            acc+=m[i][j];
        }
        printf("%d %d %d\n",max,min, acc/N);
    }
    putchar('\n');


return 0;
}
