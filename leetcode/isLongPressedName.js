/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true

Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.

 

Note:

    name.length <= 1000
    typed.length <= 1000
    The characters of name and typed are lowercase letters.
*/

/**
 * @param {string} name
 * @param {string} typed
 * @return {boolean}
 */
var isLongPressedName = function(name, typed) {
	if(name.length > typed.length)
		return false;
	if(name == typed)
		return true;
	let count = 0;
	let map_name = {};
	let map_typed = {};
	let char_name = '';
	let char_typed = '';
	for(let i = 0; i < name.length; i++) {
		let local_count = 0;		
		if(char_name == '') {
			char_name = name[i];
		} else if (char_name[char_name.length - 1] != name[i]) {
			char_name += name[i];
		}
		
		for(let k = count; k < typed.length; k++) {
			if( name[i] == typed[k] ) {
				local_count++;
			} else {
				break;
			}
		}
		if(local_count == 0) {
			let still_valid = cur_count > 1 && name[i-1] == typed[ count - 1 ];
			if( ! still_valid )
				return false;				
		}
		count += local_count;
		cur_count = local_count;
	}
	
	for(let i = 0; i < typed.length; i++) {
		if(char_typed == '') {
			char_typed = typed[i];
		} else if (char_typed[char_typed.length - 1] != typed[i]) {
			char_typed += typed[i];
		}
	}
	if(char_name == char_typed )
		return true;
    return false;
};


console.log( isLongPressedName( "saeed", "ssaaedd") ); // false
console.log( isLongPressedName( "alex", "aaleex") ); // true
console.log( isLongPressedName( "leelee", "lleeelee") ); // true
console.log( isLongPressedName( "laiden", "laiden") ); // true
console.log( isLongPressedName( "kikcxmvzi", "kiikcxxmmvvzz") ); // false
