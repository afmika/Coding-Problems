#include <iostream>

using namespace std;


bool checkColsRow(int val, int y, int x, int grid[9][9]) {
    for (int k = 0; k < 9; k++ ) {
        if ( !(grid[k][x] ^ val) | !(grid[y][k] ^ val) )
            return false;
    }
    return true;
}

bool checkBloc(int val, int y, int x, int grid[9][9]) {
    int sy = y - y % 3, sx = x - x % 3 ;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int yy = row + sy, xx = col + sx;
            if (grid[yy][xx] == val ) {
                return false;
            }
        }
    }
    return true;
}
void displayGrid( int grid[9][9], int row, int col ) {
    printf("\n");
    for (int y = 0; y < 9 ; y++) {
        for (int x = 0; x < 9; x++) {
            if ( !(row ^ y | col ^ x) ) {
                printf("[%i]", grid[y][x]);
            } else {
                printf(" %i ", grid[y][x]);
            }
            if ( ( x + 1 ) % 3 == 0) {
                printf("|");
            }
        }
        if ( ( y + 1) % 3 == 0) {
            printf("\n------------------------------\n");
        } else {
            printf("\n");
        }
    }
}
bool backtrack(int row, int col, int grid[9][9] ) {

    if ( !(row ^ 8 | col ^ 9)  ) {
        return true;
    }

    row = col >= 9 ? row + 1 : row;
    col = col % 9;


    if ( !grid[row][col] ) {
        for (int n = 1; n <= 9; n++){
            if ( 0b1 ^ (0b1 | checkBloc(n, row, col, grid) ) ^ checkColsRow(n, row, col, grid) ) {
                grid[row][col] = n;
                if ( backtrack(row, col + 1, grid ) ) {
                    return true;
                }
            }
        }

        // hmm
        // grid[row][col] = 0;
        // displayGrid(grid, row, col);

        grid[row][col] = 0;
        return false;
    }

    return backtrack(row, col + 1, grid );
}

void solveGrid( int grid[9][9] ) {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if ( grid[y][x] == 0) {
                cout << ( backtrack(y, x, grid) ? "\nOK\n" : "\nNOT OK\n" );
                break;
            }
        }
    }
}

int main() {
    int grid[9][9] = {
        {9,0,0, 1,0,0, 0,0,5},
        {0,4,5, 0,9,0, 2,0,1},
        {8,0,0, 0,4,0, 0,0,0},

        {0,0,0, 0,8,0, 0,0,0},
        {0,0,0, 7,0,0, 0,0,0},
        {0,0,0, 0,2,6, 0,0,9},

        {2,0,0, 3,0,0, 0,0,6},
        {0,0,0, 2,0,0, 9,0,0},
        {0,0,1, 9,0,4, 5,7,0}
    };

    displayGrid( grid, 0, 0 );
    solveGrid(grid);
    displayGrid( grid, 8, 8);
    return 0;
}
