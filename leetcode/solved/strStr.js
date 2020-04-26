/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.
*/
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle == '')
        return 0;
    for(let k = 0; k < haystack.length; k++ ) {
        if( haystack[k] == needle[0] && (k + needle.length - 1) < haystack.length) {
            let pass_count = 1;
            for(let q = 1; q < needle.length; q++) {
                if(haystack[k + q] == needle[q]) {
                    pass_count++;
                }
            }
            if(pass_count == needle.length)
                return k;
        }
    }
    return -1;
};

console.log( strStr("bonjourjesuisunefoutue chaine de char","jesui"))