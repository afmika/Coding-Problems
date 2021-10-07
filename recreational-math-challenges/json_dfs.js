const values = [
	{
		a : 2,
		q : {
			b : { c : 3, d : {f : 8}}
		},
		c : {
			e : -3
		}
	},
	{
		a : 8,
		q : {
			b : { c : 13, d : {f : 'hello'}}
		},
		c : {
			e : 4
		}
	}
];

// DFS
function deepSearchHelper (input, to_find, max_depth) {
	if (max_depth <= 0) 
		return false;
	let result = false;
	for (let key in input) {
		let current = input[key];
		let types = ['number', 'string'];
		let leaf = types.includes(typeof current) || current == undefined || current == null; 
		if (leaf) {
			current += '';
			let expr = new RegExp (to_find, 'i');
			if (expr.test(current)) 
				return true;
		}
		
		result = result || deepSearchHelper (input[key], to_find, max_depth - 1);
	}
	return result;
}

function deepSearch (list, to_find, max_depth) {
	let result = [];
	for (let item of list) {
		if (deepSearchHelper(item, to_find, max_depth))
			result.push(item);
	}
	return result;
}


console.log(deepSearch(values, 'hello', 10));