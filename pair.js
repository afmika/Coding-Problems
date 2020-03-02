/*
Find a pair (n,r) in an integer array such that value of nPr is maximum

Given an array of non-negative integers arr[], 
the task is to find a pair (n, r) such that nPr 
is maximum possible and r ≤ n.

nPr = n! / (n – r)!

Examples:
Input: arr[] = {5, 2, 3, 4, 1}
Output: n = 5 and r = 4
5P4 = 5! / (5 – 4)! = 120 which is maximum possible.

Input: arr[] = {0, 2, 3, 4, 1, 6, 8, 9}
Output: n = 9 and r = 8 
*/

/*
 * @author afmika
 * github.com/afmika
 * afmichael73@gmail.com
 */
 
function fact(n) {
	return n <= 0 ? 1 : n * fact(n - 1);	
}
function nPr(n, r) {
	return fact(n) / fact(n - r);
}

function search(arr) {
	let pair_sol = {n : -1, r : -1}; 
	let max = -Infinity;
	let checkedOut = {}; // hashmap
	for(let i = 0; i < arr.length; i++) {
		for(let k = 0; k < arr.length; k++) {
			if(i != k) {
				let pair = {n : arr[i], r : arr[k]};
				let key = JSON.stringify(pair);
				if(checkedOut[key] == undefined) {				
					checkedOut[key] = true;
					let npr = nPr(pair.n, pair.r);
					max = Math.max(npr, max);
					if(max == npr) {
						pair_sol = pair;
					}
				}
			}
		}
	}
	console.log(checkedOut);
	return pair_sol;
}

console.log(search([5, 2, 3, 4, 1]));
console.log(search([0, 2, 3, 4, 1, 6, 8, 9]));