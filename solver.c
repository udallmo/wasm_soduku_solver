#include <stdio.h>
#include <stdbool.h>

#define N 4
#define UNASSIGNED 0

int findUnknown(int grid[N][N]) {
    for ( int row = 0; row < N; row++) {
        for(int col= 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                // printf("%d | %d \n", row, col);
                return row, col;
            }
        }
    }
}

bool usedRow(int grid[N][N], int num, int row) {
    for (int col = 0; col < N; col++) {
        // printf("%d %d | %d\n", row, col, grid[row][col]);
        if (grid[row][col] == num) return true;
    }
    return false;
}

bool usedCol(int grid[N][N], int num, int col) {
    for (int row = 0; row < N; row++) {
        // printf("%d %d | %d\n", row, col, grid[row][col]);
        if (grid[row][col] == num) return true;
    }
    return false;
}

bool usedBox(int grid[N][N], int xRow, int xCol, int num) {
    for (int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            // printf("%d %d | %d\n", row, col, grid[row+xRow][col+xCol]);
            if (grid[row+xRow][col+xCol] == num) return true;
        }
    }
    return false;
}

bool checkNum(int grid[N][N], int num, int row, int col) {
    bool rowCheck = !usedRow(grid, num, row);
    bool colCheck = !usedCol(grid, num, col);
    // printf("-------------------------\n");
    bool boxCheck = !usedBox(grid, row - row%2, col - col%2, num);
    
    return rowCheck && colCheck && boxCheck;
}

bool solveSudoku(int grid[N][N]) {
    
    // find the unassignment locations
    int row, col = findUnknown(grid);

    // try every number
    for (int num = 1; num <= N; num++) {

        if (checkNum(grid, num, row, col)) {
            grid[row][col] = num;

            // if (solveSudoku(grid)) return true;

            // grid[row][col] = UNASSIGNED;
            return true;
        }
    }
    // should be return false
    return true;    
}



void printGrid(int grid[N][N]) 
{ 
    for (int row = 0; row < N; row++) 
    { 
       for (int col = 0; col < N; col++) 
             printf("%2d", grid[row][col]); 
        printf("\n"); 
    } 
} 

int main() 
{ 
    // 0 means unassigned cells 
    // int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
    //                   {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
    //                   {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
    //                   {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
    //                   {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
    //                   {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
    //                   {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
    //                   {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
    //                   {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 

    int grid[N][N] = {
        {4, 3, 0, 0},
        {1, 2, 3, 0},
        {0, 0, 2, 0},
        {2, 1, 0, 0},
    };
    if (solveSudoku(grid) == true) 
          printGrid(grid); 
    else
         printf("No solution exists"); 
  
    return 0; 
} 