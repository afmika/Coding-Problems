class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (dp.find(nums[i]) == dp.end()) {
                dp[nums[i]] = true;
            } else {
                return nums[i];
            }
        }
        return -1;
    }
};