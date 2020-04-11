/*There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), 
where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. 
How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2


    N will be in the range [1, 100].
    K will be in the range [1, N].
    The length of times will be in the range [1, 6000].
    All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

*/
/**
 * @constructor
 * @param {number} target
 * @param {number} time
 */
function Dest(target, time) {
	this.target = target;
	this.time = time;
}
/**
 * @param {number[][]} times
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var networkDelayTime = function(times, N, K) {
	let connection = {};
	for(let k = 0; k < times.length; k++) {
		const start = times[k][0];
		const end = times[k][1];
		const time = times[k][2];
		
		// start
		if( ! connection[ start ] )
			connection[ start ] = [ new Dest(end, time) ];
		else
			connection[ start ].push( new Dest(end, time) );
		
		// end
		if( ! connection[ end ] )
			connection[ end ] = [ new Dest(start, time) ];
		else
			connection[ end ].push( new Dest(start, time) );
	
	}
	// undefined node
	if(!connection[N] || !connection[K])
		return -1;
	
	let count = 0;
	let f_start = connection[ N ];
	let current = f_start;
	let total_time = 0;
	while(true) {
		for(let i = 0; i < current.length; i++) {
			const dest = current[i];
			if(dest.target == K) {
				return dest.time;
			} else {
				if(count < f_start.length) {
					current = f_start[count];
					total_time += f_start[count].time;
					count++;
				}
			}
		} 
	}
	return total_time;
};


console.log( networkDelayTime( [[2,1,1],[2,3,1],[3,4,1]], 2, 3) );