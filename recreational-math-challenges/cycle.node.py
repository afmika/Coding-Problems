"""
* @author afmika
* Given a random trajectory, reduce it by finding identity operations
*
* Examples :
* A B A D E -> A D E
* A C D E A -> A
* B A C E F A D -> B A D
"""

"""
* Cleans a given trajectory by reducing identity operations
* @param {number} trajectory
"""
 
def cleanTrajectory(trajectory):
	# eg. A, B, E, B, E, F -> A B E F
	clean_version = []
	cycle = None
	for i in range(0, len(trajectory)):
		current = trajectory[i]
		for k in range(i+1, len(trajectory)):
			next = trajectory[k]
			if current is next:
				temp_cycle = {
					"start" : i,
					"end" : k,
					"length" : (k - i),
					"reduced" : current,
					"pass" : False
				}
				if cycle is not None:
					cycle = temp_cycle if temp_cycle["length"] > cycle["length"] else cycle
				else:
					cycle = temp_cycle
				break
			k = k + 1
		i = i + 1
	
	for q in range(0, len(trajectory)):
		is_inside = False
		if cycle is not None:
			is_inside = q >= cycle["start"] and q <= cycle["end"]
			
		if is_inside is False:
			clean_version.append(trajectory[q])
		elif cycle["pass"] is False:
			clean_version.append(cycle["reduced"])
			cycle["pass"] = True
	
	if cycle is None:
		return clean_version
	else:
		return cleanTrajectory(clean_version)


traj = ["B","A","C","E","F","A","D","A","C","D","E","E"]
print( cleanTrajectory(traj) )