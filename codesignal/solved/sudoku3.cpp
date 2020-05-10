bool sudoku2(std::vector<std::vector<char>> grid) {
    for(int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if ( grid[y][x] != '.') {
                // row / col
                int count = 0;
                for (int p = 0; p < 9; p++ ) {
                    if ( grid[p][x] == grid[y][x] ) {
                        if ( p != y ) {
                            return false;
                        }
                    }
                    if ( grid[y][p] == grid[y][x] ) {
                        if ( p != x ) {
                            return false;
                        }
                    }
                }

                // bloc
                int sy = y - y % 3, sx = x - x % 3 ;
                for (int row = 0; row < 3; row++) { 
                    for (int col = 0; col < 3; col++) { 
                        char cur = grid[row + sy][col + sx]; 
                        if (grid[y][x] == cur && row + sy != y && col + sx != x) {
                            return false;
                        }
                    } 
                } 
            }
        }
    }
    return true;
}
