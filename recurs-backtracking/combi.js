/**
 * @author afmika
 * github.com/afmika
 * afmichael73@gmail.com
 */
 
function combi(result, str_temp, letters, n) {
	if(str_temp.length == n) {
		result.push(str_temp);
	} else {
		letters.forEach(l => {
			combi(result, str_temp + l, letters, n);
		});
	}
}

let result = [];
combi(result, '', ['a', 'b', 'c'], 3);
console.log(result);