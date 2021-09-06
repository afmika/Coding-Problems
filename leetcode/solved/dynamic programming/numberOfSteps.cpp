class Solution {
public:
    int numberOfSteps (int num) {
		// unordered_map triggers TLE
        int dp[10000001];
        dp[1] = 1;
        for (int i = 2 ; i <= num ; i++) {
            // bottom to top
            dp[i] = 1 + dp [i - 1];
            if (i % 2 == 0) dp[i] = min(dp[i] , 1 + dp[i / 2]);
        }
        return dp[num];
    }
};