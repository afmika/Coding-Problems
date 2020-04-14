/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let res = [];
	let total = 2 * n ;
	for(let i = 0; i < n; i++) {
		let str = '';
		while( str.length < total) {
			
			str += '(';
		}
		res.push(str);
	}
};