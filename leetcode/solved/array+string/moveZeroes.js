/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

var moveZeroes = function(nums) {
	let zero_count = 0;
    for(let i = 0, count = 0; i < nums.length; i++) {
    	if(nums[i] != 0) {
    		nums[count] = nums[i];
    		count++;
    	} else {
    		zero_count++;
    	}
    }
    for(let i = nums.length - zero_count; i < nums.length; i++) {
    	nums[i] = 0;
    }
    return nums;
};

console.log( moveZeroes([0,0,1,0,3,12, 1, 5, 0]));