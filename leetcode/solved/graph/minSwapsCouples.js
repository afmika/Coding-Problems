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
 * @param {number[]} row
 * @return {number}
 */
var minSwapsCouples = function(row) {
	let n_count = 0;
	let start_index = 1;
	while( true ) {
		let done = true;
		for(let i = start_index; i < row.length; i++) {
			const pair = row[ i - 1 ] + ( row[ i - 1 ] % 2 == 0 ?  1 : -1  );
			if( pair != row[i] ) {
				for(let k = 0; k < row.length; k++ ) {
					if( row[ k ] == pair ) {
						// swap(row, k, i);
						const temp = row[ k ];
						row[ k ] = row[ i ];
						row[ i ] = temp;
						break;
					}
				}
				start_index = i;
				n_count++;
				done = false;
				break;
			} else {
				i++;
			}
		}
		// console.log('index', start_index );
		if ( done ) 
			break;
	}
	// console.log( row );
	return n_count;
};
let test = [4, 1, 3, 0, 2, 5];
// let arr = [0, 2, 1, 3];
/*
let word = arr.join('');
let targ = new Array(arr.length).fill(0).map((k, i) => i).join('');
console.log(leven(word, targ));
*/
console.log( minSwapsCouples( test ) );