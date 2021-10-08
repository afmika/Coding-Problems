const fs = require ('fs');
const content = fs.readFileSync ('namesScores.input.txt').toString();
let names = content.split(',').map(x => x.replace(/"/g, ''));
let sumAlpha = str => str.split('')
		.map(s => (s.charCodeAt(0) - 64))
		.reduce((acc, i) => acc + i);

// console.log(sumAlpha('COLIN'));

function solve () {
	let result = names
		.sort()
		.map((v, pos) => {
			return sumAlpha(v) * (pos + 1);
		})
		.reduce((acc, i) => acc + i);
	return result;
}

console.log(solve());