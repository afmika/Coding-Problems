/*
A square matrix that is the negative of its transpose is a skew-symmetric matrix. Find out if the given matrix is skew-symmetric.

Example

    For

    matrix = [[ 0, 0,  1], 
              [ 0, 0, -2], 
              [-1, 2,  0]]

    the output should be
    isSkewSymmetricMatrix(matrix) = true;

    For

    matrix = [[ 0,  0,  1], 
              [ 0,  0, -2], 
              [-1, -2,  0]]

    the output should be
    isSkewSymmetricMatrix(matrix) = false.

*/

bool isSkewSymmetricMatrix(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    for (int y = 0; y < n; y++) {
        for (int x = y; x < n; x++) {
            if ( matrix[y][x] == matrix[x][y] && matrix[y][x] == 0) {
                continue;
            }

            if ( matrix[y][x] / matrix[x][y] != -1 ) {
                return false;
            }
        }
    }
    return true;
}
