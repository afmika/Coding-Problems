/*
Given a sequence of integers as an array, determine whether it is possible to obtain a strictly increasing sequence by removing no more than one element from the array.

Note: sequence a0, a1, ..., an is considered to be a strictly increasing if a0 < a1 < ... < an. Sequence containing only one element is also considered to be strictly increasing.

Example

    For sequence = [1, 3, 2, 1], the output should be
    almostIncreasingSequence(sequence) = false.

    There is no one element in this array that can be removed in order to get a strictly increasing sequence.

    For sequence = [1, 3, 2], the output should be
    almostIncreasingSequence(sequence) = true.

    You can remove 3 from the array to get the strictly increasing sequence [1, 2]. Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].

Input/Output

    [execution time limit] 4 seconds (js)

    [input] array.integer sequence

    Guaranteed constraints:
    2 ≤ sequence.length ≤ 105,
    -105 ≤ sequence[i] ≤ 105.
*/

function almostIncreasingSequence(sequence) {
	let n_count = 0, ok_count = 1;
	let map = {};
	for (let i = 1; i < sequence.length; i++) {
		if ( sequence[i-1] >= sequence[i] ) {
			n_count++;
			if (n_count > 1 ) {
				return false;
			}
		} else {
			ok_count++;
		}
		map[ sequence[i-1] ] = true;
		map[ sequence[i] ] = true;
	}
	let q = 0;
	for (let i in map)
		q++;
	console.log(ok_count, n_count)
	return n_count == 1 && q == sequence.length && ok_count + n_count == sequence.length;
}

console.log( almostIncreasingSequence([1, 2, 3, 4, 5, 6]) ); // false , 0 element to remove
console.log( almostIncreasingSequence([1, 2, 3, 4, 8, 6]) ); // true , 1 element to remove
console.log( almostIncreasingSequence([1, 2, 3, 21, 8, 6]) ); // false , 2 elements to remove
console.log( almostIncreasingSequence([1, 2, 1, 2]) ); // false , 2 element to remove
console.log( almostIncreasingSequence([10, 1, 2, 3, 4, 5]) ); // true , 1 elements to remove
console.log( almostIncreasingSequence([40, 50, 60, 10, 20, 30]) ); // false , 3 elements to remove


