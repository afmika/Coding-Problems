/*
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b

 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

Example 3:

Input: nums = []
Output: []

Example 4:

Input: nums = [-1]
Output: ["-1"]

Example 5:

Input: nums = [0]
Output: ["0"]

 

Constraints:

    0 <= nums.length <= 20
    -231 <= nums[i] <= 231 - 1
    All the values of nums are unique.
*/
class Solution {
public:
    void append(vector<string>& res, const vector<int>& nums, int left, int right) {
        if ( left - right + 1 == 0 )
            res.push_back(to_string(nums[left]));
        else 
            res.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int l = nums.size();
        vector<string> res;
        if ( l == 0 ) return res;
        
        int left = 0, right = 1;
        while ( right < l ) {
            // INT_MIN <= nums[i] <= INT_MAX
            long diff = (long) nums[right] - (long) nums[right - 1];
            if ( diff > 1 ) {
                append(res, nums, left, right);
                left  = right;
                right = left + 1;
                continue;
            }
            ++right;
        }
        append(res, nums, left, right);
        return res;
    }
};