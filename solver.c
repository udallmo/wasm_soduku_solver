#include <stdio.h>
#include <stdbool.h>

#define N 4
#define UNASSIGNED 0

int * findUnknown(int grid[N][N]) {
    static int r [2];

    for ( int row = 0; row < N; row++) {
        for(int col= 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                r[0] = row;
                r[1] = col;
                return r;
            }
        }
    }

    r[0] = -1;
    return r;
}

bool usedRow(int grid[N][N], int num, int row) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) return true;
    }
    return false;
}

bool usedCol(int grid[N][N], int num, int col) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) return true;
    }
    return false;
}

bool usedBox(int grid[N][N], int xRow, int xCol, int num) {
    for (int row = 0; row < 2; row++) {
        for(int col = 0; col < 2; col++) {
            if (grid[row+xRow][col+xCol] == num) return true;
        }
    }
    return false;
}

bool checkNum(int grid[N][N], int num, int row, int col) {
    bool rowCheck = !usedRow(grid, num, row);
    bool colCheck = !usedCol(grid, num, col);
    bool boxCheck = !usedBox(grid, row - row%2, col - col%2, num);
    
    return rowCheck && colCheck && boxCheck;
}

bool solveSudoku(int grid[N][N]) {
    
    // find the unassignment locations
    int * coord = findUnknown(grid);

    if (coord[0] == -1) return true;

    int row = coord[0];
    int col = coord[1];
    
    // try every number
    for (int num = 1; num <= N; num++) {

        if (checkNum(grid, num, row, col)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    // should be return false
    return false;    
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