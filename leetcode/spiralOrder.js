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
	let x_min = 0, x_max = matrix.length - 1;
	let y_min = 0, y_max = matrix.length - 1;
	
    let total = matrix.length * matrix.length;
	let res = new Array(total);
	let x = x_min, y = y_min, p = 0;
	let dp = 1;
	while(total - p > 0) {
		x = x_min;
		// row
		while( (x <= x_max && dp > 0) || (x >= x_min && dp < 0) ) {
			console.log("a", y, x, "v = ", matrix[y][x]);
			res[p] = matrix[y][x];
			x += dp;
			p++;
		}
		x = x >= matrix.length ? x - 1 : x;
		y_min++;
		y = y_min;
		// cols
		while((y <= y_max && dp > 0) || (y >= y_min && dp < 0)) {
			console.log("b", y, x, "v = ", matrix[y][x]);
			res[p] = matrix[y][x];
			y += dp;
			p++;
		}
		x_max--;
		dp *= -1;
	}
    return res;
};

let arr = [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
];
console.log( spiralOrder( arr ));