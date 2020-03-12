/**
 * @author afmika
 * Given a random trajectory, reduce it by finding identity operations
 *
 * Examples :
 * A B A D E -> A D E
 * A C D E A -> A
 * B A C E F A D -> B A D
 */

/**
 * Cleans a given trajectory by reducing identity operations
 * @param {number} trajectory
 */
function cleanTrajectory(trajectory) {
	// eg. A, B, E, B, E, F -> A B E F
	let clean_version = [];
	let cycle = null;
	for(let i = 0; i < trajectory.length; i++) {
		let current = trajectory[i];
		for(let k = i + 1; k < trajectory.length; k++) {
			let next = trajectory[k];
			if(current == next) {
				// Ex : a closed cycle such as A B C B C A can be reduced to a single node A
				// in our case i ... k can be reduced to the current node
				let temp_cycle = {
					start : i, 
					end : k, 
					length : (k - i),
					reduced : current,
					pass : false
				};
				if(cycle != null) {
					cycle = temp_cycle.length > cycle.length 
							? temp_cycle : cycle;
				} else {
					cycle = temp_cycle;
				}
				break;
			}
		}
	}
				
	for(let q = 0; q < trajectory.length; q++) {
		let is_inside = false;
		if(cycle != null) {
			is_inside = q >= cycle.start && q <= cycle.end;			
		}
		if(!is_inside) {
			clean_version.push(trajectory[q]);
		} else if(!cycle.pass) {
			clean_version.push(cycle.reduced);
			cycle.pass = true;
		}
	}
	
	if(cycle == null) {
		return clean_version;
	} else {
		return cleanTrajectory(clean_version);
	}
}

let traj = "B A C E F A D A C D E E".split(" ");
console.log(cleanTrajectory(traj));