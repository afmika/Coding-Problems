// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int) boxes.size();
        vector<int> ones;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            if (boxes[i] == '1') ones.push_back (i);
        
        for (int i = 0; i < n; i++) {
            for (int &o : ones) {
                if (o == i) continue;
                ans[i] += abs(i - o);
            }
        }
        return ans;
    }
};