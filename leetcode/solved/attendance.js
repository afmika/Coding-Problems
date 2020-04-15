/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:

    'A' : Absent.
    'L' : Late.
    'P' : Present.

A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:

Input: "PPALLP"
Output: True

Example 2:

Input: "PPALLL"
Output: False
*/
// count A > 2 || L_continous > 2 => false
var checkRecord = function(s) {
	let a_count = 0;
	let l_continuous = 0;
	for(let i = 0; i < s.length; i++) {
		if(s[i] == 'L') {
			l_continuous++;
			if(l_continuous >= 3)
				return false;
		} else {
			l_continuous = 0;
		}
		if(s[i] == 'A')
			a_count++;
	}
	return a_count <= 1;
};

console.log(checkRecord("AA"))