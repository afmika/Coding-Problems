/*
On the first row, we write a 0. 
Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, 
and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. 
(The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001

Note:

    N will be an integer in the range [1, 30].
    K will be an integer in the range [1, 2^(N-1)].
*/

/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var kthGrammar = function(N, K) {
    let row = '0';
	/**
	 * 0 size 1 = 2^0
	 * 01 size 2 = 2^1
	 * 0110 size 4 = 2^2
	 * 01101001  size 8 = 2^3
	 * 
	 * The pattern computed from the (N-1)-th step doesn't change at the next N-th step
	 * which means if K < 2^(N-1) we can set N to N - 1
	 **/
	const final_length = Math.pow(2, N-1);
	if(K == 1)
		return row;
	if(K < final_length )
		N--;
	if(K > final_length)
		return null;
	while( N > 0 ) {
		let new_row = '';
		for(let s = 0; s < row.length; s++) {
			new_row += row[s] == '0' ? '01' : '10';
			// if the (K-1)-th index is ready we don't need to continue
			if(new_row.length >= K )
				return new_row[K - 1];
		}
		row = new_row;
		N--;
	}
	return row[K - 1];
};

/*
console.log("res ",  kthGrammar(1, 1) );
console.log("res ",  kthGrammar(2, 1) );
console.log("res ",  kthGrammar(2, 2) );
console.log("res ",  kthGrammar(4, 5) );
console.log("res ",  kthGrammar(3, 3) );
console.log("res ",  kthGrammar(10, 3) );
console.log("res ",  kthGrammar(10, 3) );
*/
console.log("res ",  kthGrammar(1, 1) );
console.log("res ",  kthGrammar(2, 1) );
console.log("res ",  kthGrammar(3, 1) );
console.log("res ",  kthGrammar(4, 5) );
// console.log( kthGrammar(5, 2) );
// console.log( kthGrammarOptimised(10, 2) );