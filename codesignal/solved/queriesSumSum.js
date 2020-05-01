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
