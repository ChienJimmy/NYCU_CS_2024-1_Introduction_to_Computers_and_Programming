#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int (*grid_p)[NUM]){
    int identical;
    for (int row = 0; row < NUM; row++)
    {
        for (int col = 0; col < NUM; col++)
        {
            identical = 0;
            /* check row */
            for (int i = 0; i < NUM; i++){
                if (grid_p[i][col] == grid_p[row][col] && i != row){
                    identical = 1;
                    break;
                }
            }
            if (identical == 1){
                printf("(%d,%d)\n", row, col);
                continue;
            }
            /* check col */
            for (int i = 0; i < NUM; i++){
                if (grid_p[row][i] == grid_p[row][col] && i != col){
                    identical = 1;
                    break;
                }
            }
            if (identical == 1){
                printf("(%d,%d)\n", row, col);
                continue;
            }
            /* check 3x3 */
            for (int i = row - (row % 3); i < row -(row % 3) + 3; i++){
                for (int j = col - (col % 3); j < col - (col % 3) + 3; j++){
                    if (grid_p[i][j] == grid_p[row][col] && i != row && j != col){
                        identical = 1;
                        break;
                    }
                }            
            }
            if (identical == 1){
                printf("(%d,%d)\n", row, col);
                continue;
            }
        }
    }
}