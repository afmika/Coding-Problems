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
 * I used a few math tricks to solve this problem in O (log2 (N))
 * I am a little bit proud since it doesn t matter what the output is
 * this little boy will find the solution.
 */
/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var kthGrammar = function(N, K) {
	if(K == 1)
		return '0';
	/**
	* how does it work ?
	* if (N, K) = (N-1, ceil( K / 2) )
	* then (N, K) = (N-2, ceil( ceil( K / 2) /2 ) )
	*      ... ... ...
	* which is equal to
	* ... = (1, ceil( .... ceil(K /2) /2 ... /2 ))
	*/	
	
	// ex : the K-th node will produce the 2*K-th node in the next generation
	// this little trick will help us to determine which direction to take
	const map = { '0' : '01', '1' : '10' };
	K = 2 * K;
	let cur_state = '01';
	while( K > 1 ) {
		K = Math.floor(K / 2) + K % 2; //  K = Math.ceil( K / 2)
		cur_state = map[ cur_state[  (K+1) % 2 ] ]; // index child -> ... -> index root
	}
	// K = 1 ->(2*K - 1, 2*K) = '1 0'
	// K = 0 ->(2*K - 1, 2*K) = '0 1'
	// the first index will never change at the 2*K-th generation
	return cur_state[ 0 ];
}


console.log("res ",  kthGrammar(1, 1) ); // 0
console.log("res ",  kthGrammar(2, 1) ); // 0
console.log("res ",  kthGrammar(2, 2) ); // 1
console.log("res ",  kthGrammar(4, 5) ); // 1
console.log("res ",  kthGrammar(50, 5) ); // 1
console.log("res ",  kthGrammar(60, 5) ); // 1
console.log("res ",  kthGrammar(50, 5) ); // 1
console.log("res ",  kthGrammar(10000, 5660) ); // 1