/*
Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

 

Note: You may assume the string contain only lowercase English letters.

*/
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int> > m;
        int i = 0;
        for (char c : s) {
            if ( m.find(c) == m.end() ) m[c] = {0, i};
            else m[c].first++;
            ++i;
        }
        int min_idx = INT_MAX;
        for (auto c : m) {
            if (c.second.first == 0)
                min_idx = min(c.second.second, min_idx);
        }
        return min_idx == INT_MAX ? -1 : min_idx;
    }
};