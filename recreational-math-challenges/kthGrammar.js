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
 * 0 size 1 = 2^0
 * 01 size 2 = 2^1
 * 0110 size 4 = 2^2
 * 01101001  size 8 = 2^3
 * 
 * The pattern computed from the (N-1)-th step doesn't change at the next N-th step
 * which means if K < 2^(N-1) we can set N to N - 1
 **/
 
 
 const neg = {
	'0' : '1',
	'1' : '0'
 };
/**
 * @param {number} K
 * @return {number}
 */
function get_k_chain( K ) {
	let k_chain = [];
	let k_clone = K;
	// why it works ?
	// if we can get the K-th letter at the N-th generation
	// it means that
	// if (N, K) = (N-1, ceil( K / 2) )
	// then (N, K) = (N-2, ceil( ceil( K / 2) /2 ) )
	//      ... ... ...
	// which is equal to
	// ... = (1, ceil( .... ceil(K /2) /2 ... /2 ))
	
	while( K > 1 ) {
		// K = Math.ceil( K / 2)
		K = Math.floor(K / 2) + K % 2;
		k_chain.push( K ); // index child -> ... -> index root
	}
	if(k_chain.length == 0) {
		k_chain.push( 1 );
	}
	// console.log(k_clone, k_chain.map( k => k % 2 != 0 ? 'R' : 'L') );
	return k_chain;
}

/**
 * @param {string} str
 * @param {number} N
 * @param {number} K
 */
var searchKthGrammar = function(str, step, K) {
	if(K > str.length) {
		let new_str = '';
		
		let q = Math.round( K / 2 );
		if( q <= str.length ) {
			// console.log('step ', step,  q, str[q - 1] );
			return K % 2 == 1 ? str[ q - 1 ] : neg[ str[q - 1] ];
		}
		
		for(let i = 0; i < str.length ; i++) {
			new_str += str[ i ] == '0' ? '01' : '10';
			if(new_str.length >= K )
				return new_str[K - 1];
		}
		return searchKthGrammar(new_str, step + 1, K );
	}
	
	for(let i = 0; i < str.length; i++) {
		if(i == K - 1) {
			return str[i];
		}
	}
}

/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var kthGrammar = function(N, K) {
	const final_length = Math.pow(2, N-1);
	if(K == 1)
		return '0';
	if(K < final_length )
		N--;
	if(K > final_length)
		return null;

	// K >= 1
	let map = {
		'0' : '01',
		'1' : '10'
	};
	
	// ex : the K-th node will produce the 2*K-th node at the next generation
	// this little trick will help us to determine which direction should we go
	let k_chain = get_k_chain( 2 * K );
	let direction = k_chain.map( k => k % 2 != 0 ? 'R' : 'L').reverse();
	let cur_state = '01';
	for(let k = 1; k < direction.length; k++) {
		let dir = direction[ k ];
		let index = dir == 'R' ? 0 : 1;
		cur_state = map[ cur_state[ index ] ];
	}
	
	// console.log('cur state ',cur_state, k_chain);
	let latest_index = k_chain[ k_chain.length - 1];
	
	// K = 1 ->(2*K - 1, 2*K) = '1 0'
	// K = 0 ->(2*K - 1, 2*K) = '0 1'
	// the first index will never change at the 2*K-th generation
	
	return cur_state[ 0 ];
}


var kthGrammarVersion1 = function(N, K) {
    let row = '0';

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



console.log("res ",  kthGrammar(1, 1) ); // 0
console.log("res ",  kthGrammar(2, 1) ); // 0
console.log("res ",  kthGrammar(2, 2) ); // 1
console.log("res ",  kthGrammar(4, 5) ); // 1
console.log("res ",  kthGrammar(50, 5) ); // 1
console.log("res ",  kthGrammar(60, 5) ); // 1
console.log("res ",  kthGrammar(50, 5) ); // 1
console.log();

console.log("res ", 1, kthGrammar(50, 1), kthGrammarVersion1(4, 1 ) ); // 1
console.log("res ", 2, kthGrammar(50, 2), kthGrammarVersion1(4, 2 ) ); // 1
console.log("res ", 3, kthGrammar(50, 3), kthGrammarVersion1(4, 3 ) ); // 1

/*
console.log("res ", 3, kthGrammar(50, 3), kthGrammarVersion1(4, 3 ) ); // 1
console.log("res ", 4, kthGrammar(50, 4), kthGrammarVersion1(4, 4 ) ); // 1
console.log("res ", 6, kthGrammar(50, 6), kthGrammarVersion1(4, 6 ) ); // 1
console.log("res ", 8, kthGrammar(50, 8), kthGrammarVersion1(4, 8 ) ); // 1
*/
console.log("res ", 5, kthGrammar(50, 5), kthGrammarVersion1(4, 5 ) ); // 1
console.log("res ", 6, kthGrammar(50, 6), kthGrammarVersion1(4, 6 ) ); // 1
console.log("res ", 7, kthGrammar(60, 7), kthGrammarVersion1(4, 7 ) ); // 1
console.log("res ", 8, kthGrammar(60, 8), kthGrammarVersion1(4, 8 ) ); // 1
console.log("res ", 9, kthGrammar(60, 9), kthGrammarVersion1(5, 9 ) ); // 1
console.log("res ", 10, kthGrammar(70, 10), kthGrammarVersion1(5, 10 ) ); // 1
console.log("res ", 11, kthGrammar(70, 11), kthGrammarVersion1(5, 11 ) ); // 1
console.log("res ", 12, kthGrammar(70, 12), kthGrammarVersion1(5, 12 ) ); // 1
console.log("res ", 13, kthGrammar(70, 13), kthGrammarVersion1(5, 13 ) ); // 1
console.log("res ", 14, kthGrammar(70, 14), kthGrammarVersion1(5, 14 ) ); // 1

/*
console.log('parent ', get_k_chain( 6 ).reverse() ); // 1 2 3 :: 3 gen
console.log('parent ', get_k_chain( 8 ).reverse() ); // 1 2 4 :: 3 gen.
console.log('parent ', get_k_chain( 9 ).reverse() ); // 1 2 3 5 :: 4 gen. we can get the 9-th letter by computing 1-th, 2-th, 3-th, 5-th
console.log('parent ', get_k_chain( 2 ).reverse() ); 
console.log('parent ', get_k_chain( 1 ).reverse() );
console.log('parent ', get_k_chain( 4 ).reverse() ); 
console.log('parent ', get_k_chain( Math.pow(2, 9) ).reverse() ); 
*/
/*
console.log("res ",  kthGrammar(3, 3) );
console.log("res ",  kthGrammar(10, 3) );
console.log("res ",  kthGrammar(10, 3) );

console.log("res ",  kthGrammar(1, 1) );
console.log("res ",  kthGrammar(2, 1) );
console.log("res ",  kthGrammar(3, 1) );
*/
/*
let p = Math.pow(2, 20);
console.log( p );
console.log("res ",  kthGrammar(30, p ) );
*/
// console.log( kthGrammar(5, 2) );
// console.log( kthGrammarOptimised(10, 2) );