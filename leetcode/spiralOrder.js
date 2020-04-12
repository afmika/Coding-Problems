/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
	
	if( matrix.length == 0 )
		return [];
	if( matrix.length == 1)
		return matrix[0];
	if( matrix[0].length == 1) {
        let tmp = new Array(matrix.length);
        for(let i = 0; i < tmp.length; i++) {
            tmp[i] = matrix[i][0];
        }
        return tmp;
    }
	
	let x_min = 0, x_max =  matrix[0].length - 1;
	let y_min = 0, y_max = matrix.length - 1;
	
    let total = matrix.length * matrix[0].length;
	let res = new Array(total);
	
	let x = x_min, y = y_min, p = 0;
	let dx = 1, dy = 1;
	
	let x_turn = true;
	while(p < total) {
		if(x_turn) {
			if(x < x_max && dx > 0 || x > x_min && dx < 0 ) {
				res[p] = matrix[y][x];
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
				res[p] = matrix[y][x];
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
		
		if( matrix[0].length <= matrix.length && p + 1 == total ) {
			res[ p++ ] = matrix[y][x];
		}
	}
    return res;
};

let arr = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
];
console.log(arr);
console.log( spiralOrder( arr ));