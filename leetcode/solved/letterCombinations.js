/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


/**
 * @param {object} map
 * @param {string[]} result_container
 * @param {string} str_temp
 * @param {number} index
 * @param {string} digits
 * @return {void}
 */
function combi(map, result_container, str_temp, index, digits) {
	if( digits.length == index ) {
		result_container.push( str_temp );
		return;
	}
	for(let k = 0; k < map[ digits[index] ].length; k++) {
		// haha recursion go brrrr
		combi(map, result_container, str_temp + map[ digits[index] ][k], index + 1, digits );				
	}
}

/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function( digits ) {
	if(digits.length == 0) 
		return [];
    const map = {
        '1' : '', '2' : 'abc', '3' : 'def',
        '4' : 'ghi', '5' : 'jkl', '6' : 'mno',
        '7' : 'pqrs', '8' : 'tuv', '9' : 'wxyz'
    };
	let result = [];
	combi(map, result, '', 0, digits);
	return result;
};
console.log( letterCombinations('234') );