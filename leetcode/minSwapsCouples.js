/*
 N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.

Note:

    len(row) is even and in the range of [4, 60].
    row is guaranteed to be a permutation of 0...len(row)-1.
*/

/**
 * @param {number} a
 * @param {number} b
 */
var makeKeyFrom = function(a, b) {
	return  a - b > 0 ? `${b}, ${a}` : `${a}, ${b}`;
}

var leven = function(a, b) {
	let u = a.length;
	let v = b.length;
	let table_dx_dy = [] ;
	for (let k = - 1; k < u; k++) {
		table_dx_dy[k] = [];
		table_dx_dy[k][ - 1] = k + 1;
	}
	for (let j = - 1; j < v; j++) {
		table_dx_dy[ - 1][j] = j + 1;
	}
	for (let k = 0; k < u; k++) {
		for (let j = 0; j < v; j++) {
			let cout = (a.charAt(k) == b.charAt(j)) ? 0 : 1;
			table_dx_dy[k][j] = Math.min(Math.min(1 + table_dx_dy[k][j - 1], 
												  1 + table_dx_dy[k - 1][j]), 
										 cout + table_dx_dy[k - 1][j - 1]
									   );
		}
	}
	return table_dx_dy[u - 1][v - 1];
}

/**
 * @param {number[]} row
 * @return {number}
 */
var minSwapsCouples = function(row) {
	let copy = row.map(k => k);
	const n_couples = row.length / 2;
	let well_formed = 0;
	let pairs = {};
	let couples = {};
    for(let i = 0, k = 0; i < n_couples; i++) {
		if( k % 2 == 1 )
			k++;
		let key = makeKeyFrom(k, k+1);
		couples[ key ] = true;
		pairs[ k ] = k + 1;
		pairs[ k + 1 ] = k;
		k++;
	}
	
	// checks
	let n_count = 0;
	for(let i = 0; i < row.length; i++) {
		let a = row[i];
		let b = row[i + 1];
		let key = makeKeyFrom(a, b);
		if(i + 1 > row.length)
			continue;
		if( Math.abs(a - b) == 1 && couples[key] ) {
			well_formed++;
		} else {
			for(let k = i; k < row.length; k++) {
				let pair = pairs[ row[i] ] ;
				if( pair == row[k] ) {
					let temp = copy[i];
					copy[i] = pair;
					copy[k] = temp;
					console.log(copy);
					n_count++;
				}
			}
		}
	}
	if(n_couples == well_formed)
		return 0;
	return n_count;
};

let arr = [3, 0, 2, 1];
/*
let word = arr.join('');
let targ = new Array(arr.length).fill(0).map((k, i) => i).join('');
console.log(leven(word, targ));
*/
console.log( minSwapsCouples( arr ) );