/*
You've created a new programming language, and now you've decided to add hashmap support to it. Actually you are quite disappointed that in common programming languages it's impossible to add a number to all hashmap keys, or all its values. So you've decided to take matters into your own hands and implement your own hashmap in your new language that has the following operations:

    insert x y - insert an object with key x and value y.
    get x - return the value of an object with key x.
    addToKey x - add x to all keys in map.
    addToValue y - add y to all values in map.

To test out your new hashmap, you have a list of queries in the form of two arrays: queryTypes contains the names of the methods to be called (eg: insert, get, etc), and queries contains the arguments for those methods (the x and y values).

Your task is to implement this hashmap, apply the given queries, and to find the sum of all the results for get operations.

Example

    For queryType = ["insert", "insert", "addToValue", "addToKey", "get"] 
	and query = [[1, 2], [2, 3], [2], [1], [3]], the output should be hashMap(queryType, query) = 5.

    The hashmap looks like this after each query:
        1 query: {1: 2}
        2 query: {1: 2, 2: 3}
        3 query: {1: 4, 2: 5}
        4 query: {2: 4, 3: 5}
        5 query: answer is 5

    The result of the last get query for 3 is 5 in the resulting hashmap.
*/

function hashMap(queryType, query) {
	let map = {};
	let g_sum = 0;
	for(let  i = 0; i < query.length; i++) {
		switch( queryType[i] ) {
			case 'insert':
				map[ query[i][0] ] = query[i][1];
				break;
			case 'get':
				g_sum += map[ query[i][0] ];
				break;
			case 'addToKey':
				let x = query[i][0];
				let new_map = {};
				for(let key in map) {
					new_map[x + parseFloat(key)] = map[key];
				}
				map = new_map;
				break;
			case 'addToValue':
				let y = query[i][0];
				for(let key in map) {
					map[key] += y;
				}
				break;		
		}
	}
	return g_sum;
}
/*
console.log(
hashMap( ["insert", "insert", "addToValue", "addToKey", "get"] , [[1, 2], [2, 3], [2], [1], [3]])
);
*/

console.log(hashMap(
["addToValue", 
 "addToValue", 
 "insert", 
 "insert", 
 "insert", 
 "addToValue", 
 "addToValue", 
 "addToKey", 
 "get", 
 "addToKey", 
 "insert", 
 "addToKey", 
 "addToKey", 
 "insert", 
 "get", 
 "addToValue", 
 "addToValue", 
 "insert", 
 "get", 
 "addToValue", 
 "addToKey", 
 "addToValue", 
 "addToValue", 
 "get", 
 "insert", 
 "insert", 
 "get", 
 "get", 
 "get", 
 "addToValue", 
 "addToKey", 
 "addToKey", 
 "insert", 
 "addToKey", 
 "insert", 
 "get", 
 "get", 
 "get", 
 "addToKey", 
 "insert", 
 "addToValue", 
 "addToValue", 
 "get", 
 "addToKey", 
 "get", 
 "get", 
 "addToValue", 
 "addToValue", 
 "addToValue", 
 "insert", 
 "addToValue", 
 "addToKey", 
 "insert", 
 "addToValue", 
 "get", 
 "addToKey", 
 "insert", 
 "addToValue", 
 "addToValue", 
 "addToValue", 
 "addToValue", 
 "get", 
 "get", 
 "addToKey", 
 "insert", 
 "insert", 
 "addToKey", 
 "addToValue", 
 "addToKey", 
 "addToKey", 
 "insert", 
 "get", 
 "addToValue", 
 "addToKey", 
 "insert", 
 "addToKey", 
 "get", 
 "get", 
 "addToValue", 
 "addToValue", 
 "get", 
 "insert", 
 "insert", 
 "addToKey", 
 "addToValue", 
 "insert", 
 "addToKey", 
 "insert", 
 "addToKey", 
 "insert", 
 "addToKey", 
 "addToKey", 
 "get", 
 "insert", 
 "insert", 
 "addToValue", 
 "get", 
 "get", 
 "addToValue", 
 "addToValue"]
,[[-10], 
 [-32], 
 [-37,32], 
 [-45,26], 
 [-25,-23], 
 [23], 
 [49], 
 [-14], 
 [-39], 
 [15], 
 [3,44], 
 [3], 
 [-35], 
 [40,22], 
 [-56], 
 [-34], 
 [38], 
 [6,-39], 
 [-29], 
 [1], 
 [43], 
 [-30], 
 [37], 
 [-33], 
 [-23,45], 
 [-48,-21], 
 [-23], 
 [49], 
 [14], 
 [3], 
 [28], 
 [-29], 
 [38,11], 
 [-46], 
 [20,20], 
 [-95], 
 [-33], 
 [-70], 
 [-19], 
 [-14,36], 
 [16], 
 [-42], 
 [-79], 
 [20], 
 [3], 
 [6], 
 [36], 
 [-32], 
 [24], 
 [7,-12], 
 [34], 
 [-33], 
 [-46,1], 
 [-14], 
 [-26], 
 [35], 
 [-21,-48], 
 [-2], 
 [-1], 
 [41], 
 [7], 
 [5], 
 [-69], 
 [5], 
 [-40,33], 
 [-48,-20], 
 [38], 
 [49], 
 [48], 
 [40], 
 [-14,-9], 
 [39], 
 [42], 
 [-25], 
 [48,34], 
 [-41], 
 [88], 
 [-4], 
 [-47], 
 [-23], 
 [12], 
 [-45]]
 ));