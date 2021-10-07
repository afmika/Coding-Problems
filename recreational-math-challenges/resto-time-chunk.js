const paquet = 30; // 30 mins

function timeCompare (cur, next) {
	const [h1, m1] = cur;
	const [h2, m2] = next;
	if (h1 == h2)
		return m1 - m2;
	return h1 - h2;	
}

function sortASC (arr) {
	return arr.sort(timeCompare);
}

function addMinutes (time, min) {
	let [h, m] = time;
	m += min;
	if (m >= 60) h++;
	return [h, m % 60];
}

function groupByChunks (times) {
	times = sortASC(times);
	let groups = [];
	let current_time = [0, 0];
	let started = false;
	while (times.length > 0) {
		
		let curr_group = [];
		
		while (times.length > 0) {
			if (timeCompare(current_time, times[0]) >= 0) {
				curr_group.push(times[0]);
				times.shift();
			} else {
				break;
			}
		}
		
		if (curr_group.length > 0)
			started = true; 

		if (started)
			groups.push(curr_group); 
		
		// next 30 min
		current_time = addMinutes(current_time, paquet);
	}
	return groups;
}

const times = [
	[10, 10], // ex 10h 10min

	[10, 40],
	[11, 41],
	[10, 42],
	[11, 38],
	[11, 58],

	[12, 13],
	[12, 20]
];

const result = groupByChunks(times);

// affichage
// paquet == 30 min ici
result.forEach ((group, i) => {
	const interval = [i, i + 1].map(x => x * paquet);
	console.log(interval.join('-')  +' min =>', group, ' total ', group.length);
});

