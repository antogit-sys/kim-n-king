/* - Prog di prog 8
 *
 * 9. Write a program that generates a "random walk" across a 10 x 10 
 * array. The array will contain characters (all '.' initially). The 
 * program must randomly "walk" from element to element, always going up, 
 * down, left or right by one element. The elements visited by the program 
 * will be labeled with the letters A through Z, in the order visited. 
 * Here's an example of the desired output:
 * 
 *  A . . . . . . . . .
 *  B C D . . . . . . .
 *  . F E . . . . . . .
 *  H G . . . . . . . .
 *  I . . . . . . . . .
 *  J . . . . . . . Z .
 *  K . . R S T U V Y .
 *  L M P Q . . . W X .
 *  . N O . . . . . . .
 *  . . . . . . . . . .
 *
 *  Hint Use the srand and rand functions (see deal.c) to generate random numbers. 
 *  After generating a number, look at its remainder when divided by 4. There are 
 *  four possible values for the remainder -- 0, 1, 2 and 3 -- indiciating the 
 *  direction of the next move. Before performing a move, check that (a) it won't go 
 *  outside the array, and (b) it doesn't take us to an element that already has a 
 *  letter assigned. If either condition is violated, try moving in another direction. 
 *  If all four directions are blocked, thr program must terminate. Here's an example 
 *  of premature termination:
 *
 *      A B G H I . . . . .
 *      . C F . J K . . . .
 *      . D E . M L . . . .
 *      . . . . N O . . . .
 *      . . W X Y P Q . . .
 *      . . V U T S R . . .
 *      . . . . . . . . . .
 *      . . . . . . . . . .
 *      . . . . . . . . . .
 *      . . . . . . . . . .
 *
 *   Y is blocked on all four sides, so there's no place to put Z.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

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
