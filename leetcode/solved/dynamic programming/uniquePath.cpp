/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = i * j == 0 ? 1 : dp[i - 1][j] + dp[i][j - 1];             
            }
        }
        return dp[m-1][n-1];
    }
};