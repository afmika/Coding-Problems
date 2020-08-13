/**
 * @author afmika
 * github.com/afmika
 * afmichael73@gmail.com
 */
 
const map = {
	'1' : ' ', '2' : 'abc', '3' : 'def',
	'4' : 'ghi', '5' : 'jkl', '6' : 'mno',
	'7' : 'pqrs', '8' : 'tuv', '9' : 'wxyz'
};
function combi(result_container, str_temp, index, nums) {
	if( nums.length == index ) {
		result_container.push( str_temp );
		return;
	}
	for(let k = 0; k < map[ nums[index] ].length; k++) {
		// haha recursion goes brrrr
		combi( result_container, str_temp + map[ nums[index] ][k], index + 1, nums );				
	}
}

let result = [];
combi(result, '', 0, [2,3,4]); // adg, adh, ade, bdg, bdh, bde, ....
console.log( result.sort(), result.length);