/* - Prog di prog 8
 *
 * 9. 
 *
 */
#include <stdio.h>
#include <stdlib.h> /* srand(), rand() */
#include <time.h> /* time() */

#define N 10
#define NSTEP 4

void print_m(char[][N]);
void create_route(char[][N]);

int main(void){
    char grid[N][N]={0};
    
    create_route(grid);
    print_m(grid);

    return 0;
}

void create_route(char grid[][N]){

    char letter = 'A';
   
    int up = 0,   
        down = 0, 
        left = 0,
        right = 0,
        move = 0;

    srand((unsigned) time(NULL));

    grid[0][0] = letter++;

    for(int i=0,j=0;letter <= 'Z';) {
        up = down = left = right = move = 0;

        if (j + 1 < 10 && grid[i][j + 1] == 0)
            right = 1;
        if (j - 1 >= 0 && grid[i][j - 1] == 0)
            left = 1;
        if (i + 1 < 10 && grid[i + 1][j] == 0)
            down = 1;
        if (i - 1 >= 0 && grid[i - 1][j] == 0)
            up = 1;

        if (up + down + left + right == 0)
            break;

        move = rand() % NSTEP;
        
        switch(move) {
            case 0: //^
                if (up) {
                    grid[--i][j] = letter++;
                    break;
                }
            case 1://v
                if (down) {
                    grid[++i][j] = letter++;
                    break;
                }
            case 2://dx
                if (right) {
                    grid[i][++j] = letter++;
                    break;
                }
            case 3://sx
                if (left) {
                    grid[i][--j] = letter++;
                    break;
                }

            default:
                break;
        }
    }

}

void print_m(char m[][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] == 0)
                m[i][j] = '.';
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }

}
