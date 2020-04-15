/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let res = [];
	let map = {};
    for(let i = 0; i < nums.length; i++) {
        for(let j = i + 1; j < nums.length; j++) {
            for(let k = j + 1; k < nums.length; k++) {
                if( nums[i] + nums[j] + nums[k] == 0 ) {
					let temp = [ nums[i], nums[j], nums[k] ].sort();
					let key = temp.join(',');
					if( map[key] == undefined ) {						
						res.push( temp ) ;
						map[key] = true;
					}
                }
            }
        }
    }
    return res;
};

console.log( threeSum([-1, 0, 1, 2, -1, -4]) )