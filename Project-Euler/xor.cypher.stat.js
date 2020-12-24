const fs = require('fs');

const content = fs.readFileSync('p059_cipher.txt').toString();
const letters = content.split(',');

// a1 a2 a3 a4 a5 a6 a7 a8 a9 ....
//^ 
// K1 K2 K3 K1 K2 K3 K1 K2 K3 ....

// a1 ^ K1 = c1
// a4 ^ K1 = c4
// c1^c4 = a1^K1^a4^K1 = a1^a4
// x ^ y = z
// y = z^x

let map = {};
letters.forEach(l => {
	if ( map[l] == undefined ) map[l] = 0;
	map[l]++
});
console.log(map);

// 0 : 75, 80 : 107, 88 : 77 : we can assume they are all 'e'


let candidates = [0, 80, 10];
let keys = [];
candidates.forEach(c => {
	console.log('e'.charCodeAt(0) ^ c);
	keys.push('e'.charCodeAt(0) ^ c);
});
// e ^ k = 75

function permut(keys) {
	let a = keys[0], b = keys[1], c = keys[2];
	return [
		[a, b, c],
		[a, c, b],
		[b, c, a],
		[b, a, c],
		[c, a, b],
		[c, b, a]
	]
}
function decipher(key) {
	let txt = '';
	for (let i = 0; i < letters.length; i++) {
		let k = key[i % 3];
		txt += String.fromCharCode(k ^ parseInt(letters[i])) 
	}
	return txt;
}
let perms = permut(keys);
perms.forEach(perm => {
	console.log(">> ", perm);
	console.log(decipher(perm).substring(0, 50));
})