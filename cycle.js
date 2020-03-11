/**
 * @author afmika
 * Cycle detection using Floyd's turtle and Hare
 */

// fonction generateur f : list -> list 
// bound = Card (list) = taille list[]
function f( bound ) {
	return Math.floor(Math.random() * bound );
}

// genere une liste de nombre aleatoire inferieur stricte a size
function generateRandomList( size ) {
	let list = [];
	while(list.length < size) {
		list.push( f(size) );
	}
	return list;
}

// affiche un extrait de la suite en fonction de limit
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

// algo de Floyd en action
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


// demos, juste pour montrer que a_m == a_2m
let m = index_sol;
let count = 0;
let value = 0;
while(count < m) {
	value = list[value];
	count++;
}
console.log(`a${m} = ${ value }`); // affiche a_m

count = 0;
value = 0;
while(count < 2*m) {
	value = list[value];
	count++;
}
console.log(`a${2*m} = ${ value }`); // affiche a_2m

// affiche un extrait de la suite generee par f : list -> list
// on peut par exemple 'voir' a l'oeil les cycles (repetitions periodiques) pour deboguer
console.log("\n- Sequence samples...");
showSequence(list, 3*m);
