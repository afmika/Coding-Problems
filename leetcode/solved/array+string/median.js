/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. 

The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let arr = new Array(nums1.length + nums2.length);
    for(let i = 0, a = 0, b = 0; i < arr.length; i++) {
        if(nums1[a] <= nums2[b] || b >= nums2.length) {
			arr[i] = nums1[a++]; 
        } else if(nums1[a] >= nums2[b] || a >= nums1.length) {
			arr[i] = nums2[b++]; 
        }
    }
    let m = arr.length % 2 == 0 ? arr.length / 2 : 1 + Math.floor(arr.length / 2);
	if(arr.length % 2 == 0) 
		return (arr[m - 1] + arr[m]) / 2;
	return arr[m - 1];
};
console.log( findMedianSortedArrays([1, 3],[2]) ); // 2
console.log( findMedianSortedArrays([1], [3, 3]) ); // 3