class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.size() == 0 ) 
            return 0;
        
        vector<int> pref(nums.size());
        pref[0] = nums[0];
        for (int i = 1; i < (int) nums.size(); i++) {
            pref[i] = pref[i-1] + nums[i];
        }
        int maxi = INT_MIN;
        int mini = 0; // lower sum
        for (int i = 0; i < (int) nums.size(); i++) { 
			// equiv pref[i] - pref[i-1]
            maxi = max(maxi, pref[i] - mini); 
            mini = min(mini, pref[i]); 
        } 
        return maxi;
    }
};