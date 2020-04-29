/*
Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, 
each statue having an non-negative integer size. Since he likes to make things perfect, he wants to arrange them from smallest to largest so that each statue will be bigger than the previous one exactly by 1. He may need some additional statues to be able to accomplish that. Help him figure out the minimum number of additional statues needed.

Example

For statues = [6, 2, 3, 8], the output should be
makeArrayConsecutive2(statues) = 3.

Ratiorg needs statues of sizes 4, 5 and 7.
*/

/*
Why ??
ex:..
 6 2 3 8 => 2 3 6 8 => 2 3 [ 4 5 ] 6 [7] 8 
 additional status = 3
*/
function makeArrayConsecutive2(statues) {
	if (statues.length == 1)
		return 0;
	let min = Infinity, max = -Infinity;
	for (let i = 0; i < statues.length; i++ ) {
		if ( statues[i] < min ) 
			min = statues[ i ];
		if ( statues[ i ] > max ) 
			max = statues[ i ];
	}
	// console.log( max, min)
    // count sort
	let arr = new Array( max - min ).fill(null);
	for (let i = 0; i < statues.length; i++) {
		arr[ statues[i] - min ] = statues[i];
	}
	let count = 0;
	for (let i = 0; i < arr.length; i++ ) {
		if ( arr[i] == null )
			count++;
	}
	return count;
}

console.log( makeArrayConsecutive2( [6, 3] ) );