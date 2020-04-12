class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        if( n == 0 )
			return matrix;
        if( n == 1 ) {
			matrix[0][0] = 1;
            return matrix;
		}

        int x_min = 0, x_max = n - 1;
        int y_min = 0, y_max = n - 1;

        int total = n * n;

        int x = x_min, y = y_min, p = 0;
        int dx = 1, dy = 1;
        boolean x_turn = true;
        while(p < total) {
            if(x_turn) {
                if(x < x_max && dx > 0 || x > x_min && dx < 0 ) {
                    matrix[y][x] = p + 1;
                    x += dx;
                    p++;	
                } else {
                    if(x == x_max && dx > 0)
                        x_max--;
                    if(x == x_min && dx < 0)
                        y_max--;				
                    dx *= -1;
                    x_turn = false;
                }			
            } else {
                if(y < y_max && dy > 0 || y > y_min && dy < 0 ) {
                    matrix[y][x] = p + 1;
                    y += dy;
                    p++;
                } else {	
                    if(y == y_max && dy > 0)
                        y_min++;
                    if(y == y_min && dy < 0)
                        x_min++;
                    dy *= -1;
                    x_turn = true;
                }
            }

            if( p + 1 == total )
                matrix[y][x] = 1 + p++;
        }
        return matrix;  
    }
}