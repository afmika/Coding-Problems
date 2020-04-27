/*
1307. Verbal Arithmetic Puzzle
Hard

Given an equation, represented by words on left side and the result on right side.

You need to check if the equation is solvable under the following rules:

    Each character is decoded as one digit (0 - 9).
    Every pair of different characters they must map to different digits.
    Each words[i] and result are decoded as one number without leading zeros.
    Sum of numbers on left side (words) will equal to the number on right side (result). 

Return True if the equation is solvable otherwise return False.

 

Example 1:

Input: words = ["SEND","MORE"], result = "MONEY"
Output: true
Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652

Example 2:

Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
Output: true
Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214

Example 3:

Input: words = ["THIS","IS","TOO"], result = "FUNNY"
Output: true

Example 4:

Input: words = ["LEET","CODE"], result = "POINT"
Output: false

 

Constraints:

    2 <= words.length <= 5
    1 <= words[i].length, result.length <= 7
    words[i], result contains only upper case English letters.
    Number of different characters used on the expression is at most 10.
*/


var areEquals = function (map, words, result) {
	let df = 0;
	for(let i = 0; i < words.length; i++) {
		let no_leading_zero = map[ words[i][0] ] != 0;
		if ( no_leading_zero ) {
			for(let c = 0; c < words[i].length; c++) {
				df += map[ words[i][c] ] * Math.pow(10, words[i].length - c - 1 );
			}			
		} else {
			return false;
		}
	}
	let no_leading_zero = map[ result[0] ] != 0;
	if ( no_leading_zero ) {
		for(let c = 0; c < result.length; c++) {
			df -= map[ result[c] ] * Math.pow(10, result.length - c - 1 );
		}		
	} else {
		return false;
	}
	return df == 0;
}

var clone = function ( obj ) {
	let res = {};
	for(let i in obj)
		res[i] = obj[i];
	return res;
}

function combi(map, idx_array, idx, words, result) {
	console.log( map );
	if( areEquals(map, words, result) ) {
		return true;
	}
	for(let k = 0; k < 10; k++) {
		// haha recursion go brrrr
		let clone_map = clone ( map  );
		if( idx < idx_array.length) {
			clone_map[ idx_array[idx] ] = k;
			if ( combi( clone_map, idx_array, idx + 1, words, result ) ) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @param {string[]} words
 * @param {string} result
 * @return {boolean}
 */
var isSolvable = function(words, result) {
    let map = {};
	for(let i = 0; i < words.length; i++) {
		for(let c = 0; c < words[i].length; c++) {
			map[ words[i][c] ] = 0;
		}
	}
	for(let c = 0; c < result.length; c++) {
		map[ result[c] ] = 0;
	}
	let idx_array = [];
	for(let k in map) {
		idx_array.push( k );
	}
	return combi( map, idx_array, 0, words, result );
};

console.log( isSolvable(['UN', 'UN'], 'DE') );
/*
console.log( areEquals({
	'S' : 6, 
	'I' : 5, 
	'X' : 0, 
	'E' : 8, 
	'V' : 7, 
	'N' : 2, 
	'T' : 1, 
	'W' : 3, 
	'Y' : 4
}, ["SIX","SEVEN","SEVEN"], "TWENTY") );
*/