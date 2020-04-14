/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let map = {
        '1' : '',
        '2' : 'abc',
        '3' : 'def',
        '4' : 'ghi',
        '5' : 'jkl',
        '6' : 'mno',
        '7' : 'pqrs',
        '8' : 'tuv',
        '9' : 'wxyz'
    };
    let res = [];
    let index = {};
	let n_possibilities = 1; 
    
	for(let i = 0; i < digits.length; i++) {
        index[ i ] = 0;
		n_possibilities *= map[  digits[i] ].length;
	}
	
	let last_index = digits.length - 1;
	let back_count = 1;
	let disp_count = 0;
    while( true ) {
		let str = '';		

		for(let idx = 0; idx < digits.length; idx++) {
			const dg = digits[ idx ];
			str += map[ dg ][ index[ idx ] ];
		}
		for(let i = last_index - 1; i >= 0; i--) {	
			if ( index[ i ] == map[ digits[i] ].length ) {
				index[ last_index - back_count ] = 0;
				back_count++;
				index[ i ] = 0;
				break;
			}
		}
		if(disp_count % 3 == 0) console.log('');
		console.log(index, back_count);
		if( index[ last_index ] + 1 >= map[ digits[ last_index ] ].length ) {
			for(let i = last_index ; i > (last_index - back_count); i-- ) {
				index[ i ] = 0;
			}			
			index[ last_index - back_count ]++;
		} else {
			index[ last_index ]++;			
		}
	
		res.push( str );
		if(res.length >= n_possibilities) {
			return res;
		}
		disp_count++;
    }
    return res;
};
// letterCombinations('27')
console.log( letterCombinations('234') );