/*
3. Longest Substring Without Repeating Characters
Medium

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
	let map = {};
	let cur_max_substr = '';
	let temp = '';
    for(let i = 0, j = 0; i < s.length; i++) {
		j = i;
		while ( j < s.length ) {
			if (map[ s[j] ]) {
				map = {};
				temp = '';
				break;
			} else {
				map[ s[j] ] = true;
				temp += s[j];
			}
			if ( temp.length > cur_max_substr.length)
				cur_max_substr = temp;
            j++;
		}
    }
    return cur_max_substr.length;
};


console.log( lengthOfLongestSubstring('dvdf') );