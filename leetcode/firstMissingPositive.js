/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    let sol = 1;
	let max = -1;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] == sol )
            sol++;
		if(nums[i] > 0) {
			max = Math.max(max, nums[i]);
		}
    }
	if(max == nums[0] && nums.length > 1)
		sol++;
    return sol;
};
console.log(firstMissingPositive([1,2,0]));