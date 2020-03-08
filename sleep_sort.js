/**
 * @author afmika
 * Sleep Sort
 * Time complexity  : O(K) where K = max(list) is a constant 
 * which means it's virtually faster than O(n log n)
 *
 * Space complexity : O(n)
 */

function sleep_sort( list ) {
	return new Promise((resolve, reject) => {
				let result = [];
				for(let i = 0; i < list.length; ++i) {
					setTimeout(function() {
						result.push( list[i] );
						if(result.length == list.length) {
							resolve(result);
						}
					}, list[i]);
				}		
			});
}

sleep_sort( [5, 3, 4, 0, 1, 3, 9, 6] )
.then(result => {
	// boom
	console.log( result ); // [ 0, 1, 3, 3, 5, 4, 6, 9 ]
});