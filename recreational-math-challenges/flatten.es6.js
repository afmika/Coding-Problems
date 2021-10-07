/**
 * @author afmika
 *
 * I dont know if the ES6's hi lvl abstraction 
 * should be considered as a bad pratice or not
 * but imma admit this looks pretty cool
 */
 
function flatten (L) {
	if (L.length == 0) return [];
	return [ ... L.shift(), ... (R = flatten(L))];
}

const input = [[1, 2, 3], [4, 5], [6], [7, 8]];
console.log(flatten(input)); // [1, 2, 3, 4, 5, 6, 7, 8]