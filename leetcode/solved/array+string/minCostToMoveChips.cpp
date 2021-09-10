// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/submissions/
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> c(2, 0);
        for (int p : position) c[p % 2]++;
        return min(c[0], c[1]);
    }
};