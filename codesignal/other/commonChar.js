/*
Given two strings, find the number of common characters between them.

Example

For s1 = "aabcc" and s2 = "adcaa", the output should be
commonCharacterCount(s1, s2) = 3.

Strings have 3 common characters - 2 "a"s and 1 "c".
*/

function commonCharacterCount(s1, s2) {
    let map_s1 = {}, map_s2 = {};
	let common_count = 0;
    for (let i = 0; i < s1.length; i++)
		map_s1[ s1[i] ] = true;
	for (let i = 0; i < s2.length; i++)
		map_s2[ s2[i] ] = true;
	
	let counted = {};
	let array = Math.max(s1.length, s2.length) == s1.length ? [s1, s2] : [s2, s1];
	array.forEach( str => {
		let cur_map = str == s1 ? map_s2 : map_s1;
		for (let i = 0; i < str.length; i++) {
			if (cur_map[ str[i] ] && counted[ str[i] ] == undefined) {
				counted[ str[i] ] = true;
				common_count++;
			}
		}		
	});
	return common_count;
}

console.log( commonCharacterCount("aabcc" , "adcaa") );