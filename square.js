/*

Find all numbers between range L to R such that sum of digit and sum of square of digit is prime

Given a range L and R count all numbers between L to R 
such that sum of digit of each number and sum of square 
of digit of each number is Prime.

Note: 10 <= [L, R] <= 108

Examples
 Input: L = 10, R = 20
Output: 4
Such types of numbers are: 11 12 14 16

Input: L = 100, R = 130
Output: 9

*/

/**
 * @author afmika
 * github.com/afmika
 * afmichael73@gmail.com
 */
function isPrime(n) {
	for(let i = 2; i <= Math.sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

function isOK(n) {
	let n_str = n+"";
	let arr = []; 
	let [s1, s2] = [0, 0];
	for(let i = 0; i <  n_str.length; i++){
		let digit = parseInt( n_str[i] );
		s1 += digit; s2 += digit*digit;
	}
	return isPrime(s1) && isPrime(s2);
}

function search(L, R) {
	for(let i = L; i <= R; i++)
		if(isOK(i))
			console.log(i);
}

search(11, 20);