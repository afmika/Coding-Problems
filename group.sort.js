/**
 * @author afmika
 * Episodes sort algorithm
 */

/**
 * @param {number} trajectory
 */
function groupSort (array, pattern = '([0-9])+(\\.[0-9]+)?' ) {
	array = array.sort(); // sorting alphabetically first
	
	const regex = new RegExp(pattern, 'gi');
	
	// sorting according to the pattern
	let mapped = [];
	for (let i = 0; i < array.length; i++) {
		let value = array[i] + '';
		let result = value.match(regex);
		mapped.push({
			index : i,
			sortVal : result == null ? [] : result.map(q => parseFloat(q)) 
		});
	}
	
	let sorted_obj = mapped.sort((a, b) => {
		let [va, vb] = [a.sortVal, b.sortVal];
		let min_length = Math.min(va.length, vb.length);
		for (let i = 0; i < min_length; i++) {
			let diff = va[i] - vb[i];
			if ( diff > 0 ) {
				return diff;
			}
		}
		return 0;
	});
	
	let sorted = new Array(sorted_obj.length);
	for (let i = 0; i < sorted_obj.length; i++) {
		sorted[i] = array[ sorted_obj[i].index ];
	}
	return sorted;	
}

let res = groupSort([
	'bleach s1 episode 4',
	'bleach s1 episode 3',
	'bleach s1 episode 1',
	'naruto s1 episode 12',
	'bleach s3 episode 4',
	'naruto s2 episode 8',
	'bleach s1 episode 12',
	'fma v1 chapter.4',
	'fma v1 chapter.2'
]);

console.log(res);