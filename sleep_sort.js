/**
 * @author afmika
 * Sleep Sort
 * Time complexity  : O(K) where K is a constant ( K = 2*max(list))
 * which means it's virtually faster than O(n log n)
 * Yeah it's somehow stupid but at least it does the job xD
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
					}, 2 * list[i]);
				}		
			});
}

sleep_sort( [5, 3, 4, 0, 1, 3, 9, 6, 7, 10, 4] )
.then(result => {
	// boom
	console.log( result ); // [ 0, 1, 3, 3, 4, 4, 5, 6, 7, 9, 10 ]
});