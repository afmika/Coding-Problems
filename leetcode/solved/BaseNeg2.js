/*
Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).

The returned string must have no leading zeroes, unless the string is "0".

 

Example 1:

Input: 2
Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2

Example 2:

Input: 3
Output: "111"
Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3

Example 3:

Input: 4
Output: "100"
Explantion: (-2) ^ 2 = 4

*/
/**
 * @param {number} N
 * @return {string}
 */
var baseNeg2 = function(N) {
    let result = '';
    let r = 0;
	if(N <= 1)
		return N + '';
    while(true) {
        r = N % (-2);
		r += r < 0 ? 2 : 0;
		let q = ( -N + r ) / 2;
		result = r + result;
		if(q > 0 && q < 2) {
			result = q + result;
			break;
		}
		N = q;
    }
    return result;
};

console.log( baseNeg2(1) );
console.log( baseNeg2(2) );
console.log( baseNeg2(3) );
console.log( baseNeg2(4) );
console.log( baseNeg2(123456789) );