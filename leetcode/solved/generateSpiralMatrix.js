/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
	if( n == 0 )
		return [];
	if( n == 1 )
		return [[1]];
	
	let x_min = 0, x_max = n - 1;
	let y_min = 0, y_max = n - 1;
	
    let total = n * n;
	let matrix = new Array( n );
	
	let x = x_min, y = y_min, p = 0;
	let dx = 1, dy = 1;
	let x_turn = true;
	while(p < total) {
		if(x_turn) {
			if(x < x_max && dx > 0 || x > x_min && dx < 0 ) {
				if( matrix[y] == undefined )
					matrix[y] = new Array( n );
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
				if( matrix[y] == undefined )
					matrix[y] = new Array( n );
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
};
for(let n = 2; n < 5; n++)
	console.log( generateMatrix(n) );