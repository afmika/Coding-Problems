/**
 * @author afmika
 * Cycle detection using Floyd's turtle and Hare
 */

/**
 * Generator function f: list -> list
 * bound = Card (list) = size list[]
 * @param {number} bound
 */
function f( bound ) {
	return Math.floor(Math.random() * bound );
}

/** 
 * Generates a list of random numbers that are lower than size
 * @param {number} size
 */
function generateRandomList( size ) {
	let list = [];
	while(list.length < size) {
		list.push( f(size) );
	}
	return list;
}

/** 
 * Displays a preview of the sequence according to limit
 * @param {number[]} list
 * @param {number} limit
 */
function showSequence(list, limit) {
	let a = 0;
	let m = 1;
	while ( true ) {
		a = list[a];
		console.log(`a${m} = ${a}`);
		if(m == limit) {
			break;
		}
		m++;
	}	
}

/**
 * Floyd's turtle and hare
 * @param {number[]} list
 * @returns {number}
 */
function findCycle(list) {
	let [turtle, hare] = [0, 0];
	let m = 1;
	while ( true ) {
		turtle = list[turtle];
		hare = list[ list[hare] ];
		if(turtle == hare) {
			return m;
		}
		m++;
	}
}

let list = generateRandomList( 10 );
console.log(list);

let index_sol = findCycle(list);
console.log("\n- Solution m =", index_sol, " 2m =", 2*index_sol);


// Let's see if a_m == a_2m
let m = index_sol;
let count = 0;
let value = 0;
while(count < m) {
	value = list[value];
	count++;
}
console.log(`a${m} = ${ value }`); // a_m

count = 0;
value = 0;
while(count < 2*m) {
	value = list[value];
	count++;
}
console.log(`a${2*m} = ${ value }`); // a_2m

console.log("\n- Sequence samples...");
showSequence(list, 3*m);
