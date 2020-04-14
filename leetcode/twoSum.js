/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


*/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
       /**
        * Bruteforce Optimised
        *       a0    a1    a2    ...   ...     aN
        * a0   a0+a0  ...   ...   ...   ...   a0 + aN
        * a1   ....   ...
        * .    ....   ...  aK+a2  ...  aK+aP     .
        * .      .           		.      
        * .            .                         .
        * aN   aN+a1  ...   ...   ...   ...   aN + aN
        *
        * if the current loop is at index-K then we just only need to care
        * about row,col >= K, K 
        **/
    for(let i = 0; i < nums.length; i++) {
		for(let j = i+1; j < nums.length; j++) {
			if(i != j && ( nums[i] + nums[j] ) == target ) {
				return [i, j];
			}
		}
	}
	return [];
};

console.log( twoSum([3, 2, 7, 7], 9) );