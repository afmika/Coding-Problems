/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?


*/
/**
 * @param {string} S
 * @return {string}
 */
var getInverseEditedText = function(S) {
    let edited = "";
	let ignore_count = 0;
	for(let i = S.length - 1; i >= 0; i--) {
		if(S[i] == '#') {
			ignore_count++;
		} else {
			if(ignore_count > 0) {
				ignore_count--;
				continue;
			} else {
				edited += S[i];
			}
		}
	}
    return edited;
}

/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
    let _s = getInverseEditedText(S);
	let _t = getInverseEditedText(T);
    return _s == _t;
};

let S = "ab##", T = "c#d#"
console.log( backspaceCompare(S, T) );