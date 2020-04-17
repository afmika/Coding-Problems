/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
	for(let i = 0, j = 0; i < nums1.length; i++) {
		if(nums1[ i ] == 0 && i >= m) {
			nums1[i] = nums2[j];
			m++;
			j++;
			continue;
		}
		if( nums1[ i ] >= nums2[ j ]) {
			let s = nums1.length - 1;
			while( s > i ) {
				nums1[s] = nums1[--s];
			}
			m++;
			let temp = nums1[i];
			if(nums2[ j ] == nums1[ i ])
				nums1[i + 1] = nums2[j];
			else
				nums1[i] = nums2[j];
			j++;
		}
	}
};


let nums1 = [-1,0,0,3,3,3,0,0,0];
let m = 6;
let nums2 = [1,2,2];
let n = 3;
/*
let nums1 = [1,2,3,0,0,0];
let m = 3;
let nums2 = [2,5,6];
let n = 3;
*/
merge( nums1, m, nums2, n );
console.log( nums1 );
