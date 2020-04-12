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
    let arr = [];
    let r = 0;
    while(true) {
        const q = parseInt(N / -2);
		console.log("q", q)
        r = N -  q * (-2);
		if(N < -2) {
			arr.push(r);			
		} else {
			arr.push(q);
			break;			
		}
		N = q;
    }
    let str = '';
    for(let i = 0; i < arr.length; i++) {
        str += arr[arr.length - i - 1];
    }
    return str;
};

console.log( baseNeg2(2) );