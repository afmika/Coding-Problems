/*
264. Ugly Number II
Medium

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int pa = 0, pb = 0, pc = 0;
        for(int i = 1; i < n; ++i) {
			int a = 0, b = 0, c = 0;
            int res = min({
                a = dp[pa] * 2, 
                b = dp[pb] * 3, 
                c = dp[pc] * 5
            });
            dp[i] = res;
            if (a == res) ++pa;
            if (b == res) ++pb;
            if (c == res) ++pc;
        }
        return dp[n - 1]; 
    }
};