/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

Example 2:

Input: [1,3,5,6], 2
Output: 1

Example 3:

Input: [1,3,5,6], 7
Output: 4

Example 4:

Input: [1,3,5,6], 0
Output: 0


 */
#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> nums, int target) {
	int idx = 0;
	int sup_count = 0;
	bool found = false;
	for (int i = 0; i < (int) nums.size(); i++) {
		int v = nums[i];
		if ( v < target ) {
			sup_count++;
		}

		if ( v > target ) {
			found = true;
			if ( sup_count > 0) {
				return i;
			}
		}
		if ( v == target ) {
			return i;
		}
	}

	if ( ! found ) return nums.size();

	return max(0, idx);
}

int main() {
	cout << searchInsert({0,1,2,2,3,4}, 3) << endl;
	cout << searchInsert({0,1,2,4}, 3) << endl;
	cout << searchInsert({0,1,2,2,3,4}, 8) << endl;
	cout << searchInsert({0,1,2,2,2,4}, 3) << endl;
	cout << searchInsert({}, 3) << endl;
	cout << searchInsert({1,2}, 1) << endl;
	cout << searchInsert({1,2}, 0) << endl;
	return 0;
}
