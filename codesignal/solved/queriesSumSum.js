/*
Given an array of integers arr, and a matrix of integers queries 
where each query stores two indexes of arr: [L, R]. 
Your task is to calculate the sum of the numbers in arr between L and R inclusive of each query, 
then sum up those sums.

Example

    For arr = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1] and queries = [[2, 5], [4, 8], [1, 9]], the answer is 18
    Explanation
        for query [2, 5], the sum of numbers from index 2 to index 5 inclusive is 4.
        for [4, 8], it's 5
        and for [1, 9], it's 9
        then we sum up those sums and get 4 + 5 + 9 = 18

    [execution time limit] 4 seconds (js)

    [input] array.integer arr

    1 <= arr.length <= 2 * 10^5
    -10^6 <= arr[i] <= 10^6

    [input] array.array.integer queries

    1 <= queries.length <= 5 * 10^4
    queries[i].length = 2
    queries[i][0] <= queries[i][1]
    0 <= queries[i][j] < arr.length

    [output] integer64
*/
/*
function makeKey(a, b) {
    return `${a},${b}`;
}
function queriesSumSum(arr, queries) {
    let s = 0;
    let sums = {};
    for (let q = 0; q < queries.length; q++) {
        let a = queries[q][0], b = queries[q][1];
        if (sums[ makeKey(a, b) ] != undefined ) {
            s += sums[ makeKey(a, b) ];
        } else {
            let ds = 0;
            for (let t = a; t <= b; t++) {
                ds += arr[t];
            }
            sums[ makeKey(a, b) ] = ds;
            s += ds;
        }
    }
    return s;
}
*/
/*
Given an array of integers arr, and a matrix of integers queries 
where each query stores two indexes of arr: [L, R]. 
Your task is to calculate the sum of the numbers in arr between L and R inclusive of each query, 
then sum up those sums.

Example

    For arr = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1] and queries = [[2, 5], [4, 8], [1, 9]], the answer is 18
    Explanation
        for query [2, 5], the sum of numbers from index 2 to index 5 inclusive is 4.
        for [4, 8], it's 5
        and for [1, 9], it's 9
        then we sum up those sums and get 4 + 5 + 9 = 18

    [execution time limit] 4 seconds (js)

    [input] array.integer arr

    1 <= arr.length <= 2 * 10^5
    -10^6 <= arr[i] <= 10^6

    [input] array.array.integer queries

    1 <= queries.length <= 5 * 10^4
    queries[i].length = 2
    queries[i][0] <= queries[i][1]
    0 <= queries[i][j] < arr.length

    [output] integer64
*/
function makeKey(a, b) {
    return `${a}-${b}`;
}
function decomposeInterval(map, a, b) {
	let max_computed_intervl = [];
	let max_length = -Infinity;
	let empty = true;
	for (let interval in map ) {
		let [inf, sup] = interval.split('-').map(i => parseInt(i));
		if ( a <= inf && b > sup || a < inf && b >= sup) {
			let cur_length = sup - inf;
			if ( max_length < cur_length ) {
				max_length = cur_length;
				max_computed_intervl = [inf, sup];
			}
		}
		empty = false;
	}

	if ( empty || max_computed_intervl.length == 0 )
		return [];
	
	let middle = max_computed_intervl;

	let [inf, sup] = middle;
	let left = [a, inf - 1];
	let right = [sup + 1, b];
	return [left, middle, right];
}

function queriesSumSumRecurs(sums, arr, queries) {
    let s = 0;
    for (let q = 0; q < queries.length; q++) {
        let a = queries[q][0], b = queries[q][1];
        if (sums[ makeKey(a, b) ] != undefined ) {
            s += sums[ makeKey(a, b) ];
        } else {
			let ds = 0;
			let intervals = decomposeInterval(sums, a, b);
			// console.log(intervals, makeKey(a,b));
			if (intervals.length > 0 ) {
				intervals.forEach( interval => {
					let interval_key = interval.join('-');
					if ( sums[ interval_key ] == undefined ) {
						let [inf, sup] = interval;
						let decomp = decomposeInterval(sums, inf, sup);
						if (decomp.length > 0) {
                            ds += queriesSumSumRecurs(sums, arr, decomp);
						} else {							
							for (let t = inf; t <= sup; t++)
								ds += arr[t];
						}
					} else {
						ds += sums[ interval_key ];
					}
				});
			} else {
				for (let t = a; t <= b; t++) {
					ds += arr[t];
				}		
			}
            sums[ makeKey(a, b) ] = ds;
            s += ds;
        }
    }
    return s;
}

function queriesSumSum(arr, queries) {
	let sums = {};
	return queriesSumSumRecurs(sums, arr, queries);
}

let arr = [-52, 46, 0, -50, 48, -37, 31, -59, -10, 23, -21, -37, -71, 87, -86, 34, -57, 21, 7, 66, 9, 41, 20, 67, -40, 91, -90, 85, -17, -40, 57, 10, 81, 83, -30, -30, 49, -36, -46, -59, 0, 68, 33, 30, 34, 14, 71, 84, 81, 48, -42, -90, 55, -19, 53, 92, -53, -2, 74, 77, -25, -19, 44, 0, -45, -79, 5, -20, -49, -38, -1, -89, 24, 52, -80, 33, -75, -25, 0, 99, 44, 78, 96, 18, -79, 33, -30, -55, 84, -43, 73, -14, 63, 65, -87, -40, -98, -79, 20, 64]
let queries =
[[85,94], 
 [88,94], 
 [78,98], 
 [47,78], 
 [76,80], 
 [26,76], 
 [21,21], 
 [98,98], 
 [57,72], 
 [46,50]];
// console.log( queriesSumSum( [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [[2, 5], [4, 8], [1, 9]]) );
console.log( queriesSumSum( arr, queries ) );

